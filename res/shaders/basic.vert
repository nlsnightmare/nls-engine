#version 330 core
layout(location = 0) in vec2 pos;
layout(location = 1) in vec2 texCoord;


out vec4 Color;
out vec2 TextCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main(){
    gl_Position = projection * view * model * vec4(pos, 0.0f, 1.0f);
    // gl_Position = vec4(pos, 0.0f, 1.0f);

    TextCoord = texCoord;
}
