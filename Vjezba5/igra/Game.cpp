#include <iostream>
#include "Game.h"

// definicije konstruktora i metode print

Game::Game(const std::string& title, const std::string& player_name) : title(title), player(player_name,level){

}
void Game::print() const
{
    std::cout << title << '\n';
    player.print();
}