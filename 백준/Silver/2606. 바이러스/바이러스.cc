#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[104];
int visited[104];
int ret = -1;
void go(int i) {
	visited[i] = 1;
	ret++;
	for (int a : adj[i]) {
		if (visited[a]) continue;
		go(a);
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b); adj[b].push_back(a);
	}
	go(1);
	cout << ret;
	return 0;
}