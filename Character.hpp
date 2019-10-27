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
 *                of the type each derived class. There are three
 *                pure virtual methods attack, defend, and recover that make
 *                the character class an abstract class. These are
 *                overridden in the derived classes.
*********************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <random>

class Character {
private:
    int atkPts,
        defPts,
        armPts,
        strPts,
        numAtkDie,
        numDefDie;

    std::string name;

public:
    //  Constructor/Destructor
    Character();
    virtual ~Character() {};

    //  Setters/Getters
    void setAtkPts(int attackPoints);
    int getAtkPts();

    void setDefPts(int defensePoints);
    int getDefPts();

    void setArmPts(int armorPoints);
    int getArmPts();

    void setStrPts(int strengthPoints);
    int getStrPts();

    void setAtkDie(int numDie);
    int getAtkDie();

    void setDefDie(int numDie);
    int getDefDie();

    void setName(std::string name);
    std::string getName();


    //  Rolling helper method
    int roll(int minRoll, int maxRoll);

    //  Pure virtual methods
    virtual std::string getType() = 0;
    virtual int attack() = 0;
    virtual void defend(int damage) = 0;
    virtual void recover() = 0;
};


#endif //CHARACTER_HPP
