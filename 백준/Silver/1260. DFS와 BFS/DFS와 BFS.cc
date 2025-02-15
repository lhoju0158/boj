#include<bits/stdc++.h>
using namespace std;
int n, m, v;
int a, b;
vector<int> adj[100004];
int visited[100004];
void dfs(int i) {
	cout << i << " ";
	visited[i] = 1;
	if (adj[i].empty()) return;
	for (int N : adj[i]) if (!visited[N]) dfs(N);
}
void bfs(int i) {
	visited[i] = 1;
	queue<int> q;
	q.push(i);
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		cout << front << " ";
		for (int N : adj[front]) {
			if (visited[N]) continue;
			visited[N] = 1;
			q.push(N);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i < n+1; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	dfs(v);
	cout << "\n";
	memset(&visited, 0, sizeof(visited));
	bfs(v);

}