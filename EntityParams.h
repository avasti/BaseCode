#pragma once
#include <iostream>

class EntityParams
{
private:
	std::string id;
	float xPos, yPos;
	int width, height;
	int frame;
	int maxFrame, row;
	bool flipped;
public:
	EntityParams(std::string id, int xPos, int yPos, int width, int height, int maxFrame = 0, int row = 0);

	std::string GetId() { return id; }

	void SetXPos(float xPos) { this->xPos = xPos; }
	float GetXPos() { return xPos; }

	void SetYPos(float yPos) { this->yPos = yPos; }
	float GetYPos() { return yPos; }

	int GetWidth() { return width; }
	int GetHeight() { return height; }
	void SetWidth(int width) { this->width = width; }
	void SetHeight(int height) { this->height = height; }

	int GetFrame() { return frame; }
	void SetFrame(int frame) { this->frame = frame; }

	int GetMaxFrame() { return maxFrame; }
	int GetRow() { return row; }
	void SetRow(int row) { this->row = row; }

	bool IsFlipped() { return flipped; }
	void Flip() { flipped = !flipped; }
	void SetFlipped(bool flipped) { this->flipped = flipped; }

	void AddFrame();
	void AddXPos(float);
};