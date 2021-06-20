//TURING MACHINE
#include "turing.h"

Machine::Machine()
{
    this->tape = new Tape();
    this->current_index = this->tape->index_tail_tape();
    this->isWorking = false;
}
Machine::Machine(const char * str)
{
    this->tape = new Tape(str);
    this->current_index = this->tape->index_tail_tape();
    this->isWorking = false;
}
void Machine::move_left()
{
    this->current_index -= 1;
}
void Machine::move_right()
{
    this->current_index += 1;
}
void Machine::move_not()
{

}
void Machine::halt()
{
    this->isWorking = false;
}
void Machine::start()
{
    this->isWorking = true;
}    
bool Machine::working()
{
    return this->isWorking == true;
}
unsigned int Machine::index()
{
    return this->current_index;
}
//increment 
void Machine::increment(std::ofstream& out)
{  
    this->start();
    unsigned int counter = 0;
    out << "*********************Incrementing...*****************" << std::endl;
    while ((*(this->tape))[this->index()] == '9' && this->working())
    {
        counter += 1;
        if (counter == this->tape->count_els())
        {  
            out << "9{increment} -> 0{increment}L" << std::endl;
            out << "             -> 1{halt}" << std::endl;
            this->halt();
            return;
        }
        (*(this->tape))[this->index()] = '0';
        out << "9{increment} -> 0{increment}L" << std::endl;
        this->move_left();
    }
    (*(this->tape))[this->index()] += 1; //this will work bcs the numbers 0..9 are one after another in ascii
    out << (*(this->tape))[this->index()] - '0' - 1 << "{increment} -> " << (*(this->tape))[this->index()] << "{halt}" << std::endl;
    this->halt();
}
//decrement
void Machine::decrement(std::ofstream& out)
{
    this->start();
    out << "*********************Decrementing...*****************" << std::endl;
    if (this->tape->count_els() < 1)
    {
        throw std::out_of_range("can't decrement this input!");
    }
    else if(this->tape->count_els() == 1 && (*(this->tape))[0] == '0')
    {
        throw std::out_of_range("can't decrement this input!");
    }
    while ((*(this->tape))[this->index()] == '0' && this->working())
    {
        (*(this->tape))[this->index()] = '9';
        out << "0{decrement} -> 9{decrement}L" << std::endl;
        this->move_left();
    }
    (*(this->tape))[this->index()] -= 1;
    out << (*(this->tape))[this->index()] - '0' + 1 << "{decrement} -> " << (*(this->tape))[this->index()] << "{halt}" << std::endl;
    this->halt();
}
//*********composition of two TMs************
void Machine::addition(Machine& other, std::ofstream& out)
{
    out << "//////////////Adding...///////////////" << std::endl;
    while ((*(other.tape))[0] != '0')
    {
        //border case
        if ((*(this->tape))[0] == '0')
        {
            return;
        }
        else if((*(other.tape))[0] == '0')
        {
            return;
        }
        other.decrement(out);
        out << std::endl;
        this->increment(out);
        out << std::endl;
    }
}
//**********condition stated by TM********
bool Machine::isViable()
{
    this->start();
    while (this->index() >= 0 && this->working())
    {
        if (!((*(this->tape))[this->index()] >= '0' && (*(this->tape))[this->index()] <= '9'))
        {
            this->halt();
            return false;
        }
        this->move_left();
   }
    this->halt();
    return true;
}
void Machine::makeViable(std::ofstream& out)
{
    this->start();
    while (this->index() > 0 && this->working())
    {
        if ((this->index() - 1 < 0) && (!((*(this->tape))[this->index()] >= '0' && (*(this->tape))[this->index()] <= '9')))
        {
            out << (*(this->tape))[this->index()] << "{unviable} -> 0{viable}" << std::endl;
            (*(this->tape))[this->index()] = '0';
            break;
        }
        else if (!((*(this->tape))[this->index()] >= '0' && (*(this->tape))[this->index()] <= '9'))
        {
            out << (*(this->tape))[this->index()]<< "{unviable} -> 0{viable}L" << std::endl;
            (*(this->tape))[this->index()] = '0';
        }
       this->move_left();
    }
    if(!((*(this->tape))[0] >= '0' && (*(this->tape))[0] <= '9'))
    {
        out << (*(this->tape))[0] << "{unviable} -> 0{halt}" << std::endl;
        (*(this->tape))[0] = '0';
    }
    this->halt();
}
void Machine::branch(std::ofstream& out)
{
    Machine *one = new Machine(this->tape->read_tape().c_str());
    Machine *two = new Machine(this->tape->read_tape().c_str());

    if(!(isViable()))
    {
        out << "Making input viable...." << std::endl;
        out << "Changes made to input:" << std::endl;
        one->makeViable(out);
    }
    else
    {
        two->increment(out);
    }
    delete[] one;
    delete[] two;
}
void Machine::whileMachine(Machine& m, std::ofstream& out)
{
    this->start();
    out << "*********************Calculating...*****************" << std::endl;
    while (this->working())
    {
        m.increment(out);
        this->move_left();
        if (this->index() == 0)
        {
            m.increment(out);
            this->halt();
        }
    }
}
void Machine::makeMultitape(const std::vector<Machine>& machines, std::ofstream& out)
{
    int c_index = machines.size() - 1;
    out << "***************Generating multitape...***************" << std::endl;
    while (c_index >= 0)
    {
        this->tape->write_tape(machines[c_index].tape->read_tape());
        c_index -= 1;
    }
    this->tape->print_elems_on_tape(out);
}
