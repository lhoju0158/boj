#include<bits/stdc++.h>
using namespace std;
int n, m;
int sx, sy, ex, ey;
int a[1028][1028];
int sum[1028][1028];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			cin >> a[i][j];
			sum[i][j] = sum[i][j - 1] + a[i][j];
		}
	}

	while (m--) {
		cin >> sx >> sy >> ex >> ey;
		int ret = 0;
		for (int i = sx; i < ex + 1; i++) {
			ret += (sum[i][ey] - sum[i][sy - 1]);
		}
		cout << ret << "\n";
	}


	return 0;
}