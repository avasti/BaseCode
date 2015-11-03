#pragma once
#include "SDL.h"
#include "map"
#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

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

	bool Load(const char* fileName, const char* id, SDL_Renderer* pRenderer);
	void Draw(const char* id, int x, int y, int width, int height, SDL_Renderer* pRender, SDL_RendererFlip flip);
	void DrawFrame(const char* id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRender,
		SDL_RendererFlip flip);
	void setFrames(const char* id, int width, int height);

private:
	SDL_Rect SrcR;
	SDL_Rect DestR;
	std::map<char, SDL_Texture* > m_textureMap;
	std::map<char, int[2] > m_textureSizes;
	SDL_Surface* SDL_surface;
	SDL_Texture* SDL_texture;
	static TextureManager* s_pInstance;
};
#endif TEXTUREMANAGER_H