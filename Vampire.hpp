//
// Created by Justin Lin on 2019-05-01.
//
/*********************************************************************
** Program name:  Vampire.hpp
** Author:        Justin Lin
** Date:          05/23/2019
** Description:   This is the header file for the Vampire class.
 *                It is a derived class of the Character class. Included
 *                are a constructor and destructor. The class also has
 *                a method charm that acts as the Vampire's special
 *                ability, and override methods for attack, defend
 *                and getType. There are also private int constants for
 *                the vampire's stats. There is also an override for the
 *                recover method to restore hp if the Vampire wins a battle.
*********************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Character.hpp"

class Vampire : public Character {
private:
    const int VAMP_ATK = 12,
              VAMP_DEF = 6,
              VAMP_ARM = 1,
              VAMP_STR = 18,
              VAMP_ATK_DIE = 1,
              VAMP_DEF_DIE = 1,
              CHARM = 100;

public:
    Vampire();
    ~Vampire() {};
    bool charm();
    int attack() override;
    void defend(int damage) override;
    std::string getType() override;
    void recover() override;
};


#endif //VAMPIRE_HPP
