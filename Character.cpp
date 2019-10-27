//
// Created by Justin Lin on 2019-05-01.
//
/*********************************************************************
** Program name:  Character.hpp
** Author:        Justin Lin
** Date:          05/01/2019
** Description:   This is the header file for the Character class. It
 *                is an abstract class that will serve as the base
 *                class for each of the derived characters. There are
 *                7 integer member variables representing the character's
 *                attack points, defense points, armor points, strength
 *                points, number of attack die, and number of defense
 *                die, and name of Character. There is a default constructor
 *                that will initialize all member variables to zero, as well
 *                as a default destructor. There are setters/getters for each
 *                of the member variables. There is a roll method that
 *                takes two ints and rolls a number in that range. There
 *                is a virtual getType method which will return a string
 *                of the type each derived class. Lastly, there are two
 *                pure virtual methods attack and defend that make the
 *                character class an abstract class. These are
 *                overridden in the derived classes.
*********************************************************************/

#include "Character.hpp"
#include <string>
using std::string;

/*******************************************************************************
Name:         Justin Lin
Called by:    N/A
Calls:        N/A
Passed:       N/A
Returns:      N/A

Description:  This is the default constructor for the Character base class. It
              sets all member variables to 0.
*******************************************************************************/
Character::Character()
    : atkPts(0), defPts(0), armPts(0), strPts(0),
      numAtkDie(0), numDefDie(0) {}

//  Setter for atkPts
void Character::setAtkPts(int attackPoints){
    this->atkPts = attackPoints;
}

//  Getter for atkPts
int Character::getAtkPts() {
    return atkPts;
}

//  Setter for defPts
void Character::setDefPts(int defensePoints){
    this->defPts = defensePoints;
}

//  Getter for defPts
int Character::getDefPts(){
    return defPts;
}

//  Setter for armPts
void Character::setArmPts(int armorPoints){
    this->armPts = armorPoints;
}

//  Getter for armPts
int Character::getArmPts(){
    return armPts;
}

//  Setter for strPts
void Character::setStrPts(int strengthPoints){
    this->strPts = strengthPoints;
}

//  Getter for strPts
int Character::getStrPts(){
    return strPts;
}

//  Setter for numAtkDie
void Character::setAtkDie(int numDie) {
    this->numAtkDie = numDie;
}

//  Getter for numAtkDie
int Character::getAtkDie() {
    return numAtkDie;
}

//  Setter for numDefDie
void Character::setDefDie(int numDie) {
    this->numDefDie = numDie;
}

//  Getter for numDefDie
int Character::getDefDie() {
    return numDefDie;
}

//  Setter for name
void Character::setName(std::string name) {
    this->name = name;
}

//  Getter for name
string Character::getName() {
    return name;
}

/*******************************************************************************
Name:         Justin Lin
Called by:    attack, defend, charm
Calls:        N/A
Passed:       int, int
Returns:      N/A

Description:  This is the roll helper method that is used for all 'random'
              events such as die rolls or ability activations. It uses the
              random_device to generate a random number which is passed to the
              Mersenne-Twister engine to generate a pseudo-random number.
              This number is then passed into the dist object to roll a
              number between minRoll and maxRoll inclusive.
*******************************************************************************/
int Character::roll(int minRoll, int maxRoll) {
    std::random_device randomNum;
    std::mt19937 rng(randomNum());
    std::uniform_int_distribution<int> dist(minRoll, maxRoll);
    return dist(rng);
}