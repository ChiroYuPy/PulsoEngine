#include "MyGame.h"

int main() {
    AudioManager::get();
    WMGame game;
    game.start();
    return 0;
}