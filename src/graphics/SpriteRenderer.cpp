#include "SpriteRenderer.hpp"
#include <iostream>

using namespace graphics;
std::unordered_map<int,Sprite*> SpriteRenderer::sprites;

void SpriteRenderer::register_sprite(graphics::Sprite &s){
    sprites.insert(std::make_pair(1, &s));
}

void SpriteRenderer::register_sprite(graphics::Sprite* s){

    sprites.insert(std::make_pair(1, s));
}

void SpriteRenderer::Render(){
    for( auto s : SpriteRenderer::sprites ){
	s.second->Draw();
    }
}
