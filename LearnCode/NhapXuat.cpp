#if 0

#include<iostream>
#include<fstream>
#include<string>
using namespace std;


int main() {
	fstream fs;
	fs.open("C:\\Users\\NGUYEN MANH DUNG\\Desktop\\CC++\\learning\\text.txt");
	if (fs.is_open()) {
		cout << "Mo file thanh cong" << endl;
	}
	else {
		cout << "Mo file khong thanh cong" << endl;
	}
	string s;
	string t;
	std::getline(fs, s);
	std::getline(fs, t);

	cout << s;
	cout << t;
	return 0;
}

#endif