#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MonHoc{
    private:
        string maMon, tenMon;
        int soTinChi;
    public:
        MonHoc(){
            soTinChi=0;
        }
        MonHoc(string maMon, string tenMon, int soTinChi) : maMon(maMon), tenMon(tenMon), soTinChi(soTinChi) {}
        
        void nhap(){
            cout<<"Nhap ma mon hoc: "; getline(cin>>ws, maMon);
            cout<<"Nhap ten mon hoc: "; getline(cin, tenMon);
            cout<<"Nhap so tin chi cua mon hoc: "; cin>>soTinChi;
        }
        void xuat(){
            cout<<"Ma mon: "<<maMon<<endl;
            cout<<"Ten mon: "<<tenMon<<endl;
            cout<<"So tin chi: "<<soTinChi<<endl;
        }
        int getSoTinChi(){return soTinChi;}
};

class HocKy{
    private:
        string maKyHoc;
        int soMonHoc;
        vector<MonHoc> ds;
    public:
        HocKy(){
            soMonHoc = 0;
        }
        HocKy(string maKyHoc, int soMonHoc){
            this->maKyHoc = maKyHoc;
            this->soMonHoc = soMonHoc;
        }
        void nhap(){
            cout<<"Nhap ma ky hoc: "; getline(cin>>ws, maKyHoc);
            cout<<"Nhap so mon hoc: "; cin>>soMonHoc;
            ds.clear();
            for(int i=0; i<soMonHoc; i++){
                cout<<"\nNhap mon hoc thu "<<i+1<<" :"<<endl;
                MonHoc mh;
                mh.nhap();
                ds.push_back(mh);
            }
        }
        void xuat(){
            cout<<"Ma ky hoc: "<<maKyHoc<<endl;
            for(int i=0; i<ds.size(); i++){
                cout<<"Mon hoc thu "<<i+1<<" :"<<endl;
                ds[i].xuat();
            }
        }
        int tongTinChi(){
            int tong=0;
            for(int i=0; i<ds.size(); i++){
                tong+=ds[i].getSoTinChi();
            }
            return tong;
        }
        string getMaKyHoc(){return maKyHoc;}

};

void nhapDanhSachKyHoc(int n, vector<HocKy>& hk){
    for(int i=0; i<n; i++){
        cout<<"Hoc ky thu "<<i+1<<" :"<<endl;
        hk[i].nhap();
        cout<<endl;
    }
}
void tinChiTungHocKy(int n, vector<HocKy>& hk){
    for(int i=0; i<n; i++){
        cout<<"Hoc ky: "<<hk[i].getMaKyHoc()<<endl;
        cout<<"Tong so tin chi: "<<hk[i].tongTinChi()<<endl;
    }
}
void hocKyNhieuTinChiNhat(int n, vector<HocKy>& hk){
    if(n==0) return;
    int maxTinChi=hk[0].tongTinChi();
    for(int i=1; i<n; i++){
        if(hk[i].tongTinChi()>maxTinChi){
            maxTinChi = hk[i].tongTinChi();
        }
    }
    cout<<"Hoc ky co nhieu tin chi nhat la: "<<endl;
    for(int i=0; i<n; i++){
        if(hk[i].tongTinChi() == maxTinChi){
            cout<<"Ma hoc ky: "<<hk[i].getMaKyHoc()<<endl;
            cout<<"Tong tin chi: "<<maxTinChi<<endl;
        }
    }
}
int main(){
    int n;
    cout<<"Nhap so hoc ky: "; cin>>n;
    vector<HocKy> hk(n);
    cout<<"Nhap danh sach hoc ky: "<<endl;
    nhapDanhSachKyHoc(n, hk);
    cout<<"Tong tin chi tung hoc ky: "<<endl;
    tinChiTungHocKy(n, hk);
    
    hocKyNhieuTinChiNhat(n, hk);
    return 0;
}