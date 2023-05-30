// Chip8.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <random>
#include <cstdint>
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

	uint8_t keypad[KEY_COUNT]{};
	uint32_t video[VIDEO_WIDTH * VIDEO_HEIGHT]{};

private:
	uint8_t registers[REGISTER_COUNT]{};
	uint8_t memory[MEMORY_SIZE]{};
	uint16_t index{};
	uint16_t pc{};
	uint16_t stack[STACK_LEVELS]{};
	uint8_t sp{};
	uint8_t delayTimer{};
	uint8_t soundTimer{};
	uint16_t opcode;
	

	/*				OPCODELIST				*/

	//nullopcode
	void OPCODE_NULL();

	void OPCODE_CLS();
	void OPCODE_RET();
	void OPCODE_JUMPADDRESS(); //OPCODE 3 Jump to location nnn (1nnn)
	void OPCODE_CALLADDRESS(); //OPCODE 4 Call subroutine at nnn (2nnn)
	void OPCODE_3xkk();
	void OPCODE_4xkk();
	void OPCODE_5xy0();
	void OPCODE_6xkk();
	void OPCODE_7xkk();
	void OPCODE_8xy0();
	void OPCODE_8xy1();
	void OPCODE_8xy2();
	void OPCODE_8xy3();
	void OPCODE_8xy4();
	void OPCODE_8xy5();
	void OPCODE_8xy6();
	void OPCODE_8xy7();
	void OPCODE_8xyE();
	void OPCODE_9xy0();
	void OPCODE_Annn();
	void OPCODE_Bnnn();
	void OPCODE_Cxkk();
	void OPCODE_Dxyn();
	void OPCODE_Ex9E();
	void OPCODE_ExA1();
	void OPCODE_Fx07();
	void OPCODE_Fx0A();
	void OPCODE_Fx15();
	void OPCODE_Fx18();
	void OPCODE_Fx1E();
	void OPCODE_Fx29();
	void OPCODE_Fx33();
	void OPCODE_Fx55();
	void OPCODE_Fx65();

	/*				OPCODELIST				*/





	std::default_random_engine randGen;
	std::uniform_int_distribution<uint8_t> randByte;


};

