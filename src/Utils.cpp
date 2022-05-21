#include "Utils.h"

#include <format>
#include <Windows.h>

std::string GetLastErrorAsString(DWORD errorCode)
{
    LPSTR       msgBuffer = nullptr;
    std::string msg("No Error");

    if (errorCode != 0)
    {
        size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER |
            FORMAT_MESSAGE_FROM_SYSTEM |
            FORMAT_MESSAGE_IGNORE_INSERTS,
            NULL,
            errorCode,
            MAKELANGID(LANG_NEUTRAL,
                SUBLANG_DEFAULT),
            (LPSTR)&msgBuffer,
            0,
            NULL);
        msg = std::string(msgBuffer, size);

        LocalFree(msgBuffer);
    }
    return msg;
}

void fatal(const char* error, const char* _where, SIZE_T errorCode)
{
    std::string errorMsg = GetLastErrorAsString(errorCode);
    std::string message;

    message.reserve(50UL);
    message  = std::format("Error: {}\n", error);
    message += std::format("Where: {}\n", _where);
    message += std::format("Reason: {}\n", errorMsg.c_str());

    MessageBox(NULL, message.c_str(), "Fatal Error", MB_OK | MB_ICONERROR);
}