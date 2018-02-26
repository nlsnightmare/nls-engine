#include "BoxCollider2D.hpp"
#include <iostream>

using namespace physics;


BoxCollider2D::BoxCollider2D(float x, float y, float w, float h, GameObject* parent){
    this->x = x;
    this->y = x;
    this->w = w;
    this->h = h;
    this->x2 = x + w;
    this->y2 = y + h;
    this->parent = parent;
}

CollisionData BoxCollider2D::does_collide(physics::BoxCollider2D& other) const{
    CollisionData data;
    //TODO: fix it for different scales
    bool cols_x = ( this->x < other.x2 ) && ( x2 > other.x );
    bool cols_y = ( this->y < other.y2 ) && ( y2 > other.y );

    data.has_collided = cols_x && cols_y;
    data.is_trigger = this->is_trigger || other.is_trigger;

    if (data.has_collided) {
	data.x = this->x - other.x;
	data.y = this->y - other.y;
    }

    return data;
}

void BoxCollider2D::set_pos(float x, float y){
    this->x = x;
    this->y = y;
    this->x2 = x + w;
    this->y2 = y + h;
}

void BoxCollider2D::move(float x, float y){
    this->x += x;
    this->x2 += x;
    this->y += y;
    this->y2 += y;
}

void BoxCollider2D::resize(float w, float h){
    this->w = w;
    this->h = h;

    this->x2 = x + w;
    this->y2 = y + h;
}
