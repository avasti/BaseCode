#pragma once
#include "Game.h"
#include "Enemy.h"
#include "TextureManager.h"

Enemy::Enemy() {};
Enemy::~Enemy() {};

void Enemy::draw()
{
	TextureManager::Instance()->DrawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);
}

void Enemy::load(const LoaderParams* pParams)
{
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_x = pParams->getX();
	m_y = pParams->getY();
	m_textureID = pParams->getTextureID();
	m_spriteNum = pParams->getNum();
	m_currentRow = 0;
	m_speed = pParams->getSpeed();
};

void Enemy::update() {
	m_currentFrame = (int)(((Game::Instance()->getTicks()) / 100) % m_spriteNum);
	if (m_speed < 0) {
		if ((Game::Instance()->getTicks() / 5) % (100 / m_speed) == 0) {
			if (m_x >(-1)*m_width) {
				m_x -= 1;
			}
			else {
				m_x = Game::Instance()->getWidth() + m_width;
			}
		}
	}
	else if (m_speed > 0) {
		if ((Game::Instance()->getTicks() / 5) % (100 / m_speed*(-1)) == 0) {
			if (m_x < Game::Instance()->getWidth()) {
				m_x += 1;
			}
			else {
				m_x = 0 - m_width;
			}
		}
	}
};

void Enemy::clean() {
};