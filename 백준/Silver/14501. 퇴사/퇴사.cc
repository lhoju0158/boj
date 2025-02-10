#include<bits/stdc++.h>
using namespace std;

int n;
int t[1004], p[1004], dp[1004];
int ret = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }

    for (int i = 1; i <= n + 1; i++) {
        ret = max(ret, dp[i]);  // 최댓값 유지 (누적 업데이트)

        if (i + t[i] <= n + 1) {  // 퇴사 전에 끝나는 상담만 고려
            dp[i + t[i]] = max(dp[i + t[i]], ret + p[i]);
        }
    }

    cout << ret;
}
