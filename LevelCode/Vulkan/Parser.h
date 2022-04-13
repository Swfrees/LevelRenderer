#pragma once
#include "../Gateware/Gateware.h"
#include <vulkan/vulkan_core.h>
#include "h2bParser.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

enum ObjectType
{
	NONE = 0,
	MODEL,
	LIGHT
};

struct Model
{
	std::string ModelName;
	
	VkBuffer ModelVertexBuffer;
	VkBuffer ModelIndexBuffer;
	VkDeviceMemory ModelVertexMemory;
	VkDeviceMemory ModelIndexMemory;

	std::vector<H2B::VERTEX> ModelVertices;
	std::vector<unsigned> ModelIndices;
	std::vector<H2B::BATCH> ModelSubmeshes;
	std::vector<H2B::MATERIAL> ModelMaterials;

	GW::MATH::GMATRIXF ModelWorldMatrix;

};

struct LevelObject
{
	ObjectType ObjectType;
	std::string ObjectName;
	GW::MATH::GMATRIXF ObjectWorldMatrix;
};

struct Level
{
	std::string LevelPath;
	std::vector <LevelObject> LevelObjects;
	//std::vector<Models> LevelModels;
	//std::vector<DirectionLight> DirectionalLights;
	//std::vector<PointLight> PointLights;
};

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
				else if(Line == "LIGHT")
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
					if ((int) ' ' != (int)Line.at(j))
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
				if ((int)floats.at(i) != (int)',' && (int)floats.at(i) != (int)"\n")
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
		for (int i = 0; i < 4; i++)
			std::cout << ReturnLevel.LevelObjects[i].ObjectWorldMatrix.row1.data[i] << " ";
		std::cout << "\n";
		for (int i = 0; i < 4; i++)
			std::cout << ReturnLevel.LevelObjects[i].ObjectWorldMatrix.row2.data[i] << " ";
		std::cout << "\n";
		for (int i = 0; i < 4; i++)
			std::cout << ReturnLevel.LevelObjects[i].ObjectWorldMatrix.row3.data[i] << " ";
		std::cout << "\n";
		for (int i = 0; i < 4; i++)
			std::cout << ReturnLevel.LevelObjects[i].ObjectWorldMatrix.row4.data[i] << " ";
		std::cout << "\n\n";
	}

	std::cout << "-----------------------------------------\n\n";

	return ReturnLevel;
}