#include<bits/stdc++.h>
using namespace std;
int n;
long long dp[104][10]; // 0부터 9로 끝나는 숫자의 수
int result[104];
const int MOD = 1000000000;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	dp[1][0] = 0; dp[1][1] = 1; dp[1][2] = 1; dp[1][3] = 1; dp[1][4] = 1; dp[1][5] = 1; 
	dp[1][6] = 1; dp[1][7] = 1; dp[1][8] = 1; dp[1][9] = 1; 
	result[1] = 9;
	for (int i = 2; i < 101; i++) {
		dp[i][0] = dp[i-1][1];
		for (int k = 1; k < 9; k++) {
			dp[i][k] = (dp[i - 1][k + 1] + dp[i - 1][k - 1]) % MOD;
		}
		dp[i][9] = dp[i-1][8];
		for (int k = 0; k < 10; k++) {
			result[i] += (dp[i][k] % MOD); result[i] %= MOD;
		}
	}
	cout << result[n];
	
	return 0;
}