#pragma once
#include "Game.h"
#include "StaticObjects.h"
#include "TextureManager.h"

StaticObjects::StaticObjects() {};
StaticObjects::~StaticObjects() {};

void StaticObjects::draw()
{
	TextureManager::Instance()->DrawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);
}

void StaticObjects::load(const LoaderParams* pParams)
{
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_x = pParams->getX();
	m_y = pParams->getY();
	m_textureID = pParams->getTextureID();
	m_spriteNum = pParams->getNum();
	m_currentRow = 0;
	m_speed = 0;
};

void StaticObjects::update() {
	m_currentFrame = (int)(((Game::Instance()->getTicks()) / 100) % m_spriteNum);
};

void StaticObjects::clean() {
};