#include<bits/stdc++.h>
#include<vector>

using namespace std;

class SV{
    private:
        int maSV;
        string hoTen;
        int ngaySinh;
        int thangSinh;
        int namSinh;
        string gioiTinh;
        string lop;

    public:
        SV(){}

        friend istream& operator>>(istream& is, SV& sv){
            cout << "Nhap thong tin sinh vien:\n";
            cout << "\tNhap ho va ten: "; is.ignore(); getline(is, sv.hoTen);
            cout << "\tNhap ngay thang nam sinh: "; is >> sv.ngaySinh >> sv.thangSinh >> sv.namSinh;
            cout << "\tNhap gioi tinh: "; is.ignore(); getline(is, gioiTinh);
            cout << "\tNhap lop: "; is >> sv.lop;
            return is;

        }

        friend ostream& operator<<(ostream& os, SV& sv){
            os << "Thong tin sinh vien: \n";
            os << "\tHo va ten: " << sv.hoTen << "\n";
            os << "\tNgay sinh: " << sv.ngaySinh <<" / " << sv.thangSinh << " / " << sv.namSinh << "\n";
            os << "\tGioi tinh: " << sv.gioiTinh << "\n";
            os << "\tLop: " << sv.lop << "\n";
            return os;
        }

        bool operator<(const SV& other) const {
        return hoTen < other.hoTen;
        }

        int getMaSV(){
            return maSV;
        }

        string getHoTen(){
            return hoTen;
        }



};

class DS_SV{
    private:
        vector<SV> SinhVien;

    public;
        void themSinhVien(SV& sv){
            SinhVien.push_back(sv);
        }

        void xuatDS(){
            for(auto& sv: SinhVien){
                cout << sv << "\n";
            }
        }

        void sapxepDS(){
            sort(SinhVien.begin(), SinhVien.end());
        }

        SV timDiemMax(){
            return *max_element(SinhVien.begin(), SinhVien.end());
        }

        SV timDiemMin(){
            return *min_element(SinhVien.begin(), SinhVien.end())
        }

        void xoaSV(string& id){
            for(auto it = SinhVien.begin(); it != SinhVien.end(); ++it){
                

            }
        }


};

main(){}