#include<bits/stdc++.h>
using namespace std;
int n, k;
int dp[204][204];
const int MOD = 1000000000;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= k; i++) dp[1][i] = i;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = (dp[i][j] + 1) % MOD;
			for (int k = 1; k <= i; k++) dp[i][j] = (dp[i][j] + dp[k][j - 1]) % MOD;
		}
	}	
	cout << dp[n][k];
	return 0;
}