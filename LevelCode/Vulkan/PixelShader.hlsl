#define MAX_SUBMESH_PER_DRAW 1024

struct OBJ_ATTRIBUTES
{
    float3 Kd; // diffuse reflectivity
    float d; // dissolve (transparency) 
    float3 Ks; // specular reflectivity
    float Ns; // specular exponent
    float3 Ka; // ambient reflectivity
    float sharpness; // local reflection map sharpness
    float3 Tf; // transmission filter
    float Ni; // optical density (index of refraction)
    float3 Ke; // emissive reflectivity
    uint illum; // illumination model
};

struct OBJ_VERT
{
    float3 pos : SV_POSITION;
    float3 uvw : DEPTH;
    float3 nrm : NORMAL;
};

struct SHADER_MODEL_DATA
{
	//globally shared model data
    float4 sundirection, sunColor; //lighting info
    float4 camEye, sunAmbient;
    float4x4 viewMatrix, projectionMatrix; //viewing info
	//per sub-mesh transform and material data
    float4x4 matricies[MAX_SUBMESH_PER_DRAW];
    OBJ_ATTRIBUTES materials[MAX_SUBMESH_PER_DRAW];
};

struct OBJ_VERT_OUT
{
    float4 pos : SV_POSITION;
    float3 uvw : DEPTH;
    float3 nrm : NORMAL;
    float4 worldPos : WORLDPOSITION;
};

StructuredBuffer<SHADER_MODEL_DATA> SceneData;

[[vk::push_constant]]
cbuffer MESH_INDEX
{
    uint MESH_ID;
    uint MATERIAL_ID;
};

// TODO: Part 2b
// TODO: Part 4g
// TODO: Part 2i
// TODO: Part 3e
// an ultra simple hlsl pixel shader
// TODO: Part 4b
float4 main(OBJ_VERT_OUT inputVertex) : SV_TARGET
{
    inputVertex.nrm = normalize(inputVertex.nrm);
    float3 sundirectionCopy = -normalize(SceneData[0].sundirection.xyz);
    float LightRatio = saturate(dot(sundirectionCopy, inputVertex.nrm));
	//LightRatio = saturate(LightRatio + SceneData[0].sunAmbient);
    float4 colorset = float4(SceneData[MATERIAL_ID].materials[MESH_ID].Kd, 1);
    float4 ambientResult = SceneData[0].sunAmbient * colorset;
    float4 LightDirectResult = LightRatio * SceneData[0].sunColor * colorset;
	//LightDirectResult = LightDirectResult * SceneData[0].sunColor;
    float4 DiffuseResult = LightDirectResult;


    float3 VIEWDIR = normalize(SceneData[0].camEye.xyz - inputVertex.worldPos.xyz);
    float3 HALFVECTOR = normalize(sundirectionCopy + VIEWDIR);
    float INTENSITY = pow(saturate(dot(inputVertex.nrm.xyz, HALFVECTOR)), SceneData[MATERIAL_ID].materials[MESH_ID].Ns);
    float4 REFLECTEDLIGHT = SceneData[0].sunColor * float4(SceneData[MATERIAL_ID].materials[MESH_ID].Ks, 0) * INTENSITY;
	

    return saturate(REFLECTEDLIGHT + DiffuseResult + ambientResult);
	// TODO: Part 1a
	// TODO: Part 3a
	// TODO: Part 4c
	// TODO: Part 4g (half-vector or reflect method your choice)
}