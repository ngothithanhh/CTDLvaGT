/*
Viết hàm mẫu (template) nhập 1 dãy số từ bàn phím,  hàm mẫu (template) in một 
dãy số ra màn hình. Viết hàm main, sử dụng các hàm này nhập vào và in ra màn hình 1 
dãy số thực. 

*/

#include<bits/stdc++.h>

using namespace std;

template <class T>
void input(int n, T arr[]){
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
}
template <class T>
void out(int n, T arr[]){
    for(int i = 0; i < n; i++){
        cout << arr[i] <<" ";
    }
}

main(){
    int n;
    cout <<"Nhap n: "; cin >> n;
    cout <<"Nhap day so thuc:";
    float arr[n];
    input<float>(n, arr);
    cout <<"Day so thuc vua nhap: ";
    out<float>(n, arr);
}
