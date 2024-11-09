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
        float GPA;

    public:
        SV(){};

        friend istream& operator>>(istream& is, SV& sv){
            cout << "Nhap thong tin sinh vien:\n";
            cout << "\tNhap ho va ten: "; is.ignore(); getline(is, sv.hoTen);
            cout << "\tNhap ngay thang nam sinh: "; is >> sv.ngaySinh >> sv.thangSinh >> sv.namSinh;
            cout << "\tNhap gioi tinh: "; is.ignore(); getline(is, sv.gioiTinh);
            cout << "\tNhap lop: "; is >> sv.lop;
            cout << "\tNhap diem tich luy: "; is >>sv.GPA;
            return is;

        }

        friend ostream& operator<<(ostream& os, SV& sv){
            os << "Thong tin sinh vien: \n";
            os << "\tHo va ten: " << sv.hoTen << "\n";
            os << "\tNgay sinh: " << sv.ngaySinh <<" / " << sv.thangSinh << " / " << sv.namSinh << "\n";
            os << "\tGioi tinh: " << sv.gioiTinh << "\n";
            os << "\tLop: " << sv.lop << "\n";
            os << "\tDiem tich luy: " << sv.GPA << "\n";
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

        float getGPA(){
            return GPA;
        }
};

class DS_SV{
    private:
        vector<SV> SinhVien;

    public:

        //Nhap danh sach sinh vien
        void nhapDanhSach() {
            char tiepTuc = 'c';
            while (tiepTuc == 'c') {
                SV sv;
                cin >> sv;
                SinhVien.push_back(sv);
                cout << "Co tiep tuc nhap nua khong? (c/k): ";
                cin >> tiepTuc;
            }
        }

        //Them sinh vien vao danh sach
        void themSinhVien(SV& sv){
            SinhVien.push_back(sv);
        }

        //Hien thi danh sach sinh vien
        void xuatDS(){
            for(auto& sv: SinhVien){
                cout << sv << "\n";
            }
        }

        //Sap xep danh sach sinh vien theo ho va ten
        void sapxepDS(){
            sort(SinhVien.begin(), SinhVien.end());
        }

        //Tim GPA cao nhat
        SV timGPAMax(){
            return *max_element(SinhVien.begin(), SinhVien.end());
        }


        //Tim GPA thap nhat
        SV timGPAMin(){
            return *min_element(SinhVien.begin(), SinhVien.end());
        }

        //Xoa sinh vien theo ma sinh vien
        void xoaSV(int& id){
            for(auto it = SinhVien.begin(); it != SinhVien.end(); ++it){
                if(it->getMaSV() == id){
                    SinhVien.erase(it);
                    cout << "Da xoa !!!\n";
                    return;
                }
            }
            cout << "Khong tim thay !!\n";
        }


        //Sua thong tin sinh vien theo ma sinh vien
        void suaThongTinSV(int& id){
            for(auto& sv: SinhVien){
                if(sv.getMaSV() == id){
                    cout << "Nhap thong tin moi cho sinh vien:\n";
                    cin >> sv;
                    return;
                }
            }
            cout << "Khong tim thay sinh vien nay!!\n";
        }

        //Tim kiem thong tin sinh vien theo ho ten
        void timKiemSV(string& name){
            int check = 0;
            for(auto& sv : SinhVien){
                if(sv.getHoTen() == name){
                    cout << "Thong tin sinh vien co ten " << name <<" la:\n";
                    cout << sv;
                    check++;
                }
            }
            if(!check) cout << "Khong tim thay sinh vien co ten: " << name << "\n";
        }

        //Kiem tra danh sach rong?
        bool ktraDSRong(){
            return SinhVien.empty();
        }
};

class APP{
    private:
        DS_SV qlySinhVien;

    public:
        void menu(){
            int choice;
            do {
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

                switch (choice) {
                    case 1:
                        qlySinhVien.nhapDanhSach();
                        break;

                    case 2:{
                        if(qlySinhVien.ktraDSRong()){
                            cout << "Danh sach sinh vien hien dang rong!!\n";
                        }
                        else{
                            qlySinhVien.xuatDS();
                        break;

                        }
                    }
                        
                    case 3: {
                        if(qlySinhVien.ktraDSRong()){
                            cout << "Danh sach sinh vien hien dang rong!!\n";
                        }
                        else{
                            int maSV;
                            cout << "Nhap ma sinh vien can xoa: ";
                            cin >> maSV;
                            qlySinhVien.xoaSV(maSV);
                            break;
                        }
                    }
                            
                    case 4: {
                        if(qlySinhVien.ktraDSRong()){
                            cout << "Danh sach sinh vien hien dang rong!!\n";
                        }
                        else{
                            int maSV;
                            cout << "Nhap ma sinh vien can sua: ";
                            cin >> maSV;
                            qlySinhVien.suaThongTinSV(maSV);
                            break;
                        }
                    }

                    case 5:
                        qlySinhVien.sapxepDS();
                        break;

                    case 6: {
                        if(qlySinhVien.ktraDSRong()){
                            cout << "Danh sach sinh vien hien dang rong!!\n";
                        }
                        else{
                            string hoTen;
                            cout << "Nhap ten sinh vien can tim: ";
                            cin.ignore();
                            getline(cin, hoTen);
                            qlySinhVien.timKiemSV(hoTen);
                            break;
                        }
                    }
                            
                    case 0:
                        cout << "Thoat chuong trinh!!!\n";
                        break;
                        
                    default:
                        cout << "Lua chon khong hop le!!\n";
                        break;
                }
            } while (choice != 0);
        }        
};

main(){
    APP app;
    app.menu();
    return 0;
}