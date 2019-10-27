//
// Created by Justin Lin on 2019-05-01.
//
/*********************************************************************
** Program name:  BlueMen.cpp
** Author:        Justin Lin
** Date:          05/01/2019
** Description:   This is the implementation file for the BlueMen class.
 *                It is a derived class of the Character class. Included
 *                are a constructor and destructor. The class also has
 *                override methods for attack, defend and getType.
 *                There are also private int constants for the BlueMen's
 *                stats as well as a method 'mob' which is the BlueMen's
 *                special ability. There is also a override recover
 *                method that will restore str to the BlueMen if they
 *                win a battle based on their current str and their
 *                max str.
*********************************************************************/
#include "BlueMen.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

/*******************************************************************************
Name:         Justin Lin
Called by:    N/A
Calls:        setAtkPts, setDefPts, setArmPts, setStrPts, setAtkDie, setDefDie
Passed:       N/A
Returns:      N/A

Description:  This is the default constructor for the BlueMen class. It
              initializes the member variables to the constants defined as
              private member variables.
*******************************************************************************/
BlueMen::BlueMen() {
    setAtkPts(BLUE_MEN_ATK);
    setDefPts(BLUE_MEN_DEF);
    setArmPts(BLUE_MEN_ARM);
    setStrPts(BLUE_MEN_STR);
    setAtkDie(BLUE_MEN_ATK_DIE);
    setDefDie(BLUE_MEN_DEF_DIE);
}

/*******************************************************************************
Name:         Justin Lin
Called by:    defend
Calls:        N/A
Passed:       N/A
Returns:      N/A

Description:  This is the special ability for the BlueMen class. It will
              change the number of defense die the BlueMen get to roll when
              defending an attack based on the amount of strength they
              have left.
*******************************************************************************/
void BlueMen::mob() {
    if (getStrPts() <= 12) {
        setDefDie(3);
    }
    if (getStrPts() <= 8) {
        setDefDie(2);
    }
    if (getStrPts() <= 4) {
        setDefDie(1);
    }
}

/*******************************************************************************
Name:         Justin Lin
Called by:    tournament
Calls:        roll, getAtkDie, getAtkPts
Passed:       N/A
Returns:      int

Description:  This is the override attack method for the BlueMen class. It
              uses the roll method in the base class to roll an attack for
              each of the attack die. Each of the rolls are printed as well
              as the total attack which is also returned.
*******************************************************************************/
int BlueMen::attack() {
    int atkRoll = 0,
        totalRoll = 0;

    for (int i = 0; i < getAtkDie(); i++) {
        atkRoll = roll(1, getAtkPts());
//        cout << "[Atk Roll]: " << atkRoll << " ";
        totalRoll += atkRoll;
    }
//    cout << "[Total Atk]: " << totalRoll << endl;
    return totalRoll;
}

/*******************************************************************************
Name:         Justin Lin
Called by:    tournament
Calls:        roll, getArmPts, getStrPts, getDefDie, getDefPts, setStrPts, mob
Passed:       int
Returns:      N/A

Description:  This is the override defend method for the BlueMen class.
              The method takes in an int as a parameter representing damage.
              First, the mob method is called to see how many defense die
              the BlueMen class will have. The method prints out the armor
              and current strength of the BlueMen before the attack. Then it
              will roll the defense die(s) to come up with a defense roll.
              Each roll is printed along with the total roll. The total
              defense roll and armor is subtracted from the damage damage
              passed in to see if any damage occurs. If the damage is higher
              than the defense calculation, it is subtracted from the BlueMen's
              current life. The total damage taken is printed along with
              the resulting strength.
*******************************************************************************/
void BlueMen::defend(int damage) {
    int defRoll = 0,
            totalRoll = 0,
            totalDmg = 0,
            life = 0;

    //  Use special ability first to set correct number of defense die
    mob();

    //  Print current stats
//    cout << "[Armor]: " << getArmPts() << " ";
//    cout << "[Current Str]: " << getStrPts() << " ";

    //  Roll defense die
    for (int i = 0; i < getDefDie(); i++) {
        defRoll = roll(1, getDefPts());
//        cout << "[Def Roll]: " << defRoll << " ";
        totalRoll += defRoll;
    }
//    cout << "[Total Def]: " << totalRoll << " ";

    //  Calculate if damage breaks through defense
    totalDmg = damage - totalRoll - getArmPts();

    //  Only adjust health if damage is dealt
    if (totalDmg > 0) {
        life = getStrPts() - totalDmg;
        if (life <= 0) {
            setStrPts(0);
        } else {
            setStrPts(life);
        }
    //  If defense holds, no damage dealt
    } else {
        totalDmg = 0;
    }

//    cout << "[Total Dmg Taken]: " << totalDmg << " ";
//    cout << "[Str]: " << getStrPts() << endl;
}

/*******************************************************************************
Name:         Justin Lin
Called by:    tournament, addFighter
Calls:        N/A
Passed:       N/A
Returns:      string

Description:  This is the override defend method for the getType method. It
              simply just returns a string with the name of the class.
*******************************************************************************/
string BlueMen::getType() {
    return "[Blue Men] ";
}

/*******************************************************************************
Name:         Justin Lin
Called by:    tournament
Calls:        N/A
Passed:       N/A
Returns:      N/A

Description:  This is the override method for the recover method. It will
              recover (heal) the character by 50% of the hp the character is
              currently missing. For example, if a character has a max of
              100 str and is currently at 80 str, the method will heal the
              character for 10 str and set the str to 90. Integer rounding
              will occur if the formula is a fraction.
*******************************************************************************/
void BlueMen::recover() {
    setStrPts(getStrPts() + (BLUE_MEN_STR - getStrPts()) / 2);
}