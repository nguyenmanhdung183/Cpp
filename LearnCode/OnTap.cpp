#if 1
#include<iostream>
#include<vector>
#include<stack>
#include<math.h>
#include<string>
#include<queue>
using namespace std;

int main() {
#if 1 ma trận chữ-> đảo

		int n;
		queue<string> qrt;

		string s;
		while (true) {
			cin >> n;
			int column = n;
			if (n == 0) break;
			cin.ignore();
			getline(cin, s);
			queue<char> q;
			int rows = s.length() % n == 0 ? s.length() / n : s.length() / n + 1;
			vector<vector<int>> vt(rows, vector<int>(n));

			for (int i = 0; i < s.length(); i++) {
				q.push(s[i]);
			}

			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < n; j++) {
					if (i % 2 == 0) {
						vt[i][j] = q.front();
						q.pop();
					}
					if (i % 2 != 0) {
						vt[i][n - j - 1] = q.front();
						q.pop();
					}
				}
			}

			string rt = "";
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < rows; j++) {
					rt += vt[j][i];
				}
			}
			qrt.push(rt);

		}
		while (!qrt.empty()) {
			cout << qrt.front() << endl; qrt.pop();

		}

#endif
		return 0;
}

#endif