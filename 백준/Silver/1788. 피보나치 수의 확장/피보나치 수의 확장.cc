#include<bits/stdc++.h>
using namespace std;
int n;
int dp[1000004];
const int MOD = 1000000000;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// 
	dp[0] = 0; dp[1] = 1; 
	cin >> n;
	for (int i = 2; i < abs(n) + 1; i++) {
		dp[i] = (dp[i - 2] + dp[i - 1])%MOD;
	}
	if (n < 0 && abs(n) % 2 == 0) cout << -1;
	else if (n == 0) cout << 0;
	else cout << 1;
	cout << "\n" << dp[abs(n)];
	return 0;
}