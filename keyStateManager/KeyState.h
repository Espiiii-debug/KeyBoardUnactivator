//
// Created by Espiiii on 28/10/2021.
//

#ifndef KEYBOARDHOOK_KEYSTATE_H
#define KEYBOARDHOOK_KEYSTATE_H
#ifdef _WIN32
namespace KeyState {

    int getKeyState(int key);

    int getShiftActive();

    int getCapitalActive();

}

#endif
#endif //KEYBOARDHOOK_KEYSTATE_H
