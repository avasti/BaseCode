#pragma once
#include "Game.h"
#include "StaticObjects.h"
#include "TextureManager.h"

StaticObjects::StaticObjects() {};
StaticObjects::~StaticObjects() {};

void StaticObjects::draw()
{
	TextureManager::Instance()->drawFrame(m_textureID, m_position.getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);
}

void StaticObjects::drawRotation(int angle) 
{
	TextureManager::Instance()->draw(m_textureID, m_position.getX(), m_position.getY(), m_width, m_height, angle, Game::Instance()->getRender(), SDL_FLIP_NONE);
};

void StaticObjects::load(const LoaderParams* pParams)
{
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());
	m_textureID = pParams->getTextureID();
	m_spriteNum = pParams->getNum();
	m_currentRow = 0;
	m_currentFrame = 0;
	m_maxVelocity = pParams->getMaxSpeed();
	m_velocity.setX(0);
	m_velocity.setY(0);
	m_acceleration.setX(0);
	m_acceleration.setY(0);
	m_friction.setX(1000);
	m_friction.setY(1000);
};

void StaticObjects::update() {
	int framesPorSegundo = 10;
	m_currentFrame = (int)((((Game::Instance()->getTicks())*framesPorSegundo) / 1000) % m_spriteNum); //canvia 10 veces por segundo
};

void StaticObjects::clean()
{

};
