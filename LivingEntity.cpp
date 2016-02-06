#include "LivingEntity.h"
#include <SDL.h>
#include "TextureManager.h"
#include "Game.h"
#include <cmath>
#include "Camera.h"

using namespace std;

LivingEntity::LivingEntity() : Entity()
{
}


LivingEntity::~LivingEntity()
{
	
}

void LivingEntity::Move(float xPos, float yPos)
{	
	if (xPos < 0 && !params->IsFlipped() || xPos > 0 && params->IsFlipped())
		params->Flip();
	if (SDL_GetTicks() % 100 / (int)Game::GetInstance()->delta == 0)
		params->AddFrame();
	params->AddXPos(xPos);
	
}

void LivingEntity::Accelerate(int aX, int aY)
{
	velocity.X += (aX * acceleration.X);
	velocity.Y += (aY * acceleration.Y);

	if (velocity.X > 0)
		velocity.X = fmin(velocity.X, maxVel.X);
	else if (velocity.X < 0)
		velocity.X = fmax(velocity.X, -maxVel.X);
	if (velocity.Y > 0)
		velocity.Y = fmin(velocity.Y, maxVel.Y);
	else if (velocity.Y < 0)
		velocity.Y = fmax(velocity.Y, -maxVel.Y);

	velocity.X *= (1 - friction.X);

	if (abs(velocity.X) < 0.1)
	{
		velocity.X = 0;
	}

	if (!IsCollidingWithTile(position.X + velocity.X, position.Y))
		position.X += velocity.X;
		
	if (!IsCollidingWithTile(position.X, position.Y + velocity.Y)) {
		position.Y += velocity.Y;
		inAir = true;
	}
	else if (inAir) {
		inAir = false;
		position.Y = getYGravity(position.X, position.Y);
	}

	bool isFlipped;

	if (aX > 0)
		isFlipped = false;
	else if (aX < 0)
		isFlipped = true;
	else if (aX == 0)
		isFlipped = params->IsFlipped();

	params->SetFlipped(isFlipped);

	if (SDL_GetTicks() % 3 == 0 && aX != 0)
		params->AddFrame();	
}

void LivingEntity::Load(EntityParams * params)
{
	this->params = params;
	position.X = params->GetXPos();
	position.Y = params->GetYPos();
	velocity = Vector2D(0, 0);
	friction = Vector2D(0.25, 0.25);
}

void LivingEntity::Draw()
{
	SDL_Rect img, draw;
	img.x = 0;
	img.y = 0;
	img.w = params->GetWidth();
	img.h = params->GetHeight();

	draw.x = (int)position.X;
	draw.y = (int)position.Y;
	draw.h = params->GetHeight();
	draw.w = params->GetWidth();

	SDL_RendererFlip flip = params->IsFlipped() ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;

	SDL_Texture * textura = TextureManager::GetInstance()->GetArray()[params->GetId()];
	SDL_RenderCopyEx(Game::GetInstance()->GetRenderer(), textura, &img, &draw, 0, NULL, flip);
}

void LivingEntity::DrawFrame()
{
	const Vector2D * camPos = TheCam->GetPosition();

	if (position.X - camPos->X < 0 || position.X - camPos->X > Tools::GetWidth() ||
		position.Y - camPos->Y < 0 || position.Y - camPos->Y > Tools::GetHeight())
		return;
	SDL_Rect img, draw;

	img.x = params->GetWidth() * params->GetFrame();
	img.y = params->GetHeight() * params->GetRow();
	img.w = params->GetWidth();
	img.h = params->GetHeight();

	draw.x = (int)position.X - camPos->X;
	draw.y = (int)position.Y - camPos->Y;
	draw.w = params->GetWidth();
	draw.h = params->GetHeight();

	SDL_RendererFlip flip = params->IsFlipped() ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;

	SDL_Texture * textura = TextureManager::GetInstance()->GetArray()[texture];
	SDL_RenderCopyEx(Game::GetInstance()->GetRenderer(), textura, &img, &draw, 0, NULL, flip);
}

void LivingEntity::Update()
{
	
}

void LivingEntity::Clear()
{
	this->~LivingEntity();
}

bool LivingEntity::IsCollidingWithTile(int x, int y) {
	
	for each (TileLayer * layer in collisionLayers) {
		vector<vector<int>> tiles = layer->GetTiles();
		int size = layer->GetTileset(0)->tileWidth;
		int yReal = y - Tools::GetHeight() + ((tiles.size() + 1) * size);
		int row = yReal / size;
		int cell = x / size;
		if (row >= tiles.size() || y >= Tools::GetHeight())
			return true;
		if (x >= tiles.size() * size || x < 0 || yReal >= tiles[row].size() * size || yReal < 0)
			return true;
		int x2 = x + size;
		int y2 = y + size;

		//Check Horitzonal collision
		if (x + collisionMargin >= cell * size || x2 - collisionMargin <= (1 + cell) * size)
		{
			if (tiles[row][cell] != 0 || tiles[row][cell + 1] != 0)
				return true;
		}
		//Check Vertical collision
		else if (y >= row * size || y2 <= (1 + row) * size)
		{
			if (tiles[row][cell] != 0 || tiles[row + 1][cell] != 0)
				return true;
		}
	}
	return false;
}

void LivingEntity::LoadCollisionLayers(vector<TileLayer *> * layers) {
	this->collisionLayers = *layers;
}

int LivingEntity::getYGravity(int x, int y)
{
	for each (TileLayer * layer in collisionLayers) {
		vector<vector<int>> tiles = layer->GetTiles();
		int size = layer->GetTileset(0)->tileWidth;
		int yReal = y - Tools::GetHeight() + ((tiles.size() + 1) * size);
		int row = yReal / size;
		int cell = x / size;
		int newY = (row)* size - ((tiles.size() + 1) * size) + Tools::GetHeight();
		return newY + size - 1;
	}
}

bool LivingEntity::CollideWithAnotherEntity(LivingEntity * another)
{
	if (another == NULL || params->GetId() == another->params->GetId())
	{
		return false;
	}
	Vector2D aMin = Vector2D(position.X + collisionMargin, position.Y);
	Vector2D aMax = Vector2D(position.X + GetWidth() - collisionMargin, position.Y + GetHeight());
	Vector2D bMin = Vector2D(another->position.X + another->collisionMargin, another->position.Y);
	Vector2D bMax = Vector2D(another->position.X + another->GetWidth() - another->collisionMargin, another->position.Y + another->GetHeight());

	return (aMin.X < bMax.X) && (aMax.X > bMin.X) && (aMin.Y < bMax.Y) && (aMax.Y > bMin.Y);
}

void LivingEntity::CheckCollisions(vector<Entity *> entitats)
{
	for each (LivingEntity * entity in entitats)
	{
		bool collide = CollideWithAnotherEntity(entity);
		if (collide)
		{
			if (Player * player = dynamic_cast<Player *>(entity))
			{
				if (Enemy * enemy = dynamic_cast<Enemy *>(this))
				{
					player->Die();
				}
			}
		}
	}
}

void LivingEntity::Die()
{
	this->position.X = -150;
	this->position.Y = 500;
}