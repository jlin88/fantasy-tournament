//
// Created by Justin Lin on 2019-05-01.
//
/*********************************************************************
** Program name:  Medusa.cpp
** Author:        Justin Lin
** Date:          05/01/2019
** Description:   This is the implementation file for the Medusa class. It is
 *                a derived class of the Character class. Included are
 *                a constructor and destructor. The class also has
 *                override methods for attack, defend and getType.
 *                There are also private int constants for the Medusa's
 *                stats as well as a method 'glare' which is the Medusa
 *                class' special ability. There is also an override
 *                recover method that will restore strength to the
 *                Medusa based on her current str and max str.
*********************************************************************/
#include "Medusa.hpp"
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

Description:  This is the default constructor for the Medusa class. It
              initializes the member variables to the constants defined as
              private member variables.
*******************************************************************************/
Medusa::Medusa() {
    setAtkPts(MEDUSA_ATK);
    setDefPts(MEDUSA_DEF);
    setArmPts(MEDUSA_ARM);
    setStrPts(MEDUSA_STR);
    setAtkDie(MEDUSA_ATK_DIE);
    setDefDie(MEDUSA_DEF_DIE);
}

/*******************************************************************************
Name:         Justin Lin
Called by:    attack
Calls:        N/A
Passed:       N/A
Returns:      N/A

Description:  This is the special ability of the Medusa class. If Medusa rolls
              an attack of 12, glare is used to set attack to 100 for the
              attack instantly killing the other character.
*******************************************************************************/
void Medusa::glare() {
//    cout << "-=[Medusa used [glare]=-" << " ";
    setAtkPts(100);
}

/*******************************************************************************
Name:         Justin Lin
Called by:    tournament
Calls:        roll, getAtkDie, getAtkPts
Passed:       N/A
Returns:      int

Description:  This is the override attack method for the Medusa class. It
              uses the roll method in the base class to roll an attack for
              each of the attack die. Each of the rolls are printed as well
              as the total attack which is also returned. The method also
              checks if a total of 12 is rolled. When this occurs, the glare
              method is called to use Medusa's special ability. Medusa's
              attack points are reset at the end of the method.
*******************************************************************************/
int Medusa::attack() {
    int atkRoll = 0,
        totalRoll = 0;

    //  Roll attack die
    for (int i = 0; i < getAtkDie(); i++) {
        atkRoll = roll(1, getAtkPts());
//        cout << "[Atk Roll]: " << atkRoll << " ";
        totalRoll += atkRoll;
    }

    //  Check to use glare
    if (totalRoll == 12) {
        glare();
        totalRoll = getAtkPts();
    }

//    cout << "[Total Atk]: " << totalRoll << endl;

    //  Reset attack points back to normal
    setAtkPts(MEDUSA_ATK);
    return totalRoll;
}

/*******************************************************************************
Name:         Justin Lin
Called by:    tournament
Calls:        roll, getArmPts, getStrPts, getDefDie, getDefPts, setStrPts
Passed:       int
Returns:      N/A

Description:  This is the override defend method for the Medusa class.
              The method takes in an int as a parameter representing damage.
              The method prints out the armor and current strength of the
              Medusa before the attack. Then it will roll the defense
              die(s) to come up with a defense roll. Each roll is printed
              along with the total roll. The total defense roll and armor
              is subtracted from the damage damage passed in to see if
              any damage occurs. If the damage is higher than the
              defense calculation, it is subtracted from the Medusa's
              current life. The total damage taken is printed along with
              the resulting strength.
*******************************************************************************/
void Medusa::defend(int damage) {
    int defRoll = 0,
        totalRoll = 0,
        totalDmg = 0,
        life = 0;

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
    totalDmg = damage - totalRoll - getArmPts();

    // If damage is done, calculate new strength totals
    if (totalDmg > 0) {
        life = getStrPts() - totalDmg;
        if (life <= 0) {
            setStrPts(0);
        } else {
            setStrPts(life);
        }

    //  If no damage cannot break through defense, no damage taken
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
string Medusa::getType() {
    return "[Medusa] ";
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
void Medusa::recover() {
    setStrPts(getStrPts() + (MEDUSA_STR - getStrPts()) / 2);
}