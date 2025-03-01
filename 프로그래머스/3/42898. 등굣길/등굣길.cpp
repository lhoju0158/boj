#include <string>
#include <vector>
using namespace std;
int visited[104][104];
int MOD = 1000000007;
int dp[104][104];

int solution(int m, int n, vector<vector<int>> puddles) {
    for(vector<int> vec:puddles){
        dp[vec[1]-1][vec[0]-1]=-1;
    }
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (i == 0 && j == 0) continue;
            if (dp[i][j] == -1) { dp[i][j] = 0; continue; } 
            if (i > 0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            if (j > 0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;

        }
    }
    int answer = dp[n-1][m-1];
    return answer;
}