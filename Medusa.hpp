//
// Created by Justin Lin on 2019-05-01.
//
/*********************************************************************
** Program name:  Medusa.hpp
** Author:        Justin Lin
** Date:          05/01/2019
** Description:   This is the header file for the Medusa class. It is
 *                a derived class of the Character class. Included are
 *                a constructor and destructor. The class also has
 *                override methods for attack, defend and getType.
 *                There are also private int constants for the Medusa's
 *                stats as well as a method 'glare' which is the Medusa
 *                class' special ability. There is also an override
 *                recover method that will restore strength to the
 *                Medusa based on her current str and max str.
*********************************************************************/
#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Character.hpp"

class Medusa : public Character {
private:
    const int MEDUSA_ATK = 6,
              MEDUSA_DEF = 6,
              MEDUSA_ARM = 3,
              MEDUSA_STR = 8,
              MEDUSA_ATK_DIE = 2,
              MEDUSA_DEF_DIE = 1;
public:
    Medusa();
    ~Medusa() {};
    void glare();
    int attack() override;
    void defend(int damage) override;
    std::string getType() override;
    void recover() override;
};


#endif //MEDUSA_HPP
