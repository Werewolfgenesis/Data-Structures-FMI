#pragma once
#include "test.h"
//****************test functions*****************
void Test::testBranch()
{
    std::ifstream file;
    file.open("branch\\test.txt");
    std::string input;
    getline(file, input);
    file.close();
    Machine m(input.c_str());

    std::ofstream out;
    out.open("branch\\correcct_output.txt");

    m.branch(out);
    out.close();
}
void Test::testIncrement()
{
    std::ifstream file;
    file.open("increment\\test.txt");
    std::string input;
    getline(file,input);
    Machine m(input.c_str());
    file.close();

    std::ofstream out;
    out.open("increment\\correct_output.txt");

    m.increment(out);
    out.close();   
}
void Test::testDecrement()
{
    std::ifstream file;
    file.open("decrement\\test.txt");
    std::string input;
    getline(file, input);
    Machine m(input.c_str());
    file.close();
    
    std::ofstream out;
    out.open("decrement\\correct_output.txt");

    m.decrement(out);
}
void Test::testAddition()
{
    std::ifstream input;
    std::vector<std::string> numbers;

    input.open("addition\\test.txt");
    while (!input.eof())
    {
        std::string read;
        getline(input,read);
        numbers.push_back(read);
    }
    input.close();

    std::ofstream out;
    out.open("addition\\correct_output.txt");

    Machine m(numbers[0].c_str());
    Machine n(numbers[1].c_str());
    
    m.addition(n,out);
    out.close();
}
void Test::testMultitapeDEMO()
{
    std::ifstream input;
    std::vector<std::string> numbers;
    
    input.open("multitape\\test.txt");
    
    while (!input.eof())
    {
        std::string read;
        getline(input,read);
        numbers.push_back(read);
    }
    input.close();

    Machine m(numbers[0].c_str());
    Machine n(numbers[1].c_str());
    Machine p(numbers[2].c_str());
    std::vector<Machine> machines;

    machines.push_back(m);
    machines.push_back(n);

    std::ofstream out;
    out.open("multitape\\correct_output.txt");
    p.makeMultitape(machines, out);
    out.close();
}
void Test::testWhile()
{
    std::ifstream input;
    std::vector<std::string> numbers;

    input.open("while\\test.txt");

    while (!input.eof())
    {
        std::string read;
        getline(input, read);
        numbers.push_back(read);
    }
    input.close();

    Machine m(numbers[0].c_str());
    Machine n(numbers[1].c_str());

    std::ofstream out;
    out.open("while\\correct_output.txt");

    n.whileMachine(m, out);
    out.close();
}
void Test::startTest()
{
    testIncrement();
    testDecrement();
    testAddition();
    testBranch();
    testWhile();
    testMultitapeDEMO();
}