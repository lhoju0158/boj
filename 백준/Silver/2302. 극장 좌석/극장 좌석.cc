#include<bits/stdc++.h>
using namespace std;
int n, m;
int seat[44];
int vip[44];
int ret = 1;
vector<int> vec;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int tem; cin >> tem;
		vip[tem] = 1;
	}
	seat[0] = 1; seat[1] = 1; seat[2] = 2;
	for (int i = 3; i < 41; i++) {
		seat[i] = seat[i - 1] + seat[i - 2];
	}
	if (m == 0) { cout << seat[n]; return 0; }
	int start = 1;
	int end = 1;
	while (true) {
		if (end == n+1) break;
		if (vip[end]) {
			ret *= seat[end - start];
			start = end + 1;
		}
		end++;
	}
	ret *= seat[end - start];
	cout << ret;
	return 0;
}