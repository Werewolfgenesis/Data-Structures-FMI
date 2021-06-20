#pragma once
#include <iostream>
#include "..\\Tape\\Tape.cpp"
#include "..\\Tape\\Tape.h"
class Machine
{
private:
//***********class fields**************
    Tape *tape;
    unsigned int current_index; 
    bool isWorking;
public:
//*********************constructors***************
    Machine();
    Machine(const char *);
//************directions*****************
    void move_left();
    void move_right();
    void move_not();
//********************switch off and switch on methods**************
    void halt();
    void start();
//***********accessing current index and working state**************
    bool working();
    unsigned int index();
//***********************simple methods*****************************
    void increment(std::ofstream&);
    void decrement(std::ofstream&);
//***********************composition of TMs*************************
    void addition(Machine&, std::ofstream&);
//*******************methods for branching**************************  
    bool isViable();
    void makeViable(std::ofstream&);
//***********************branching of TMs***************************
    void branch(std::ofstream&);
//************************while loop with TM************************
    void whileMachine(Machine&, std::ofstream&);
//********make multi-tape from vector of single-tape machines*******
    void makeMultitape(const std::vector<Machine>&, std::ofstream&);
//*******************end-of-class*********************************
};

