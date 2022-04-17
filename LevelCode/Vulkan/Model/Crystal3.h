// "Crystal3.h" generated by "Obj2Header.exe" [Version 1.9d] Author: L.Norri Fullsail University.
// Data is converted to left-handed coordinate system and UV data is V flipped for Direct3D/Vulkan.
// The companion file "Crystal3.h2b" is a binary dump of this format(-padding) for more flexibility.
// Loading *.h2b: read version, sizes, handle strings(max len 260) by reading until null-terminated.
/***********************/
/*  Generator version  */
/***********************/
#ifndef _Crystal3_version_
const char Crystal3_version[4] = { '0','1','9','d' };
#define _Crystal3_version_
#endif
/************************************************/
/*  This section contains the model's size data */
/************************************************/
#ifndef _Crystal3_vertexcount_
const unsigned Crystal3_vertexcount = 36;
#define _Crystal3_vertexcount_
#endif
#ifndef _Crystal3_indexcount_
const unsigned Crystal3_indexcount = 36;
#define _Crystal3_indexcount_
#endif
#ifndef _Crystal3_materialcount_
const unsigned Crystal3_materialcount = 1; // can be used for batched draws
#define _Crystal3_materialcount_
#endif
#ifndef _Crystal3_meshcount_
const unsigned Crystal3_meshcount = 1;
#define _Crystal3_meshcount_
#endif
/************************************************/
/*  This section contains the raw data to load  */
/************************************************/
#ifndef __OBJ_VEC3__
typedef struct _OBJ_VEC3_
{
	float x,y,z; // 3D Coordinate.
}OBJ_VEC3;
#define __OBJ_VEC3__
#endif
#ifndef __OBJ_VERT__
typedef struct _OBJ_VERT_
{
	OBJ_VEC3 pos; // Left-handed +Z forward coordinate w not provided, assumed to be 1.
	OBJ_VEC3 uvw; // D3D/Vulkan style top left 0,0 coordinate.
	OBJ_VEC3 nrm; // Provided direct from obj file, may or may not be normalized.
}OBJ_VERT;
#define __OBJ_VERT__
#endif
#ifndef _Crystal3_vertices_
// Raw Vertex Data follows: Positions, Texture Coordinates and Normals.
const OBJ_VERT Crystal3_vertices[36] =
{
	{	{ -0.084734f, -0.002159f, -0.136484f },	{ 0.615490f, 0.756953f, 0.000000f },	{ -0.030000f, -0.350300f, -0.936200f }	},
	{	{ 0.075832f, -0.002159f, -0.141623f },	{ 0.840381f, 0.756953f, 0.000000f },	{ -0.030000f, -0.350300f, -0.936200f }	},
	{	{ -0.005935f, -0.382821f, 0.003426f },	{ 0.721701f, 0.952997f, 0.000000f },	{ -0.030000f, -0.350300f, -0.936200f }	},
	{	{ -0.160565f, -0.002159f, 0.005139f },	{ 0.506701f, 0.758410f, 0.000000f },	{ -0.830500f, -0.335400f, -0.444700f }	},
	{	{ -0.084734f, -0.002159f, -0.136484f },	{ 0.615490f, 0.756953f, 0.000000f },	{ -0.830500f, -0.335400f, -0.444700f }	},
	{	{ -0.005935f, -0.382821f, 0.003426f },	{ 0.721701f, 0.952997f, 0.000000f },	{ -0.830500f, -0.335400f, -0.444700f }	},
	{	{ 0.075832f, -0.002159f, 0.141623f },	{ 0.159619f, 0.756953f, 0.000000f },	{ 0.000000f, -0.341300f, 0.940000f }	},
	{	{ -0.075832f, -0.002159f, 0.141623f },	{ 0.372042f, 0.756953f, 0.000000f },	{ 0.000000f, -0.341300f, 0.940000f }	},
	{	{ -0.005935f, -0.382821f, 0.003426f },	{ 0.265830f, 0.952997f, 0.000000f },	{ 0.000000f, -0.341300f, 0.940000f }	},
	{	{ -0.075832f, -0.002159f, 0.141623f },	{ 0.372042f, 0.756953f, 0.000000f },	{ -0.802500f, -0.328200f, 0.498200f }	},
	{	{ -0.160565f, -0.002159f, 0.005139f },	{ 0.490722f, 0.756953f, 0.000000f },	{ -0.802500f, -0.328200f, 0.498200f }	},
	{	{ -0.005935f, -0.382821f, 0.003426f },	{ 0.278299f, 0.952997f, 0.000000f },	{ -0.802500f, -0.328200f, 0.498200f }	},
	{	{ -0.005935f, 0.382821f, 0.003426f },	{ 0.265830f, 0.047003f, 0.000000f },	{ 0.000000f, 0.337900f, 0.941200f }	},
	{	{ -0.075832f, -0.002159f, 0.141623f },	{ 0.372042f, 0.756953f, 0.000000f },	{ 0.000000f, 0.337900f, 0.941200f }	},
	{	{ 0.075832f, -0.002159f, 0.141623f },	{ 0.159619f, 0.756953f, 0.000000f },	{ 0.000000f, 0.337900f, 0.941200f }	},
	{	{ -0.005935f, -0.382821f, 0.003426f },	{ 0.265830f, 0.952997f, 0.000000f },	{ 0.810500f, -0.352400f, -0.467900f }	},
	{	{ 0.075832f, -0.002159f, -0.141623f },	{ 0.840381f, 0.756953f, 0.000000f },	{ 0.810500f, -0.352400f, -0.467900f }	},
	{	{ 0.160565f, -0.002159f, 0.005139f },	{ 0.040939f, 0.756953f, 0.000000f },	{ 0.810500f, -0.352400f, -0.467900f }	},
	{	{ -0.005935f, 0.382821f, 0.003426f },	{ 0.721702f, 0.047003f, 0.000000f },	{ -0.030000f, 0.346800f, -0.937400f }	},
	{	{ 0.075832f, -0.002159f, -0.141623f },	{ 0.840381f, 0.756953f, 0.000000f },	{ -0.030000f, 0.346800f, -0.937400f }	},
	{	{ -0.084734f, -0.002159f, -0.136484f },	{ 0.615490f, 0.756953f, 0.000000f },	{ -0.030000f, 0.346800f, -0.937400f }	},
	{	{ -0.005935f, -0.382821f, 0.003426f },	{ 0.265830f, 0.952997f, 0.000000f },	{ 0.795800f, -0.350300f, 0.494000f }	},
	{	{ 0.160565f, -0.002159f, 0.005139f },	{ 0.040939f, 0.756953f, 0.000000f },	{ 0.795800f, -0.350300f, 0.494000f }	},
	{	{ 0.075832f, -0.002159f, 0.141623f },	{ 0.159619f, 0.756953f, 0.000000f },	{ 0.795800f, -0.350300f, 0.494000f }	},
	{	{ -0.005935f, 0.382821f, 0.003426f },	{ 0.278299f, 0.047003f, 0.000000f },	{ -0.831600f, 0.332000f, -0.445300f }	},
	{	{ -0.084734f, -0.002159f, -0.136484f },	{ 0.615490f, 0.756953f, 0.000000f },	{ -0.831600f, 0.332000f, -0.445300f }	},
	{	{ -0.160565f, -0.002159f, 0.005139f },	{ 0.500000f, 0.752226f, 0.000000f },	{ -0.831600f, 0.332000f, -0.445300f }	},
	{	{ -0.005935f, 0.382821f, 0.003426f },	{ 0.265830f, 0.047003f, 0.000000f },	{ -0.803500f, 0.324900f, 0.498800f }	},
	{	{ -0.160565f, -0.002159f, 0.005139f },	{ 0.490722f, 0.756953f, 0.000000f },	{ -0.803500f, 0.324900f, 0.498800f }	},
	{	{ -0.075832f, -0.002159f, 0.141623f },	{ 0.372042f, 0.756953f, 0.000000f },	{ -0.803500f, 0.324900f, 0.498800f }	},
	{	{ -0.005935f, 0.382821f, 0.003426f },	{ 0.270986f, 0.041177f, 0.000000f },	{ 0.811600f, 0.348900f, -0.468600f }	},
	{	{ 0.160565f, -0.002159f, 0.005139f },	{ 0.037098f, 0.752226f, 0.000000f },	{ 0.811600f, 0.348900f, -0.468600f }	},
	{	{ 0.075832f, -0.002159f, -0.141623f },	{ 0.840381f, 0.756953f, 0.000000f },	{ 0.811600f, 0.348900f, -0.468600f }	},
	{	{ 0.075832f, -0.002159f, 0.141623f },	{ 0.159619f, 0.756953f, 0.000000f },	{ 0.796800f, 0.346800f, 0.494700f }	},
	{	{ 0.160565f, -0.002159f, 0.005139f },	{ 0.040939f, 0.756953f, 0.000000f },	{ 0.796800f, 0.346800f, 0.494700f }	},
	{	{ -0.005935f, 0.382821f, 0.003426f },	{ 0.265830f, 0.047003f, 0.000000f },	{ 0.796800f, 0.346800f, 0.494700f }	},
};
#define _Crystal3_vertices_
#endif
#ifndef _Crystal3_indices_
// Index Data follows: Sequential by mesh, Every Three Indices == One Triangle.
const unsigned int Crystal3_indices[36] =
{
	 0, 1, 2,
	 3, 4, 5,
	 6, 7, 8,
	 9, 10, 11,
	 12, 13, 14,
	 15, 16, 17,
	 18, 19, 20,
	 21, 22, 23,
	 24, 25, 26,
	 27, 28, 29,
	 30, 31, 32,
	 33, 34, 35,
};
#define _Crystal3_indices_
#endif
// Part of an OBJ_MATERIAL, the struct is 16 byte aligned so it is GPU register friendly.
#ifndef __OBJ_ATTRIBUTES__
typedef struct _OBJ_ATTRIBUTES_
{
	OBJ_VEC3    Kd; // diffuse reflectivity
	float	    d; // dissolve (transparency) 
	OBJ_VEC3    Ks; // specular reflectivity
	float       Ns; // specular exponent
	OBJ_VEC3    Ka; // ambient reflectivity
	float       sharpness; // local reflection map sharpness
	OBJ_VEC3    Tf; // transmission filter
	float       Ni; // optical density (index of refraction)
	OBJ_VEC3    Ke; // emissive reflectivity
	unsigned    illum; // illumination model
}OBJ_ATTRIBUTES;
#define __OBJ_ATTRIBUTES__
#endif
// This structure also has been made GPU register friendly so it can be transfered directly if desired.
// Note: Total struct size will vary depenedening on CPU processor architecture (string pointers).
#ifndef __OBJ_MATERIAL__
typedef struct _OBJ_MATERIAL_
{
	// The following items are typically used in a pixel/fragment shader, they are packed for GPU registers.
	OBJ_ATTRIBUTES attrib; // Surface shading characteristics & illumination model
	// All items below this line are not needed on the GPU and are generally only used during load time.
	const char* name; // the name of this material
	// If the model's materials contain any specific texture data it will be located below.
	const char* map_Kd; // diffuse texture
	const char* map_Ks; // specular texture
	const char* map_Ka; // ambient texture
	const char* map_Ke; // emissive texture
	const char* map_Ns; // specular exponent texture
	const char* map_d; // transparency texture
	const char* disp; // roughness map (displacement)
	const char* decal; // decal texture (lerps texture & material colors)
	const char* bump; // normal/bumpmap texture
	void* padding[2]; // 16 byte alignment on 32bit or 64bit
}OBJ_MATERIAL;
#define __OBJ_MATERIAL__
#endif
#ifndef _Crystal3_materials_
// Material Data follows: pulled from a .mtl file of the same name if present.
const OBJ_MATERIAL Crystal3_materials[1] =
{
	{
		{{ 0.130034f, 0.640000f, 0.164621f },
		1.000000f,
		{ 0.500000f, 0.500000f, 0.500000f },
		96.078430f,
		{ 1.000000f, 1.000000f, 1.000000f },
		60.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		1.000000f,
		{ 0.000000f, 0.000000f, 0.000000f },
		2},
		"Green",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
	},
};
#define _Crystal3_materials_
#endif
/************************************************/
/*  This section contains the model's structure */
/************************************************/
#ifndef _Crystal3_batches_
// Use this conveinence array to batch render all geometry by like material.
// Each entry corresponds to the same entry in the materials array above.
// The two numbers provided are the IndexCount and the IndexOffset into the indices array.
// If you need more fine grained control(ex: for transformations) use the OBJ_MESH data below.
const unsigned int Crystal3_batches[1][2] =
{
	{ 36, 0 },
};
#define _Crystal3_batches_
#endif
#ifndef __OBJ_MESH__
typedef struct _OBJ_MESH_
{
	const char* name;
	unsigned    indexCount;
	unsigned    indexOffset;
	unsigned    materialIndex;
}OBJ_MESH;
#define __OBJ_MESH__
#endif
#ifndef _Crystal3_meshes_
// Mesh Data follows: Meshes are .obj groups sorted & split by material.
// Meshes are provided in sequential order, sorted by material first and name second.
const OBJ_MESH Crystal3_meshes[1] =
{
	{
		"default",
		36,
		0,
		0,
	},
};
#define _Crystal3_meshes_
#endif
