//Quan li sinh vien bang vector

#include<iostream>
#include "vector.cpp"

using namespace std;

class SinhVien{
    private:
        int maSV;
        string ten;
        string gioiTinh;
        int tuoi;
        float diem;
        string lop;

    public:
        SinhVien(){}

        friend istream& operator>>(istream& is, SinhVien& sv){
            cout << "Nhap ma sinh vien: "; is >> sv.maSV;
            cout << "Nhap ten sinh vien: "; is.ignore(); getline(is, sv.ten);
            cout << "Nhap gioi tinh: "; is.ignore(); getline(is, sv.gioiTinh);
            cout << "Nhap tuoi: "; is >> sv.tuoi;
            cout << "Nhap diem: "; is >> sv.diem;
            cout << "Nhap lop: "; is.ignore(); getline(is, sv.lop);
            return is;
        }

        friend ostream& operator<<(ostream& os, SinhVien& sv){
            os << "Ma sinh vien: " << sv.maSV << " Ten: " << sv.ten << " Gioi tinh: " << sv.gioiTinh << " Tuoi: " << sv.tuoi << " Diem: " << sv.diem << "Lop: " << sv.lop <<"\n";
            return os; 
        }

        bool operator<(SinhVien& other){
            return this->ten < other.ten;
        }

        string getTen(){
            return ten;
        }

        string getGioiTinh(){
            return gioiTinh;
        }

        int getMaSV(){
            return maSV;
        }

        int getTuoi(){
            return tuoi;
        }

        float getDiem(){
            return diem;
        }

        string getLop(){
            return lop;
        }

        void suaThongTin(){
            cin >> *this;
        }

};


class DS_SinhVien{
    private:
        Vector<SinhVien> ds;

    public:

        void themSV(){
            char tieptuc = 'c';
            while (tieptuc){
                SinhVien sv;
                cin >> sv;
                ds.push_back(sv);
                cout << "Co nhap nua khong? (c/k): "; cin >> tieptuc;
            }
        }

        void xoaSV(int& maSV){
            int check = 0;
            for(int i = 0; i < ds.size(); i++){
                if(ds[i].getMaSV() == maSV){
                    check++;
                    ds.erase(i);
                    break;
                }
            }

            if(check == 0){
                cout << "Khong tim thay sinh vien co ma: " << maSV << "\n";
            }
            else{
                cout << "Da xoa\n";
            }
        }

        void suaThongTinSV(int& maSV){
            for(int i = 0; i < ds.size(); i++){
                if(ds[i].getMaSV() == maSV){
                    cout << ds[i] << "\n";
                    cout << "Nhap thong tin moi cho sinh vien: ";
                    ds[i].suaThongTin();
                }
            }
        }

        void sapXepSV(){
            for(int i = 0; i < ds.size() - 1; i++){
                for(int j = i + 1; j < ds.size(); j++){
                    if(ds[i].getTen() > ds[j].getTen()){
                        swap(ds[i], ds[j]);
                    }
                }
            }

            cout << "Da sap xep\n";
        }

        void hienThiDSSV(){
            cout << "Danh sach sinh vien co trong vector:\n";
            for(int i = 0; i < ds.size(); i++){
                cout << ds[i] << "\n";
            }
        }

        void timKiemSV(string& ten){
            int check = 0;
            for(int i = 0; i < ds.size(); i++){
                if(ds[i].getTen() == ten){
                    check++;
                    cout << ds[i] << "\n";
                }
            }

            if(check){
                cout << "Khong tim thay sinh vien co ten: " << ten << "\n";
            }
        }
};

class App{
    private:
        DS_SinhVien qlSV;

    public:
        void menu(){
            int choice;
            cout << "\n===== Menu Quan Ly Sinh Vien =====\n";
            cout << "1. Nhap danh sach sinh vien\n";
            cout << "2. Hien thi danh sach sinh vien\n";
            cout << "3. Xoa sinh vien\n";
            cout << "4. Sua thong tin sinh vien\n";
            cout << "5. Sap xep sinh vien theo ho ten\n";
            cout << "6. Tim kiem sinh vien theo ho ten\n";
            cout << "0. Thoat\n";
            cout << "Nhap lua chon: ";
            cin >> choice;
        }

};