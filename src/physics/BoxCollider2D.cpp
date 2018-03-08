#include "BoxCollider2D.hpp"
#include "../Math.hpp"
#include <iostream>

using namespace physics;


BoxCollider2D::BoxCollider2D(float x, float y, float w, float h, GameObject* parent){
    this->x = x - w/2;
    this->y = y - y/2;
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
	float disx1 = other.x2 - this->x;
	float disx2 = other.x - this->x2;
	float disy1 = other.y2 - this->y;
	float disy2 = other.y - this->y2;
	data.x = math::minabs(disx1, disx2);
	data.y = math::minabs(disy1, disy2);
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

    this->x += ( this->w - w ) / 2;
    this->w = w;

    this->y += ( this->h - h ) / 2;
    this->h = h;
    this->x2 = x + w;
    this->y2 = y + h;
}
