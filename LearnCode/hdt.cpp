#if 0
#include<iostream>
using namespace std;

/************** CLASS *************/
//thuộc tính attribute (tên, tuổi)(private)
//phương thức behavior (đi lại)(public)
//object đôi tượng

/*
đóng gói: chỉ thao tác trong class

*/
class SinhVien {
	private:
		string name;
		double mark;

	public:
		//hàm khởi tạo
		SinhVien();
		SinhVien(string, double);

		//hàm
		void hello() {cout << "Hello" << endl;}
		void chao();

		//set-get
		double getmark();

		//hàm bạn: để có thể truy cập vào class
		friend double laydiemra(SinhVien);
		//hàm huỷ
		~SinhVien();
};
void SinhVien::chao() {
	cout << "Chào" << endl;
}

//hàm khởi tạo
SinhVien::SinhVien() {
}
SinhVien::SinhVien(string name, double mark) {
	this->name = name;
	this->mark = mark;
}

SinhVien::~SinhVien() {
}
double SinhVien::getmark(){
	return mark;
}

//hàm bạn
double laydiemra(SinhVien a) {
	return a.mark;
}
int main() {
	//cout << "HDT" << endl;

	//đóng gói, kế thừa, đa hình, trừu tượng 

	SinhVien a;// gọi luôn hàm khởi tạo
	SinhVien b("Nguyen Van A", 10);

	a.chao();
	cout << laydiemra(b) << endl;
	cout << b.getmark() << endl;
	return 0;
 }


#endif