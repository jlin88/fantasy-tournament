//
// Created by Justin Lin on 2019-05-18.
//

/*********************************************************************
** Program name:  FantasyGame.cpp
** Author:        Justin Lin
** Date:          05/18/2019
** Description:   This is the implementation file for the FantasyGame class.
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
#include "FantasyGame.hpp"
#include "integerValidation.hpp"
#include "inBounds.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;

FantasyGame::FantasyGame() {}

FantasyGame::~FantasyGame() {
    while (!team1.isEmpty()) {
        team1.removeFront();
    }
    while (!team2.isEmpty()) {
        team2.removeFront();
    }
    while (!losers.isEmpty()) {
        losers.removeFront();
    }
}

/*******************************************************************************
Name:         Justin Lin
Called by:    playTournament
Calls:        integerValidation, inBounds, printQueue, addFighter
Passed:       N/A
Returns:      N/A

Description:  This is a method to obtain validated user input and initialize
              the derived Characters for each team for the tournament game.
              The method prompts the user for input to set up each team
              getting the number of fighters, type of each fighter, and name
              of each fighter. Each team's final lineup will be printed
              displaying the type and name of each derived Character on each
              team.
*******************************************************************************/
void FantasyGame::setup() {
    int numFighters = 0,
        fighter = 0;

    //  Get number of fighters on each team
    cout << "How many fighters are on each team?\n"
            "Please enter an integer between 1 and 10" << endl;

    do {
        numFighters = integerValidation();
    } while (!inBounds(numFighters, 1, 10));

    //  Pick and set team 1's lineup
    cout << "Pick your lineup for Team 1" << endl;
    for (int i = 0; i < numFighters; i++) {
        cout << "Pick Fighter #" << i+1 << "\n"
                "1. Vampire\n"
                "2. Barbarian\n"
                "3. BlueMen\n"
                "4. Medusa\n"
                "5. Harry Potter" << endl;
        do {
            fighter = integerValidation();
        } while (!inBounds(fighter, 1, 5));

        addFighter(team1, fighter);
    }
    //  Display team1
    team1.printQueue();

    //  Pick and set team 2's lineup
    cout << "Pick your lineup for Team 2" << endl;
    for (int i = 0; i < numFighters; i++) {
        cout << "Pick Fighter #" << i+1 << "\n"
                "1. Vampire\n"
                "2. Barbarian\n"
                "3. BlueMen\n"
                "4. Medusa\n"
                "5. Harry Potter" << endl;

        do {
            fighter = integerValidation();
        } while (!inBounds(fighter, 1, 5));

        addFighter(team2, fighter);
    }

    //  Display team2
    team2.printQueue();
}

/*******************************************************************************
Name:         Justin Lin
Called by:    setup
Calls:        setName, addBack
Passed:       Queue by reference representing a team, int representing what
              type of fighter to add.
Returns:      N/A

Description:  This is a method to add fighters to the back of the Queue
              representing each team. The corresponding team is passed by
              reference as an argument, alongside an int representing which
              derived Character to add to the team. A switch statement will
              dynamically allocate the derived Character. The user is then
              prompted for a string input to name the Character. Lastly,
              the character will be added to the back of the team.
*******************************************************************************/
void FantasyGame::addFighter(Team &team, int choice) {
    Character *fighter = nullptr;
    string name = "";

    switch (choice) {
        case 1:
            fighter = new Vampire;
            break;
        case 2:
            fighter = new Barbarian;
            break;
        case 3:
            fighter = new BlueMen;
            break;
        case 4:
            fighter = new Medusa;
            break;
        case 5:
            fighter = new HarryPotter;
    }
    //  Set fighter's name and add to team
    cout << "What is the " << fighter->getType() << "'s name?" << endl;
    getline(cin, name);
    fighter->setName(name);
    team.addBack(fighter);
}

/*******************************************************************************
Name:         Justin Lin
Called by:    playTournament
Calls:        integerValidation, inBounds, printStack
Passed:       N/A
Returns:      N/A

Description:  This is a method to prompt the user if they want to see the loser
              stack. If the user selects to see the user stack, the printStack
              method from the Queue class will be called. This will print the
              losers in a stack-like method displaying the losers from tail
              to head.
*******************************************************************************/
void FantasyGame::loserMenu() {
    int choice = 0;

    cout << "Do you want to see the loser stack? \n"
            "1. Yes\n"
            "2. No" << endl;
    do {
        choice = integerValidation();
    } while (!inBounds(choice, 1, 2));

    if (choice == 1) {
        losers.printStack();
    }
}

