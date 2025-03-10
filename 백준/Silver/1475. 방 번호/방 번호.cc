#include<bits/stdc++.h>
using namespace std;
string s;
int ret = 1;

int a[10];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> s;
	for (char c : s) { 
		a[c - '0']++; 
	}
	for (int i = 0; i < 10; i++) {
		if (i == 6 || i == 9) continue;
		ret = max(ret, a[i]);
	}
	ret = max(ret, (a[6] + a[9] + 1) / 2);
	cout << ret;
	return 0;
}