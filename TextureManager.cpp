#include "TextureManager.h"

TextureManager::TextureManager() {};
TextureManager* TextureManager::s_pInstance = 0;

bool TextureManager::Load(const char* fileName, const char* id, SDL_Renderer* pRenderer) {
	SDL_surface = SDL_LoadBMP(fileName);
	SDL_SetColorKey(SDL_surface, 1, SDL_MapRGB(SDL_surface->format, 255, 0, 255));
	SDL_texture = SDL_CreateTextureFromSurface(pRenderer, SDL_surface);
	m_textureMap[*id] = SDL_texture;
	return true;
};

void TextureManager::Draw(const char* id, int x, int y, int width, int height, SDL_Renderer* pRender, SDL_RendererFlip flip) {
	TextureManager::SrcR.w = m_textureSizes[*id][0];
	TextureManager::SrcR.h = m_textureSizes[*id][1];
	TextureManager::DestR.x = x;
	TextureManager::DestR.y = y;
	TextureManager::DestR.w = width;
	TextureManager::DestR.h = height;
	TextureManager::SrcR.w = width;
	TextureManager::SrcR.h = height;
	SDL_RenderCopyEx(pRender, m_textureMap[*id], &SrcR, &DestR, 0, 0, flip);
};

void TextureManager::DrawFrame(const char* id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRender, SDL_RendererFlip flip) {
	TextureManager::SrcR.x = currentFrame*m_textureSizes[*id][0];
	TextureManager::SrcR.y = currentRow*m_textureSizes[*id][1];
	TextureManager::SrcR.w = m_textureSizes[*id][0];
	TextureManager::SrcR.h = m_textureSizes[*id][1];
	TextureManager::DestR.x = x;
	TextureManager::DestR.y = y;
	TextureManager::DestR.w = width;
	TextureManager::DestR.h = height;
	SDL_RenderCopyEx(pRender, m_textureMap[*id], &SrcR, &DestR, 0, 0, flip);//Los tres últimos parametros son para girar o voltear el sprite, no los usamos.
};

TextureManager::~TextureManager() {

};

void TextureManager::setFrames(const char* id, int w, int h) {
	m_textureSizes[*id][1] = h;
	m_textureSizes[*id][0] = w;
}
