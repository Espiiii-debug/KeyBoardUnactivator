#ifndef H_HOOK_H
#define H_HOOK_H
#ifdef _WIN32
#include <windows.h>
#include <iostream>
#define KEYBOARD_HOOK_ERROR KeyBoardHook::keyBoardHookError
#define KEYBOARD_HOOK_START KeyBoardHook::keyBoardHookStart


namespace KeyBoardHook {

    int startHook();

    int stopHook();

    std::string getStringError();

    int cancelKeyHook(bool cancel);

    LRESULT CALLBACK keyboardHookReplacement(const int code, const WPARAM wParam, const LPARAM lParam);

    extern std::string keyBoardHookError;
    extern bool keyBoardHookStart;

}
#endif
#endif