#include <iostream>

template<typename T>
struct Node{
    T data;
    Node* next;

    Node(Node* next,const T& data){
        this->next = next;
        this->data = data;
    }
};

template<typename T>
class LinkedList{
private:
   Node<T>* next;
public:
    LinkedList(){
        this->next = nullptr;
    }
    void push_back(const T& elem){
        if (this->next == nullptr)
        {
            this->next = new Node<T>(nullptr, elem);
            return;
        }
        Node<T>* tmp = this->next;
        while (tmp->next != nullptr)
        {
           tmp = tmp->next;
        }
        tmp->next = new Node<T>(nullptr, elem);
    }
    void print(){
        if (this->next == nullptr)
        {
            std::cout << "Empty list!" << std::endl;
            return;
        }
        Node<T>* tmp = this->next;
        while (tmp != nullptr)
        {
           std::cout << tmp->data << std::endl;
           tmp = tmp->next;
           
        }
    }

    //--------tasks-----------------
    unsigned sum() const{
        Node<T>* tmp = this->next;
        unsigned sum = 0;
        while (tmp != nullptr)
        {
            sum += tmp->data;
           tmp = tmp->next;
        }
        return sum;
    }

    Node<T>* first(){
        return this->next;
    }
    void remove_on_pos(unsigned index){
        if (this->next == nullptr)
        {
            std::cout << "Empty list" << std::endl;
            return;
        }
        if (index == 0 && this->next->next)
        {
            Node<T>* save = this->next->next;
            delete this->next;
            this->next = save;
            return;
        }
        
        
        Node<T>* tmp = this->next;
        while (index != 1 && tmp)
        {
            std::cout << "Opa";
            tmp = tmp->next;
            index -= 1;
        }
        Node<T>* save = tmp;
        tmp->next = tmp->next->next;
        delete save->next;
    }
    void pop_back(){
        if (this->next == nullptr)
        {
            std::cout << "Empty!" << std::endl;
            return; 
        }
        if (this->next && !this->next->next)
        {
            delete this->next;
            this->next = nullptr;
            return;
        }
        
        Node<T>* current = this->next;
        while (current->next->next != nullptr)
        {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
        
    }
    void pop(){
        if (this->next == nullptr)
        {
            std::cout << "Empty " << std::endl;
            return;
        }
        if (this->next && !this->next->next)
        {
            delete this->next;
            this->next = nullptr;
            return;
        }
        
        Node<T>* save = this->next->next;
        delete this->next;
        this->next = save;
        
    }
};

int main(){

    LinkedList<int> l;
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    std::cout << l.sum() << std::endl;
    l.pop_back();
    l.pop();
    l.print();
    return 0;
}