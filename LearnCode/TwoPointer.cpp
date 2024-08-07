#if 0
#include<iostream>
using namespace std;
int main() {
	/*
	* nối 2 mảng
	//so phan tu
	6 7 
	1 6 9 13 18 18
	2 3 8 13 15 21 25
	*/

	int a, b;
	cin >> a >> b;
	int arr[100];
	int brr[100];
	int crr[200];

	for (int i = 0; i < a; i++) cin >> arr[i];
	for (int i = 0; i < b; i++) cin >> brr[i];



	int i = 0;
	int j = 0;
	int t = 0;
	while (i < a && j < b) {
		if (arr[i] <= brr[j]) {
			crr[t] = arr[i];
			i++;
			t++;

		}
		else {
			crr[t] = brr[j];
			j++;
			t++;
		}

	}
	while(i<a){
		crr[t] = arr[i];
		t++;
		i++;
	}
	while (j < b) {
		crr[t] = brr[j];
		t++;
		j++;
	}
	for (int i = 0; i < a + b ; i++) {
		cout << crr[i] << "\t";
	}
	return 0;
}


#endif