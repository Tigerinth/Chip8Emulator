// Chip8.cpp : Defines the entry point for the application.
//

#include "Chip8.h"

#include <fstream>

const unsigned int START_ADDRESS = 0x200;

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