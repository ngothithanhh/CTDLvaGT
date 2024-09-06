/*
 Viết hàm tìm giá trị lớn nhất (max) và giá trị nhỏ nhất (min) của 3 số nguyên theo 
nguyên mẫu dưới đây. Viết hàm main cho phép nhập vào 3 số nguyên tìm giá trị lớn nhất 
và nhỏ nhất bằng hàm đã xây dựng. 
void maxmin(int a, int b, int c, int &max, int &min); 
*/

#include<bits/stdc++.h>

using namespace std;

void maxmin(int a, int b, int c, int &max, int &min){
    max = a;
    min = a;

    if(b > max) max = b;
    if(c > max) max = c;

    if(b < min) min = b;
    if(c < min) min = c;
}

main(){
    int a, b, c, max, min;
    cout <<"Nhap 3 so nguyen: ";
    cin >> a >> b >> c;
    maxmin(a , b, c, max, min);
    if(max == min) cout <<"Khong co";
    else{
        cout <<"Gia tri lon nhat " << max << "\n";
        cout <<"Gia tri nho nhat " << min;
    } 
    

}