#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> vec;
int a, b;
int dp[504];
int ret = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> a >> b; vec.push_back({ a,b }); }
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (vec[j].second < vec[i].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		//cout << i << " " << dp[i] << "\n";
		ret = max(ret, dp[i]);
	}
	cout << n-ret;
	return 0;
}