#include<bits/stdc++.h>
using namespace std;
int n;
int a[100004][3]; 
int dp[100004][3];
int test = 1;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true) {
		cin >> n;
		if (n == 0) break;
		fill(&a[0][0], &a[0][0] + 3 * (n + 1), 0);
		for (int i = 1; i < n+1; i++)
			for (int j = 0; j < 3; j++)
				cin >> a[i][j];
		dp[2][0] = a[1][1]+a[2][0];
		dp[2][1] = min(dp[2][0], min(a[1][1], (a[1][1] + a[1][2]))) + a[2][1];
		dp[2][2] = min(dp[2][1], min(a[1][1], min(a[1][1],(a[1][1] + a[1][2])))) + a[2][2];
		for (int i = 3; i < n+1; i++){
			dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + a[i][0];
			dp[i][1] = min(dp[i][0], min(dp[i - 1][0], min(dp[i - 1][1],dp[i-1][2]))) + a[i][1];
			dp[i][2] = min(dp[i][1], min(dp[i - 1][1], dp[i - 1][2])) + a[i][2];
		}	
		//cout << "\n";
		//for (int i = 1; i < n + 1; i++) {
		//	for (int j = 0; j < 3; j++) {
		//		cout<<  dp[i][j]<<" ";
		//	}
		//	cout << "\n";
		//}
				
		cout << test << ". " << dp[n][1] << "\n";
		test++;
	}
	return 0;
}