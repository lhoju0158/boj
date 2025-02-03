#include<bits/stdc++.h>
using namespace std;
int n;
char a[64][64];
stack<int> s;
string go(int y, int x, int size) {
	if (size == 1) {
		return string(1,a[y][x]);
	}
	string tem = "";
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (a[y][x] != a[i][j]) {
				tem += "(";
				tem += go(y, x, size / 2);
				tem += go(y, x + size / 2, size / 2);
				tem += go(y+ size / 2, x, size / 2);
				tem += go(y+ size / 2, x+ size / 2, size / 2);
				tem +=  ")";
				return tem;
			}
		}
	}
	// 모두 동일한 경우
	return string(1, a[y][x]);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			a[i][j] = s[j];
		}
	}
	cout<<go(0,0,n);
	return 0;
}