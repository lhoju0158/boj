#include<bits/stdc++.h>
using namespace std;
int n;
int dp[1000004];
int pre[1000004];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		pre[i] = i - 1;
		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
			pre[i] = i / 2;
		}
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
			dp[i] = min(dp[i], dp[i / 3] + 1);
			pre[i] = i / 3;
		}
	}
	cout << dp[n]-1 << "\n";
	while (true) {
		if (n == 1) break;
		cout << n << " ";
		n = pre[n];
	}

	cout << 1;
}