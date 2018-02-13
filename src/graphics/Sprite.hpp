#pragma once
#include <glm/glm.hpp>
#include "low_level/Shader.hpp"
#include "low_level/VertexArray.hpp"
#include "low_level/Texture.hpp"

namespace graphics {
    
    class Sprite
    {
    public:
	Sprite(Texture* t, Shader* s = Shader::get("basic"));
	Sprite(std::string textureName);
	virtual ~Sprite();

	void Draw() const;

	void set_shader(Shader shader);
	inline Shader& get_shader() const { return *m_shader; };

	void set_texture(Texture t);
	inline Texture& get_texture() const { return *m_texture; };

	void set_position(float x, float y, float z);
	void set_position(const glm::vec3& v);

	void translate(float x, float y, float z);
	void translate(const glm::vec3& v);


	void scale(float x, float y, float z);
	void scale(const glm::vec3& v);


	void rotate(float degrees);
	glm::mat4 get_model_matrix() const;


    private:
	glm::mat4 m_model_matrix;
	void calculate_model_matrix();

	glm::mat4 m_position_matrix;
	glm::mat4 m_scale_matrix;
	glm::mat4 m_rotation_matrix;
	glm::vec3 m_position;
	glm::vec3 m_scale;
	float m_rotation;
	
	Texture* m_texture;
	Shader* m_shader;

	VertexArray* m_vao;
    };

}
