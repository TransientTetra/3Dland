#version 130

out vec4 outColor;

uniform sampler2D diffuse;

varying vec2 texCoord0;

void main(void)
{
	outColor = texture2D(diffuse, texCoord0);
}