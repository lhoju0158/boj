#include<bits/stdc++.h>
using namespace std;
long long a, b, c, ret;
int aa[10];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> a >> b >> c;
	ret = a * b * c;
	string s = to_string(ret);
	for (char c : s) {
		aa[c - '0']++;
	}
	for (int i = 0; i < 10; i++) {
		cout << aa[i] << "\n";
	}

	return 0;
}