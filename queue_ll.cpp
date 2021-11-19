#include <iostream>

template<typename T> class Queue{
    private:

    template<typename R>
    struct Node{
        R data;
        Node<R>* next;

        Node(const R& _data, Node<R>* _next) : data(_data), next(_next) {}
    };

    Node<T>* first, *last;
    unsigned size;

    public:
    Queue() = default;
    ~Queue();

    T front() const;
    T back() const;

    void pop();
    void push(const T&);

    bool empty() const;
    unsigned sizee() const;
    
};

template<typename T> inline Queue<T>::~Queue(){
    while(this->first){
        Node<T>* to_del = this->first;
        this->first = this->first->next;
        delete to_del;
    }
    
}
//O(1)
template<typename T> inline T Queue<T>::front() const{
    return this->first->data;
}
//O(1)
template<typename T> inline T Queue<T>::back() const{
    return this->last->data;
}
//O(1)
template<typename T> inline void Queue<T>::pop(){
    Node<T>* to_del = this->first;
    this->first = this->first->next;
    delete to_del;
}

//O(1)
template<typename T> inline void Queue<T>::push(const T& elem){
    if (this->first == nullptr)
    {
        this->first = new Node<T>(elem, nullptr);
        this->last = this->first;
        this->size += 1;
        return;
    }

    Node<T>* new_node = new Node<T>(elem, nullptr);
    this->last->next = new_node;
    this->last = this->last->next;
    this->size += 1;
}

//O(1)
template<typename T> inline bool Queue<T>::empty() const{
    return this->first == nullptr;
}
//O(1)
template<typename T> inline unsigned Queue<T>::sizee() const{
    return this->size;
}

int main(){
    Queue<int> q;
    q.push(2);
    q.push(1);
    q.push(3);
    q.push(2);

    while (!q.empty())
    {
        std::cout << "Elem: " << q.front() << std::endl; 
        q.pop();
    }
    
    return 0;
}
