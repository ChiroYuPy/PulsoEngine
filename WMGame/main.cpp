#include "MyGame.h"

int main() {
    AudioManager::get();
    MyGame game;
    game.start();
    return 0;
}