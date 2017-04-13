#version 330 core

//light
uniform vec3 lightPosition;
uniform vec3 lightIntensity;

//material color data
uniform vec3 ambient;
uniform vec3 specular;
uniform float shininess;
uniform float opacity;

//textures
uniform sampler2D diffuseTexture;
uniform sampler2D normalTexture;

in vec3 lightDir;
in vec3 viewDir;
in vec2 texCoord;

out vec4 fragColor;

void dbModel(const in vec3 norm, const in vec2 flipYTexCoord, out vec3 ambientAndDiff, out vec3 spec)
{
    vec3 r = reflect(-lightDir, norm);
    vec3 diffuseColor = texture2D(diffuseTexture, flipYTexCoord).rgb;
    vec3 kAmbient = lightIntensity * ambient * diffuseColor;
    float sDotN = max(dot(lightDir, norm), 0.0);
    vec3 diffuse = lightIntensity * diffuseColor * sDotN;

    ambientAndDiff = kAmbient + diffuse;

    spec = vec3(0.0);

    if (sDotN > 0.0)
        spec = (lightIntensity * specular) * pow(max(dot(r, viewDir), 0.0), shininess);
}

void main()
{
    vec2 flipYTexCoord = texCoord;
    flipYTexCoord.x = 1.0 - texCoord.x;

    vec4 normal = 2.0 * texture2D(normalTexture, flipYTexCoord) - vec4(1.0);

    vec3 result = lightIntensity * ambient * texture2D(diffuseTexture, flipYTexCoord).rgb;

    vec3 ambientAndDiff, spec;
    dbModel(normalize(normal.xyz), flipYTexCoord, ambientAndDiff, spec);
    result = ambientAndDiff + spec;

    fragColor = vec4(result, opacity);
}
