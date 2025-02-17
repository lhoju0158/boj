#include<bits/stdc++.h>
using namespace std;
vector<int> adj[104];
int n, m, t1, t2;
int visited[104];
int ret = -1;
void go(int i,int level) {
	visited[i] = 1;
	if (i == t2) { ret = level; return; }
	for (int a : adj[i]) {
		if (visited[a]) continue;
		go(a,level+1);
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> t1 >> t2 >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b); adj[b].push_back(a);
	}
	go(t1, 0);
	cout << ret;
	return 0;
}