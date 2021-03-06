#include "../GameManager.hpp"
#include "SpriteRenderer.hpp"
#include "../game/GameObject.hpp"
#include <iostream>

using namespace graphics;
std::unordered_map<int,std::vector<Sprite*>> SpriteRenderer::sprites;


void SpriteRenderer::register_sprite(graphics::Sprite* s){
    int text_id = s->get_texture().ID();
    auto it = sprites.find(text_id);

    if (it == sprites.end()) {
	std::vector<Sprite*> v;
	v.push_back(s);
	sprites.insert(std::make_pair(text_id,v));
    }
    else 
	it->second.push_back(s);
}

void SpriteRenderer::Render(){
    for( auto v : SpriteRenderer::sprites ){
	auto t = Texture::get(v.first);
	t->Bind();
	for (auto s : v.second) {
	    s->Draw();
	}
    }
}
void SpriteRenderer::remove_sprite(Sprite* s){
    int text_id = s->get_texture().ID();
    for (auto i = 0; i < sprites.at(text_id).size(); ++i) {
	if (sprites.at(text_id).at(i) ==s)
	    sprites.at(text_id).erase(sprites.at(text_id).begin() + i);
    }

}
