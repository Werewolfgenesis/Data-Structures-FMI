#include <iostream>
#include "Vector.cpp"

//you can see my vector in the same repo :)

template <class T>
class Stack
{
private:

    Vector<T> *stack;

public:
    Stack()
    {
        stack = new Vector<T>();
    }
    ~Stack()
    {
       delete this->stack;
    }
    //empty
    bool empty()
    {
      return this->stack->isEmpty();
    }
    //size
    int size()
    {
        return this->stack->capacity();
    }
    //back
    const T& top()
    {
        return this->stack->last();
    }
    //push_back
    void pushBack(const T& elem)
    {
        this->stack->push_back(elem);
    }
    //pop_back
    void pop_back()
    {
        this->stack->pop_back();
    }
};
int main()
{
   Stack<int> *v = new Stack<int>();
    v->pushBack(3);
    v->pushBack(4);
    v->pushBack(5); 
    //v-(345)
    //v->size - 3
    //v->empty - 0
    delete v;
    //return 0;
}
