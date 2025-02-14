#include<bits/stdc++.h>
using namespace std;
int n;
int a[100004][3];
const int MOD = 9901;
int main() {
	cin >> n;
	// 
	a[0][0] = 1; a[0][1] = 1; a[0][2] = 1;
	for (int i = 1; i < n; i++) {
		a[i][0] = (a[i - 1][1] + a[i - 1][2]) % MOD;
		a[i][1] = (a[i - 1][0] + a[i - 1][2]) % MOD;
		a[i][2] = (a[i - 1][0] + a[i - 1][1] + a[i - 1][2]) % MOD;
	}
	cout << (a[n - 1][0] + a[n - 1][1] + a[n - 1][2])%MOD;
	return 0;
}