#pragma once

class GameObject;
namespace physics {

    struct CollisionData
    {
	bool has_collided;
	float x;
	float y;
	float is_trigger;
    };
    
    class BoxCollider2D
    {
    public:
	BoxCollider2D(float x, float y, float w, float h, GameObject* parent);

	void set_pos(float x, float y);
	void move(float x, float y);
	void resize(float w, float h);


	CollisionData does_collide(BoxCollider2D& other) const;

	float x,y,x2,y2;
	float w,h;
	bool is_trigger;

	GameObject* parent;
    };
}
