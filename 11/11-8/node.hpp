#ifndef _NODE_HPP
#define _NODE_HPP

#include <iostream>
#include <stdlib.h>

template <class T> class Node
{
        public:
                Node(const T val) : data(new T(val)), next(0), prev(0) { }
                Node(const T* val, Node* prevNode); 
                T* data;
                Node* next;
                Node* prev;
                friend std::ostream& operator<< (std::ostream& stream, const Node& node) { return stream << *node.data; }
                void uncreate(); 

                // rule of 3 all passing
                Node(const Node& rhs) { if (this != &rhs) this->data = new T(*rhs.data); }
                Node& operator=(const Node& rhs);
                ~Node() { uncreate(); }

                friend bool operator==(const Node& lhs, const Node& rhs)
                {
                        return lhs.data == rhs.data;
                }
};

template <class T> Node<T>::Node(const T* val, Node* prevNode) : data(new T(*val)), next(0), prev(0)
{
       prevNode->next = this;
       this->prev = prevNode;
}

template <class T> Node<T>& Node<T>::operator=(const Node& rhs)
{
        if (this != &rhs) {
                uncreate();
                this->data = new T(*rhs.data);
        }

        return *this;
}

template <class T> void Node<T>::uncreate()
{
        delete data;
        data = 0;
}

#endif
