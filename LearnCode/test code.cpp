#if 0
#include<iostream>
#include<string>
using namespace std;

class SinhVien {
private:
	string name;
	int id;
	int age;
	double mark;

	static int count;//đếm số lượng sv, dùng chung cho tât cả data
public:
	SinhVien();
	SinhVien(string, int, int, double);

	void nhap();
	void xuat();
	 
	double getmark();
	~SinhVien();
};

int SinhVien::dem = 0;
SinhVien::SinhVien() {
	name = "";
	id = 0;
	age = 0;
	mark = 0;
}
SinhVien::SinhVien(string name, int id, int age, double mark) {
	this->name = name;
	this->id = id;
	this->age = age;
	this->mark = mark;
	cin.ignore();
}
SinhVien::~SinhVien(){}
void SinhVien::nhap() {
	cout << "nhap ten: "; getline(cin, name);
	cout << "nhap id: "; cin >> id;
	cout << "nhap tuoi: "; cin >> age;
	cout << "nhap diem: "; cin >> mark;
}


void SinhVien::xuat() {
	cout << name << "\t" << id << "\t" << age << "\t" << mark << endl;
}
double SinhVien::getmark() {
	return mark;
}
int main() {
	SinhVien a;
	a.nhap();
	a.xuat();
	cout << a.getmark() << endl;
	return 0;
}

#endif