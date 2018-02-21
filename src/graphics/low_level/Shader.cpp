#include <glm/gtc/type_ptr.hpp>
#include <math.h>
#include <fstream>
#include <string>
#include <boost/filesystem.hpp>
#include <GL/glew.h>

// TODO: replace iostream with a logging system
#include <iostream>
#include "Shader.hpp"

using namespace graphics;
std::map<std::string, Shader*> Shader::shaders;

static std::string readfile(const std::string &filepath){

    std::string buffer,line;
    std::ifstream vs_stream(filepath.c_str());
    while (!vs_stream.eof()) {
	getline(vs_stream, line);
	buffer += line + '\n';
    }

    return buffer;
}

Shader::Shader(std::string name){
    unsigned int vShader;
    vShader = Shader::compile(name + ".vert", GL_VERTEX_SHADER);

    unsigned int fShader;
    fShader = Shader::compile(name + ".frag", GL_FRAGMENT_SHADER);

    unsigned int shader = Shader::link(vShader, fShader);
    glDeleteShader(vShader);
    glDeleteShader(fShader);

    m_id = shader;

    cache_uniforms();


}
unsigned int Shader::link(int vShader, int fShader){
    unsigned int shader;
    shader = glCreateProgram();
    glAttachShader(shader,vShader);
    glAttachShader(shader,fShader);
    glLinkProgram(shader);
    int  success;
    char infoLog[512];
    glGetProgramiv(shader, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shader, 512, NULL, infoLog);
        std::cout << "Error! Failed to link shader!" << std::endl;
	std::cout << infoLog  << std::endl;

    }

    return shader;
}
unsigned int Shader::compile(const std::string& filename, int mode){
    unsigned int shaderID;
    shaderID = glCreateShader(mode);

    std::string shaderIDSrc;

    shaderIDSrc = readfile(filename);
    const char* c_str = shaderIDSrc.c_str();

    glShaderSource(shaderID, 1, &c_str, NULL);
    glCompileShader(shaderID);
    int  success;
    char infoLog[512];
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
    if (!success) {
	glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
	std::cout << "Error! Failed to compile " << filename << std::endl;
	std::cout << infoLog << std::endl;
    }

    return shaderID;
}

void Shader::Bind() const {
    glUseProgram(m_id);
}

void Shader::Unbind() const {
    glUseProgram(0);
}

void Shader::setFloat( const std::string& name, float value) const{
    int loc = glGetUniformLocation(m_id, name.c_str());
    glUniform1f(loc, value);
}
void Shader::setInt( const std::string& name, int value) const{
    int loc = glGetUniformLocation(m_id, name.c_str());
    glUniform1i(loc, value);
}
void Shader::setBool( const std::string& name, bool value) const{
    int loc = glGetUniformLocation(m_id, name.c_str());
    glUniform1i(loc, value);
}

void Shader::setTexture(const std::string& name, const Texture& t){
    int i = m_textures.size();
    m_textures.push_back(t);
    setInt(name,i);
    t.Bind(i);
}


void Shader::set_model(const glm::mat4 &position) const {
    Bind();
    glUniformMatrix4fv(m_model_location, 1, GL_FALSE, glm::value_ptr(position));
}
void Shader::set_view( const glm::mat4& view ) const{
    Bind();
    glUniformMatrix4fv(m_view_location, 1, GL_FALSE, glm::value_ptr(view));
}
void Shader::set_projection( const glm::mat4& projection ) const{
    Bind();
    glUniformMatrix4fv(m_projection_location, 1, GL_FALSE, glm::value_ptr(projection));
}

void Shader::cache_uniforms(){
    this->Bind();
    m_model_location = glGetUniformLocation(m_id, "model");
    m_view_location = glGetUniformLocation(m_id, "view");
    m_projection_location = glGetUniformLocation(m_id, "projection");
    this->Unbind();
}



Shader* Shader::get(std::string name){
    auto s =Shader::shaders.find(name);

    if (s == Shader::shaders.end()) {
	std::cout << "couldn't find shader [" << name << "]" << std::endl;
	return nullptr;
    }
    else {
	return s->second;
    }
}

//TODO: comment this mess
bool Shader::load_shaders(std::string path){
    for ( auto& p : boost::filesystem::directory_iterator(path)){
	std::string file = p.path().string();
	auto pos = file.find(".frag");
	if (pos != std::string::npos){
	    file = file.substr(0, pos);
	    Shader* s = new Shader(file);
	    std::string name = file.substr(file.find_last_of("/") + 1);
	    Shader::shaders.insert(std::make_pair(name, s));
	}
    }
    return true;
}

void Shader::delete_shaders(){
    for (auto kv : Shader::shaders) {
	delete kv.second;
    }

}
