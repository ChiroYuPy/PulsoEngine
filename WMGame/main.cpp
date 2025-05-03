#include "MyGame.h"

int main() {
    AudioManager::get(); // to remove later
    auto game = std::make_shared<WMGame>();
    game->start();
    return 0;
}