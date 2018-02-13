#pragma once
#include <unordered_map>

#include "./low_level/Texture.hpp"
#include "Sprite.hpp"
#include "Camera.hpp"


namespace graphics {
    
    class SpriteRenderer
    {
    public:
	SpriteRenderer() = delete;

	static void register_sprite(Sprite& s);
	static void register_sprite(Sprite* s);

	static void Render() ;


    private:
	static std::unordered_map<int,Sprite*> sprites;
    };

}
