#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Queue {
public:
    Queue();
    ~Queue();

    void push(const T& value);
    void pop();
    T front() const;
    int size() const;
    bool empty() const;
    void move_to_rear();
    void display() const;

private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* frontNode;
    Node* rearNode;
    int count;
};

// Inline definitions of template functions

template <typename T>
Queue<T>::Queue() : frontNode(nullptr), rearNode(nullptr), count(0) {}

template <typename T>
Queue<T>::~Queue() {
    while (!empty()) {
        pop();
    }
}

template <typename T>
void Queue<T>::push(const T& value) {
    Node* newNode = new Node(value);
    if (empty()) {
        frontNode = rearNode = newNode;
    } else {
        rearNode->next = newNode;
        rearNode = newNode;
    }
    count++;
}

template <typename T>
void Queue<T>::pop() {
    if (empty()) {
        throw std::out_of_range("Queue is empty");
    }
    Node* temp = frontNode;
    frontNode = frontNode->next;
    delete temp;
    count--;
    if (count == 0) rearNode = nullptr;
}

template <typename T>
T Queue<T>::front() const {
    if (empty()) {
        throw std::out_of_range("Queue is empty");
    }
    return frontNode->data;
}

template <typename T>
int Queue<T>::size() const {
    return count;
}

template <typename T>
bool Queue<T>::empty() const {
    return count == 0;
}

template <typename T>
void Queue<T>::move_to_rear() {
    if (!empty()) {
        T frontValue = front();
        pop();
        push(frontValue);
    }
}

template <typename T>
void Queue<T>::display() const {
    Node* current = frontNode;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

#endif
