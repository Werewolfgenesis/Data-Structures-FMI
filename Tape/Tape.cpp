#include "Tape.h"
#include <cassert>
    
Tape::Tape()
{
    for (unsigned int i = 0; i < size; i++)
    {
        arr.push_back('#');
    }
}
Tape::Tape(const char * str)
{
    unsigned int index_iter = strlen(str);
    for (unsigned int i = 0; i < index_iter; i++)
    {
        arr.push_back(str[i]);
    }
    for (unsigned int i = index_iter; i < this->size; i++)
    {
        arr.push_back('#');
    }
}
const Tape& Tape::operator=(const Tape& other)
{
    if(this != &other)
    {
        this->arr = other.arr; 
    }
    return *this;
}
void Tape::print_elems_on_tape(std::ofstream& out)
{
    Node<char>* current = this->arr.firstElement();
    
    while (current->data != '#')
    {
        out << current->data;
        current = current->next;
    }  
}
char& Tape::operator[](const unsigned int& return_index)
{
    if(return_index > size){throw std::out_of_range("Index too big dude!");}
    Node<char> * current = this->arr.firstElement();
    unsigned int counter = 0;
    while (current)
    {
        if (counter == return_index)
        {
            return current->data;
        }
        counter += 1;
        current = current->next;
    }
}
unsigned int Tape::index_head_tape()
{
   return 0;
}
unsigned int Tape::index_tail_tape()
{
    unsigned int index = 0;
    Node<char> * current = this->arr.firstElement();
    while (current->next->data != '#')
    {
        index += 1;
        current = current->next;
    }
    return index;
}
const unsigned int Tape::count_els()
{
    Node<char>* current = this->arr.firstElement();
    unsigned int counter = 0;
    while (current->data != '#')
    {
        counter += 1;
        current = current->next;
    }
    return counter;
}
const std::string Tape::read_tape()
{
    std::string result = "";
    Node<char>* current = this->arr.firstElement();
    assert(current != nullptr);
    while (current->data != '#')
    {
        result += current->data;
        current = current->next;
    }
    return result;
}
void Tape::write_tape(const std::string& str)
{
    Node<char>* current = this->arr.firstElement();
    unsigned int index = 0;
    assert(current->next != nullptr);
    while (current->next && current->next->data != '#')
    {
        current = current->next;
    }
    current->next->data = '*';
    current = current->next->next;
    while (str[index])
    {
        current->data = str[index];
        index += 1;
        current = current->next;
    }
}

