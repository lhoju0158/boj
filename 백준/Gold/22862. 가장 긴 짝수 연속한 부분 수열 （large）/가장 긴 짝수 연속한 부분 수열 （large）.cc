#include<bits/stdc++.h>
using namespace std;
int n, k, ret = 0;
int a[1000004];
int st, en, cnt;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) { cin >> a[i]; }
	en = 0; cnt = a[st] % 2;
	for (int st = 0; st < n; st++) {
		while (en<n-1) {
			if (a[en+1] % 2 == 0) en++;
			else if (cnt < k) {
				en++; cnt++;
			}
			else break;
		}
		ret = max(ret, en - st + 1 - cnt);
		if (a[st] % 2 != 0) cnt--;
	}
	cout <<ret;
	return 0;
}