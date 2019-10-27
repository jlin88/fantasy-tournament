//
// Created by Justin Lin on 2019-05-02.
//
/*********************************************************************
** Program name:  menu.cpp
** Author:        Justin Lin
** Date:          05/03/2019
** Description:   This is the implementation file for a menu function
 *                to test the Character class and derived characters.
 *                The menu first asks the user if they want to play.
 *                Then has the user select each of the characters
 *                for the two players. The characters will be
 *                dynamically allocated and will battle each other
 *                until one player wins. The menu will then ask the
 *                user if they want to play again.
*********************************************************************/
#include "menu.hpp"
#include "integerValidation.hpp"
#include "inBounds.hpp"
#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

void menu() {
    Character *p1;
    Character *p2;
    bool playAgain = true;
    int choice = 0,
        p1Char = 0,
        p2Char = 0,
        attack = 0;

    while (playAgain) {
        // Play menu
        cout << "Fantasy Combat Game\n"
                "Pick an option:\n"
                "1. Play game\n"
                "2. Quit" << endl;
        do {
            choice = integerValidation();
        } while (!inBounds(choice, 1, 2));

        if (choice == 1) {
            //  Pick Player 1's character
            cout << "Pick a character for Player 1\n"
                    "1. Vampire\n"
                    "2. Barbarian \n"
                    "3. Blue Men\n"
                    "4. Medusa\n"
                    "5. Harry Potter\n" << endl;
            do {
                p1Char = integerValidation();
            } while (!inBounds(p1Char, 1, 5));

            //  Dynamically create Player 1's character
            if (p1Char == 1) {
                p1 = new Vampire;
            } else if (p1Char == 2) {
                p1 = new Barbarian;
            } else if (p1Char == 3) {
                p1 = new BlueMen;
            } else if (p1Char == 4) {
                p1 = new Medusa;
            } else if (p1Char == 5) {
                p1 = new HarryPotter;
            }

            //  Pick Player 2's character
            cout << "Pick a character for Player 2\n"
                    "1. Vampire\n"
                    "2. Barbarian \n"
                    "3. Blue Men\n"
                    "4. Medusa\n"
                    "5. Harry Potter\n" << endl;
            do {
                p2Char = integerValidation();
            } while (!inBounds(p2Char, 1, 5));

            if (p2Char == 1) {
                p2 = new Vampire;
            } else if (p2Char == 2) {
                p2 = new Barbarian;
            } else if (p2Char == 3) {
                p2 = new BlueMen;
            } else if (p2Char == 4) {
                p2 = new Medusa;
            } else if (p2Char == 5) {
                p2 = new HarryPotter;
            }

            //  Battle the two players
            int count = 1;
            while (p1->getStrPts() > 0 && p2->getStrPts() > 0) {

                cout << "***** [ROUND " << count << "] *****" << endl;

                cout << "[Player [1]: " << p1->getType();
                attack = p1->attack();
                cout << "[Player [2]: " << p2->getType();
                p2->defend(attack);

                if (p2->getStrPts() != 0) {
                    cout << "[Player [2]: " << p2->getType();
                    attack = p2->attack();
                    cout << "[Player [1]: " << p1->getType();
                    p1->defend(attack);
                    count++;
                }
            }
            cout << "*********************" << endl;
            if (p1->getStrPts() == 0) {
                cout << "* [Player [2] wins! *" << endl;
            } else if (p2->getStrPts() == 0) {
                cout << "* [Player [1] wins! *" << endl;
            }
            cout << "*********************" << endl;

            //  Deallocate memory
            delete p1;
            delete p2;

        } else if (choice == 2) {
            playAgain = false;
        }
    }
}