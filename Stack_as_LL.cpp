#include <iostream>
class Stack
{
private:
    template<typename T>
    struct Node{
        T data;
        Node<T>* next;

        Node(T _data, Node<T>* _next) : data(_data), next(_next){}
    };

    Node<int>* top;
public:
    Stack(Node<int>* _top = nullptr);
    ~Stack();

    void push(const int& data);
    void pop();
    bool empty() const;

    int& get_top() const;
};

inline Stack::Stack(Node<int>* _top){this->top = _top;}

inline Stack::~Stack(){delete[] this->top;}

inline void Stack::push(const int& data){
    if (this->top == nullptr)
    {
        this->top = new Node<int>(data, nullptr);
        return;
    }
    Node<int>* new_elem = new Node<int>(data, this->top);
    this->top = new_elem;    
}

inline void Stack::pop(){
    if(this->top == nullptr){return;}

    Node<int>* to_del = this->top;
    this->top = this->top->next;
    delete[] to_del;
}

inline bool Stack::empty() const {return this->top == nullptr;}

inline int& Stack::get_top() const {return this->top->data;}

void test_stack(){
    Stack s;
    s.push(2);
    s.push(2);
    s.push(9);
    s.push(3);
    s.push(0);

    while (!s.empty())
    {
        std::cout << s.get_top() << std::endl;
        s.pop();
    }
}
int main(){

    test_stack();
    
    return 0;
}