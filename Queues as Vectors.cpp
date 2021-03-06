//queue => first in first out
#include <iostream>
#include "Vector.cpp"
//see vector.cpp
template <class T>
class Queue
{
private:
    Vector<T> * queue;
public:
    Queue():queue(nullptr);
    ~Queue()
    {
        delete this->queue;
    }
    //element access
    const T& front()
    {
        return this->queue->first();
    }
    const T& last()
    {
        return this->queue->last();
    }
    //capacity
    bool is_empty()
    {
        return this->queue->isEmpty();
    }
    int size()
    {
        return this->queue->capacity();
    }
    //modifiers
    void push(const T& elem)
    {
        this->queue->push_back(elem);
    }
    void pop()
    {
        return this->queue->pop_front();
    }
    void swap()
    {
        //TO DO
    }
};

int main()
{
  return 0;
}
