#ifdef _WIN32
#include "KeyState.h"
#include <windows.h>
namespace KeyState {

    int getKeyState(int key) {
        return GetKeyState(key);
    }

    int getShiftActive() {
        return GetKeyState(VK_LSHIFT) < 0 || GetKeyState(VK_RSHIFT) < 0;
    }

    int getCapitalActive() {
        return (GetKeyState(VK_CAPITAL) & 1 ) == 1;
    }




}



#endif