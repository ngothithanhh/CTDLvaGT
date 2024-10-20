#include<iostream>

using namespace std;
#ifndef __linkedlist__cpp__
#define __linkedlist__cpp__

template <class T>
class Node{
    private:
        T elem;
        Node *next;
    public:
        Node (){}
        Node(T x , Node<T> *N=NULL){
			elem =x;
			next = N;
		}
        
    

};

#endif