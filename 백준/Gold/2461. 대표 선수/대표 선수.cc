#include<bits/stdc++.h>
using namespace std;
int a[1004][1004];
int n, m;
int points[1004] = { 0 };
int ret = 0x7fffffff;
pair<int, int> mn; pair<int, int>mx;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)cin >> a[i][j];
		sort(a[i], a[i] + m);
	}
	while (true) {
		mn = { 1e9,0 }; mx = { 0,0 };
		for (int i = 0; i < n; i++) {
			if (mn.first > a[i][points[i]]) { mn = { a[i][points[i]],i }; }
			if (mx.first < a[i][points[i]]) { mx = { a[i][points[i]],i }; }
			// cout << i << "번째 줄, point: " << points[i] << "그리고 그 값: " << a[i][points[i]]<<"\n";
		}
		// cout << "\n=> " << abs(mn.first - mx.first)<<"\n";
		ret = min(ret, abs(mn.first - mx.first));
		points[mn.second]++;
		if (points[mn.second] >= m) break;
	}
	cout << ret;
	return 0;
}