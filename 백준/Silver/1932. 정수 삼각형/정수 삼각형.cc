#include<bits/stdc++.h>
using namespace std;
int n;
int a[501][501];
// int visited[501][501];
int dp[502];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> a[i][j];
		}
	}
	dp[0] = a[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = i; j >= 0; j--) {
			if (j == 0) dp[j] += a[i][j];
			else dp[j] = max(dp[j], dp[j - 1]) + a[i][j];
		}
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		// cout << dp[i] << " ";
		ret = max(ret, dp[i]);
	}
	cout << ret;

	return 0;
}