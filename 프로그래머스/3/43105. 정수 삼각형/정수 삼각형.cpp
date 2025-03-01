#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int dp[500][500];
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    for(int i=0;i<triangle.size();i++){
        // i번째 줄
        for(int j=0;j<i+1;j++){
            dp[i][j]=triangle[i][j];
            // j번째 index
            if(i==0) break;
            if(j==0) dp[i][j]+=dp[i-1][0];
            else if(j==i) dp[i][j]+=dp[i-1][j-1];
            else dp[i][j]+=max(dp[i-1][j],dp[i-1][j-1]);
        }
    }
    // for(int i=0;i<triangle.size();i++){
    //     // i번째 줄
    //     for(int j=0;j<i+1;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    for(int i=0;i<triangle.size();i++){
        answer = max(answer,dp[triangle.size()-1][i]);
    }
    return answer;
}