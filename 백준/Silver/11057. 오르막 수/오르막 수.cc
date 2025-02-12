#include<bits/stdc++.h>
using namespace std;
int a[1004][10];
int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < 10; i++) {
		a[1][i] = 1;
	}
	for (int i = 2; i < n + 1; i++) {
		a[i][0] = a[i - 1][0];
		for (int j = 1; j < 10; j++) {
			a[i][j] = (a[i - 1][j] + a[i][j - 1])%10007;
		}
	}
	int ret = 0;
	for (int i = 0; i < 10; i++) ret = (ret+a[n][i])%10007;
	cout <<ret;
	return 0;
}