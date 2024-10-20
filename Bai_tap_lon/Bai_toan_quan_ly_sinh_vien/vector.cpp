#include<iostream>

using namespace std;

#ifndef __vector__cpp__
#define __vector__cpp__
// -> Ten tu dat: __vector__cpp__
template <class T>
class Vector{
    private:
        T *V; //mang dong
        int cap, num; //cap: so luong o nho duoc cap phat; num: so luong phan tu co trong vector
    public:
        Vector(){
            cap = 0;
            num = 0;
            V = new T[1];
        }
        Vector(int n, T value){
            cap = n;
            num = n;
            V = new T[n];
            for(int i = 0; i < n; i++){
                V[i] = value;
            }
        }

        ~Vector(){
            if(V != nullptr){
                delete[] V;
            }
        }
        int size(){
            return num;
        }
        bool empty(){
            return num == 0;
        }
        int capacity(){
            return cap;
        }
        void pop_back(){
            if(num > 0){
                num--;
            }
            else{
                cout <<"Error ! ! !";
            }
        }

        //Lay phan tu cuoi cung cua vector
        T &back(){ //tham chieu, lay truc tiep gia tri cua phan tu cuoi cung -> gan truc tiep gia tri
            return V[num-1];
        }

        void extend(int newCap){
            if(newCap < cap){
                return;
            }
            cap = newCap;
            T *tmp = new T[cap];
            for(int i = 0; i < num; i++){
                tmp[i] = V[i];
            }
            if(V) delete[] V;
            V = tmp;
        }
        void push_back(T value){
            if(num == cap){
                extend(cap * 2); //chien thuat gap doi
            }
            v[num] = value;
            ++num;
        }
        void insert(int pos, T x){
            if(num == cap){
                extend(cap * 2);
            }
            for(int i = num - 1; i >= pos; i--){
                V[i+1] = V[i];
            }
            V[pos] = x;
            ++num;
        }
        void erase(int pos){
            if(pos < 0 || pos >= size()){
                cout <<"Error ! ! !";
            }
            for(; pos < num; pos++){
                V[pos] = V[pos+1];
            }
            num--;

        }
        T &operator [](int i){
            // if(i >= size() || i < 0){
            //     cout <<"Error ! ! !";
            //     return -1;
            // }
            return V[i];
        }

        //Gan 2 vector cho nhau
        Vector &operator =(Vector<T> b){
            num = b.num;
            cap = b.cap;
            if(cap != 0){
                V = new T[cap];
                for(int i = 0; i < num; i++){
                    V[i] = b.V[i];
                }
            }
            else{
                V = nullptr;
            }
            return *this;
        }
        typedef T *iterator;
        iterator begin(){
            return V;
        }
        iterator end(){
            return V + num;
        }
};
#endif