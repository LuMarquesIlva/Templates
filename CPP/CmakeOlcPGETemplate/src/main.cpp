#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class PixelGame : public olc::PixelGameEngine 
{
public:
	PixelGame()
	{
		sAppName = "PixelGame";
	}

public:
	bool OnUserCreate() override
	{
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		for (int x = 0; x < ScreenWidth(); x++)
			for (int y = 0; x < ScreenHeight(); y++)
				Draw(x, y, olc::Pixel(rand() % 255, rand() % 255, rand() % 255));
		return true;
	}

};

int main() {
	
	PixelGame demo;
	if (demo.Construct(256, 250, 4, 4))
		demo.Start();

	return 0;
}
