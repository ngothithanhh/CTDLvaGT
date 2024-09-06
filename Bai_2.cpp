/*
Nhập vào xâu ký tự (kiểu string) bằng cin, chuyển đổi xâu ký tự đó thành xâu ký tự 
hoa, xâu ký tự thường,  in ra màn hình xâu ký tự hoa, xâu ký tự tường. 
Ví dụ:  - - 
Nhập vào:  Hello World 
In ra màn hình: HELLO WORLD và hello world
*/

#include<bits/stdc++.h>
#include<string>

using namespace std;

main(){
    string s;
    cout <<"Nhap xau ki tu:";
    getline(cin, s); 
    string upper_s = s, lower_s = s;
    for(int i = 0; i < s.length(); i++){
        if(upper_s[i] >='a' && upper_s[i] <='z'){
            upper_s[i] = upper_s[i] - ('a'-'A');
        }
        if(lower_s[i] >='A' && lower_s[i] <='Z'){
            lower_s[i] = lower_s[i] + ('a'-'A');
        }
    }

    cout << upper_s << "   " << lower_s;
}