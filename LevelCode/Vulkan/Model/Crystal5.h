// "Crystal5.h" generated by "Obj2Header.exe" [Version 1.9d] Author: L.Norri Fullsail University.
// Data is converted to left-handed coordinate system and UV data is V flipped for Direct3D/Vulkan.
// The companion file "Crystal5.h2b" is a binary dump of this format(-padding) for more flexibility.
// Loading *.h2b: read version, sizes, handle strings(max len 260) by reading until null-terminated.
/***********************/
/*  Generator version  */
/***********************/
#ifndef _Crystal5_version_
const char Crystal5_version[4] = { '0','1','9','d' };
#define _Crystal5_version_
#endif
/************************************************/
/*  This section contains the model's size data */
/************************************************/
#ifndef _Crystal5_vertexcount_
const unsigned Crystal5_vertexcount = 48;
#define _Crystal5_vertexcount_
#endif
#ifndef _Crystal5_indexcount_
const unsigned Crystal5_indexcount = 66;
#define _Crystal5_indexcount_
#endif
#ifndef _Crystal5_materialcount_
const unsigned Crystal5_materialcount = 1; // can be used for batched draws
#define _Crystal5_materialcount_
#endif
#ifndef _Crystal5_meshcount_
const unsigned Crystal5_meshcount = 1;
#define _Crystal5_meshcount_
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
#ifndef _Crystal5_vertices_
// Raw Vertex Data follows: Positions, Texture Coordinates and Normals.
const OBJ_VERT Crystal5_vertices[48] =
{
	{	{ 0.314580f, 0.089639f, -0.019717f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.753200f, 0.522800f, 0.399200f }	},
	{	{ 0.218609f, 0.213887f, -0.013702f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.753200f, 0.522800f, 0.399200f }	},
	{	{ 0.121171f, 0.213887f, 0.182470f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.753200f, 0.522800f, 0.399200f }	},
	{	{ 0.174366f, 0.066643f, 0.262576f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.753200f, 0.522800f, 0.399200f }	},
	{	{ 0.140215f, 0.081200f, -0.282293f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.694300f, 0.543900f, -0.471300f }	},
	{	{ 0.097439f, 0.213887f, -0.196172f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.694300f, 0.543900f, -0.471300f }	},
	{	{ 0.218609f, 0.213887f, -0.013702f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.694300f, 0.543900f, -0.471300f }	},
	{	{ 0.314580f, 0.089639f, -0.019717f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.694300f, 0.543900f, -0.471300f }	},
	{	{ -0.174366f, 0.066699f, -0.262576f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.067600f, 0.511300f, -0.856700f }	},
	{	{ -0.121171f, 0.213887f, -0.182470f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.067600f, 0.511300f, -0.856700f }	},
	{	{ 0.097439f, 0.213887f, -0.196172f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.067600f, 0.511300f, -0.856700f }	},
	{	{ 0.140215f, 0.081200f, -0.282293f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.067600f, 0.511300f, -0.856700f }	},
	{	{ -0.314580f, 0.081200f, 0.019717f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.763400f, 0.511300f, -0.394700f }	},
	{	{ -0.218609f, 0.213887f, 0.013702f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.763400f, 0.511300f, -0.394700f }	},
	{	{ -0.121171f, 0.213887f, -0.182470f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.763400f, 0.511300f, -0.394700f }	},
	{	{ -0.174366f, 0.066699f, -0.262576f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.763400f, 0.511300f, -0.394700f }	},
	{	{ 0.097439f, 0.213887f, -0.196172f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.121171f, 0.213887f, -0.182470f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.218609f, 0.213887f, 0.013702f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.218609f, 0.213887f, -0.013702f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.121171f, 0.213887f, 0.182470f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.097439f, 0.213887f, 0.196172f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.140215f, 0.081200f, 0.282293f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.705600f, 0.531600f, 0.468600f }	},
	{	{ -0.097439f, 0.213887f, 0.196172f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.705600f, 0.531600f, 0.468600f }	},
	{	{ -0.218609f, 0.213887f, 0.013702f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.705600f, 0.531600f, 0.468600f }	},
	{	{ -0.314580f, 0.081200f, 0.019717f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.705600f, 0.531600f, 0.468600f }	},
	{	{ 0.174366f, 0.066643f, 0.262576f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.067700f, 0.511300f, 0.856800f }	},
	{	{ 0.121171f, 0.213887f, 0.182470f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.067700f, 0.511300f, 0.856800f }	},
	{	{ -0.097439f, 0.213887f, 0.196172f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.067700f, 0.511300f, 0.856800f }	},
	{	{ -0.140215f, 0.081200f, 0.282293f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.067700f, 0.511300f, 0.856800f }	},
	{	{ 0.314580f, 0.089639f, -0.019717f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.628200f, -0.670000f, -0.395600f }	},
	{	{ -0.000000f, -0.216945f, 0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.628200f, -0.670000f, -0.395600f }	},
	{	{ 0.140215f, 0.081200f, -0.282293f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.628200f, -0.670000f, -0.395600f }	},
	{	{ -0.314580f, 0.081200f, 0.019717f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.614400f, -0.675300f, 0.408000f }	},
	{	{ -0.000000f, -0.216945f, 0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.614400f, -0.675300f, 0.408000f }	},
	{	{ -0.140215f, 0.081200f, 0.282293f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.614400f, -0.675300f, 0.408000f }	},
	{	{ 0.174366f, 0.066643f, 0.262576f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.678700f, -0.678200f, 0.281800f }	},
	{	{ -0.000000f, -0.216945f, 0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.678700f, -0.678200f, 0.281800f }	},
	{	{ 0.314580f, 0.089639f, -0.019717f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.678700f, -0.678200f, 0.281800f }	},
	{	{ 0.140215f, 0.081200f, -0.282293f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.014200f, -0.683900f, -0.729400f }	},
	{	{ -0.000000f, -0.216945f, 0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.014200f, -0.683900f, -0.729400f }	},
	{	{ -0.174366f, 0.066699f, -0.262576f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.014200f, -0.683900f, -0.729400f }	},
	{	{ -0.140215f, 0.081200f, 0.282293f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.014100f, -0.684000f, 0.729400f }	},
	{	{ -0.000000f, -0.216945f, 0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.014100f, -0.684000f, 0.729400f }	},
	{	{ 0.174366f, 0.066643f, 0.262576f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.014100f, -0.684000f, 0.729400f }	},
	{	{ -0.174366f, 0.066699f, -0.262576f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.666800f, -0.683900f, -0.296000f }	},
	{	{ -0.000000f, -0.216945f, 0.000000f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.666800f, -0.683900f, -0.296000f }	},
	{	{ -0.314580f, 0.081200f, 0.019717f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.666800f, -0.683900f, -0.296000f }	},
};
#define _Crystal5_vertices_
#endif
#ifndef _Crystal5_indices_
// Index Data follows: Sequential by mesh, Every Three Indices == One Triangle.
const unsigned int Crystal5_indices[66] =
{
	 0, 1, 2,
	 3, 0, 2,
	 4, 5, 6,
	 7, 4, 6,
	 8, 9, 10,
	 11, 8, 10,
	 12, 13, 14,
	 15, 12, 14,
	 16, 17, 18,
	 19, 16, 18,
	 20, 19, 18,
	 21, 20, 18,
	 22, 23, 24,
	 25, 22, 24,
	 26, 27, 28,
	 29, 26, 28,
	 30, 31, 32,
	 33, 34, 35,
	 36, 37, 38,
	 39, 40, 41,
	 42, 43, 44,
	 45, 46, 47,
};
#define _Crystal5_indices_
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
#ifndef _Crystal5_materials_
// Material Data follows: pulled from a .mtl file of the same name if present.
const OBJ_MATERIAL Crystal5_materials[1] =
{
	{
		{{ 0.122841f, 0.640000f, 0.453373f },
		1.000000f,
		{ 0.500000f, 0.500000f, 0.500000f },
		96.078430f,
		{ 1.000000f, 1.000000f, 1.000000f },
		60.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		1.000000f,
		{ 0.000000f, 0.000000f, 0.000000f },
		2},
		"Cyan",
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
#define _Crystal5_materials_
#endif
/************************************************/
/*  This section contains the model's structure */
/************************************************/
#ifndef _Crystal5_batches_
// Use this conveinence array to batch render all geometry by like material.
// Each entry corresponds to the same entry in the materials array above.
// The two numbers provided are the IndexCount and the IndexOffset into the indices array.
// If you need more fine grained control(ex: for transformations) use the OBJ_MESH data below.
const unsigned int Crystal5_batches[1][2] =
{
	{ 66, 0 },
};
#define _Crystal5_batches_
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
#ifndef _Crystal5_meshes_
// Mesh Data follows: Meshes are .obj groups sorted & split by material.
// Meshes are provided in sequential order, sorted by material first and name second.
const OBJ_MESH Crystal5_meshes[1] =
{
	{
		"default",
		66,
		0,
		0,
	},
};
#define _Crystal5_meshes_
#endif
