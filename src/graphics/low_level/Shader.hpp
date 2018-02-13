#pragma once
#include <string>
#include <vector>
#include <map>
#include <glm/glm.hpp>
#include "Texture.hpp"

namespace graphics {
    
class Shader
{
public:
    Shader(std::string name);
    // ~Shader();


    void Bind() const;
    void Unbind() const;
    void setFloat( const std::string& name, float value) const;
    void setInt( const std::string& name, int value) const;
    void setBool( const std::string& name, bool value) const;
    void setTexture( const std::string& name, const Texture& t);
    void set_model( const glm::mat4& position ) const;
    void set_view( const glm::mat4& view ) const;
    void set_projection( const glm::mat4& projection ) const;

    inline unsigned int ID() const { return m_id; };

    static bool load_shaders(std::string path);
    static void delete_shaders();

    static Shader* get(std::string name);


private:
    static unsigned int link(int vShader, int fShader);
    static unsigned int compile(const std::string& filename, int mode);
    unsigned int m_id;
    unsigned int load;

    std::vector<Texture> m_textures;
    static std::map<std::string, Shader*> shaders;

    // Uniform locations
    void cache_uniforms();
    int m_model_location;
    int m_view_location;
    int m_projection_location;


};

}
