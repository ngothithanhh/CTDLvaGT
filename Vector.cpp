#include<iostream>

using namespace std;

#ifndef __Vector__cpp__
#define __Vector__cpp__

template <typename T>
class Vector{
    private:
        int num; //So phan tu hien tai co trong vector
        int cap; //So luong o nho duoc cap phat
        T *v; //Mang dong

    public:
        Vector(){
            cap = 0;
            num = 0;
            v = new T[1];
        }

        Vector(int n, T value){
            cap = n;
            num = n;
            v = new T[n];
            for(int i = 0; i < n; i++){
                v[i] = value;
            }
        }

        ~Vector(){
        	delete[] v;
		}

        //Lay so luong phan tu hien tai trong mang
        int getSize(){
            return num;
        }

        //Lay so luong o nho hien tai bo nho duoc cap phat
        int getCap(){
            return cap;
        }

        //Xoa phan tu cuoi
        void pop_back(){
            if(num > 0){
                num--;
            }
            else{
                cout << "Error !!\n";
            }
        }

        void extend(int newCap){
            if(newCap < cap){
                return;
            }
            cap = newCap;
            T *tmp = new T[cap];
            for(int i = 0; i <  num; i++){
                tmp[i] = v[i];
            }

            if(v) delete[] v;
            v = tmp;
        }

        //Tra ve phan tu dau tien
        T &front(){
            return v[0];
        }

        //Tra ve phan tu cuoi cung 
        T &back(){
            return v[num-1];
        }

        //Them phan tu vao cuoi
        void push_back(T value){
            if(num == cap){
                extend(cap*2); //Chien thuat gap doi
            }
            v[num] = value;
            ++num;
        }

        //Them phan tu vao vi tri cu the
        void insert(int pos, T value){
            if(num == cap){
                extend(cap*2);
            }

            for(int i = num - 1; i >= pos; i--){
                v[i+1] = v[i]; 
            }

            v[pos] = value;
            ++num;
        }

        //Loai bo phan tu
        void erase(int pos){
            if(pos < 0 || pos >= num){
                cout <<"Error !!!\n";
            }
            else{
                for(int i = pos; i < num; i++){
                    v[i] = v[i+1];
                }
                num--;
            }
        }

        //Truy cap phan tu voi chi so pos
        T operator[](int pos){
            return v[pos];
        }

        // Xoa tat ca
        void clear() {
            num = 0;
        }

        Vector &operator= (Vector<T> v2){
            num = v2.num;
            cap = v2.cap;
            if(cap != 0){
                v = new T[cap];
                for(int i = 0; i < num; i++){
                    v[i] = v2.v[i];
                }
            }
//            else{
//                v = nullptr;
//            }
            return *this;
        }

        //Bo lap xuoi ITERATOR
        class iterator{
            private:
                T *ptr;
            public:
                iterator(T* p){
                    ptr = p;
                }

                //Truy cap gia tri cua phan tu
                T& operator*(){
                    return *ptr;
                }
                
                //Di chuyen den phan tu tiep theo
                iterator& operator++(){
                    ptr++;
                    return *this;
                }

                iterator& operator--(){
                    ptr--;
                    return *this;
                }

                 // So sánh hai iterator
                bool operator!=(const iterator &other) const{
                    return ptr != other.ptr;
                }

                bool operator==(const iterator &other) const{
                    return ptr == other.ptr;
                }
        };


        //Bo lap nguoc REVERSE_ITERATOR
        class reverse_iterator{
            private:
            T *ptr;

            public:
            reverse_iterator (T* p){
                ptr = p;
            }

            T& operator*(){
                return *ptr;
            }

            reverse_iterator& operator++(){
                ptr--;
                return *this;
            }

            reverse_iterator& operator--(){
                ptr++;
                return *this;
            }

            bool operator!=(const reverse_iterator &other) const{
                return ptr != other.ptr; 
                }

            bool operator==(const reverse_iterator &other) const {
                return ptr == other.ptr; 
            }

        };

        //Cac phuong thuc ho tro iterator va reverse_iterator
        iterator begin(){ 
            return iterator(v); 
        }
        iterator end(){
            return iterator(v + num); 
        }
        reverse_iterator rbegin(){ 
            return reverse_iterator(v + num - 1); 
        }
        reverse_iterator rend(){ 
            return reverse_iterator(v - 1); 
        }
};

#endif

// int main() {
//     Vector<int> vec(3, 10); 
//     vec.push_back(20);     

   
//     cout << "Duyet xuoi: ";
//     for (Vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
//         cout << *it << " ";
//     }
//     cout << endl;

    
//     cout << "Duyet nguoc: ";
//     for (Vector<int>::reverse_iterator rit = vec.rbegin(); rit != vec.rend(); ++rit) {
//         cout << *rit << " ";
//     }
//     cout << endl;

//     return 0;
// }
