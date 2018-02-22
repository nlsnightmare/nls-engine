#include <GL/glew.h>
#include <iostream>
#include <boost/filesystem.hpp>
#include "stb_image.h"
#include "Texture.hpp"

using namespace graphics;

std::unordered_map<std::string, Texture*> Texture::textures_n;
std::unordered_map<int, Texture*> Texture::textures_i;

Texture::Texture(std::string filename, bool has_alpha){
    int width, height, nrChanells;
    m_data = stbi_load(filename.c_str(), &width, &height, &nrChanells, 0);

    if (m_data == NULL) {
	std::cout << "invalid texture path! " << filename << std::endl;
    }


    glGenTextures(1, &m_id);
    glBindTexture(GL_TEXTURE_2D, m_id);

    if (nrChanells == 4)
    {
	std::cout << filename << " has alpha!" << std::endl;
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_data);
    }
    else
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, m_data);

    glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void Texture::Bind(int num) const {
   switch (num) {
   case 0: 
       glActiveTexture(GL_TEXTURE0);
       break;
   case 1: 
       glActiveTexture(GL_TEXTURE1);
       break;
   case 2: 
       glActiveTexture(GL_TEXTURE2);
       break;
   case 3: 
       glActiveTexture(GL_TEXTURE3);
       break;
   case 4: 
       glActiveTexture(GL_TEXTURE4);
       break;
   case 5: 
       glActiveTexture(GL_TEXTURE5);
       break;
default:
       break;
   }
   glBindTexture(GL_TEXTURE_2D,m_id);
}

void Texture::load_textures(std::string path){
    for ( auto& p : boost::filesystem::directory_iterator(path)){
	std::string file = p.path().string();
	Texture* t = new Texture(file);
	std::string name = file.substr(file.find_last_of("/") + 1);
	Texture::textures_n.insert(std::make_pair(name, t));
	Texture::textures_i.insert(std::make_pair(t->ID(), t));
    }
}

Texture* Texture::get(int id){
    auto s = Texture::textures_i.find(id);

    if (s == Texture::textures_i.end()) {
	std::cout << "couldn't find texture [" << id << "]" << std::endl;
	return nullptr;
    }
    else {
	return s->second;
    }
}

Texture* Texture::get(std::string name){
    auto s = Texture::textures_n.find(name);

    if (s == Texture::textures_n.end()) {
	std::cout << "couldn't find texture [" << name << "]" << std::endl;
	return nullptr;
    }
    else {
	return s->second;
    }
}
void Texture::delete_textures(){
    for( auto kv : Texture::textures_n ){
	delete kv.second;
    }
}
