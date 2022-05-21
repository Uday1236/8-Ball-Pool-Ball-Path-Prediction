#pragma once

#include <Windows.h>

struct Memory
{
	Memory() {}

	DWORD getGameModuleBase();
	BOOL  read(SIZE_T address, PVOID buffer, SIZE_T bufferSize);
	BOOL  write(SIZE_T address, PVOID buffer, SIZE_T bufferSize);


	template <typename T>
	inline T read(SIZE_T address)
	{
		T buffer{};

		read(address, &buffer, sizeof(buffer));
		return buffer;
	}

	template <typename T>
	inline BOOL write(SIZE_T address, T value)
	{
		return write(address, &value, sizeof(value));
	}

	static HANDLE getProcessHandle();
};