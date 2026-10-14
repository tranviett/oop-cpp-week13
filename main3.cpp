#include <iostream>
#include <string>

using namespace std;

class Employee {
protected:
    string cccd;      // CCCD
    string sdt;       // Số điện thoại
    string address;   // Địa chỉ
public:
    Employee() {
        cccd = "";
        sdt = "";
        address = "";
    }
    Employee(string c, string s, string a) {
        cccd = c;
        sdt = s;
        address = a;
    }

    void displayInfo() const {
        cout << "CCCD: " << cccd << endl;
        cout << "SDT: " << sdt << endl;
        cout << "Address: " << address << endl;
    }

    string getCCCD() const { return cccd; }
    string getSDT() const { return sdt; }
    string getAddress() const { return address; }

    void setCCCD(string c) { cccd = c; }
    void setSDT(string s) { sdt = s; }
    void setAddress(string a) { address = a; }
};

class HourlyEmployee : public Employee {
private:
    int soGioLamViec;   // số giờ làm việc
    double donGia;      // đơn giá (vnd/giờ)
public:
    HourlyEmployee() : Employee() {
        soGioLamViec = 0;
        donGia = 0;
    }
    HourlyEmployee(string c, string s, string a, int soGio, double dg)
        : Employee(c, s, a) {
        soGioLamViec = soGio;
        donGia = dg;
    }

    void displayInfo() const {
        Employee::displayInfo();   // gọi hàm lớp cha
        cout << "So gio lam viec: " << soGioLamViec << endl;
        cout << "Don gia: " << donGia << endl;
        cout << "Luong: " << tinhLuong() << endl;
    }
    double tinhLuong() const { return soGioLamViec * donGia; }

    int getSoGioLamViec() const { return soGioLamViec; }
    double getDonGia() const { return donGia; }
    void setSoGioLamViec(int g) { soGioLamViec = g; }
    void setDonGia(double dg) { donGia = dg; }
};

class MonthlyEmployee : public Employee {
private:
    double luongCoBan;   // lương cơ bản
    double phuCap;       // phụ cấp
    double heSoThuong;   // hệ số thưởng
public:
    MonthlyEmployee() : Employee() {
        luongCoBan = 0;
        phuCap = 0;
        heSoThuong = 0;
    }
    MonthlyEmployee(string c, string s, string a, double lcb, double pc, double hs)
        : Employee(c, s, a) {
        luongCoBan = lcb;
        phuCap = pc;
        heSoThuong = hs;
    }

    void displayInfo() const {
        Employee::displayInfo();   // gọi hàm lớp cha
        cout << "Luong co ban: " << luongCoBan << endl;
        cout << "Phu cap: " << phuCap << endl;
        cout << "He so thuong: " << heSoThuong << endl;
        cout << "Luong: " << tinhLuong() << endl;
    }
    double tinhLuong() const { return luongCoBan + phuCap + luongCoBan * heSoThuong; }

    double getLuongCoBan() const { return luongCoBan; }
    double getPhuCap() const { return phuCap; }
    double getHeSoThuong() const { return heSoThuong; }
    void setLuongCoBan(double lcb) { luongCoBan = lcb; }
    void setPhuCap(double pc) { phuCap = pc; }
    void setHeSoThuong(double hs) { heSoThuong = hs; }
};

int main() {

    Employee e1("079123456789", "Nguyen Van A", "Ho Chi Minh");
    HourlyEmployee h1("079876543210", "Tran Thi B", "Ha Noi", 160, 50000);
    MonthlyEmployee m1("079987654321", "Le Minh C", "Da Nang", 15000000, 2000000, 1.2);

    cout << "--- Thong tin Employee ---" << endl;
    e1.displayInfo();
    cout << "\n--- Thong tin HourlyEmployee ---" << endl;
    h1.displayInfo();
    cout << "\n--- Thong tin MonthlyEmployee ---" << endl;
    m1.displayInfo();

    return 0;
}