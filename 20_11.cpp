#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Nguoi{
    protected:
        string cccd, hoTen;
    public:
        Nguoi(){}
        Nguoi(string cccd, string hoTen) : cccd(cccd), hoTen(hoTen) {}
        virtual ~Nguoi(){}

        virtual void nhap(){
            cout<<"Nhap cccd: "; getline(cin>>ws, cccd);
            cout<<"Nhap ho va ten: "; getline(cin>>ws, hoTen);
        }
        virtual void xuat(){
            cout<<"CCCD: "<<cccd<<endl;
            cout<<"Ho va ten: "<<hoTen<<endl;
        }
        string getHoTen(){return hoTen;}
};
class NhanVien : public Nguoi{
    private:
        int namSinh;
        double heSoLuong;
        
    public:
        NhanVien(){}
        NhanVien(int namSinh, double heSoLuong) : namSinh(namSinh), heSoLuong(heSoLuong){}
        void nhap() override{
            Nguoi :: nhap();
            cout<<"Nhap nam sinh (>1900): "; cin>>namSinh;
            cout<<"Nhap he so luong: "; cin>>heSoLuong;
            cin.ignore(1000, '\n');
        }
        void xuat() override{
            Nguoi :: xuat();
            cout<<"Nam sinh: "<<namSinh<<endl;
            cout<<"He so luong: "<<heSoLuong<<endl;
        }
        int getNamSinh(){return namSinh;}
        double getHeSoLuong(){return heSoLuong;}
        double tinhLuong(){return heSoLuong * 1.5;}
};
void nhapNhanVien(int n, vector<NhanVien>& nv){
    for(int i=0; i<n; i++){
        cout<<"Nhap nhan vien thu "<<i+1<<" :"<<endl;
        nv[i].nhap();
        cout<<endl;
    }
}
int nhanVienTuoiCaoNhat(int n, vector<NhanVien>& nv){
    int maxTuoi = nv[0].getNamSinh();
    for(int i=1; i<n; i++){
        if(nv[i].getNamSinh()<maxTuoi){     //nam sinh cang nho tuoi cang lon
            maxTuoi = nv[i].getNamSinh();
        }
    }
    return maxTuoi;
}
void timNhanVien(int n, string tenNhanVien, vector<NhanVien>& nv){
    bool timThay = false;
    for(int i=0; i<n; i++){
        if(nv[i].getHoTen() == tenNhanVien){
            timThay = true;
            nv[i].xuat();
            cout<<"Luong: "<<nv[i].tinhLuong()<<endl;
            break; 
        }
    }
    if(timThay == false){
        cout<<"Khong tim thay nhan vien co ten vua nhap!"<<endl;
    }
}

class SinhVien : public Nguoi{
    private:
        int maLop;
        double diem;
    public:
        SinhVien(){}
        SinhVien(int maLop, double diem) : maLop(maLop), diem(diem){}
        void nhap() override{
            Nguoi :: nhap();
            cout<<"Nhap ma lop (1, 2, 3): "; cin>>maLop;
            cout<<"Nhap diem (thang 10): "; cin>>diem;
            cin.ignore(1000, '\n');
        }
        void xuat() override{
            Nguoi :: xuat();
            cout<<"Ma lop: "<<maLop<<endl;
            cout<<"Diem: "<<diem<<endl;
        }
        double getDiem(){return diem;}
        int getMaLop(){return maLop;}

};

void nhapSinhVien(int m, vector<SinhVien>& sv){
    for(int i=0; i<m; i++){
        cout<<"Nhap sinh vien thu "<<i+1<<" :"<<endl;
        sv[i].nhap();
        cout<<endl;
    }
}
double diemThapNhat(int m, vector<SinhVien>& sv){
    double min = sv[0].getDiem();
    for(int i=1; i<m; i++){
        if(sv[i].getDiem() < min){
            min = sv[i].getDiem();
        }
    }
    return min;
}
int demSinhVienTruot(double diemChuan, int m, vector<SinhVien>& sv){
    int dem=0;
    for(int i=0; i<m; i++){
        if(sv[i].getDiem() < diemChuan){
            dem++;
        }
    }
    return dem;
}
void thongKe(int m, vector<SinhVien>& sv){
    int dem1=0, dem2=0, dem3=0;
    int demMax=0;
    for(int i=0; i<m; i++){
        if(sv[i].getMaLop() == 1){
            dem1++;
        }else if(sv[i].getMaLop() == 2){
            dem2++;
        }else if(sv[i].getMaLop() == 3){
            dem3++;
        }
    }
    demMax = dem1;
    if(dem2>demMax) demMax = dem2;
    if(dem3>demMax) demMax = dem3;
    if(demMax==0){
        cout<<"Danh sach rong!"<<endl;
        return;
    }
    cout<<"Ma lop 1 co "<<dem1<<" sinh vien."<<endl;
    cout<<"Ma lop 2 co "<<dem2<<" sinh vien."<<endl;
    cout<<"Ma lop 3 co "<<dem3<<" sinh vien."<<endl;
    
    cout<<"Ma lop co nhieu sinh vien nhat la: ";
    if(demMax==dem1) cout<<"1 ";
    if(demMax==dem2) cout<<"2 ";
    if(demMax==dem3) cout<<"3 ";
}
void sinhVienTruot(double diemChuan, string tenSinhVien, int m, vector<SinhVien>& sv){
    bool timThay = false;
    for(int i=0; i<m; i++){
        if(sv[i].getHoTen()==tenSinhVien){
            timThay=true;
            if(sv[i].getDiem()<diemChuan){
                cout<<"Sinh vien truot!"<<endl;
                break;
            }else{
                cout<<"Sinh vien do!"<<endl;
                break;
            }
        }
    }
    if(timThay == false){
        cout<<"Sinh vien nhap vao khong co trong danh sach!"<<endl;
    }
}
int main(){
    //nhan vien
    int n;
    cout<<"Nhap so nhan vien (n>0): "; cin>>n;
    vector<NhanVien> nv(n);
    cout<<endl<<"Nhap thong tin nhan vien: "<<endl;
    nhapNhanVien(n, nv);
    cout<<"Nhan vien co tuoi cao nhat sinh nam: "<<nhanVienTuoiCaoNhat(n, nv)<<endl;
    string tenNhanVien = "";
    cout<<"Nhap ten nhan vien can tim: ";   getline(cin>>ws, tenNhanVien);
    timNhanVien(n, tenNhanVien, nv);
    //sinh vien
    int m;
    cout<<endl<<"Nhap so sinh vien (m>0): "; cin>>m;
    vector<SinhVien> sv(m);
    cout<<endl<<"Nhap thong tin sinh vien: "<<endl;
    nhapSinhVien(m, sv);
    cout<<"Sinh vien co diem thap nhat la: "<<diemThapNhat(m, sv)<<endl;
    double diemChuan;
    cout<<"Nhap diem chuan (thang 10): ";  cin>>diemChuan;
    cout<<"So sinh vien truot voi diem chuan "<<diemChuan<<" la: "<<demSinhVienTruot(diemChuan, m, sv)<<endl;
    string tenSinhVien = "";
    cout<<"Nhap ten sinh vien can kiem tra (do hoac truot): ";  getline(cin>>ws, tenSinhVien);
    sinhVienTruot(diemChuan, tenSinhVien, m, sv);
    
    return 0;
}