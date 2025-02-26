#include <iostream>
#include "Game1.h"

using namespace std;
using namespace sf;

int main() {
    srand(static_cast<unsigned>(time(NULL)));

    // Game Engine ///
    Game1 game;
   

    // Game Loop
    while (game.running()) {

        //update
        game.update();

        //render
        game.render();

    }

    return 0;
}
