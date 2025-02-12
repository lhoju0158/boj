#include<bits/stdc++.h>
using namespace std;
int n;
int a[10004];
int dp[10004][2];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i < n + 1; i++) cin >> a[i];
	// for (int i = 1; i < n + 1; i++) cout<< a[i]<<" ";
	// cout << "\n";
	dp[1][0] = a[1]; dp[1][1] = a[1];
	dp[2][0] = a[1] + a[2]; dp[2][1] = a[2];
	if (n == 1) { cout << a[1]; return 0; }
	if (n == 2) { cout << a[1] + a[2]; return 0; }
	int ret = a[1] + a[2];
	for (int i = 3; i < n + 1; i++) {
		dp[i][0] = dp[i - 1][1] + a[i];
		for (int j = i - 2; j >= 1; j--) {
			dp[i][1] = max(dp[i][1], max(dp[j][0], dp[j][1]));
		}
		dp[i][1] += a[i];
		ret = max(ret, max(dp[i][0], dp[i][1]));
	}
	//for (int i = 1; i < n + 1; i++) { 
	//	cout << dp[i][0] << " " << dp[i][1] << "\n"; 
	//}
	cout << ret;
}