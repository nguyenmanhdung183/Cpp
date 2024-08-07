#if 0
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<string>
//thêm vào mà ko trùng lặp
// đếm các phần tử khác nhau
using namespace std;

int main() {
	/*******************SET********************/
#if 0
	//set<int> arr;
	//begin-rbegin
	//multiset<int> arr;
	//unorderedset<int> arr; 


	//arr.insert(100);//Olog(n)
	//arr.insert(300);
	//arr.insert(200);
	//arr.insert(400);
	//arr.insert(100);
	//arr.erase(100);
	//for (int x : arr) {
	//	cout << x << endl;
	//}


	/////////////////////////////////////////////////////////////////////

	//cho mảng có n pt, sliding window size = k,
	//	in ra phan tu lon nhat trong tung sliding window

	//	10 3
	//	1 2 3 1 4 5 1 8 9 10

	int n, k;
	cin >> n >> k;
	int arr[100];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	set<int> a;
	vector<int> rt;
	for (int i = 0; i < k; i++) {
		a.insert(arr[i]);
	}

	for (int i = 1; i < n; i++) {
		rt.push_back(*a.rbegin());
		a.erase(*a.begin());
		a.insert(arr[i + k - 1]);
	}

	for (int x : rt) {
		cout << x << "\t";

	}
#endif


	/********************MAP*******************/
#if 1
	//olog(n)
	//bài toán tần suất xuất hiện
	//(key, value)
	//key là unique
	//trùng key-> cập nhập lại value
	//tim kiem key -> count, find tuong tu set


	//map<int, int> mp;
	//mp[100] = 200;//(100,200)
	//mp.insert({ 300,400 });
	//cout <<"size = " << mp.size() << endl;


	//for (pair<int, int> x : mp) {
	//	cout << x.first << " " << x.second << endl;
	//}
	//std::cin.ignore();



	//đếm số lượng trong mảng và in ra tần suất của nó
	/*
8
1 1 2 1 3 5 1 4
	*/ //map=-multimap(ko lọc key)
	map<int, int> m;

	int n;
	std::cin >> n;
	int a[100];
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
	int is = 1;
		if (m.find(a[i]) != m.end()) {
			m[a[i]]++;
		}else{
			m.insert({ a[i], 1 });
		}
	}
	for (map<int, int> ::iterator it = m.begin(); it != m.end();it++) {
		cout << (*it).first << " " << (*it).second << endl;
	}


#endif
	return 0;
}
#endif