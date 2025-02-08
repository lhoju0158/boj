#include<bits/stdc++.h>
using namespace std;
int n;
int a[304];
int dp[304][3];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i < n+1; i++) {
		cin >> a[i];
	}
	if (n == 1) { cout << a[1]; return 0; }
	dp[1][1] = a[1];
	dp[1][2] = 0;
	dp[2][1] = a[2];
	dp[2][2] = a[1] + a[2];
	for (int i = 3; i < n+1; i++) {
		dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + a[i];
		dp[i][2] = dp[i - 1][1] + a[i];
	}
	cout << max(dp[n][1], dp[n][2]);
}