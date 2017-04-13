#version 150 core

uniform sampler2D diffuseTexture;

in vec3 position;
in vec2 texCoord;

out vec4 fragColor;

vec4 dModel(const in vec2 flipYTexCoord)
{
    vec3 diffuseColor = texture2D(diffuseTexture, flipYTexCoord).rgb;
    return vec4(diffuseColor, 1.0);
}

void main()
{
    vec2 flipYTexCoord = texCoord;
    flipYTexCoord.x = 1.0 - texCoord.x;

    vec4 result = dModel(flipYTexCoord);

    fragColor = result;
}
