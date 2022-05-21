#pragma once

#include "Vector.h"

#include <basetsd.h>

struct Memory;

struct GlobalVars
{
	inline GlobalVars() { ZeroMemory(this, sizeof(*this)); }

	bool    isMenuOn;
	Memory* memory;
	SIZE_T  gameModuleBase;
	SIZE_T  sharedGameManager;

	struct
	{
		Vector2D scale;

	} gameloopWindowInfo;

	struct
	{
		struct
		{
			bool simpleGuideLine;
		} esp;

	} features;

	bool init();
};

extern GlobalVars* gGlobalVars;