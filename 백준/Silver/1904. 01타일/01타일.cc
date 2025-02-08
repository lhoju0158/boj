#include<bits/stdc++.h>
using namespace std;
int dp[1000004],n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i < 1000001; i++) {
		dp[i] = (dp[i - 2] + dp[i - 1])%15746;
	}
	cin >> n;
	cout << dp[n];
	return 0;
}