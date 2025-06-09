#pragma once
#include "MusicPlayer.h"
#include "MusicPlayerUI.h"

class Controller {
private:
    MusicPlayer player;
    MusicPlayerUI ui;
public:
    void iniciarConInterfaz();
};
