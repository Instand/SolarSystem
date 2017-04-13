#version 330 core

in vec3 vertexPosition;
in vec3 vertexNormal;
in vec2 vertexTexCoord;
in vec4 vertexTangent;

out vec3 lightDir;
out vec3 viewDir;
out vec2 texCoord;

uniform mat4 viewMatrix;
uniform mat4 modelMatrix;
uniform mat4 modelView;
uniform mat3 modelViewNormal;
uniform mat4 mvp;
uniform float texCoordScale;
uniform vec3 lightPosition;

void main()
{
    texCoord = vertexTexCoord * texCoordScale;

    vec3 normal = normalize(modelViewNormal * vertexNormal);
    vec3 tangent = normalize(modelViewNormal * vertexTangent.xyz);
    vec3 position = vec3(modelView * vec4(vertexPosition, 1.0));
    vec3 binormal = normalize(cross(normal, tangent));

    mat3 tangentMatrix = mat3 (
        tangent.x, binormal.x, normal.x,
        tangent.y, binormal.y, normal.y,
        tangent.z, binormal.z, normal.z);

    vec3 s = lightPosition - position;
    lightDir = normalize(tangentMatrix * vec3(viewMatrix * vec4(s, 1.0)));

    vec3 v = -position;
    viewDir = normalize(tangentMatrix * v);


    gl_Position = mvp * vec4(vertexPosition, 1.0);
}
