#include <iostream>
#include <cassert>
//double linked list

template <class T>
class DLL
{
    private:
    struct Node
    {
        Node* prev;
        Node* next;
        T data;

        Node(T _data,Node* _prev = nullptr, Node* _next = nullptr)
        {
            this->data = _data;
            this->prev = _prev;
            this->next = _next;
        }
    };
    Node *first,*last;
    
    void copy(const DLL<T>& others)
    {
        Node *csave=others.first;
        this->first = new Node(others.first->data, nullptr, nullptr);
        Node *cur=this->first;
        Node* nextBox = nullptr;
        while(csave->next != nullptr)
        {
            csave = csave->next;
            nextBox = new Node(csave->data, cur, nullptr);
            cur->next = nextBox;
            cur = cur->next;
        }
    }
    void destroy()
    {
        Node *save = this->first;
        while (this->first != this->last)
        {
            this->first = this->first->next;
            delete save;
            save = this->first;
        }
        this->last = nullptr;
    }
    public:
    DLL() : first(nullptr), last(nullptr){}
    DLL(const DLL<T>& other)
    {
        this->copy(other);
    }
    DLL& operator=(const DLL<T>& others)
    {
        if(this != &others)
        {
            this->destroy();
            this->copy(others);
        }
        return *this;
    }
    ~DLL()
    {
        Node *save = this->first;
        while (this->first != this->last)
        {
            this->first = this->first->next;
            delete save;
            save = this->first;
        }
        this->last = nullptr;
    }

    void print()
    {
        Node *cur = first;
        std::cout << "[ ";
        while(cur != nullptr)
        {
            std::cout << cur->data << " ";
            cur = cur->next;
        }
        std::cout << "]" << std::endl;
    }
    
    //DLL<T>& operator= (const DLL<T> other);
    void push(const T& _data)
    {
        if(first == nullptr)
        {
            first = new Node(_data, first, nullptr);
            last = first;
            return;
        }

        Node *newElem = new Node(_data,nullptr,first);
        first = newElem;
    }

    void push_back(const T& _data)
    {
        if(first == nullptr)
        {
            first = new Node(_data, first, nullptr);
            last = first;
            return;
        }
        Node *newElem = new Node(_data, last, nullptr);
        last->next = newElem;
        last = last->next;
    }

    void pop()
    {
        if(first == nullptr)
        {
            return;
        }
        if(first->next == nullptr)
        {
            delete first;
            first = nullptr;
            last = nullptr;
            return;
        }
        Node *save = first;
        first = first->next;
        delete save;
    }

    void pop_back()
    {
        if(first == nullptr) //empty list
        {
            return;
        }
        if(first->next == nullptr)
        {
            delete first;
            first = nullptr;
            last = nullptr;
            return;
        }
        Node *save = last;
        last = last->prev;
        last->next = nullptr;
        delete save;
    }

    size_t size()
    {
        size_t cnt = 0;
        Node* cur = first;
        while (cur != nullptr)
        {
            cur = cur->next;
            cnt++;
        }
        return cnt;
    }

    const T& operator[] (size_t pos) const
    {
        Node *cur = first;
        while(cur != nullptr && pos>0)
        {
            cur = cur->next;
            pos--;
        }
        return cur->data;
    }
    
    T& operator[] (size_t pos)
    {
        Node *cur = first;
        while(cur != nullptr && pos>0)
        {
            cur = cur->next;
            pos--;
        }
        return cur->data;
    }

    void insertAt (size_t pos, const T& elem)
    {
        Node *curr = first;
        DLL list ;
        size_t counter = 0;
        while (counter < pos)
        {
            list.push_back(curr->data);
            curr = curr->next;
            counter += 1;
        }
        
        list.push_back(elem);
        Node* curr2 =curr;
         
        while (curr2 != nullptr)
        {
            if (curr2 == last)
            {
                list.push_back(curr2->data);
                curr2 = curr2->next;
            }
            else
            {
                list.push_back(curr2->next->data);
                curr2 = curr2 -> next;
            }
        }
        this->first = list.first;
        this->last = list.last;
    }
};

int main()
{
    DLL<int> dae;
    dae.push(1);
    dae.push(2);
    dae.push(3);
    dae.push(4);
    dae.push_back(5);
    /*dae.print();
    std::cout << dae.size() << std::endl;
    dae.pop();
    dae.print();
    std::cout << dae.size() << std::endl;
    dae.pop_back();
    dae.print();
    std::cout << dae.size() << std::endl;
    std::cout << dae[1] << std::endl; //2*/
    DLL<int> nee;
    nee.push(2);
    nee.push(1);
    nee.push(0);
    nee.insertAt(1,10);
    nee.print();
    return 0;
}
