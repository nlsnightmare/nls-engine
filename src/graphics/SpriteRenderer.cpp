#include "SpriteRenderer.hpp"
#include "../game/GameObject.hpp"
#include <iostream>

using namespace graphics;
std::unordered_map<int,std::vector<Sprite*>> SpriteRenderer::sprites;

void SpriteRenderer::register_sprite(graphics::Sprite &s){
    // static int i = 0;
    // sprites.insert(std::make_pair(i, &s));
    // i++;
}

void SpriteRenderer::register_sprite(graphics::Sprite* s){
    int text_id = s->get_texture().ID();

    if (sprites.find(text_id) == sprites.end()) {
	std::vector<Sprite*> v;
	v.push_back(s);
	sprites.insert(std::make_pair(text_id,v));
    }

    // static int i = 0;
    // sprites.insert(std::make_pair(i, s));
    // i++;
}

void SpriteRenderer::Render(){
    for( auto v : SpriteRenderer::sprites ){
	auto t = Texture::get(v.first);
	t->Bind();
	for (auto s : v.second) {
	    s->Draw();
	}

	// GameObject* go = (GameObject*)s.second;
	// s.second->Draw();
    }
}
