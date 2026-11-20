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
};
void nhapNhanVien(int n, vector<NhanVien>& nv){
    for(int i=0; i<n; i++){
        nv[i].nhap();
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

int main(){
    int n;
    cout<<"Nhap n nhan vien: "; cin>>n;
    int m;
    cout<<"Nhap m sinh vien: "; cin>>m;
    vector<NhanVien> nv(n);
    vector<SinhVien> sv(m);
    cout<<"Nhap thong tin nhan vien: "<<endl;
    nhapNhanVien(n, nv);
    cout<<"Nhan vien co tuoi cao nhat sinh nam: "<<nhanVienTuoiCaoNhat(n, nv)<<endl;

}