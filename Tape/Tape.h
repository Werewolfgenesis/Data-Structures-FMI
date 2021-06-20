#pragma once
#include <vector>
#include "..\\DLL\\DLL.cpp"
#include "..\\DLL\\Node.h"
#include <iostream>
#include <fstream>
#include <cstring>

const unsigned int MAX_TAPE_SIZE = 256;

class Tape
{
private:
    //**************class fields*****************
    DLlist<char> arr;
    unsigned int size = MAX_TAPE_SIZE;
public:
//**************deafault constructor**************
     Tape();
//*********constructor with parameters************
     Tape(const char *);
//*************operator=**************************
     const Tape& operator=(const Tape&);
//***********method to print elems on file**********
     void print_elems_on_tape(std::ofstream&);
//************index operator**********************
     char& operator[](const unsigned int&);
//**************index first element**************
     unsigned int index_head_tape();
//**********index last non space element**********
     unsigned int index_tail_tape();
//***********count non space elements*************
     const unsigned int count_els();
//*********read the non space elements************
     const std::string read_tape();
//*********write elements on tape****************
     void write_tape(const std::string&);
};