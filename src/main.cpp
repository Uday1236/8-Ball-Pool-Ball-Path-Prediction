#include <iostream>
#include "GlobalVars.h"
#include "Memory.h"
#include "GUI.h"
#include "GameManager.h"
#include "Prediction.h"

//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
int main()
{
    MSG    msg;
    HANDLE process = Memory::getProcessHandle();

    if (process != nullptr) {
        if (gGlobalVars->init()) {
            GUI::init();
            while (1) {
                while (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE)) {
                    TranslateMessage(&msg);
                    DispatchMessage(&msg);
                }

                //if (GameManager::isPlayerTurn())
                //    gPrediction->initAutoAim();

                Sleep(10);
            }
        }

        CloseHandle(process);
    }
}

