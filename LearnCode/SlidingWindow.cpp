#include<iostream>
using namespace std;
#if 0
int main() {
	int stc;
	int n;
	int k;
	cin >> stc;
	while (stc--) {
		cin >> n;
		cin >> k;
		int arr[1001];
		int dem = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			if (arr[i] <= k) dem++;
		}
		//stage 1
		int count=0;//v1
		for (int i = 0; i < dem; i++) {
			if (arr[i] <= k) count++;
		}
		int maxa = count;
		//di chuyển
		for (int i = 1; i <= n - k; i++) {
			if (arr[i - 1] <= k) count--;
			if (arr[i + k-1] <= k) count++;
			maxa = max(maxa, count);
		}

		cout << dem - maxa << endl;
	}
	return 0;
}//bài toán các số <=k liền nhau

#endif
#if 0
int main() {
	/*
	10 6 5
	2 
	10
	1
	5
	9

output=1
	
	*/
	//sobong-lientiep-hong
	int n, k, b;
	cin >> n >> k >> b;
	int arr[100];
	int brr[100] = {1};
	fill(brr, brr + n, 1);

	for (int i = 0; i < b; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < b; i++) {
		brr[arr[i]] = 0;
	}
	int dem=0;
	for (int i = 0; i <k; i++) {
		if (brr[i] == 1) dem++;
	}

	int maxa = dem;
	for (int i = 1; i <= n - k ; i++) {
		if (brr[i - 1] == 1) dem--;
		if (brr[i + k - 1] == 1) dem++;
		maxa = max(maxa, dem);
	}
	cout << k-maxa;
	return 0;
}
#endif