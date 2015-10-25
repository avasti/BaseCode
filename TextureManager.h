#pragma once
#include "map"
#include "SDL.h"

class TextureManager
{
private:

	TextureManager();

public:

	static TextureManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new TextureManager();
		}
		return s_pInstance;
	}

	~TextureManager();

	bool load(const char* fileName, const char* id, SDL_Renderer* pRenderer);
	void draw(const char* id, int x, int y, int width, int height, SDL_Renderer* pRender, SDL_RendererFlip flip);
	void drawFrame(const char* id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRender, SDL_RendererFlip flip);
	void setSizeFrames(const char* id, int width, int height);

private:

	SDL_Rect SrcR;
	SDL_Rect DestR;
	SDL_Texture* SDL_texture;
	SDL_Surface* SDL_surface;
	std::map<char, int[2] > m_textureSizes;
	std::map<char, SDL_Texture* > m_textureMap;
	static TextureManager* s_pInstance;	
};
