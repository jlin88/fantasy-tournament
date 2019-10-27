//
// Created by Justin Lin on 2019-05-01.
//
/*********************************************************************
** Program name:  Vampire.cpp
** Author:        Justin Lin
** Date:          05/23/2019
** Description:   This is the implementation file for the Vampire class.
 *                It is a derived class of the Character class. Included
 *                are a constructor and destructor. The class also has
 *                a method charm that acts as the Vampire's special
 *                ability, and override methods for attack, defend
 *                and getType. There are also private int constants for
 *                the vampire's stats. There is also an override for the
 *                recover method to restore hp if the Vampire wins a battle.
*********************************************************************/
#include "Vampire.hpp"
#include <random>
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

Description:  This is the default constructor for the Vampire class. It
              initializes the member variables to the constants defined as
              private member variables.
*******************************************************************************/
Vampire::Vampire() {
    setAtkPts(VAMP_ATK);
    setDefPts(VAMP_DEF);
    setArmPts(VAMP_ARM);
    setStrPts(VAMP_STR);
    setAtkDie(VAMP_ATK_DIE);
    setDefDie(VAMP_DEF_DIE);
}

/*******************************************************************************
Name:         Justin Lin
Called by:    defend
Calls:        roll
Passed:       N/A
Returns:      N/A

Description:  This is the special ability for the Vampire class. It calls the
              roll method to roll a number between 1 and 2. If a 1 is rolled,
              the ability activates.
*******************************************************************************/
bool Vampire::charm() {
    int num = 0;

    //  Rolls to see if charm happens
    num = roll(1,2);

    if (num == 1) {
        //cout << "Vampire used [charm]" << endl;
        return true;
    } else if (num == 2) {
        return false;
    }
}

/*******************************************************************************
Name:         Justin Lin
Called by:    tournament
Calls:        roll
Passed:       N/A
Returns:      int

Description:  This is the override attack method for the Vampire class. It
              uses the roll method in the base class to roll an attack for
              each of the attack die. Each of the rolls are printed as well
              as the total attack which is also returned.
*******************************************************************************/
int Vampire::attack() {

    int atkRoll = 0;

    //  Roll between 1 to attack points inclusive
    atkRoll = roll(1, getAtkPts());
//    cout << "[Atk Roll]: " << atkRoll << " ";
//    cout << "[Total Atk]: " << atkRoll << " " << endl;
    return atkRoll;
}

/*******************************************************************************
Name:         Justin Lin
Called by:    tournament
Calls:        roll, getArmPts, getStrPts, getDefDie, getDefPts, setStrPts, charm
Passed:       int
Returns:      N/A

Description:  This is the override defend method for the Vampire class.
              The method takes in an int as a parameter representing damage.
              The method prints out the armor and current strength of the
              Vampire before the attack. If the Vampire's special ability
              charm roll succeeds, it will skip the attack. Otherwise, the
              method will roll the defense die(s) to come up with a defense
              roll. Each roll is printed along with the total roll. The total
              defense roll and armor is subtracted from the damage damage
              passed in to see if any damage occurs. If the damage is higher
              than the defense calculation, it is subtracted from the Vampire's
              current life. The total damage taken is printed along with
              the resulting strength. At the end, the Vampire's defense is
              set back to normal.
*******************************************************************************/
void Vampire::defend(int damage) {
    int defRoll = 0,
        totalDmg = 0,
        life = 0;

    bool charmWorked = false;

    //  First roll charm to see if attack is negated
    charmWorked = charm();

    if (!charmWorked) {
        //  Print current stats
//        cout << "[Armor]: " << getArmPts() << " ";
//        cout << "[Current Str]: " << getStrPts() << " ";

        defRoll = roll(1, getDefPts());
//        cout << "[Def Roll]: " << defRoll << " ";
        totalDmg = damage - defRoll - getArmPts();

        //  If damage breaks through defense, calculate new strength
        if (totalDmg > 0) {
            life = getStrPts() - totalDmg;
            if (life <= 0) {
                setStrPts(0);
            } else {
                setStrPts(life);
            }
        //  If no damage is done, damage is zero
        } else {
            totalDmg = 0;
        }

//        cout << "[Total Def]: " << defRoll << " ";
//        cout << "[Total Dmg Taken]: " << totalDmg << " ";
//        cout << "[Str]: " << getStrPts() << endl;
    }
}

/*******************************************************************************
Name:         Justin Lin
Called by:    addFighter, tournament
Calls:        N/A
Passed:       N/A
Returns:      string

Description:  This is the override method for the getType method. It
              simply just returns a string with the name of the class.
*******************************************************************************/
string Vampire::getType() {
    return "[Vampire] ";
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
void Vampire::recover() {
    setStrPts(getStrPts() + (VAMP_STR - getStrPts())/2);
}