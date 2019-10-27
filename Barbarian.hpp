//
// Created by Justin Lin on 2019-05-01.
//
/*********************************************************************
** Program name:  Barbarian.hpp
** Author:        Justin Lin
** Date:          05/23/2019
** Description:   This is the header file for the Barbarian class. It is
 *                a derived class of the Character class. Included are
 *                a constructor and destructor. The class also has
 *                override methods for attack, defend and getType.
 *                There are also private int constants for the Barbarian's
 *                stats. There is also an override for the recover method
 *                that restores str based on the Barbarian's max str
 *                and current str.
*********************************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"

class Barbarian : public Character {
private:
    const int BARB_ATK = 6,
              BARB_DEF = 6,
              BARB_ARM = 0,
              BARB_STR = 12,
              BARB_ATK_DIE = 2,
              BARB_DEF_DIE = 2;
public:
    Barbarian();
    ~Barbarian() {};
    int attack() override;
    void defend(int damage) override;
    std::string getType() override;
    void recover() override;
};


#endif //BARBARIAN_HPP
