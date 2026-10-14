#include <iostream>
#include <string>

using namespace std;

class People {
private:
    string cccd;
    string name;
    string address;

public:
// Constructor không tham số - gán giá trị mặc định
    People() {
        cccd = "000000000000";
        name = "Unknown";
        address = "Unknown";
    }
    // Constructor có tham số
    People(string c, string n, string a) {
        cccd = c;
        name = n;
        address = a;
    }

    // Hàm hiển thị thông tin
    void displayInfo() const {
        cout << "CCCD:" << cccd << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
    }

    // getters, setters
    string getCccd() const { return cccd; }
    string getName() const { return name; }
    string getAddress() const { return address; }
    void setCccd(string c) { cccd = c; }
    void setName(string n) { name = n; }
    void setAddress(string a) { address = a; }
};

class Student : public People {
private:
    string mssv;
    int yearEntrance;
public:
// Constructor không tham số - gán giá trị mặc định
    Student() : People() {
        mssv = "N//A";
        yearEntrance = 0;
    }
    // Constructor có tham số
    Student(string c, string n, string a,
    string m, int y)
    : People(c, n, a) {
        mssv = m;
        yearEntrance = y;
    }

    // Hàm hiển thị thông tin (ghi đè)
    void displayInfo() const {
        People :: displayInfo(); // gọi hàm của lớp cha
        cout << "MSSV: " << mssv << endl;
        cout << "Year Entrance: " << yearEntrance << endl;
    }

    // getters, setters
    string getMssv() const { return mssv; }
    int getYearEntrance() const {return yearEntrance; }
    void setMssv(string m) { mssv = m; }
    void setYearEntrance(int y) {yearEntrance=y;}

};

class FIEStudent : public Student {
private:
    int credits;
public:
// Constructor không tham số - gán giá trị mặc định
    FIEStudent() : Student() {
        credits = 0;
    }
    // Constructor có tham số
    FIEStudent(string c, string n, string a,
    string m, int y, int cr)
    : Student(c, n, a, m, y) {
        credits = cr;
    }

    // Hàm hiển thị thông tin (ghi đè)
    void displayInfo() const {
        Student :: displayInfo(); // gọi hàm của lớp cha (và People)
        cout << "Credits: " << credits << endl;
    }

    // getters, setters
    int getCredits() const { return credits; }
    void setCredits(int cr) { credits = cr; }

    // Hàm hiển thị thông tin
    void displayInfo() const {
    cout << "CCCD: " << getCccd() << endl;
    cout << "Name: " << getName() << endl;
    cout << "Address: " << getAddress() << endl;
    cout << "MSSV :" << getMssv() << endl;
    cout << "Year Entrance :" << getYearEntrance() << endl;
    cout << "Credits: " << credits << endl;
    cout <<"------------------------------------" << endl;
    }
};

int main() {
    // === 1. Tạo các đối tượng People bằng các constructor khác nhau ===
    People p1; // mặc định
    People p2("079123456789", "Nguyen Van A", "Ho Chi Minh"); // có tham số

    // === 2. Tạo các đối tượng Student ===
    Student s1; // mặc định (goi People())
    Student s2("079123456789", "Tran Thi B", "Ha Noi", "SV001", 2023); // có tham số

    // === 3. Tạo các đối tượng FIEStudent ===
    FIEStudent f1; // mặc định (goi Student() -> People())
    FIEStudent f2("079987654321", "Le Minh C", "Da Nang",
    "FIE2023001", 2023, 120); // có tham số

    // === 4. Hiển thị thông tin các đối tượng ===
    cout << " ---- Thong tin doi tuong p1 (People - mac dinh) ---- " << endl;
    p1.displayInfo();
    cout << endl;

    cout << " ---- Thong tin doi tuong p2 (People - co tham so) ---- " << endl;
    p2.displayInfo();
    cout << endl;

    cout << " ---- Thong tin doi tuong s1 (Student - mac dinh) ---- " << endl;
    s1.displayInfo();
    cout << endl;

    cout << " ---- Thong tin doi tuơng s2 (Student - co tham so) ---- " << endl;
    s2.displayInfo();
    cout << endl;

    cout << " ---- Thong tin doi tuong f1 (FIEStudent - mac dinh) ---- " << endl;
    f1.displayInfo();
    cout << endl;

    cout << " ---- Thong tin doi tuong f2 (FIEStudent - co tham so) ---- " << endl;
    f2.displayInfo();
    cout << endl;

    return 0;
}