#pragma once
#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include "SDL.h"
#include "map"

class TextureManager
{
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
	void draw(const char* id, int x, int y, int width, int height, int currentFrame, SDL_Renderer* pRender, SDL_RendererFlip flip);
	void drawFrame(const char* id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRender, SDL_RendererFlip flip);
	void setSizeFrames(const char* id, int width, int height);
	void clean(const char* id);

private:
	TextureManager();
	static TextureManager* s_pInstance;
	std::map<char, SDL_Texture* > MAP_textureMap;
	std::map<char, int[2] > MAP_textureSizes;
	SDL_Surface* SDL_surface;
	SDL_Texture* SDL_texture;
	SDL_Rect srcrect;
	SDL_Rect dstrect;
};
#endif TEXTUREMANAGER_H