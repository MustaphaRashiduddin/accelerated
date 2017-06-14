#ifndef _LIST_HPP
#define _LIST_HPP

#include <stdlib.h>
#include <memory>
#include <iostream>
#include "node.hpp"

template <class T> class List
{
        private:
                Node<T>* head;
                Node<T>* tail;
                Node<T>* curr;

                void kill(Node<T>* curr); 
        public:
                List() : head(0), tail(0), curr(0) { }
                ~List() { kill(head); }
                void push_back(const T val);
                void print();
                void printR();

                class iterator;
                iterator begin() { return head; }
                // const iterator begin() const { return head; }

                // iterator end() { return tail; }
                iterator end() { return 0; }
                // const iterator end() const { return tail; }

};

template <class T> void List<T>::push_back(const T val)
{
        if (head == 0) {
                head = curr = tail = new Node<T>(val);
        } else {
                tail->next = new Node<T>(&val, tail);
                tail = tail->next;
        }
}

template <class T> void List<T>::print()
{
        std::cerr << "List: ";
        curr = head;
        if (curr != 0) {
                std::cerr << *curr->data << " ";
                while (curr->next != 0) {
                        curr = curr->next;
                        std::cerr << *curr->data << " ";
                }
        }
        curr = head;
}

template <class T> void List<T>::printR()
{
        std::cerr << "ListR: ";
        curr = tail;
        if (curr != 0) {
                std::cerr << *curr->data << " ";
                while (curr->prev != 0) {
                        curr = curr->prev;
                        std::cerr << *curr->data << " ";
                }
        }
        curr = head;
}

template <class T> void List<T>::kill(Node<T>* curr)
{
        if (curr != 0) {
                if (curr->next != 0) kill(curr->next);
                delete curr;
        }
}

template <class T> class List<T>::iterator {
        private:
                Node<T>* it;
        public:
                // constructors
                iterator() : it(0) { }
                iterator(Node<T>* rhs);
                iterator& operator=(const Node<T>& rhs);

                // operators 
                Node<T>& operator*() { return *it; }
                iterator& operator++();
                iterator operator++(int);

                // friend operators
                friend bool operator==(const iterator& lhs, const iterator& rhs) { return lhs.it == rhs.it; }
                friend bool operator!=(const iterator& lhs, const iterator& rhs) { return !(lhs == rhs); }
};

template <class T> typename List<T>::iterator& List<T>::iterator::operator++()
{
        it = it->next;
        return *this;
}

template <class T> typename List<T>::iterator List<T>::iterator::operator++(int)
{
        iterator res(*this);
        ++(*this);
        return res;
}

template <class T> List<T>::iterator::iterator(Node<T>* rhs) : it(0)
{
        if (this->it != rhs) {
                it = rhs;
        }
}

template <class T> typename List<T>::iterator& List<T>::iterator::operator=(const Node<T>& rhs)
{
        if (this->it != rhs) {
                it = rhs;
        }
}

#endif
