#include <iostream>
#include <cmath>

#include "Game.hpp"

int main(int argc, char* argv[])
{
    Game game("Game of Life", 1280, 720);
    game.run();
}
