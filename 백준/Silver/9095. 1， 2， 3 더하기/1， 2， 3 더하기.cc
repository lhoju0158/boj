#include<bits/stdc++.h>
using namespace std;
int n, t;
typedef long long ll;
ll dp[12];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < 12; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	cin >> t;
	for (int i = 0; i < t; i++) { cin >> n; cout << dp[n]<<"\n"; }

	return 0;
}