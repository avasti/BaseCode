#include "TileLayer.h"
#include "Tools.h"
#include "TextureManager.h"
#include "Game.h"

TileLayer::TileLayer(int width, int height, int tileWidth, int tileHeight, std::vector<Tileset> tileSets) : Layer(tileSets)
{
	this->width = width;
	this->height = height;
	this->tileWidth = tileWidth;
	this->tileHeight = tileHeight;	
}

TileLayer::~TileLayer()
{
}

void TileLayer::Update()
{
	position.X = 0;
	position.Y = 0;
}

void TileLayer::Render()
{
	Vector2D scr((float)Tools::GetWidth(), (float)Tools::GetHeight());
	for (int row = 0; row < width; row++) 
	{
		for (int tile = 0; tile < height; tile++)
		{		
			int current = tileIDs[tile][row];
			if (current == 0)
				continue;

			
			int x1 = (row * tileWidth) - (position.X / tileWidth);
			int x2 = x1 + tileWidth;
			int y1 = Tools::GetHeight() - (90 - tile) * tileHeight;
			int y2 = y1 + tileHeight;

			if (y1 < 0 && y2 < 0)
				continue;
			if (x1 < 0 && x2 < 0 || x1 > Tools::GetWidth() && x1 > Tools::GetWidth())
				continue;
			
			Tileset * ts = GetTileset(current);
			current--;
			Draw(ts->name, ts, x1 - position.X, y1 - position.Y, 
				(current - (ts->firstGridID - 1)) / ts->numColumns,
				(current - (ts->firstGridID - 1)) % ts->numColumns);
		}
	}
}

void TileLayer::SetTileIDs(const std::vector<std::vector<int>>& tileIDs)
{
	this->tileIDs = tileIDs;
}

void TileLayer::Draw(string id, Tileset * ts, int x, int y, int row, int frame)
{
	SDL_Rect source, draw;
	
	source.x = ts->margin + (ts->spacing + ts->tileWidth) * (frame);
	source.y = ts->margin + (ts->spacing + ts->tileHeight) * row;
	source.w = ts->tileWidth;
	source.h = ts->tileHeight;

	draw.w = tileWidth;
	draw.h = tileHeight;
	draw.x = x;
	draw.y = y;

	SDL_Texture * textura = TextureManager::GetInstance()->GetArray()[id];
	SDL_RenderCopy(TheGame->GetRenderer(), textura, &source, &draw);
}