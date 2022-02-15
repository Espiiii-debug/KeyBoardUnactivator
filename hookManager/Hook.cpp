//
// Created by Espiiii on 28/10/2021.
//

#ifdef _WIN32
#include "Hook.h"
#include <windows.h>
#include <iostream>
#include <errno.h>

HHOOK hHook = { NULL };

std::string KeyBoardHook::keyBoardHookError = "";
bool KeyBoardHook::keyBoardHookStart = false;

int KeyBoardHook::startHook() {
    hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyBoardHook::keyboardHookReplacement, NULL, 0);

    if(hHook == NULL){
        KeyBoardHook::keyBoardHookError = "Can't create hook";
        std::cout << errno;
        return -1;
    } else {
        KEYBOARD_HOOK_START = true;
        return 0;
    }
}

int KeyBoardHook::stopHook() {
    if(KEYBOARD_HOOK_START == false) {
        KEYBOARD_HOOK_ERROR = "Can't stop an non-started process";
        return -1;
    }else {

        int unHook = UnhookWindowsHookEx(hHook);
        if (unHook != 0) {
            KEYBOARD_HOOK_START = false;
            return 0;

        } else {
            KEYBOARD_HOOK_ERROR = "Can't stop hook : ";
            return -1;
        }
    }
}

int KeyBoardHook::cancelKeyHook(bool cancel) {

    return 0;
}

std::string KeyBoardHook::getStringError() {

    if(KEYBOARD_HOOK_ERROR == ""){
        return NULL;
    } else {
        return KEYBOARD_HOOK_ERROR;
    }
}

LRESULT CALLBACK KeyBoardHook::keyboardHookReplacement(const int code, const WPARAM wParam, const LPARAM lParam) {
    KBDLLHOOKSTRUCT *p = (KBDLLHOOKSTRUCT *) lParam;
    switch(p->vkCode) {
        case(VK_LWIN) :
            return 1;
    }

    return CallNextHookEx(hHook, code, wParam, lParam);
}



#endif