//
// Created by Justin Lin on 2019-05-13.
//

/*********************************************************************
** Program name:  Team.cpp
** Author:        Justin Lin
** Date:          05/18/2019
** Description:   This is the implementation file for the Team class.
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
#include "Team.hpp"
#include <iostream>
using std::cout;
using std::endl;

/*******************************************************************************
Name:         Justin Lin
Called by:    N/A
Calls:        N/A
Passed:       N/A
Returns:      N/A

Description:  This is the default constructor for the Queue class. It simply
              initializes the head pointer to nullptr.
*******************************************************************************/
Team::Team() : head(nullptr) {}

/*******************************************************************************
Name:         Justin Lin
Called by:    N/A
Calls:        removeFront
Passed:       N/A
Returns:      N/A

Description:  This is the default deconstructor for the Queue class. It uses
              the removeFront method until the queue is empty to deallocate
              the dynamic memory used.
*******************************************************************************/
Team::~Team() {
    while (!isEmpty()) {
        removeFront();
    }
}

/*******************************************************************************
Name:         Justin Lin
Called by:    tournament, addBack, getFront, removeFront, printQueue
Calls:        N/A
Passed:       N/A
Returns:      bool

Description:  This is a bool method that will return true if the queue is
              empty, and false if there is a node in the queue.
*******************************************************************************/
bool Team::isEmpty() {
    if (head == nullptr) {
        return true;
    } else {
        return false;
    }
}

/*******************************************************************************
Name:         Justin Lin
Called by:    addFighter
Calls:        isEmpty
Passed:       pointer to Character
Returns:      N/A

Description:  This method adds a dynamically allocated node to the end of the
              queue. If the queue is empty, it will set the new Node as the
              head of the queue and the next/prev links to point to itself.
              Otherwise, the method will add a new node to the end of the
              queue and set the links accordingly.
*******************************************************************************/
void Team::addBack(Character *hero) {
    //  If Queue is empty create new head
    if (isEmpty()) {
         head = new CharNode(hero);

         //  Set links
         head->next = head->prev = head;
    } else {
        //  Set temp node to last node
        CharNode *temp = head->prev;

        //  Link last node to new node
        temp->next = new CharNode(hero);

        //  Set temp to new node
        temp = temp->next;

        //  Link new node
        temp->prev = head->prev;
        temp->next = head;
        head->prev = temp;
    }
}

/*******************************************************************************
Name:         Justin Lin
Called by:    tournament
Calls:        isEmpty
Passed:       N/A
Returns:      pointer to Character

Description:  This method simply returns the value of the head Node.
*******************************************************************************/
Character* Team::getFront() {
    if (!isEmpty()) {
        return head->fighter;
    }
}

/*******************************************************************************
Name:         Justin Lin
Called by:    setup
Calls:        N/A
Passed:       N/A
Returns:      N/A

Description:  This method will print the type and name of each Node in the
              queue from front to back. If the list is empty, an error message
              will be printed instead. This will simulate an abstract Queue
              data structure.
*******************************************************************************/
void Team::printQueue() {

    //  Start at head
    CharNode *temp = head;
    cout << "[Queue]: ";

    //  Loop through until last in queue and print each type/name
    while (temp->next != head) {
        cout << temp->fighter->getType() << temp->fighter->getName()
             << " ";
        temp = temp->next;
    }

    //  Print last value
    cout << temp->fighter->getType() << temp->fighter->getName() << endl;
}

/*******************************************************************************
Name:         Justin Lin
Called by:    loserMenu
Calls:        getType, getName
Passed:       N/A
Returns:      N/A

Description:  This method will print the type and name of each Node in the
              queue from back to front. If the list is empty, an error message
              will be printed instead. This will simulate an abstract stack
              data structure.
*******************************************************************************/
void Team::printStack() {
    //  Start at back of Stack
    CharNode *temp = head->prev;
    cout << "[Stack]: ";

    //  Loop through until first in stack and print each type/name
    while (temp->prev != head->prev) {
        cout << temp->fighter->getType() << temp->fighter->getName()
             << " ";
        temp = temp->prev;
    }

    //  Print last (head) value
    cout << temp->fighter->getType() << temp->fighter->getName() << endl;
}

/*******************************************************************************
Name:         Justin Lin
Called by:    dtor
Calls:        isEmpty
Passed:       N/A
Returns:      N/A

Description:  This method deletes (deallocates) the Node that is currently at
              the front of the Queue, and sets the links of the neighboring
              Nodes accordingly. The method checks if the Queue contains
              one Node or more. If it only contains one Node, it will delete
              the head and set it to nullptr. This method deletes the fighter
              contained inside the QueueNode as well.
*******************************************************************************/
void Team::removeFront() {
    //  If there is only one node delete head
    if (!isEmpty()) {
        if (head->next == head) {
            delete head->fighter;
            delete head;
            head = nullptr;
        } else {
            //  Break/reset links
            CharNode *temp = head->next;
            temp->prev = head->prev;
            head->prev->next = temp;

            //  Deallocate old 'head'
            delete head->fighter;
            delete head;

            //  Set new head
            head = temp;
        }
    }
}

/*******************************************************************************
Name:         Justin Lin
Called by:    tournament
Calls:        isEmpty
Passed:       N/A
Returns:      N/A

Description:  This method deletes (deallocates) the Node that is currently at
              the front of the Queue, and sets the links of the neighboring
              Nodes accordingly. The method checks if the Queue contains
              one Node or more. If it only contains one Node, it will delete
              the head and set it to nullptr. This method is used to move
              a fighter so it does not deallocate the fighter.
*******************************************************************************/
void Team::moveFront() {
    //  If there is only one node delete head
    if (!isEmpty()) {
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            //  Break/reset links
            CharNode *temp = head->next;
            temp->prev = head->prev;
            head->prev->next = temp;

            //  Deallocate old 'head'
            delete head;

            //  Set new head
            head = temp;
        }
    }
}