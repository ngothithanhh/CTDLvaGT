/*
Viết hàm mẫu (template) tìm ước chung lớn nhất của 2 số. 
*/

#include<bits/stdc++.h>

using namespace std;

template <typename T>
T UCLN(T a, T b){
    while(b != 0){
        T tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
main(){
    cout <<"UCLN cua 2 so nguyen: " <<UCLN<int>(4, 8);

}