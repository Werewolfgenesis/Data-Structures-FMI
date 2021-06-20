#include <iostream>
#include "Node.h"

template <typename T>
class DLlist
{
private:
    Node<T>* first;
    Node<T>* last;

    void copy(const DLlist<T>& other)
    {
        Node<T>* other_iter = other.first;
        this->first = new Node<T>(nullptr, nullptr, other.first->data);
        Node<T>* current = this->first;
        Node<T>* next_box = nullptr;
        while (other_iter->next != nullptr)
        {
            other_iter= other_iter->next;
            next_box = new Node<T>(current, nullptr, other_iter->data);
            current->next = next_box;
            current = current->next;
        }
    }
    void destroy()
    {
        Node<T>* current = this->first;
        while (current)
        {
            this->first = this->first->next;
            delete current;
            current = this->first;
        }
        
    }
public:
    DLlist()
    {
        this->first = nullptr;
        this->last = nullptr;
    }
    DLlist(const DLlist<T>& other)
    {
        this->copy(other);
    }
    DLlist<T>& operator=(const DLlist<T>& other)
    {
        if(this != &other)
        {
            this->destroy();
            this->copy(other);
        }  
    }
   
    ~DLlist()
    {
        this->destroy();
    }

    void push_back(const T& data)
    {
        if(this->first == nullptr)
        {
            this->first = new Node<T>(nullptr, nullptr, data);
            this->last = this->first;
            return;
        }
        Node<T>* new_box = new Node<T>(last, nullptr,data);
        this->last->next = new_box;
        this->last = new_box;
    }
    void push_front(const T& data)
    {
        if (this->first == nullptr)
        {
            this->first = new Node<T>(nullptr, nullptr, data);
            this->last = this->first;
            return;
        }
        Node<T>* new_box = new Node<T>(nullptr, this->first, data);
        this->first->prev = new_box;
        this->first = new_box;
    }
    void pop_back()
    {
        if(this->first == nullptr)
        {
            throw std::out_of_range("List is empty be tapak");
        }
        else if(this->first->next == nullptr)
        {
            delete this->first;
            this->first = nullptr;
            this->last = nullptr;
            return;
        }
        Node<T>* save = this->last->prev;
        delete this->last;
        this->last = save;
        this->last->next = nullptr;
    }

    void removeElement(Node<T>*& element){
        Node<T>* current = element;

        if(element){
            return;
        } 

        element->prev->next = element->next;
        if(!element->next)
        element->next->prev = element->prev;
        delete element;
        element = current->next;
    }
    void print()
    {
        Node<T>* current = this->first;
        while (current)
        {
            std::cout << current->data << std::endl;
            current = current->next;
        }
    }
    Node<T>*& firstElement()
    {
        return this->first;
    }
};