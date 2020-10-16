#include <iostream>
template <class T>

class Vector
   {
    private:
       T* data;
       int size;
    public:
       Vector()
       {
           this->data = nullptr;
           this->size = 0;
       }
       Vector(const T& other)
       {
           this->size = other.size;
           this->data = new T[this->size];
           for (int i = 0; i <= this->size; i++)
           {
               this->data[i] = other.data[i];
           }
       }
       ~Vector()
       {
          delete this->data;
       }
       T& operator=(const T& other)
       {
           if(this != &other)
           {
               delete this->data;
               this->size = other.size;
               this->data = new T[other.size];
               for (size_t i = 0; i <= other.size; i++)
               {
                   this->data[i] = other.data[i];
               }
           }
           return *this;
       }
       T& operator[](size_t pos)
       {
          return this->data[pos];
       }
       int capacity()
       {
           return this->size;
       }
       void push_back(const T& elem)
       {
         T *biggerBuffer = new T[size+1];
    for (size_t i = 0; i < size; ++i)
    {
        biggerBuffer[i] = data[i];
    }
    biggerBuffer[size] = elem;
    ++size;
    
    delete []data;      
    data = biggerBuffer;
       }
       void print()
       {    
           for (int i = 0; i < this->size; i++)
          {
               std::cout << this->data[i];
          }
       }
       void pop_back()
       {
           T* newBuffer = new T[size - 1];
           for (size_t i = 0; i < size - 1; i++)
           {
               //std::cout << "sd"; 
               newBuffer[i] = data[i];
           }
           delete data;
           size--;
           data = newBuffer;   
       }
       bool isEmpty()
       {
           if (this->size == 0)
           {
               return true;
           }
           return false;
       }
       const T& last()
       {
           return this->data[size - 1];
       }
       
    };
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
