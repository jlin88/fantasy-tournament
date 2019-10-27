//
// Created by Justin Lin on 2019-05-18.
//

/*********************************************************************
** Program name:  FantasyGame.hpp
** Author:        Justin Lin
** Date:          05/18/2019
** Description:   This is the header file for the FantasyGame class.
 *                The class will run the tournament between two teams
 *                using derived Characters as fighters for each team.
 *                The class contains three private member variables
 *                representing each team, and a pile for the losers
 *                of each battle. The class has methods to add a
 *                fighter to each team, a method to obtain validated
 *                user input to create each team, a method to run the
 *                battle/scoring portion of the tournament, a method
 *                to give the user an option to print the loser stack,
 *                and lastly a method to run the entire tournament game.
*********************************************************************/
#ifndef FANTASYGAME_HPP
#define FANTASYGAME_HPP

#include "Team.hpp"

class FantasyGame {
private:
    Team team1,
         team2,
         losers;

public:
    FantasyGame();
    ~FantasyGame();
    void setup();
    void addFighter(Team &team, int choice);
    void loserMenu();
    void tournament();
    void playTournament();
};


#endif //FANTASYGAME_HPP
