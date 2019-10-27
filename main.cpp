/*********************************************************************
** Program name:  main.cpp
** Author:        Justin Lin
** Date:          05/01/2019
** Description:   This is main file for Project 4. It simply creates
 *                a FantasyGame object and calls the playTournament
 *                method to run the tournament game.
*********************************************************************/

#include <iostream>
#include "Character.hpp"
#include "Vampire.hpp"
#include "menu.hpp"
#include "Team.hpp"
#include "Barbarian.hpp"
#include "FantasyGame.hpp"

int main() {

    FantasyGame game;
    game.playTournament();

    return 0;
}