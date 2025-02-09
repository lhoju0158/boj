#include<bits/stdc++.h>
using namespace std;
int n, ret;
int a[100004];
int dp[100004];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		cin >> a[i];
	}
	ret = 1;
	for (int i = 1; i < n + 1; i++) {
		dp[i] = 1;
		for (int j = 1; j < n + 1; j++) {
			if (a[j] < a[i]) dp[i] = max(dp[i], dp[j]+1);
		}
		ret = max(ret, dp[i]);
	}
	cout << ret;
}