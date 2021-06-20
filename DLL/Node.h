#pragma once

template <typename T>
struct Node
{
    Node* prev;
    Node* next;
    T data;

    Node(Node* prev, Node* next, T data)
    {
        this->prev = prev;
        this->next = next;
        this->data = data;
    }
};
