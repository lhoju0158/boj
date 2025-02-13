#include<bits/stdc++.h>
using namespace std;
int n;
int a[1004];
vector<int> dp[1004];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int ret = 1;
	for (int i = 1; i < n + 1; i++)cin >> a[i];
	dp[1].push_back(a[1]);
	for (int i = 2; i < n + 1; i++) {
		// dp[i].push_back(a[i]);
		for (int j = 1; j < i; j++) {
			if (dp[j].back() < a[i] && dp[i].size() < dp[j].size()) {
				dp[i].clear();
				for (int k : dp[j])  dp[i].push_back(k);
				// dp[i].push_back(a[i]);
			}
		}
		dp[i].push_back(a[i]);
		ret = dp[ret].size() > dp[i].size() ? ret : i;
		
	}
	cout << dp[ret].size() << "\n";
	for (int i : dp[ret]) cout << i << " ";
	//cout << "\n";
	//for (int i = 1; i < n + 1; i++) {
	//	for (int j : dp[i]) cout << j << " ";
	//	cout << "\n";
	//}
	return 0;
}