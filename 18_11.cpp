#include <iostream>
using namespace std;

class DaySo{
	private:
		int n;
		int *a;
	public:
		DaySo(){
			n=0;
			a=nullptr;
		}
		DaySo(int n, int *a){
			this->n = n;
			this->a = new int[n];
			for(int i=0; i<n; i++){
				this->a[i] = a[i];
			}
		}
		~DaySo(){
			delete[] a;
		}
		friend istream& operator>>(istream& in, DaySo& ds);
		friend ostream& operator<<(ostream& out, const DaySo& ds);
		int timMaxChan();
		long long tichKhoang(int a, int b);
		bool tatCaAm();
        void sapXepTang();
};
istream& operator>>(istream& in, DaySo& ds){
	cout<<"Nhap so luong phan tu cua day: "; in>>ds.n;
	delete[] ds.a;
	ds.a = new int[ds.n];
	cout<<"Nhap phan tu (so nguyen) cua day: "<<endl;
	for(int i=0; i<ds.n; i++){
		cout<<"a["<<i<<"] = "; in>>ds.a[i];
		cout<<endl;
	}
	return in;
}
ostream& operator<<(ostream& out, const DaySo& ds){
	for(int i=0; i<ds.n; i++){
		out<<ds.a[i]<<" ";
	}
	return out;
}
int DaySo::timMaxChan(){
	bool coChan = false;
	int maxChan = -1e9;
	for(int i=0; i<n; i++){
		if(a[i]%2==0){
			coChan=true;
			if(a[i]>maxChan){
				maxChan = a[i];
			}
		}
	}
	if(coChan==false){
		cout<<"Khong co phan tu chan trong day!"<<endl;
		return -1;
	}
	return maxChan;
}
long long DaySo::tichKhoang(int a, int b){
	long long tich = 1;
	bool coPhanTu = false;
	
	for(int i=0; i<n; i++){
		if(this->a[i]>=a && this->a[i]<=b){
			coPhanTu = true;
			tich*=this->a[i];
		}	
	}
	if(coPhanTu == false){
		cout<<"Khong co phan tu nao nam trong khoang ["<<a<<","<<b<<"] !"<<endl;
		return -1;
	}
	return tich;
}
bool DaySo::tatCaAm(){
	for(int i=0; i<n; i++){
		if(a[i]>=0){
			return false;
		}
	}
	return true;
}
void DaySo::sapXepTang(){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i]>a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
int main(){
	DaySo ds;
	cin>>ds;
	cout<<"Day so nguyen vua nhap vao mang: ";
	cout<<ds;
	
	int maxChan = ds.timMaxChan();
	cout<<"\nPhan tu chan lon nhat trong day la: "<<maxChan<<endl;
	
	int a, b;
	cout<<"Nhap khoang [a,b]: "; cin>>a>>b;
	long long tich = ds.tichKhoang(a, b);
	cout<<"\nTich cac phan tu nam trong khoang ["<<a<<","<<b<<"] la: "<<tich<<endl;
	
	if(ds.tatCaAm()){
		cout<<"Day toan so am!"<<endl;
	}else{
        cout<<"Day xuat hien so duong! khong am hoan toan"<<endl;
    }

    ds.sapXepTang();
    cout<<"Day so sau khi sap xep tang dan la: "<<ds<<endl;
	return 0;
}