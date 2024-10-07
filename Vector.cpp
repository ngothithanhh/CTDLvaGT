#include<iostream>
using namespace std;
#ifndef __vector__cpp__
#define __vector__cpp__
 
template <class T>
class vector_reverse_iterator{
	T *curr;	
	public:
		vector_reverse_iterator(T *c=0){
            curr = c;
        }

		vector_reverse_iterator<T> &operator=(vector_reverse_iterator<T> it){
			this->curr = it.curr; 
			return *this;
		}

        //++curr
		vector_reverse_iterator<T> operator++(){
			curr--;
			return curr;
		}
        //++curr
		vector_reverse_iterator<T> operator++(int){
			vector_reverse_iterator<T> tmp = curr;
			curr--;
			return tmp;
		}

		T &operator*() {
            return *curr;
        }

		bool operator!=(vector_reverse_iterator<T> t) {
            return curr != t.curr;
        }
};
 
template <class T>
class Vector{
    private:
        int cap, num;
        T *v;
    public:
        Vector(){
            num = cap = 0;
            v = 0;
        }

        Vector(int n, T value){
            num = cap = n;

            v = new T[n];

            for(int i = 0; i < n; i++){
                v[i] = value;
            }
        }

        ~Vector(){
            if(v) delete[] v;
        }

        int capacity(){
            return cap;
        }

        int size(){
            return num;
        }

        bool empty(){
            return num == 0;
        }

        void pop_back(){
            if(num > 0) num--;
            else cout <<"Error ! ! !";
        }

        void extend(int newCap){

            if(newCap < cap){
                return;
            }

            cap = newCap;
            T *tmp = new T[cap];

            for(int i = 0; i < num; i++){
                tmp[i] = v[i];
            }

            if(v) delete[] v;

            v = tmp;
        }

        T &back(){
            return v[num-1];
        }

        void push_back(T x){
            if(num == cap) extend(cap*2 + 1);

            v[num++] = x;
        }

        T &operator[] (int k){
            return v[k];
        }
        void insert(int pos, T x){
            if(num == cap) extend(cap*2 + 1);

            for(int i = num - i; i >= pos; i--){
                v[i+1] = v[i];
            }

            v[pos] = x;
            num++;
        }

        void replace(int pos, T x){
            v[pos] = x;
        }

        void erase(int pos){
            if(pos < 0 || pos >= size()){
                cout <<"Error ! ! !";
            }
            for(; pos < num; pos++){
                v[pos] = v[pos+1];
            }
            num--;
        }

        typedef T *iterator; 
		iterator begin() {return v;}
		iterator end() {return v+num;}
		typedef vector_reverse_iterator<T> reverse_iterator;
		reverse_iterator rbegin() {return reverse_iterator(v+num-1);} 
		reverse_iterator rend() {return reverse_iterator(v-1);} 
};

#endif

main(){
    Vector<int> v(7,6);
    cout << "Vector ban dau: "; 
    for(int i = 0; i < v.size(); i++){
        cout << v[i] <<" ";
    }
    cout <<"\n";

    v.push_back(11);
    cout << "Vector sau chen: "; 
    for(int i = 0; i < v.size(); i++){
        cout << v[i] <<" ";
    }
    cout <<"\n";

    v.erase(5);
    cout << "Vector sau xoa: "; 
    for(int i = 0; i < v.size(); i++){
        cout << v[i] <<" ";
    }
    cout <<"\n";

    v.replace(3, -9);
    cout << "Vector sau thay the: "; 
    for(int i = 0; i < v.size(); i++){
        cout << v[i] <<" ";
    }
    cout <<"\n";

    cout <<"Phan tu thu 2 trong vector: " << v[2] <<"\n";

}