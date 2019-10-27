//
// Created by Justin Lin on 2019-05-01.
//

/*********************************************************************
** Program name:  Barbarian.cpp
** Author:        Justin Lin
** Date:          05/23/2019
** Description:   This is the implementation file for the Barbarian class. It is
 *                a derived class of the Character class. Included are
 *                a constructor and destructor. The class also has
 *                override methods for attack, defend and getType.
 *                There are also private int constants for the Barbarian's
 *                stats. There is also an override for the recover method
 *                that restores str based on the Barbarian's max str
 *                and current str.
*********************************************************************/
#include "Barbarian.hpp"
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

Description:  This is the default constructor for the Barbarian class. It
              initializes the member variables to the constants defined as
              private member variables.
*******************************************************************************/
Barbarian::Barbarian() {
    setAtkPts(BARB_ATK);
    setDefPts(BARB_DEF);
    setArmPts(BARB_ARM);
    setStrPts(BARB_STR);
    setAtkDie(BARB_ATK_DIE);
    setDefDie(BARB_DEF_DIE);
}

/*******************************************************************************
Name:         Justin Lin
Called by:    tournament
Calls:        roll, getAtkDie, getAtkPts
Passed:       N/A
Returns:      int

Description:  This is the override attack method for the Barbarian class. It
              uses the roll method in the base class to roll an attack for
              each of the attack die. Each of the rolls are printed as well
              as the total attack which is also returned.
*******************************************************************************/
int Barbarian::attack() {
    int atkRoll = 0,
        totalRoll = 0;

    //  Roll once per each attack die
    for (int i = 0; i < getAtkDie(); i++) {
        atkRoll = roll(1, getAtkPts());
        //cout << "[Atk Roll]: " << atkRoll << " ";
        totalRoll += atkRoll;
    }
    //cout << "[Total Atk]: " << totalRoll << endl;
    return totalRoll;
}

/*******************************************************************************
Name:         Justin Lin
Called by:    tournament
Calls:        roll, getArmPts, getStrPts, getDefDie, getDefPts, setStrPts
Passed:       int
Returns:      N/A

Description:  This is the override defend method for the Barbarian class.
              The method takes in an int as a parameter representing damage.
              The method prints out the armor and current strength of the
              Barbarian before the attack. Then it will roll the defense
              die(s) to come up with a defense roll. Each roll is printed
              along with the total roll. The total defense roll and armor
              is subtracted from the damage damage passed in to see if
              any damage occurs. If the damage is higher than the
              defense calculation, it is subtracted from the Barbarian's
              current life. The total damage taken is printed along with
              the resulting strength.
*******************************************************************************/
void Barbarian::defend(int damage) {
    int defRoll = 0,
        totalRoll = 0,
        totalDmg = 0,
        life = 0;

//    cout << "[Armor]: " << getArmPts() << " ";
//    cout << "[Current Str]: " << getStrPts() << " ";

    //  Roll once for each defense die
    for (int i = 0; i < getDefDie(); i++) {
        defRoll = roll(1, getDefPts());
//        cout << "[Def Roll]: " << defRoll << " ";
        totalRoll += defRoll;
    }
//    cout << "[Total Def Rolls]: " << totalRoll << " ";
    totalDmg = damage - totalRoll - getArmPts();

    //  Calculates strength if damage is taken
    if (totalDmg > 0) {
        life = getStrPts() - totalDmg;
        if (life <= 0) {
            setStrPts(0);
        } else {
            setStrPts(life);
        }
    //  If attack doesn't break through defense, no damage taken
    } else {
        totalDmg = 0;
    }
//    cout << "[Total Dmg Taken]: " << totalDmg << " ";
//    cout << "[Str]: " << getStrPts() << endl;
}
/*******************************************************************************
Name:         Justin Lin
Called by:    addFighter, tournament
Calls:        N/A
Passed:       N/A
Returns:      string

Description:  This is the override defend method for the getType method. It
              simply just returns a string with the name of the class.
*******************************************************************************/
string Barbarian::getType() {
    return "[Barbarian] ";
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
void Barbarian::recover() {
    setStrPts(getStrPts() + (BARB_STR - getStrPts()) / 2);
}