/*******************************************************************************
Name:         Justin Lin
Called by:    playTournament
Calls:        isEmpty, getType, getName, getStrPts, attack, defend, recover,
              removeFront, addBack
Passed:       N/A
Returns:      N/A

Description:  This is a method to run the fighting and scoring portion of the
              tournament game. The method will run the battles between the
              two teams until one team is defeated. The head Nodes of each
              team will battle, with the loser being placed in the loser stack
              and the winner being sent to the back of the corresponding team's
              Queue. Every battle a team wins scores 1 point for the team
              which is kept track by the team1Score and team2Score counters.
              At the end, the final score will be displayed, alongside a
              message displaying which team won the tournament.
*******************************************************************************/
void FantasyGame::tournament() {
    int attack = 0,
        team1Score = 0,
        team2Score = 0,
        round = 1;

    //  While both teams have eligible fighters
    while (!team1.isEmpty() && !team2.isEmpty()) {
        cout << "*******************************\n"
             << "********** [Round " << round << "] **********\n"
             << "*******************************" << endl;

        round++;
        cout << team1.getFront()->getType() << team1.getFront()->getName()
             << " [vs] " << team2.getFront()->getType()
             << team2.getFront()->getName() << endl;

        //  Battle between two heads
        while (team1.getFront()->getStrPts() > 0
               && team2.getFront()->getStrPts() > 0) {

            //  Team 1 attacks and Team 2 defends
            attack = team1.getFront()->attack();
            team2.getFront()->defend(attack);

            //  Team 2 attacks and Team 1 defends
            if (team2.getFront()->getStrPts() != 0) {
                attack = team2.getFront()->attack();
                team1.getFront()->defend(attack);
            }
        }

        //  If team 2 wins the fight
        if (team1.getFront()->getStrPts() == 0) {
            cout << team2.getFront()->getType() << team2.getFront()->getName()
                 << " wins the battle!" << endl;

            //  Recover winner
            team2.getFront()->recover();

            //  Put winner to back of queue
            team2.addBack(team2.getFront());
            team2.moveFront();

            //  Put loser to loser stack
            losers.addBack(team1.getFront());
            team1.moveFront();

            //  Give winner a point
            team2Score++;

        //  If team 1 wins the fight
        } else if (team2.getFront()->getStrPts() == 0) {
            cout << team1.getFront()->getType() << team1.getFront()->getName()
                 << " wins the battle!" << endl;

            //  Recover winner
            team1.getFront()->recover();

            //  Put winner to back of queue
            team1.addBack(team1.getFront());
            team1.moveFront();

            //  Put loser to loser stack
            losers.addBack(team2.getFront());
            team2.moveFront();

            //  Give winner a point
            team1Score++;
        }
    }
    //  Display score
    cout << "The score is [Team 1]: " << team1Score << " [Team 2]: "
         << team2Score << endl;

    if (team1Score > team2Score) {
        cout << "[Team 1] wins the tournament!" << endl;
    } else {
        cout << "[Team 2] wins the tournament!" << endl;
    }
}

/*******************************************************************************
Name:         Justin Lin
Called by:    main
Calls:        integerValidation, inBounds, setup, tournament, loserMenu, ~Queue
Passed:       N/A
Returns:      N/A

Description:  This is a method to run the entire Fantasy Combat Tournament
              game. It calls the corresponding methods to simulate the
              tournament game. At the end, it will prompt the user if they
              want to play another game. If the user plays another game, the
              playTournament will call the destructor on each team, and the
              loser stack to deallocate the dynamic memory so the user
              can play a fresh game. This method will loop until the user
              decides to quit.
*******************************************************************************/
void FantasyGame::playTournament() {
    int choice = 0;
    bool quit = false;
    while (!quit) {

        setup();
        tournament();
        loserMenu();

        cout << "Do you want to play again? \n"
                "1. Yes\n"
                "2. No" << endl;

        do {
            choice = integerValidation();
        } while (!inBounds(choice, 1, 2));

        //  If user plays again, deallocate first round teams/losers
        if (choice == 1) {
            team1.~Team();
            team2.~Team();
            losers.~Team();

        //  Exit condition
        } else {
            quit = true;
        }
    }
}