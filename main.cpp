#include <bits/stdc++.h>

using namespace std;

class sanpham{
private:
    string masp;
    string mangban;
    string ten;
    string ttrang;
    double gia;
    bool daban;
public:
    void nhap() {
        cout << "Ma SP: "; cin >> masp;
        cin.ignore();
        cout << "Ten: "; getline(cin, ten);
        cout << "Tinh trang: "; getline(cin, ttrang);
        cout << "Gia: "; cin >> gia;
        cout << "Ma nguoi ban: "; cin >> mangban;
        daban = false;
    }
    void xuat() {
        cout << masp << " | " << ten << " | " << ttrang
             << " | " << gia << " | ";
        if(daban)cout<<"da ban"; else cout<<"chua ban";
    }
    string getmasp(){
        return masp;
    }
    string getmangban(){
        return mangban;
    }
    bool spdaban(){
        return daban;
    }
};
class nguoi{
protected:
    string ten;
    string diachi;
    string sdt;
    string gtinh;
    int tuoi;
public:
    void input(){
        cin.ignore();
        cout << "ho ten: "; getline(cin, ten);
        cin.ignore();
        cout << "dia chi: "; getline(cin, diachi);
        cin.ignore();
        cout << "sdt: "; getline(cin, sdt);
        cout << "tuoi: "; cin >> tuoi;
        cin.ignore();
        cout << "gioi tinh: "; getline(cin, gtinh);
    }
    void output(){
        cout << ten << " | " << diachi << " | " << sdt << endl;
    }
};
class nguoiban : public nguoi{
private:
    string mangban;
public:
    void nhap(){
        cout << "ma nguoi ban: "; cin>>mangban;
        nguoi::input();
    }
    string getma(){
        return mangban;
    }
};
class nguoimua : public nguoi{
private: 
    string mangmua;
public:
    void nhap(){
        cout << "ma nguoi mua: "; cin >> mangmua;
        nguoi::input();
    }
    string getma(){
        return mangmua;
    }
};

int main(){

}
// friend istream& operator>>(istream &in, ){};
// friend ostream& operator<<(ostream &out,){};
