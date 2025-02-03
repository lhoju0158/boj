#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10001];
int visited[10001];
int result[10001];
int n, m, a, b, ret;
int go(int t) {
	int ret = 1;
	visited[t] = 1;
	for (int i : adj[t]) {
		if ( visited[i]) continue;
		ret+=go(i);
	}
	return ret;
}
int main() {
	ret = 0;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[b].push_back(a);
	}
	for (int i = 1; i < n+1; i++) {
		memset(visited, 0, sizeof(visited));
		result[i] = go(i);
		ret = max(ret, result[i]);
	}
	for (int i = 1; i < n + 1; i++)
		if (ret == result[i])
			cout << i << " ";
	return 0;
}