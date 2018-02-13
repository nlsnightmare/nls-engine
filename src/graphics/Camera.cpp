#include "Camera.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace graphics;

Camera* Camera::main = nullptr;

Camera::Camera(float height, float width, CameraMode m){
    if (m == CameraMode::ORTHOGRAPHIC)
	m_projection_matrix = glm::ortho(0.0f, width, 0.0f, height, near_plane, far_plane);
    else if(m == CameraMode::PERSPECTIVE)
	m_projection_matrix = glm::perspective(glm::radians(45.0f), width/height, near_plane, far_plane);

    m_view_matrix = glm::translate(m_view_matrix, glm::vec3(0.5f, 0.5f,-1.0f));
}

void Camera::make_main(){
    Camera::main = this;
}

void Camera::set_position(float x, float y, float z){
    this->set_position(glm::vec3(x,y,z));
}
void Camera::set_position(const glm::vec3& v){
    m_view_matrix = glm::translate(glm::mat4(), v);
}

void Camera::translate(float x, float y, float z){
    this->translate(glm::vec3(x,y,z));
}
void Camera::translate(const glm::vec3& v){
    m_view_matrix = glm::translate(m_view_matrix, v);
}
