#pragma once
#include <glm/glm.hpp>

namespace graphics {
    
    class Camera
    {
    public:
	static Camera* main;

	enum class CameraMode {
	    ORTHOGRAPHIC, PERSPECTIVE
	};

	Camera(float width, float height, CameraMode m);
	void make_main();

	inline glm::mat4 get_projection_matrix() const { return m_projection_matrix; };
	inline glm::mat4 get_view_matrix() const { return m_view_matrix; };

	void set_position(float x, float y, float z);
	void set_position(const glm::vec3& v);

	void translate(float x, float y, float z);
	void translate(const glm::vec3& v);

    private:
	const float far_plane = 100.0f;
	const float near_plane = 0.1f;
	glm::mat4 m_projection_matrix;
	glm::mat4 m_view_matrix;
    };
}
