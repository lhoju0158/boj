#include<bits/stdc++.h>
using namespace std;
int n;
double ret = 0;
double a[10004];
double dp[10004];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> a[i]; }
	dp[0] = a[0] > 1 ? a[0] : 1;
	for (int i = 1; i < n; i++) {
		dp[i] = max(a[i], dp[i - 1] * a[i]);
		ret = max(dp[i], ret);
	}
	
	cout.precision(3);
	cout << fixed << ret;
	
	return 0;
}