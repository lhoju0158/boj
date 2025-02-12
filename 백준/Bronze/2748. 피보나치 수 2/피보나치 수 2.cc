#include<bits/stdc++.h>
using namespace std;
int n;
long long dp[94];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	dp[0] = 0; dp[1] = 1;
	for (int i = 2; i < n + 1; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n];
}