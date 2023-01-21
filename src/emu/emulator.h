#pragma once

#include <cstdint>
#include <string_view>
#include <chrono>
#include <random>

namespace Backend 
{
	const std::uint16_t MEMORY = 0x1000;
	const std::uint32_t START_ADDRESS = 0x200;
	const std::uint32_t FONTSET_SIZE = 80;
	const std::uint32_t FONTSET_START_ADDRESS = 0x50;
	const std::uint8_t VIDEO_WIDTH = 64;
	const std::uint8_t VIDEO_HEIGHT = 32;

	struct Emulator
	{
	public:
		typedef void (Emulator::* Chip8Func)();
		Chip8Func table[0xF + 1];
		Chip8Func table0[0xE + 1];
		Chip8Func table8[0xE + 1];
		Chip8Func tableE[0xE + 1];
		Chip8Func tableF[0x65 + 1];

		std::default_random_engine randGen;
		std::uniform_int_distribution<std::uint16_t> randByte;
		std::uint8_t registers[16];
		std::uint8_t memory[MEMORY];
		std::uint16_t index;
		std::uint16_t pc;
		std::uint16_t stack[16];
		std::uint8_t sp;
		std::uint8_t delayTimer;
		std::uint8_t soundTimer;
		std::uint8_t keypad[16];
		std::uint32_t video[VIDEO_WIDTH * VIDEO_HEIGHT];
		std::uint16_t opcode;
		std::uint8_t fontset[FONTSET_SIZE] = 
		{
			0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
			0x20, 0x60, 0x20, 0x20, 0x70, // 1
			0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
			0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
			0x90, 0x90, 0xF0, 0x10, 0x10, // 4
			0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
			0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
			0xF0, 0x10, 0x20, 0x40, 0x40, // 7
			0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
			0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
			0xF0, 0x90, 0xF0, 0x90, 0x90, // A
			0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
			0xF0, 0x80, 0x80, 0x80, 0xF0, // C
			0xE0, 0x90, 0x90, 0x90, 0xE0, // D
			0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
			0xF0, 0x80, 0xF0, 0x80, 0x80  // F
		};

		Emulator();
		
		void Cycle();

		void Table0();
		void Table8();
		void TableE();
		void TableF();

		void LoadROM(std::string_view filename);
		void OP_NULL();
		void OP_00E0();
		void OP_00EE();
		void OP_1nnn();
		void OP_2nnn();
		void OP_3xkk();
		void OP_4xkk();
		void OP_5xy0();
		void OP_6xkk();
		void OP_7xkk();
		void OP_8xy0();
		void OP_8xy1();
		void OP_8xy2();
		void OP_8xy3();
		void OP_8xy4();
		void OP_8xy5();
		void OP_8xy6();
		void OP_8xy7();
		void OP_8xyE();
		void OP_9xy0();
		void OP_Annn();
		void OP_Bnnn();
		void OP_Cxkk();
		void OP_Dxyn();
		void OP_Ex9E();
		void OP_ExA1();
		void OP_Fx07();
		void OP_Fx0A();
		void OP_Fx15();
		void OP_Fx18();
		void OP_Fx1E();
		void OP_Fx29();
		void OP_Fx33();
		void OP_Fx55();
		void OP_Fx65();
	};


}
