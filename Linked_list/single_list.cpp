#include<bits/stdc++.h>
#include "node.cpp"
#include "list_iterator.cpp"

using namespace std;
#ifndef __singList__cpp__
#define __singList__cpp__

template <class T>
class list{
    node<T> *head, *trailer;
    int num;

    public:
        typedef slist_iterator<T> iterator;
        list(){
            head = trailer = NULL;
            num = 0;
        }

        list(int n, T x){
            head = trailer = NULL;
            num = 0;
            for(int i = 0; i <= k; i++) push_back(x);
        }

        iterator begin(){
			return head;
		}
		iterator end(){
			return NULL;
		}

        int size(){
            return num;
        }

        bool empty(){
            return num == 0;
        }

        T &front(){
            return head->getElement();
        }

        T &back(){
            return trailer->getElement();
        }

        void push_front(T x){
            head = new node<T> (x,head);

            if(num == 0) trailer = head;
            num++;
        }

        void push_back(T x){
            if(num == 0) push_front(x);
            else{
                trailer->setNext(new node<T>(x,NULL));
                trailer = trailer->getNext();
                num++;
            }
        }

        void pop_front(){
            if(num == 0) return;

            if(num == 1) head = trailer = NULL;
            else{
                head = head->getNext();
            }

            num--;
        }

        void pop_back(){
            if(num == 0) return;

            if(num == 1){
                head = trailer = NULL;
                num--;
                return;
            } 
            node<T> *p = head;
            while(p->getNext() != trailer) p = p->getNext();    
            p->setNext(NULL);
            trailer = p;
            num--;
        }

};

#endif