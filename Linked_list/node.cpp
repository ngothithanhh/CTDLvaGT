#include<bits/stdc++.h>

using namespace std;

#ifndef __node__cpp__
#define __node__cpp__

template <class T>
class node{
    private:

        T elem;
        Node *next;

    public:
        
        node(){}

        node(T x, node<T> *n = NULL){
            elem = x;
            next = N;
        }

    void setNext(Node<T> *n = NULL){
        next = n;
    }

    void setElement(T x){
        elem = x;
    }

    T &getElement(){
        return elem;
    }

    node<T> *getNext(){
        return next;
    }
};
#endif