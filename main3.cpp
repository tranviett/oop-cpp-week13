```cpp
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class NhanVien {
protected:
    string cccd, sdt, diaChi;

public:
    NhanVien(string id = "", string phone = "", string dc = "") {
        cccd = id;
        sdt = phone;
        diaChi = dc;
    }

    virtual double tinhLuong() const = 0;

    virtual void xuatThongTin() const {
        cout << "CCCD: " << cccd << endl;
        cout << "So dien thoai: " << sdt << endl;
        cout << "Dia chi: " << diaChi << endl;
    }

    virtual ~NhanVien() {}
};

class NhanVienTheoGio : public NhanVien {
private:
    int gioLam;
    double tienGio;

public:
    NhanVienTheoGio(string id, string phone, string dc,
                    int gio, double gia)
        : NhanVien(id, phone, dc), gioLam(gio), tienGio(gia) {}

    double tinhLuong() const override {
        return gioLam * tienGio;
    }

    void xuatThongTin() const override {
        NhanVien::xuatThongTin();
        cout << "Loai nhan vien: Theo gio" << endl;
        cout << "So gio lam: " << gioLam << endl;
        cout << "Tien cong moi gio: " << tienGio << endl;
        cout << "Luong: " << tinhLuong() << " VND" << endl;
    }
};

class NhanVienTheoThang : public NhanVien {
private:
    double luongCoBan, phuCap, thuong;

public:
    NhanVienTheoThang(string id, string phone, string dc,
                      double luong, double pc, double hs)
        : NhanVien(id, phone, dc),
          luongCoBan(luong), phuCap(pc), thuong(hs) {}

    double tinhLuong() const override {
        return luongCoBan + phuCap + luongCoBan * thuong;
    }

    void xuatThongTin() const override {
        NhanVien::xuatThongTin();
        cout << "Loai nhan vien: Theo thang" << endl;
        cout << "Luong co ban: " << luongCoBan << endl;
        cout << "Phu cap: " << phuCap << endl;
        cout << "He so thuong: " << thuong << endl;
        cout << "Luong: " << tinhLuong() << " VND" << endl;
    }
};

int main() {
    NhanVienTheoGio nv1("001", "0901111111", "Da Nang", 160, 50000);
    NhanVienTheoThang nv2("002", "0902222222", "Ha Noi",
                          15000000, 2000000, 1.2);
    NhanVienTheoGio nv3("003", "0903333333", "Can Tho", 100, 60000);
    NhanVienTheoThang nv4("004", "0904444444", "Hue",
                          8000000, 1000000, 0.5);

    NhanVien* danhSach[] = {&nv1, &nv2, &nv3, &nv4};
    int n = 4;

    double tongLuong = 0;
    double caoNhat = danhSach[0]->tinhLuong();
    double thapNhat = danhSach[0]->tinhLuong();
    int viTriMax = 0, viTriMin = 0;
    int demGio = 0, demThang = 0;

    cout << fixed << setprecision(0);

    cout << "===== DANH SACH NHAN VIEN =====" << endl;

    for (int i = 0; i < n; i++) {
        cout << "\nNhan vien thu " << i + 1 << endl;
        danhSach[i]->xuatThongTin();

        double luong = danhSach[i]->tinhLuong();
        tongLuong += luong;

        if (luong > caoNhat) {
            caoNhat = luong;
            viTriMax = i;
        }

        if (luong < thapNhat) {
            thapNhat = luong;
            viTriMin = i;
        }

        if (i == 0 || i == 2)
            demGio++;
        else
            demThang++;
    }

    cout << "\nTong quy luong: " << tongLuong << " VND" << endl;

    cout << "\n===== NHAN VIEN LUONG CAO NHAT =====" << endl;
    danhSach[viTriMax]->xuatThongTin();

    cout << "\n===== NHAN VIEN LUONG THAP NHAT =====" << endl;
    danhSach[viTriMin]->xuatThongTin();

    cout << "\nNhan vien theo gio: " << demGio << endl;
    cout << "Nhan vien theo thang: " << demThang << endl;

    double mucLuong;
    cout << "\nNhap muc luong can loc: ";
    cin >> mucLuong;

    cout << "\n===== NHAN VIEN CO LUONG CAO HON MUC LOC =====" << endl;

    bool timThay = false;
    for (int i = 0; i < n; i++) {
        if (danhSach[i]->tinhLuong() > mucLuong) {
            danhSach[i]->xuatThongTin();
            cout << endl;
            timThay = true;
        }
    }

    if (!timThay)
        cout << "Khong tim thay nhan vien phu hop." << endl;

    // Sap xep nhan vien theo luong giam dan
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (danhSach[i]->tinhLuong() <
                danhSach[j]->tinhLuong()) {
                NhanVien* temp = danhSach[i];
                danhSach[i] = danhSach[j];
                danhSach[j] = temp;
            }
        }
    }

    cout << "\n===== DANH SACH LUONG GIAM DAN =====" << endl;

    for (int i = 0; i < n; i++) {
        cout << "\nNhan vien thu " << i + 1 << endl;
        danhSach[i]->xuatThongTin();
    }

    return 0;
}
