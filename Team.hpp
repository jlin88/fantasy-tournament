//
// Created by Justin Lin on 2019-05-13.
//

/*********************************************************************
** Program name:  Team.hpp
** Author:        Justin Lin
** Date:          05/18/2019
** Description:   This is the header file for the Team class.
 *                The class utilizes a circular doubly linked list to
 *                create a Queue/Stack data structure. The class contains
 *                a struct named CharNode, and a pointer to CharNode
 *                representing the front of the Queue/Stack as private member
 *                variables. The CharNode struct contains an a pointer to
 *                a Character representing a Node, and two pointers to
 *                QueueNode representing the next/prev links in a doubly
 *                linked list. The class has a ctor/dtor to initialize
 *                and deallocate dynamically allocated memory. There are
 *                also methods to check if the Queue/Stack is empty, a method
 *                to add a Node to the back of the Queue/Stack, a method to
 *                get the value at the 'head' of the queue/stack, a method to
 *                remove the head of the queue (dequeue) and lastly, a
 *                method to print the values of each node in the Queue.
 *                Lastly, there is a method to print the linked list
 *                from tail to head making the abstract data structure
 *                a stack.
*********************************************************************/
#ifndef TEAM_HPP
#define TEAM_HPP


#include "Character.hpp"

class Team {
private:
    struct CharNode {
        Character *fighter;
        CharNode *next,
                 *prev;

        CharNode(Character *hero) {
            fighter = hero;
            next = nullptr;
            prev = nullptr;
        }
    };

    CharNode *head;

public:
    //  Ctor/Dtor
    Team();
    ~Team();

    bool isEmpty();
    void addBack(Character *hero);
    Character* getFront();
    void removeFront();
    void printQueue();
    void printStack();
    void moveFront();
};


#endif //TEAM_HPP
