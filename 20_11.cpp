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
        ~Nguoi(){}

        virtual void nhap(){
            cout<<"Nhap cccd: "; getline(cin>>ws, cccd);
            cout<<"Nhap ho va ten: "; getline(cin>>ws, hoTen);
        }
        virtual void xuat(){
            cout<<"CCCD: "<<cccd<<endl;
            cout<<"Ho va ten: "<<hoTen<<endl;
        }

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
            cout<<"Nhap nam sinh: "; cin>>namSinh;
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
        string getHoTen(){return hoTen;}
};

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
            cout<<"Nhap diem: "; cin>>diem;
            cin.ignore(1000, '\n');
        }
        void xuat() override{
            cout<<"Ma lop: "<<maLop<<endl;
            cout<<"Diem: "<<diem<<endl;
        }
        double getDiem(){return diem;}

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
void timNhanVien(int n, string ten, vector<NhanVien>& nv){
    bool timThay = false;
    for(int i=0; i<n; i++){
        if(nv[i].getHoTen() == ten){
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

void nhapSinhVien(int m, vector<SinhVien>& sv){
    for(int i=0; i<m; i++){
        cout<<"Nhap sinh vien thu "<<i+1<<" :"<<endl;
        sv[i].nhap();
        cout<<endl;
    }
}
double diemThapNhat(int m, vector<SinhVien>& sv){
    int min = sv[0].getDiem();
    for(int i=1; i<m; i++){
        if(sv[i].getDiem() < min){
            min = sv[i].getDiem();
        }
    }
    return min;
}
int main(){
    //nhan vien
    int n;
    cout<<"Nhap so nhan vien: "; cin>>n;
    vector<NhanVien> nv(n);
    cout<<endl<<"Nhap thong tin nhan vien: "<<endl;
    nhapNhanVien(n, nv);
    cout<<"Nhan vien co tuoi cao nhat sinh nam: "<<nhanVienTuoiCaoNhat(n, nv)<<endl;
    string ten;
    cout<<"Nhap ten nhan vien can tim: ";
    getline(cin>>ws, ten);
    timNhanVien(n, ten, nv);
    //sinh vien
    int m;
    cout<<"Nhap so sinh vien: "; cin>>m;
    vector<SinhVien> sv(m);
    cout<<"Nhap thong tin sinh vien: "<<endl;
    nhapSinhVien(m, sv);
    cout<<"Sinh vien co diem thap nhat la: "<<diemThapNhat(m, sv)<<endl;
    
    return 0;
}