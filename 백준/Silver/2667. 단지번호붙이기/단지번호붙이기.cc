#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
int n;
char a[26][26];
int visited[26][26];
vector<pair<int,int>> ones;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,-1,1 };
int ret = 0;
void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (a[ny][nx] == '0' || visited[ny][nx]) continue;
		dfs(ny, nx);
	}
	ret++;
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			a[i][j] = s[j];
			if (a[i][j]=='1') ones.push_back({i,j});
		}
	}
	for (pair<int, int> p : ones) {
		if (visited[p.first][p.second]) continue;
		ret = 0;
		dfs(p.first, p.second);
		vec.push_back(ret);
	}
	sort(vec.begin(), vec.end());
	cout << vec.size() << "\n";
	for (int i : vec) cout << i << "\n";
	return 0;
}