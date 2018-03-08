#pragma once
#include <vector>
#include <functional>

#include "BoxCollider2D.hpp"
#include "../game/GameObject.hpp"

namespace physics {

    typedef std::function<void(GameObject*, GameObject*, float, float)> event_type;
    
    class PhysicsEngine
    {
    public:
	PhysicsEngine();


	void tick(float dt);
	static void register_collider(BoxCollider2D* col);
	static void remove_collider(BoxCollider2D* col);
	void set_trigger(event_type fun);
	void set_collision(event_type fun);

	void handle_collision(GameObject* a, GameObject* b, CollisionData& data);
    private:
	event_type event_trigger;
	event_type event_collision;
	static std::vector<BoxCollider2D*> cols;
    };


}
