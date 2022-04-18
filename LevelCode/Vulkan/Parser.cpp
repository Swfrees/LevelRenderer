
#define GATEWARE_ENABLE_CORE // All libraries need this
#define GATEWARE_ENABLE_SYSTEM // Graphics libs require system level libraries
#define GATEWARE_ENABLE_GRAPHICS // Enables all Graphics Libraries


#include "Parser.h"
#include <windows.h>
#include <direct.h>
#include "../Gateware/Gateware.h"
#include <vulkan/vulkan_core.h>
using namespace H2B;

Level ParseLevel(std::string LevelName)
{
	Level ReturnLevel = {};

	std::fstream FStream = std::fstream(LevelName);

	while (FStream.is_open())
	{
		char Buffer[CHAR_MAX] = {};
		FStream.getline(Buffer, CHAR_MAX);
		std::string Line = (std::string)Buffer;

		if (Line[0] != '#' && !Line.empty())
		{
			LevelObject TempObject;
			TempObject.ObjectType = NONE;

			//increase look length if adding sound/camera
			for (size_t i = 0; i < 2; i++)
			{
				if (Line == "MESH")
				{
					TempObject.ObjectType = MODEL;
				}
				else if (Line == "LIGHT")
				{
					TempObject.ObjectType = LIGHT;
				}
			}

			FStream.getline(Buffer, CHAR_MAX);
			Line = (std::string)Buffer;

			if (Line.find('.') != std::string::npos) //npos = no position
			{
				TempObject.ObjectName = "";
				for (size_t i = 0; i < Line.find_first_of('.'); i++)
				{
					TempObject.ObjectName += Line.at(i);
				}
			}

			else
			{
				TempObject.ObjectName = Line;
			}

			std::string floats = "";
			for (size_t i = 0; i < 4; i++)
			{
				FStream.getline(Buffer, CHAR_MAX);
				Line = (std::string)Buffer;

				for (size_t j = Line.find_first_of('(') + 1; Line.at(j) != ')' && j < Line.size(); j++)
				{
					if ((int)' ' != (int)Line.at(j))
					{
						floats += Line.at(j);
					}
				}

				floats.append("\n");
			}

			GW::MATH::GMATRIXF TempMatrix = GW::MATH::GMATRIXF();

			int Iter = 0;
			std::string TempString = "";

			for (size_t i = 0; i < floats.size(); i++)
			{
				if ((int)floats.at(i) != (int)',' && (int)floats.at(i) != (int)'\n')
				{
					TempString += floats.at(i);
				}
				else
				{
					TempMatrix.data[Iter] = atof(TempString.c_str());
					TempString = "";

					Iter++;
				}
			}

			TempObject.ObjectWorldMatrix = TempMatrix;
			ReturnLevel.LevelObjects.push_back(TempObject);
		}
		if (Line.empty())
		{
			FStream.close();
		}
	}

	std::cout << "Parsed " << ReturnLevel.LevelObjects.size() << " " << "Game Objects.\n";
	std::cout << "-----------------------------------------\n";

	for (int i = 0; i < ReturnLevel.LevelObjects.size(); i++) {
		std::cout << (int)ReturnLevel.LevelObjects[i].ObjectType << "\n" << ReturnLevel.LevelObjects[i].ObjectName << "\n";
		for (int j = 0; j < 4; j++)
			std::cout << ReturnLevel.LevelObjects[i].ObjectWorldMatrix.row1.data[j] << " ";
		std::cout << "\n";
		for (int j = 0; j < 4; j++)
			std::cout << ReturnLevel.LevelObjects[i].ObjectWorldMatrix.row2.data[j] << " ";
		std::cout << "\n";
		for (int j = 0; j < 4; j++)
			std::cout << ReturnLevel.LevelObjects[i].ObjectWorldMatrix.row3.data[j] << " ";
		std::cout << "\n";
		for (int j = 0; j < 4; j++)
			std::cout << ReturnLevel.LevelObjects[i].ObjectWorldMatrix.row4.data[j] << " ";
		std::cout << "\n\n";
	}

	std::cout << "-----------------------------------------\n\n";

	return ReturnLevel;
}

void H2BLoad(std::string ObjectName, std::vector<H2B::VERTEX> &OutputVertices, std::vector<unsigned> &OutputIndices, std::vector<H2B::BATCH> &OutputSubmeshes, std::vector<H2B::MATERIAL> &OutputMaterials)
{
	Parser ParseObject = {};
	ParseObject.Parse(ObjectName.c_str());
	OutputVertices = ParseObject.vertices;
	OutputIndices = ParseObject.indices;
	OutputSubmeshes = ParseObject.batches;
	OutputMaterials = ParseObject.materials;
}

