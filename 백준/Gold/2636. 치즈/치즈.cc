#include<bits/stdc++.h>
using namespace std;
int n, m, ny, nx, result, tem, ttt;
int a[104][104];
int visited[104][104];
int dy[4] = { -1,1,0,0 };
int dx[4] = {0,0 ,-1,1};
stack<pair<int, int>> st;
void go(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (a[ny][nx] == 0 && !visited[ny][nx]) go(ny, nx);
		if (a[ny][nx] == 1) st.push({ ny,nx });
	}
	return;
}
int main() {
	cin >> m >> n;
	ttt = 0;
	tem = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) {
				result++;
			}
		}
	}
	//
	while (true) {
		go(0, 0);
		while (!st.empty()) {
			a[st.top().first][st.top().second] = 0;
			st.pop();
		}
		// 
		bool flag = false;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 1) {
					tem++;
					flag = true;
				}
			}

		}
		//cout << "\n";

		//for (int i = 0; i < m; i++) {
		//	for (int j = 0; j < n; j++) {
		//		cout << a[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
		fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
		ttt++;
		if (!flag) break;
		result = tem;
		tem = 0;
	}
	cout << ttt <<"\n"<<result;

	return 0;
}