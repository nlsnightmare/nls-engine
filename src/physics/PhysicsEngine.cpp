#include "PhysicsEngine.hpp"
#include "../Math.hpp"
#include <iostream>

using namespace physics;
std::vector<BoxCollider2D*> PhysicsEngine::cols;

PhysicsEngine::PhysicsEngine(){
    //TODO
}

void PhysicsEngine::register_collider(physics::BoxCollider2D *col){
    cols.push_back(col);
}

void PhysicsEngine::remove_collider(physics::BoxCollider2D *col){
    for (auto i = 0; i < cols.size(); ++i) {
	if (cols[i] == col) {
	    cols.erase(cols.begin() + i);
	    break;
	}
    }

    delete col;

}


void PhysicsEngine::tick(float dt){
    for (int i = 0; i < cols.size(); ++i) {
	for (int j = i + 1; j < cols.size(); ++j) {
	    CollisionData col_data = cols[i]->does_collide(*cols[j]);
	    if (!col_data.has_collided)
		continue;

	    auto o1 = cols[i]->parent;
	    auto o2 = cols[j]->parent;
	    if (col_data.is_trigger) {
		std::cout << "collision\n";
		event_trigger(o1,o2,col_data.x,col_data.y);
		event_trigger(o2,o1,-col_data.x,-col_data.y);
	    }
	    else {
		event_collision(o1,o2,col_data.x,col_data.y);
		event_collision(o2,o1,-col_data.x,-col_data.y);

		handle_collision(o1,o2,col_data);
	    }
	}
    }
}
void PhysicsEngine::handle_collision(GameObject* a, GameObject* b, CollisionData& data){
    // step 1: which object should move?
    GameObject* target;
    if (a->get_mass() < b->get_mass() )
	target = a;
    else 
    {
	target = b;
	data.x = -data.x;
	data.y = -data.y;
    }
    
    if (std::abs(data.x) > std::abs(data.y)) {
	float dx =  ( math::sign(data.x) - data.x ) /2;
	GameObject_translate(target, dx, 0, 0);
    }
    else {
	float dy = ( math::sign(data.y) - data.y ) /2;
	GameObject_translate(target, 0, dy, 0);
    }
}

void PhysicsEngine::set_collision(event_type fun){
    event_collision = fun;
}
void PhysicsEngine::set_trigger(event_type fun){
    event_trigger = fun;
}


