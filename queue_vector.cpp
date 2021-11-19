#include <iostream>
#include<vector>

//Queue implementation with vector

template<typename T> class Queue{
    private:
    std::vector<T> arr;

    public:
    Queue() = default;
    Queue(const Queue<T>&) = default;
    Queue<T>& operator=(const Queue<T>&) = default;
    ~Queue() = default;

    T front() const;
    T back() const;

    void pop();
    void push(const T&);

    bool empty() const;
    unsigned size() const;
};

//O(1)
template<typename T> inline T Queue<T>::front() const{
    return this->arr[0];
}
//O(1)
template<typename T> inline T Queue<T>::back() const{
    return this->arr[this->arr.size() - 1];
}
//O(n)
template<typename T> inline void Queue<T>::pop(){
    this->arr.erase(this->arr.begin());
}
//O(1)
template<typename T> inline void Queue<T>::push(const T& elem){
    this->arr.push_back(elem);
}
//O(1)
template<typename T> inline bool Queue<T>::empty() const{
    return this->arr.size() == 0;
}
//O(1)
template<typename T> inline unsigned Queue<T>::size() const{
    return this->arr.size();
}

int main(){
    Queue<int> q;
    q.push(2);
    q.push(1);
    q.push(3);
    q.push(2);

    while (!q.empty())
    {
        std::cout << q.front(); q.pop();
    }
    
    return 0;
}