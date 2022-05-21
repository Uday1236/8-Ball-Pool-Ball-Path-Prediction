#include "globalVars.h"
#include "Offsets.h"
#include "Memory.h"

static GlobalVars globalVars;
GlobalVars*       gGlobalVars =&globalVars;

bool GlobalVars::init() 
{
	isMenuOn                    = true;
	memory                      = new Memory();
	gGlobalVars->gameModuleBase = gGlobalVars->memory->getGameModuleBase();
	if (gGlobalVars->gameModuleBase == 0UL)
		return false;

	sharedGameManager = memory->read<SIZE_T>(gGlobalVars->gameModuleBase + gOffsets::SharedGameManager);
	if (gGlobalVars->sharedGameManager == 0UL)
		return false;

	return true;
}