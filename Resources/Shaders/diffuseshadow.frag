#version 330 core

uniform mat4 viewMatrix;

uniform vec3 lightPosition;
uniform vec3 lightIntensity;

//material data
uniform vec3 ambient;
uniform vec3 specular;
uniform float shininess;
uniform float opacity;

uniform sampler2D diffuseTexture;
uniform sampler2DShadow shadowMapTexture;

in vec4 positionInLightSpace;

in vec3 position;
in vec3 normal;
in vec2 texCoord;

out vec4 fragColor;

vec3 dModel(const in vec2 flipYTexCoord)
{
    vec3 s = normalize(vec3(viewMatrix * vec4(lightPosition, 1.0)) - position);
    vec3 v = normalize(-position);
    vec3 r = reflect(-s, normal);
    float diffuse = max(dot(s, normal), 0.0);
    float specularValue = 0.0;

    if (dot(s, normal) > 0.0)
        specularValue = (shininess / (8.0 * 3.14)) * pow(max(dot(r, v), 0.0), shininess);

    vec3 diffuseColor = texture2D(diffuseTexture, flipYTexCoord).rgb;

    return lightIntensity * ((ambient + diffuse) * diffuseColor + specularValue * specular);
}

void main()
{
    vec2 flipYTexCoord = texCoord;
    flipYTexCoord.y = 1.0 - texCoord.y;

    float shadowMapSample = textureProj(shadowMapTexture, positionInLightSpace);

    vec3 result = lightIntensity * ambient * texture2D(diffuseTexture, flipYTexCoord).rgb;
    if (shadowMapSample > 0)
        result += dModel(flipYTexCoord);

    float alpha = opacity * texture2D(diffuseTexture, flipYTexCoord).a;

    fragColor = vec4(result, alpha);
}
