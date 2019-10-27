//
// Created by Justin Lin on 2019-05-01.
//
/*********************************************************************
** Program name:  BlueMen.hpp
** Author:        Justin Lin
** Date:          05/01/2019
** Description:   This is the header file for the BlueMen class. It is
 *                a derived class of the Character class. Included are
 *                a constructor and destructor. The class also has
 *                override methods for attack, defend and getType.
 *                There are also private int constants for the BlueMen's
 *                stats as well as a method 'mob' which is the BlueMen's
 *                special ability. There is also a override recover
 *                method that will restore str to the BlueMen if they
 *                win a battle based on their current str and their
 *                max str.
*********************************************************************/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Character.hpp"

class BlueMen : public Character {
private:
    const int BLUE_MEN_ATK = 10,
              BLUE_MEN_DEF = 6,
              BLUE_MEN_ARM = 3,
              BLUE_MEN_STR = 12,
              BLUE_MEN_ATK_DIE = 2,
              BLUE_MEN_DEF_DIE = 3;
public:
    BlueMen();
    ~BlueMen() {};
    void mob();
    int attack() override;
    void defend(int damage) override;
    std::string getType() override;
    void recover() override;
};


#endif //BLUEMEN_HPP
