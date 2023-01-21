#include <iostream>
#include <chrono>

#include "emu/emulator.h"
#include "emu/platform.h"

int main(int argc, char** argv)
{
	int videoScale = 20;
	int cycleDelay = 3;
	std::string romFilename = "D:/Bureau/Tetris [Fran Dachille, 1991].ch8";

	Platform platform("CHIP-8 Emulator", Backend::VIDEO_WIDTH * videoScale, Backend::VIDEO_HEIGHT * videoScale, Backend::VIDEO_WIDTH, Backend::VIDEO_HEIGHT);

	Backend::Emulator chip8;
	chip8.LoadROM(romFilename);

	int videoPitch = sizeof(chip8.video[0]) * Backend::VIDEO_WIDTH;

	auto lastCycleTime = std::chrono::high_resolution_clock::now();
	bool quit = false;

	while (!quit)
	{
		quit = platform.ProcessInput(chip8.keypad);

		auto currentTime = std::chrono::high_resolution_clock::now();
		float dt = std::chrono::duration<float, std::chrono::milliseconds::period>(currentTime - lastCycleTime).count();

		if (dt > cycleDelay)
		{
			lastCycleTime = currentTime;

			chip8.Cycle();
			platform.Update(chip8.video, videoPitch);
		}
	}

	return 0;

    return 0;
}
