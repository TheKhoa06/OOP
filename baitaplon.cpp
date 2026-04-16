#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

class sanpham {
private:
    string masp;
    string mangban;
    string ten;
    string ttrang;
    double gia;
    bool daban;
public:
    sanpham() {
        masp = "";
        mangban = "";
        ten = "";
        ttrang = "";
        gia = 0;
        daban = false;
    }

    void nhap() {
        cout << "Ma SP: ";
        cin >> masp;
        cin.ignore();

        cout << "Ten: ";
        getline(cin, ten);

        cout << "Tinh trang: ";
        getline(cin, ttrang);

        cout << "Gia: ";
        cin >> gia;

        cout << "Ma nguoi ban: ";
        cin >> mangban;

        daban = false;
    }

    void xuat() const {
        cout << masp << " | " << ten << " | " << ttrang
             << " | " << fixed << setprecision(0) << gia << " | " << mangban << " | ";
        if (daban) cout << "da ban";
        else cout << "chua ban";
        cout << endl;
    }

    string getmasp() const {
        return masp;
    }

    string getmangban() const {
        return mangban;
    }

    bool spdaban() const {
        return daban;
    }

    void setdaban(bool x) {
        daban = x;
    }
};

class nguoi {
protected:
    string ten;
    string diachi;
    string sdt;
    string gtinh;
    int tuoi;
public:
    nguoi() {
        ten = "";
        diachi = "";
        sdt = "";
        gtinh = "";
        tuoi = 0;
    }

    void input() {
        cout << "Ho ten: ";
        getline(cin, ten);

        cout << "Dia chi: ";
        getline(cin, diachi);

        cout << "SDT: ";
        getline(cin, sdt);

        cout << "Tuoi: ";
        cin >> tuoi;
        cin.ignore();

        cout << "Gioi tinh: ";
        getline(cin, gtinh);
    }

    void output() const {
        cout << ten << " | " << diachi << " | " << sdt
             << " | " << tuoi << " | " << gtinh;
    }
};

class nguoiban : public nguoi {
private:
    string mangban;
    int soluonggiaodich;
public:
    nguoiban() {
        mangban = "";
        soluonggiaodich = 0;
    }

    void nhap() {
        cout << "Ma nguoi ban: ";
        cin >> mangban;
        cin.ignore();
        nguoi::input();
    }

    void xuat() const {
        cout << "Ma nguoi ban: " << mangban << " | ";
        output();
        cout << " | So giao dich: " << soluonggiaodich << endl;
    }

    string getma() const {
        return mangban;
    }

    void tanggiaodich() {
        soluonggiaodich++;
    }
};

class nguoimua : public nguoi {
private:
    string mangmua;
    int soluongmua;
public:
    nguoimua() {
        mangmua = "";
        soluongmua = 0;
    }

    void nhap() {
        cout << "Ma nguoi mua: ";
        cin >> mangmua;
        cin.ignore();
        nguoi::input();
    }

    void xuat() const {
        cout << "Ma nguoi mua: " << mangmua << " | ";
        output();
        cout << " | So luong mua: " << soluongmua << endl;
    }

    string getma() const {
        return mangmua;
    }

    void tangmua() {
        soluongmua++;
    }
};

class giaodich {
private:
    string magd;
    string mamua;
    string maban;
    string masp;
public:
    giaodich() {
        magd = "";
        mamua = "";
        maban = "";
        masp = "";
    }

    void nhap() {
        cout << "Ma giao dich: ";
        cin >> magd;
        cout << "Ma nguoi mua: ";
        cin >> mamua;
        cout << "Ma nguoi ban: ";
        cin >> maban;
        cout << "Ma san pham: ";
        cin >> masp;
    }

    void xuat() const {
        cout << "Ma GD: " << magd
             << " | Ma nguoi mua: " << mamua
             << " | Ma nguoi ban: " << maban
             << " | Ma SP: " << masp << endl;
    }

    string getmagd() const {
        return magd;
    }

    string getmamua() const {
        return mamua;
    }

    string getmaban() const {
        return maban;
    }

    string getmasp() const {
        return masp;
    }
};

class quanli {
private:
    sanpham dssp[MAX];
    nguoiban dsnb[MAX];
    nguoimua dsnm[MAX];
    giaodich dsgd[MAX];

    int slsp;
    int slnb;
    int slnm;
    int slgd;

public:
    quanli() {
        slsp = 0;
        slnb = 0;
        slnm = 0;
        slgd = 0;
    }

    int timsp(string ma) {
        for (int i = 0; i < slsp; i++) {
            if (dssp[i].getmasp() == ma) return i;
        }
        return -1;
    }

    int timnguoiban(string ma) {
        for (int i = 0; i < slnb; i++) {
            if (dsnb[i].getma() == ma) return i;
        }
        return -1;
    }

    int timnguoimua(string ma) {
        for (int i = 0; i < slnm; i++) {
            if (dsnm[i].getma() == ma) return i;
        }
        return -1;
    }

