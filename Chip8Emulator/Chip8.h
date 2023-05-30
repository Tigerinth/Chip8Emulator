// Chip8.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
const unsigned int KEY_COUNT = 16;
const unsigned int MEMORY_SIZE = 4096;
const unsigned int REGISTER_COUNT = 16;
const unsigned int STACK_LEVELS = 16;
const unsigned int VIDEO_HEIGHT = 32;
const unsigned int VIDEO_WIDTH = 64;

class Chip8 {

public:

	Chip8();
	void LoadROM(char const* filename);
	void Cycle();

	
	uint8_t registers[REGISTER_COUNT]{};
	uint8_t memory[MEMORY_SIZE]{};
	uint16_t index{};
	uint16_t pc{};
	uint16_t stack[STACK_LEVELS]{};
	uint8_t sp{};
	uint8_t delayTimer{};
	uint8_t soundTimer{};
	uint8_t keypad[KEY_COUNT]{};
	uint32_t video[VIDEO_WIDTH * VIDEO_HEIGHT]{};
	uint16_t opcode;




	std::default_random_engine randGen;
	std::uniform_int_distribution<uint8_t> randByte;


};


// TODO: Reference additional headers your program requires here.
