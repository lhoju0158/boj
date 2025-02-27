#include<bits/stdc++.h>
using namespace std;
int n, d, k, c;
int sushi[30004];
int check[3004];
int cnt;
int coupon;
int ret = 0;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++) {
		cin >> sushi[i];
	}
	for (int i = 0; i < n; i++) {
		cnt = 0; coupon = 1;
		for (int j = i; j < i + k; j++) {
			if (!check[sushi[j % n]]) { check[sushi[j % n]] = 1;  cnt++; }
			if (sushi[j % n] == c) { coupon = 0; }
		}
		ret = max(cnt + coupon, ret);
		
		memset(check, 0, sizeof(check));
	}
	cout << ret;
	return 0;
}