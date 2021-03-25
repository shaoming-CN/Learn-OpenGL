#version 330 core
									
in vec4 vertexColor;
in vec2 TexCoords;

uniform sampler2D screenTexture;
out vec4 FragColor;								   
void main()
{             
    FragColor = texture(screenTexture, TexCoords);
}