void LoadLevel(Level &InputLevel, VkDevice& device, VkPhysicalDevice& physicalDevice)
{
	for (size_t i = 0; i < InputLevel.LevelObjects.size(); i++)
	{
		if (InputLevel.LevelObjects[i].ObjectType == MODEL)
		{

			std::string TempString = "";
			TempString = (std::string)_getcwd(NULL, 0);
			for (size_t i = TempString.size() - 1; TempString.at(i) != '\\'; i--)
			{
				TempString.erase(i);
			}
			TempString.append("Model\\");
			TempString.append(InputLevel.LevelObjects[i].ObjectName);
			TempString.append(".h2b");

			Model TempModel = {};
			TempModel.ModelName = TempString;
			TempModel.ModelWorldMatrix = InputLevel.LevelObjects[i].ObjectWorldMatrix;

			H2BLoad(TempString, TempModel.ModelVertices, TempModel.ModelIndices, TempModel.ModelSubmeshes, TempModel.ModelMaterials);

			InputLevel.LevelModels.push_back(TempModel);
			int CurrentIndex = InputLevel.LevelModels.size() - 1;

			GvkHelper::create_buffer(physicalDevice, device, sizeof(VERTEX) * InputLevel.LevelModels[CurrentIndex].ModelVertices.size(),
				VK_BUFFER_USAGE_VERTEX_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
				VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, &InputLevel.LevelModels[CurrentIndex].ModelVertexBuffer, &InputLevel.LevelModels[CurrentIndex].ModelVertexMemory);
			GvkHelper::write_to_buffer(device, InputLevel.LevelModels[CurrentIndex].ModelVertexMemory, InputLevel.LevelModels[CurrentIndex].ModelVertices.data() , sizeof(VERTEX) * InputLevel.LevelModels[CurrentIndex].ModelVertices.size());
			GvkHelper::create_buffer(physicalDevice, device, sizeof(unsigned int) * InputLevel.LevelModels[CurrentIndex].ModelIndices.size(),
				VK_BUFFER_USAGE_INDEX_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
				VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, &InputLevel.LevelModels[CurrentIndex].ModelIndexBuffer, &InputLevel.LevelModels[CurrentIndex].ModelIndexMemory);
			GvkHelper::write_to_buffer(device, InputLevel.LevelModels[CurrentIndex].ModelIndexMemory, InputLevel.LevelModels[CurrentIndex].ModelIndices.data(), sizeof(unsigned int) * InputLevel.LevelModels[CurrentIndex].ModelIndices.size());
		}
	}
}

void SetupModelData(Level &InputLevel, SHADER_MODEL_DATA &modelData)
{
	for (size_t i = 0, m = 0; i < InputLevel.LevelModels.size(); i++)
	{
		modelData.matricies[i] = InputLevel.LevelModels[i].ModelWorldMatrix;
		for (size_t j = 0; j < InputLevel.LevelModels[i].ModelSubmeshes.size(); j++, m++)
		{
			InputLevel.LevelModels[i].SubmeshMaterials.push_back(InputLevel.LevelModels[i].SubmeshMaterials.size());
			modelData.materials[m] = InputLevel.LevelModels[i].ModelMaterials[j].attrib;
		}
	}
}

struct UINT2
{
	unsigned int x;
	unsigned int y;
};

void RenderModels(Level InputLevel, std::vector<VkDescriptorSet> descriptorSet, VkCommandBuffer &commandBuffer, VkPipelineLayout &pipelineLayout, VkDeviceSize *offsets)
{

	int m = 0;

	for (size_t i = 0; i < InputLevel.LevelModels.size(); i++)
	{

		vkCmdBindVertexBuffers(commandBuffer, 0, 1, &InputLevel.LevelModels[i].ModelVertexBuffer, offsets);
		vkCmdBindIndexBuffer(commandBuffer, InputLevel.LevelModels[i].ModelIndexBuffer, *offsets, VK_INDEX_TYPE_UINT32);

		for (size_t j = 0; j < descriptorSet.size(); j++)
		{
			vkCmdBindDescriptorSets(commandBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS,
				pipelineLayout, 0, 1, &descriptorSet[j], 0, nullptr);
		}


		for (size_t j = 0; j < InputLevel.LevelModels[i].ModelSubmeshes.size(); j++, m++)
		{
			UINT2 PushInts = {};
			PushInts.x = i;
			PushInts.y = m /*InputLevel.LevelModels[i].SubmeshMaterials[i + j]*/;
			vkCmdPushConstants(commandBuffer, pipelineLayout, (VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT), *offsets, sizeof(unsigned int) * 2, &PushInts);
			vkCmdDrawIndexed(commandBuffer, InputLevel.LevelModels[i].ModelSubmeshes[j].indexCount, 1, InputLevel.LevelModels[i].ModelSubmeshes[j].indexOffset, *offsets, 0);
		}
	}
}

void LevelCleanup(Level &InputLevel, VkDevice &device)
{
	vkDeviceWaitIdle(device);

	for (int i = 0; i < InputLevel.LevelModels.size(); ++i) {
		vkDestroyBuffer(device, InputLevel.LevelModels[i].ModelVertexBuffer, nullptr);
		vkFreeMemory(device, InputLevel.LevelModels[i].ModelVertexMemory, nullptr);
		vkDestroyBuffer(device, InputLevel.LevelModels[i].ModelIndexBuffer, nullptr);
		vkFreeMemory(device, InputLevel.LevelModels[i].ModelIndexMemory, nullptr);
	}

}