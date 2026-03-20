//
// Created by gaagaagi on 2026-03-20.
//

#ifndef ORBITAL_MECHANICS_MENU_STATE_H
#define ORBITAL_MECHANICS_MENU_STATE_H

#include "app_state.h"

class MenuState : public AppState {
public:
    void handle_input() override;
    void update() override;
    void draw() override;
    void onEnter() override;
    void onExit() override;

    MenuState(AppContext context);

};


#endif //ORBITAL_MECHANICS_MENU_STATE_H