#include "GUI.h"
#include "GlobalVars.h"
#include "Ball.h"
#include "Balls.h"
#include "GenericData.h"
#include "TableInfo.h"
#include "Memory.h"
#include "Offsets.h"
#include "D2DOverlay/DirectOverlay.h"
#include <cmath>
#include <string>
#include <intrin.h>
#include "const.h"
#include <vector>
#include "Prediction.h"
#include "Colors.hpp"
#include "GameManager.h"
#include "AdsManager.h"

#include <array>

#pragma comment(lib, "D2DOverlay\\D2DOverlay.lib")

namespace AEngineRenderWindow
{
    HWND  window;
}

void drawLine(const Vector2D& src, const Vector2D& dst, const Color* color, float thickness = 1.f)
{
    float point[4];

    point[0] = static_cast<float>(src.x);
    point[1] = static_cast<float>(src.y);
    point[2] = static_cast<float>(dst.x);
    point[3] = static_cast<float>(dst.y);
    DrawLine(point[0], point[1], point[2], point[3], thickness, color->r, color->g, color->b, color->a);
}

void drawCircle(const Vector2D& point, vec_t radius, const Color* color, float thickness = 1.f, bool filled = true)
{
    float pointf[2], radiusf;
    
    pointf[0] = static_cast<float>(point.x);
    pointf[1] = static_cast<float>(point.y);
    radiusf   = static_cast<float>(radius);
    DrawCircle(pointf[0], pointf[1], radiusf, thickness, color->r, color->g, color->b, color->a, filled);
}

void drawAimLine()
{
    bool                        draw, predictionState;
    float                       tickness;
    Color*                      color;
    SIZE_T                      i, j, countA, countB;
    Vector2D                    srcPoint, dstPoint;
    Prediction::PredictionInfo* predictionInfo;
    const auto& pocketsPositions = TableInfo::getPocketsPositions();

    if (GameManager::isPlayerTurn() && gPrediction->init()) {
        countA = gBalls->getCount();
        for (i = 0UL; i < countA; i++) {
            predictionInfo = &gPrediction->infoA[i];
            draw = (predictionInfo->initialPos != predictionInfo->predictedPosition);
            if (draw) {
                color = &colors[i % colors.size()];
                tickness = (i > 8) ? 1.f : 5.f;
                countB = predictionInfo->positions.size();
                for (j = 1; j < countB; j++) {
                    srcPoint = predictionInfo->positions[j - 1].toScreen();
                    dstPoint = predictionInfo->positions[j].toScreen();
                    draw = (srcPoint != dstPoint);
                    if (draw)
                        drawLine(srcPoint, dstPoint, color, tickness);
                }

                drawCircle(dstPoint, Ball::getRadius() * 5.0 * gGlobalVars->gameloopWindowInfo.scale.x, color, 1.f);
            }
        }

        predictionState = gPrediction->stateA;
        if (predictionState)
            color = &colors[6]; // green
        else
            color = &colors[3]; // red
        for (auto& pocketPosition : pocketsPositions) {
            srcPoint = pocketPosition.toScreen();
            drawCircle(srcPoint, TableInfo::getPocketRadius() * 5.0 * gGlobalVars->gameloopWindowInfo.scale.x, color, 5.f, false);
        }
    }
}

void drawLoop(int width, int height) {
    drawAimLine();
}

void CALLBACK timerCallback(HWND hwnd, UINT uMsg, UINT timerId, DWORD dwTime);

void GUI::init()
{
    HWND       gameLoopWindow;
    HINSTANCE  instance = GetModuleHandle(nullptr);
    HICON      icon = nullptr;

    gameLoopWindow = FindWindow("TXGuiFoundation", "Gameloop");
    if (gameLoopWindow)
        AEngineRenderWindow::window = FindWindowEx(gameLoopWindow, 0, "AEngineRenderWindowClass", "AEngineRenderWindow");
    if (AEngineRenderWindow::window) {
        DirectOverlaySetOption(D2DOV_FONT_IMPACT | D2DOV_VSYNC);
        DirectOverlaySetup(drawLoop, AEngineRenderWindow::window);
        SetTimer(NULL, 0UL, 5000U, timerCallback);
    }
}

void GUI::end()
{
    KillTimer(NULL, 0UL);
}

static void CALLBACK timerCallback(HWND hwnd, UINT uMsg, UINT timerId, DWORD dwTime)
{
    RECT            buffer;
    Vector2D        size;
    Vector4D        tableBuffer;
    constexpr vec_t widthScale = 6.05678233438, heightScale = 3.62416107383, bottomScale = 6.79245283019;

    if (IsWindow(AEngineRenderWindow::window)) {
        GetWindowRect(AEngineRenderWindow::window, &buffer);
        tableBuffer.x = static_cast<vec_t>(buffer.left);
        tableBuffer.y = static_cast<vec_t>(buffer.top);
        tableBuffer.z = static_cast<vec_t>(buffer.right);
        tableBuffer.w = static_cast<vec_t>(buffer.bottom);

        size.x = tableBuffer.z - tableBuffer.x;
        size.y = tableBuffer.w - tableBuffer.y;

        gGlobalVars->gameloopWindowInfo.scale.x = size.x / static_cast<double>(GetSystemMetrics(SM_CXSCREEN));
        gGlobalVars->gameloopWindowInfo.scale.y = size.y / static_cast<double>(GetSystemMetrics(SM_CYSCREEN));

        tableBuffer.x = size.x / widthScale;
        tableBuffer.y = size.y / heightScale;
        tableBuffer.z = size.x - size.x / widthScale;
        tableBuffer.w = size.y - size.y / bottomScale;
        TableInfo::Position::set(tableBuffer.x, tableBuffer.y, tableBuffer.z, tableBuffer.w);

        tableBuffer.z -= tableBuffer.x;
        tableBuffer.w -= tableBuffer.y;
        TableInfo::setSize(tableBuffer.z, tableBuffer.w);
    }

    AdsManager::disableAdBreakScreen();
}
