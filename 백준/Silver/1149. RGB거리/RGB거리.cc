#include<bits/stdc++.h>
using namespace std;
int dp[3];
int a[1001][3];
int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}

	dp[0] = a[0][0];
	dp[1] = a[0][1];
	dp[2] = a[0][2];
	for (int i = 1; i < n; i++) {
		int r = min(dp[1], dp[2]) + a[i][0];
		int g = min(dp[0], dp[2]) + a[i][1];
		int b = min(dp[0], dp[1]) + a[i][2];
		// update
		dp[0] = r; dp[1] = g; dp[2] = b;
	}
	int ret = 1e7;
	for (int i : dp) ret = min(ret, i);
	cout << ret;
}