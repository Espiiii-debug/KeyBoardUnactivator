#include <iostream>
#include <windows.h>
#include "keyStateManager/KeyState.h"
#include "hookManager/Hook.h"
#include <thread>

void asyncTask() {
    if (KeyBoardHook::startHook() != 0) {
        std::cout << KEYBOARD_HOOK_ERROR << std::endl;
    }
    while (GetMessage(NULL, NULL, 0, 0));

}


int main() {
    short prev_touch = 0, curr_touch = 0;
#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
    while (true) {
        if (GetAsyncKeyState(VK_END))
            curr_touch = 1;
        else
            curr_touch = 0;
        if (prev_touch != curr_touch) {
            if (!prev_touch) {
                std::thread thrd(asyncTask);
                std::this_thread::sleep_for(std::chrono::seconds(30));
                KeyBoardHook::stopHook();
                thrd.detach();

            }
            prev_touch = curr_touch;
        }
    }
#pragma clang diagnostic pop

    return 0;
}
