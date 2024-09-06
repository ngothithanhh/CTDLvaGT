/*
Viết hàm mẫu (template) tìm max của hai số, áp dụng tìm max của 2 số nguyên và 
hai số thực.
*/

#include<bits/stdc++.h>

using namespace std;

template <typename T>
T fMax(T a, T b){
    if(a > b) return a;
    return b;
}

main(){
    int a, b;
    float c, d;
    cout << "Nhap hai so nguyen: "; cin >> a >> b;
    cout <<"Nhap hai so thuc: "; cin >> c >> d;
    cout <<"Max cua 2 so nguyen: " << fMax<int>(a,b) <<"\n";
    cout <<"Max cua 2 so thuc: " << fMax<float>(c,d);

}