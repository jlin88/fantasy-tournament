//
// Created by Justin Lin on 2019-05-02.
//
/*********************************************************************
** Program name:  HarryPotter.hpp
** Author:        Justin Lin
** Date:          05/01/2019
** Description:   This is the header file for the HarryPotter class. It is
 *                a derived class of the Character class. There is a bool
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

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Character.hpp"

class HarryPotter : public Character {
private:
    const int HP_ATK = 6,
              HP_DEF = 6,
              HP_ARM = 0,
              HP_STR = 10,
              HP_ATK_DIE = 2,
              HP_DEF_DIE = 2;

    bool usedHog;

public:
    HarryPotter();
    ~HarryPotter() {};
    void hogwarts();
    int attack() override;
    void defend(int damage) override;
    std::string getType() override;
    void recover() override;
};


#endif //HARRYPOTTER_HPP
