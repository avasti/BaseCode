#include "Button.h"
#include "Game.h"

void Button::Load(EntityParams * params)
{
	this->id = params->GetId();
	this->params = params;
	text = new InertEntity();
	text->params = params;
}

Entity * Button::Create()
{
	return new Button();
}

void Button::SetOnClickListener(void(*callback)())
{
	this->callback = callback;
}

void Button::Draw()
{
	SDL_Rect img, draw;
	img.x = 0;
	img.y = 0;
	img.w = params->GetWidth();
	img.h = params->GetHeight();

	draw.x = (int)params->GetXPos();
	draw.y = (int)params->GetYPos();
	draw.h = params->GetHeight();
	draw.w = params->GetWidth();

	SDL_RendererFlip flip = params->IsFlipped() ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;

	SDL_Texture * textura = NULL;
	switch (state)
	{
	case WAIT:
		textura = TextureManager::GetInstance()->GetArray()["Wait"];
		break;
	case HOVER:
		textura = TextureManager::GetInstance()->GetArray()["Hover"];
		break;
	case PRESSED:
		textura = TextureManager::GetInstance()->GetArray()["Pressed"];
		break;
	}
	SDL_RenderCopyEx(TheGame->GetRenderer(), textura, &img, &draw, 0, NULL, flip);

	SDL_Texture * text = TextureManager::GetInstance()->GetArray()[id.c_str()];
	SDL_RenderCopyEx(TheGame->GetRenderer(), text, &img, &draw, 0, NULL, flip);

}

void Button::DrawFrame()
{
	Draw();
}

void Button::Update()
{
	int x = BigHandle->GetMousePosition().first;
	int y = BigHandle->GetMousePosition().second;

	if (x > params->GetXPos() && x < params->GetWidth() + params->GetXPos() &&
		y > params->GetYPos() && y < params->GetHeight() + params->GetYPos())
	{		
		if (BigHandle->GetMouseButtons().first && state != WAIT)
		{
			state = PRESSED;			
		}
		else if (state == PRESSED && !BigHandle->GetMouseButtons().first)
		{
			state = WAIT;
			callback();
		}
		else if (!BigHandle->GetMouseButtons().first)
		{
			state = HOVER;
		}
	}
	else
	{
		state = WAIT;
	}
}

void Button::Clear()
{

}