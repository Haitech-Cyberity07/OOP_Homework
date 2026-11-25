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
                cout<<"Nhap mon hoc thu "<<i+1<<" :"<<endl;
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
        HocKy h;
        h.nhap();
        hk.push_back(h);
    }
}
void tinChiTungHocKy(int n, vector<HocKy>& hk){
    
}
int main(){
    int n;
    cout<<"Nhap so hoc ky: "; cin>>n;
    vector<HocKy> hk;

}