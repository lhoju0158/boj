#include<bits/stdc++.h>
using namespace std;
int n;
long long p[1004];
long long dp[1004];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		cin >> p[i];
	}
	dp[1] = p[1];
	dp[2] = max(2 * dp[1], p[2]);

	for (int i = 3; i < n + 1; i++) {
		for (int j = 1; j < i + 1; j++)
			dp[i] = max(dp[i - j] + dp[j], dp[i]);
		dp[i] = max(dp[i], p[i]);
	}
	cout << dp[n];

	return 0;
}