#include "Sprite.hpp"
#include "SpriteRenderer.hpp"

#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include "Camera.hpp"

using namespace graphics;

Sprite::Sprite(Texture* t, Shader* s)
    : m_texture(t), m_shader(s)
{
    vertData d[4];
    d[0] = vertData( 0.5f,  0.5f, 1.0f, 1.0f);
    d[1] = vertData(-0.5f,  0.5f, 0.0f, 1.0f);
    d[2] = vertData(-0.5f, -0.5f, 0.0f, 0.0f);
    d[3] = vertData( 0.5f, -0.5f, 1.0f, 0.0f);
    unsigned int indicies[] = {
    	0, 1, 2,
    	0, 2, 3
    };

    m_vao = new VertexArray(d, 4, indicies, 2 * 3);

    m_shader->Bind();
    m_shader->setTexture("image", *t);
    set_position(1,0,0);

    SpriteRenderer::register_sprite(this);
}

Sprite::~Sprite(){

    delete m_vao;
}


void Sprite::Draw() const {
    m_vao->Bind();
    m_shader->Bind();
    m_shader->set_model(get_model_matrix());
    m_shader->set_projection(Camera::main->get_projection_matrix());
    m_shader->set_view(Camera::main->get_view_matrix());
    
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Sprite::set_texture(Texture t){
    m_texture = &t;
}

void Sprite::set_shader(Shader shader){
    m_shader = &shader;
}

glm::vec3 Sprite::get_position() const{
    return m_position;
}

void Sprite::set_position(float x, float y, float z){
    this->set_position(glm::vec3(x,y,z));
}
void Sprite::set_position(const glm::vec3& v){
    m_position = v;
    m_position_matrix = glm::translate(glm::mat4(), v);
    calculate_model_matrix();
}

void Sprite::translate(float x, float y, float z){
    this->translate(glm::vec3(x,y,z));
}
void Sprite::translate(const glm::vec3& v){
    m_position += v;
    m_position_matrix = glm::translate(glm::mat4(), m_position);
    calculate_model_matrix();
}

void Sprite::scale(float x, float y, float z){
    this->scale(glm::vec3(x,y,z));
}
void Sprite::scale(const glm::vec3& v){
    m_scale_matrix = glm::scale(glm::mat4(), v);
    calculate_model_matrix();
}
    

void Sprite::rotate(float degrees){
    m_rotation_matrix = glm::rotate(glm::mat4(), glm::radians(degrees), glm::vec3(0,0,1));
    calculate_model_matrix();
}

void Sprite::calculate_model_matrix(){
    m_model_matrix = m_position_matrix * m_rotation_matrix * m_scale_matrix ;//* m_rotation_matrix;
}

glm::mat4 Sprite::get_model_matrix() const{
    return m_model_matrix;
}

