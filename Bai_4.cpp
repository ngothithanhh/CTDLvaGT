/*
Viết hàm có đối mặc định để có thể vừa tìm max hoặc tìm min tùy theo đối ismax 
theo nguyên mẫu dưới đây, sau đó viết hàm main nhập vào 3 số nguyên khác nhau tìm số 
không phải max, min bằng cách tính tổng rồi trừ đi max và min. 
int MaxMin(int a, int b, int c, bool ismax = true);
*/

#include<bits/stdc++.h>

using namespace std;

int MaxMin(int a, int b, int c, bool ismax = true){
    if(ismax){
        int max = a;
        if(b > max) max = b;
        if(c > max) max = c;
        return max;
    }
    else{
        int min = a;
        if(b < min) min = b;
        if(c < min) min = c;
        return min;
    }
}

main(){
    int a, b, c;
    cout <<"Nhap a, b, c:";
    cin >> a >> b >> c;
    int max_val = MaxMin(a, b, c,true);
    int min_val = MaxMin(a, b, c, false);
    cout << (a + b + c) - max_val - min_val;

}