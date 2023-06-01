// Chip8.cpp : Defines the entry point for the application.
//

#include "Chip8.h"

#include <fstream>
#include <random>
#include <cstdint>

const unsigned int START_ADDRESS = 0x200;
const unsigned int FONTSET_SIZE = 80;
const unsigned int FONTSET_START_ADRESS = 0x50;

uint8_t fontset[FONTSET_SIZE] =
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

void Chip8::LoadROM(char const* filename)
{
	std::ifstream file(filename, std::ios::binary | std::ios::ate);

	if (file.is_open())
	{
		// dosya boyutunu al ve bu icerigi tutmak icin tamponda yer ac
		std::streampos size = file.tellg();
		char* buffer = new char[size];

		// dosyanin basina don ve tamponu doldur
		file.seekg(0, std::ios::beg);
		file.read(buffer, size);
		file.close();

		// (baslangic adresi 0x200) Chip8'in hafizasina ROM icerigini yukle
		for (long i = 0; i < size; ++i)
		{
			memory[START_ADDRESS + i] = buffer[i];
		}

		// tamponu bosalt
		delete[] buffer;
	}
}

Chip8::Chip8()
	: randGen(std::chrono::system_clock::now().time_since_epoch().count())
{
	// Initialize PC
	pc = START_ADDRESS;

	// Initialize RNG
	randByte = std::uniform_int_distribution<uint8_t>(0, 255U);


	// Load fonts into memory
	for (unsigned int i = 0; i < FONTSET_SIZE; ++i)
	{
		memory[FONTSET_START_ADDRESS + i] = fontset[i];
	}

}
Chip8::OPCODE_NULL() {

}
Chip8::OPCODE_CLS() {
	uint16_t videosize = sizeof(video);
	memset(video, 0, videosize);
}
Chip8::OPCODE_RET() {
	pc = stack[sp];
	sp--;
}
Chip8::OPCODE_JUMPADDRESS() {
	uint16_t atlanacakadres = opcode & 0x0FFFu;
	pc = atlanacakadres;
}
Chip8::OPCODE_CALLADDRESS() {

}