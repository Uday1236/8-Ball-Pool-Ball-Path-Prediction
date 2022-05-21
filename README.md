MEM_RESERVED     : Booking a memory space.
MEM_COMMIT       : To make a booked memory space usable/accessible.

reinterpret_cast : from pointer to pointer and from intger to pointer and vice versa
static_cast      : converts from any-to-any have the same size (i don't know)

aimLength  = "libgame-BPM-GooglePlay-Gold-Release-Module-2594.so"+34B5F2C
entityList = "libgame-BPM-GooglePlay-Gold-Release-Module-2594.so"+0355D6C4
entityList = 08 20 81 E5 0C 20 81 E5 04 20 A0 E1 10 30 81 E5 1C D0 4B E2
3.50657980671
Patch:
/* ball ball collision [string]*\
"libgame-BPM-GooglePlay-Gold-Release-Module-2594.so"+28C1AFE
/* ball line collision [string]*\
"libgame-BPM-GooglePlay-Gold-Release-Module-2594.so"+28C1CAC
/* ball point collision [string]*\
"libgame-BPM-GooglePlay-Gold-Release-Module-2594.so"+28C1F3D

/* Height && Width [float*]*\
"libgame-BPM-GooglePlay-Gold-Release-Module-2594.so"+35727E8

/* Table Width && Height [double]*/
"getPocketRadius"
max_balls_count
/*table info + re-join*/
set breakpoint at dword_1AF3F14

/ coins/cash/level etc \
search for checkBuyMostExpensiveCueAchievement

MAX_POWER Use ->
F2 0F 59 FE 66 0F 57 FB 8B 55 5C 66 0F D6 62 30 66 0F D6 6A 38 F3 0F 7E 5A 50

66 0F D6 8D 80 00 00 00 66 0F D6 95 90 00 00 00 66 0F D6 9D 98 00 00 00 66 0F D6 A5 A0 00 00 00 66 0F D6 AD C0 00 00 00 66 0F D6 B5 D8 00 00 00 66 0F D6 BD E0 00 00 00 89 7D 40 8B 8D 00 02 00 00

handleBallMovement -> IDA

/* Executable Base *\
"libgame-BPM-GooglePlay-Gold-Release-Module-2594.so"+60B7D3
/* Size *\
0x1FA4000

static constexpr auto xValue = 6.46464646465f, topValue = 3.76306620209f, bottomValue = 7.76978417266f;

8b 5d ? 89 5c 24 ? 8b 5d ? 89 5c 24 ? 89 54 24 ? c7 44 24 ? ? ? ? ? 83 c4 ? 8d 54 24 ? 89 55 ? 8d 64 24 ? 89 7d
/*then*/
c7 45 ? ? ? ? ? 90 e9 ? ? ? ? c7 85 ? ? ? ? ? ? ? ? 8b 55 ? 89 d6 89 55 ? 8b 5d

7F 45 4C 46 01 01 01 00 00 00 00 00 00 00 00 00 03 00 28 00 01 00 00 00 00 00 00 00 34 00 00 00 80 47 3E 03 00 02 00 05 34 00 20 00 08 00 28 00 1A 00 19 00 06 00 00 00 34 00 00 00 34 00 00 00 34 00 00 00 00 01 00 00 00 01 00 00 04 00 00 00 04 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00

v8 = 0
v1 = 66
v5 = 5381
v7 = 0x47681CAC + 1
repeat
    v8 = readByte(v7)
    v5 = 33 * v5 + v1
    v1 = v8
    v7 = v7 + 1
until (v8 == 0)

print(string.upper(string.format("%x", v5)))

x86 Code
C7 85 50 06 00 00 58 6E 6D 0E C7 45 40 FE 1A 68 47 C7 45 78 B8 5A A2 46 E9 C3 97 9C FF C7 85 50 06 00 00 64 6E 6D 0E 8B 55 40 89 D3 89 55 54 BE A8 AF FC 47 C7 45 50 A8 AF FC 47 89 5D 40 8D BE 98 00 00 00 89 7D 5C 89 7D 44 C7 45 78 D4 5A A2 46
namespace Entity
{
    constexpr SIZE_T positionX = 0x8;
    constexpr SIZE_T positionY = 0xC;
};

--the register values like EAX and EBX can be read here. 
--Changing them has no effect though
--Note: Keep in mind hexadecimal values start with 0x

return (readInteger(ESP + 0x14)==0x05AF837C and EDX== ) --return a non-zero value if you want to break


0x4000000
0x77900d0
0x37900D0

-123.19952499999
13857505684674839934

0E16D920
10000920

/////////////\\\\\\\\\\\
0E1C5000
10000000

tificate Authority - G2y

0E5BF45A - F3 0F7E 8E 98020000  - movq xmm1,[esi+00000298]
0E5BF527 - F3 0F7E BE 98020000  - movq xmm7,[esi+00000298]
0E5A3E3D - F3 0F7E BA 98020000  - movq xmm7,[edx+00000298]
0E669B71 - 66 0FD6 8E 98020000  - movq [esi+00000298],xmm1
0E6698D1 - F3 0F7E 5F 00  - movq xmm3,[edi+00]
0E75F48C - 

void Prediction::PredictionInfo::stop()
{
    auto v29 = this->predictedPosition.y + this->velocity.y * time3;
    auto v30 = this->predictedPosition.y;
    if (this->velocity.y > 0.0)
        v30 = this->predictedPosition.y + this->velocity.y * time3;
    auto v31 = -127.0;
    auto v32 = this->predictedPosition.x + this->velocity.x * time3;
    if (this->velocity.x > 0.0)
        v32 = this->predictedPosition.x;
    auto v33 = -63.5;
    auto v34 = 127.0;
    if (v32 >= Ball::getRadius() + v31)
    {
        auto v35 = this->predictedPosition.x;
        if (this->velocity.x > 0.0)
            v35 = this->predictedPosition.x + this->velocity.x * time3;
        if (this->velocity.y > 0.0)
            v29 = this->predictedPosition.y;
        if (v29 >= Ball::getRadius() + v33 && v35 <= v31 + 254.0 - Ball::getRadius() && v30 <= v33 + v34 - Ball::getRadius()) {
            this->stop();
            *time = time3;
            return;
        }
    }
    this->onTable = false;
    this->velocity.nullify();
    this->velocity.x = vecZero;
    this->velocity.x = vecZero;
    this->velocity.x = vecZero;
    this->velocity.x = vecZero;
}

# 8 Ball Pool Ball Path Prediction
It's a x86 hack library, designed to work on gameloop emulator.

Features:
- Ball Path Prediction
- Auto-Aim - disabled by default
- AdBlock (Ad Break Screen)

Video: [![Watch the video](https://img.youtube.com/vi/7-cKs1hOfdE/maxresdefault.jpg)](https://youtu.be/7-cKs1hOfdE)

Supported Platforms:

- Windows Only

Notes:
- game uses the same algorithm for all platforms.
- offsets are the same in Android, they might be differnt for other platforms.

Dependencies:

[D2DOverlay precompiled lib](https://github.com/coltonon/D2DOverlay)

Build:

compile using microsoft visual studio version 2019/2022 with the following settings:

- x86 & Release
- C++ language standard: Preview - Features from the Latest C++ Working Draft (/std:c++latest)
- C language standard: ISO C17 (2018) Standard (/std:c17)

Code documentation:

unfortunately i'm not used to write documentation in my code, but i should start doing it.   

Final Notes:

- code isn't optimized a lot just take that in account for a better performance.