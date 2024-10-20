//Quan li sinh vien bang danh sach lien ket

#include<bits/stdc++.h>
#include "vector.cpp"
#include "list.cpp"

using namespace std;

class SinhVien{
    private:
        int maSV;
        string ten;
        string gioiTinh;
        int tuoi;
        float diem;

    public:
        SinhVien(){}

        friend istream& operator>>(istream& is, SinhVien& sv){
            cout << "Nhap ma sinh vien: "; is >> sv.maSV;
            cout << "Nhap ten sinh vien: "; is.ignore(); getline(is, sv.ten);
            cout << "Nhap gioi tinh: "; is.ignore(); getline(is, sv.gioiTinh);
            cout << "Nhap tuoi: "; is >> sv.tuoi;
            cout << "Nhap diem: "; is >> sv.diem;
            return is;
        }

        friend ostream& operator<<(ostream& os, SinhVien& sv){
            os << "Ma sinh vien: " << sv.maSV << " Ten: " << sv.ten << " Gioi tinh: " << sv.gioiTinh << " Tuoi: " << sv.tuoi << " Diem: " << sv.diem << "\n";
            return os; 
        }

        bool operator<(SinhVien& other){
            return this->diem < other.diem;
        }

        string getTen(){
            return ten;
        }

        string getGioiTinh(){
            return gioiTinh;
        }

        int getTuoi(){
            return tuoi;
        }

        float getDiem(){
            return diem;
        }

};


class DS_SinhVien{
    private:
        vector<SinhVien> dsVector;
        list<SinhVien> dsList;


}