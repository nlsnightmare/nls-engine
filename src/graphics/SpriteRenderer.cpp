#include "SpriteRenderer.hpp"
#include "../game/GameObject.hpp"
#include <iostream>

using namespace graphics;
std::unordered_map<int,Sprite*> SpriteRenderer::sprites;

void SpriteRenderer::register_sprite(graphics::Sprite &s){
    static int i = 0;
    sprites.insert(std::make_pair(i, &s));
    i++;
}

void SpriteRenderer::register_sprite(graphics::Sprite* s){
    static int i = 0;
    sprites.insert(std::make_pair(i, s));
    i++;
}

void SpriteRenderer::Render(){
    for( auto s : SpriteRenderer::sprites ){
	GameObject* go = (GameObject*)s.second;
	s.second->Draw();
    }
}
