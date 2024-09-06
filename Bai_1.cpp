/*
Viết chương trình sử dụng toán tử cin, cout để nhập vào 3 số nguyên, kiểm tra xem 
nó có thể tạo thành 3 cạnh của tam giác vuông không? 
*/

#include<bits/stdc++.h>

using namespace std;

main(){
    cout << "Nhap 3 so nguyen a, b, c: ";
    int a, b, c;
    cin >> a >> b >> c;
    if(a + b > c && b + c > a && a + c > b ){
        cout << "3 canh tren la 3 canh cua tam giac!";
    }
    else{
        cout <<"3 canh tren khong la 3 canh cua tam giac!";
    }
}