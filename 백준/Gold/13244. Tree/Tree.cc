#include<bits/stdc++.h>
using namespace std;
int t, m, n, a, b;
vector<int> adj[1004];
int visited[1004];
void go(int i) {
	visited[i] = 1;
	for (int a : adj[i]) {
		if (!visited[a]) go(a);
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> m >> n;
		for(int i=0;i<n;i++) {
			cin >> a >> b;
			adj[a].push_back(b); adj[b].push_back(a);
		}
		int cnt = 0;
		for (int i = 1; i <= m; i++) {
			if (!visited[i]) { go(i); cnt++; }
		}
		if ((cnt == 1) && (m-1 == n )) cout << "tree\n";
		else cout << "graph\n";
		// clear
		for (int i = 1; i <= m; i++) { adj[i].clear(); }
		fill(visited,visited+1004,0);
	}
	return 0;
}