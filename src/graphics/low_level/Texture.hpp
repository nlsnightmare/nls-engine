#pragma once
#include <string>
#include <unordered_map>

namespace graphics {
    
    class Texture
    {
    public:
	Texture(){};
	Texture(std::string filename, bool has_alpha = false);

	void Bind(int num = 0) const;
	void Unbind() const;

	inline unsigned int ID() const { return m_id; };

	static Texture* get(std::string name);
	static void load_textures(std::string path);
	static void delete_textures();
    

    private:
	unsigned int m_id;
	int m_width, m_height, m_Chanells;
	unsigned char *m_data;

	static std::unordered_map<std::string, Texture*> textures;
    };

}
