#include<iostream>
#include "single_list.cpp"

using namespace std;

class SV{
    private:
        int MaSV;
        string Hoten;
        int Ngay, Thang, Namsinh;
        string Gioitinh;
        string Quequan;

    public:

        SV(){}

        SV(int ma, string ten, int ngaySinh, int thangSinh, int namSinh, string gioiTinh, string queQuan){
            this->MaSV = ma;
            this->Hoten = ten;
            this->Ngay = ngaySinh;
            this->Thang = thangSinh;
            this->Namsinh = namSinh;
            this->Gioitinh = Gioitinh;
            this->Quequan = queQuan;
        }

        void display() {
        cout << "MaSV: " << maSv << ", Ho ten: " << hoTen 
            << ", Ngay sinh: " << ngay << "/" << thang << "/" << nam 
                  << ", Gioi tinh: " << gioiTinh << ", Que quan: " << queQuan << std::endl;
    } 

}