    void themnguoiban() {
        if (slnb >= MAX) {
            cout << "Danh sach nguoi ban da day!\n";
            return;
        }
        dsnb[slnb].nhap();
        slnb++;
        cout << "Them nguoi ban thanh cong!\n";
    }

    void themnguoimua() {
        if (slnm >= MAX) {
            cout << "Danh sach nguoi mua da day!\n";
            return;
        }
        dsnm[slnm].nhap();
        slnm++;
        cout << "Them nguoi mua thanh cong!\n";
    }

    void themsanpham() {
        if (slsp >= MAX) {
            cout << "Danh sach san pham da day!\n";
            return;
        }
        dssp[slsp].nhap();
        slsp++;
        cout << "Them san pham thanh cong!\n";
    }

    void themgiaodich() {
        if (slgd >= MAX) {
            cout << "Danh sach giao dich da day!\n";
            return;
        }

        giaodich gd;
        gd.nhap();

        int vtsp = timsp(gd.getmasp());
        int vtban = timnguoiban(gd.getmaban());
        int vtmua = timnguoimua(gd.getmamua());

        if (vtsp == -1) {
            cout << "Khong tim thay san pham!\n";
            return;
        }
        if (vtban == -1) {
            cout << "Khong tim thay nguoi ban!\n";
            return;
        }
        if (vtmua == -1) {
            cout << "Khong tim thay nguoi mua!\n";
            return;
        }
        if (dssp[vtsp].spdaban()) {
            cout << "San pham da ban roi!\n";
            return;
        }
        if (dssp[vtsp].getmangban() != gd.getmaban()) {
            cout << "San pham khong thuoc nguoi ban nay!\n";
            return;
        }

        dsgd[slgd] = gd;
        slgd++;

        dssp[vtsp].setdaban(true);
        dsnb[vtban].tanggiaodich();
        dsnm[vtmua].tangmua();

        cout << "Them giao dich thanh cong!\n";
    }

    void indsSanPham() const {
        if (slsp == 0) {
            cout << "Danh sach san pham rong!\n";
            return;
        }
        for (int i = 0; i < slsp; i++) {
            dssp[i].xuat();
        }
    }

    void indsNguoiBan() const {
        if (slnb == 0) {
            cout << "Danh sach nguoi ban rong!\n";
            return;
        }
        for (int i = 0; i < slnb; i++) {
            dsnb[i].xuat();
        }
    }

    void indsNguoiMua() const {
        if (slnm == 0) {
            cout << "Danh sach nguoi mua rong!\n";
            return;
        }
        for (int i = 0; i < slnm; i++) {
            dsnm[i].xuat();
        }
    }

    void tracuugiaodich() const {
        string ma;
        cout << "Nhap ma giao dich can tim: ";
        cin >> ma;

        for (int i = 0; i < slgd; i++) {
            if (dsgd[i].getmagd() == ma) {
                cout << "Thong tin giao dich:\n";
                dsgd[i].xuat();
                return;
            }
        }
        cout << "Khong tim thay giao dich!\n";
    }

    void thongketheonguoiban() const {
        string ma;
        cout << "Nhap ma nguoi ban: ";
        cin >> ma;

        int daban = 0, chuaban = 0;
        bool co = false;

        for (int i = 0; i < slsp; i++) {
            if (dssp[i].getmangban() == ma) {
                co = true;
                if (dssp[i].spdaban()) daban++;
                else chuaban++;
            }
        }

        if (!co) {
            cout << "Khong co san pham nao cua nguoi ban nay!\n";
            return;
        }

        cout << "Nguoi ban " << ma << ":\n";
        cout << "So san pham da ban: " << daban << endl;
        cout << "So san pham ton kho: " << chuaban << endl;
    }

    void menu() {
        int chon;
        do {
            cout << "\n========= MENU =========\n";
            cout << "1. Them nguoi ban\n";
            cout << "2. Them nguoi mua\n";
            cout << "3. Them san pham\n";
            cout << "4. Them giao dich\n";
            cout << "5. In danh sach san pham\n";
            cout << "6. In danh sach nguoi ban\n";
            cout << "7. In danh sach nguoi mua\n";
            cout << "8. Tra cuu giao dich theo ma\n";
            cout << "9. Thong ke theo ma nguoi ban\n";
            cout << "0. Thoat\n";
            cout << "Chon: ";
            cin >> chon;
            cin.ignore();

            switch (chon) {
                case 1:
                    themnguoiban();
                    break;
                case 2:
                    themnguoimua();
                    break;
                case 3:
                    themsanpham();
                    break;
                case 4:
                    themgiaodich();
                    break;
                case 5:
                    indsSanPham();
                    break;
                case 6:
                    indsNguoiBan();
                    break;
                case 7:
                    indsNguoiMua();
                    break;
                case 8:
                    tracuugiaodich();
                    break;
                case 9:
                    thongketheonguoiban();
                    break;
                case 0:
                    cout << "Thoat chuong trinh!\n";
                    break;
                default:
                    cout << "Lua chon khong hop le!\n";
            }
        } while (chon != 0);
    }
};

int main() {
    quanli ql;
    ql.menu();
    return 0;
}