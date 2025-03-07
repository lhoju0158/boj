#include<bits/stdc++.h>
using namespace std;
int t, w;
int a[1004];
int dp[1004][34][3];
int ret = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t >> w;
	for (int i = 1; i < t+1; i++) {
		cin >> a[i];
	}
	if (a[1] == 1) dp[1][0][1] = 1;
	else dp[1][1][2] = 1;

	for (int i = 2; i <= t; i++) {
		for (int j = 0; j <= w; j++) {
			// 머물러 있는 경우
			dp[i][j][1] = dp[i - 1][j][1] + (a[i] == 1);
			dp[i][j][2] = dp[i - 1][j][2] + (a[i] == 2);

			// 이동하는 경우
			if (j > 0) {
				dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - 1][2] + (a[i] == 1));
				dp[i][j][2] = max(dp[i][j][2], dp[i - 1][j - 1][1] + (a[i] == 2));

			}
		}
	}
	for (int j = 0; j <= w; j++) {
		ret = max(ret, max(dp[t][j][1], dp[t][j][2]));
	}
	cout << ret;
	return 0;
}