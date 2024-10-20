#include<bits/stdc++.h>
#include "node.cpp"

using namespace std;

#ifndef __list__cpp__
#define __list__cpp__

template <class T>
class list_iterator{
    node<T> *curr;
    public:
        list_iterator(){
            curr = NULL;
        } 

        list_iterator(node<T> *p){
            curr = p;
        }

        node<T> *getCurr(){
            return curr;
        }

        list_iterator<T> &operator=(list_iterator<T> p){
            this->curr = p.getCurr();
            return *this;
        }

        bool operator!=(list_iterator<T> p){
            return curr!=p.getCurr();
        }

        list_iterator<T> operator++(){
            curr = curr->getNext();
            return curr;
        }

        list_iterator<T> operator++(int){
			node<T> *temp = curr;
			curr=curr->getnext();
			return temp;
		}

        T &operator*(){
            return curr->getElement();
        }
};

#endif