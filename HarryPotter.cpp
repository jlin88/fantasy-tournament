//
// Created by Justin Lin on 2019-05-02.
//
/*********************************************************************
** Program name:  HarryPotter.cpp
** Author:        Justin Lin
** Date:          05/01/2019
** Description:   This is the implementation file for the HarryPotter class.
 *                It is a derived class of the Character class. There is a bool
 *                member variable to keep track of the class' special ability.
 *                Included are a constructor and destructor. The class also has
 *                override methods for attack, defend and getType.
 *                There are also private int constants for the HarryPotter's
 *                stats as well as a method 'hogwarts' which is HarryPotter's
 *                special ability. There is also an override recover method
 *                that will restore strength to HarryPotter based on his
 *                current strength and max strength and also whether or not
 *                his Hogwarts ability has been used
*********************************************************************/
#include "HarryPotter.hpp"
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
              private member variables. The unique member variable to this
              class usedHog is set to false.
*******************************************************************************/
HarryPotter::HarryPotter() {
    setAtkPts(HP_ATK);
    setDefPts(HP_DEF);
    setArmPts(HP_ARM);
    setStrPts(HP_STR);
    setAtkDie(HP_ATK_DIE);
    setDefDie(HP_DEF_DIE);
    usedHog = false;
}

/*******************************************************************************
Name:         Justin Lin
Called by:    defend
Calls:        N/A
Passed:       N/A
Returns:      N/A

Description:  This is the special ability for the HarryPotter class. It will
              bring HarryPotter back to life with 20 strength the first time
              he 'dies'. When called, it will switch the usedHog variable to
              true indicating that the ability can only be used once a fight.
*******************************************************************************/
void HarryPotter::hogwarts() {
//    cout << "Harry Potter used [Hogwarts]!" << endl;
    setStrPts(20);
    usedHog = true;
}

/*******************************************************************************
Name:         Justin Lin
Called by:    tournament
Calls:        roll, getAtkDie, getAtkPts
Passed:       N/A
Returns:      int

Description:  This is the override attack method for the HarryPotter class. It
              uses the roll method in the base class to roll an attack for
              each of the attack die. Each of the rolls are printed as well
              as the total attack which is also returned.
*******************************************************************************/
int HarryPotter::attack() {
    int atkRoll = 0,
        totalRoll = 0;

    //  Roll attack die
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
Calls:        roll, getArmPts, getStrPts, getDefDie, getDefPts, setStrPts
Passed:       int
Returns:      N/A

Description:  This is the override defend method for the HarryPotter class.
              The method takes in an int as a parameter representing damage.
              The method prints out the armor and current strength of the
              HarryPotter before the attack. Then it will roll the defense
              die(s) to come up with a defense roll. Each roll is printed
              along with the total roll. The total defense roll and armor
              is subtracted from the damage damage passed in to see if
              any damage occurs. If the damage is higher than the
              defense calculation, it is subtracted from the HarryPotter's
              current life. The method will also check if HarryPotter has
              used his special ability hogwarts yet. If the ability has not
              been used and HarryPotter 'dies', he will come back to life
              with 20 strength. Lastly, the total damage taken is printed along
              with the resulting strength.
*******************************************************************************/
void HarryPotter::defend(int damage) {
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

    //  Calculate if attack breaks defense
    totalDmg = damage - totalRoll - getArmPts();

    //  Adjusts life by damage taken
    if (totalDmg > 0) {
        life = getStrPts() - totalDmg;
        //  If hogwarts already used, and life hits 0 harry potter dies
        if ((life <= 0) && (usedHog == true)) {
            setStrPts(0);

        //  Uses hogwarts if strength hits 0, and hasn't used hogwarts yet
        } else if (life <= 0) {
            hogwarts();

        //  Sets strength to account for damage taken
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
Called by:    tournament, addFighter
Calls:        N/A
Passed:       N/A
Returns:      string

Description:  This is the override defend method for the getType method. It
              simply just returns a string with the name of the class.
*******************************************************************************/
string HarryPotter::getType() {
    return "[Harry Potter] ";
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
              character for 10 str and set the str to 90. The max strength
              for HarryPotter depends on whether or not Hogwarts has been used.
              If Hogwarts has been used max strength is 20, otherwise it is 10.
              Integer rounding will occur if the formula is a fraction.
*******************************************************************************/
void HarryPotter::recover() {
    if (usedHog) {
        setStrPts(getStrPts() + (20 - getStrPts()) / 2);
    } else {
        setStrPts(getStrPts() + (HP_STR - getStrPts()) / 2);
    }
}
