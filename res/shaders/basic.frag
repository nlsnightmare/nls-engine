#version 330 core
in vec4 Color;
in vec2 TextCoord;

out vec4 finalColor;

uniform sampler2D image;

void main(){
    finalColor = texture(image, TextCoord);
    // finalColor = vec4(0.0f, 1.0f, 1.0f, 1.0f);
}
