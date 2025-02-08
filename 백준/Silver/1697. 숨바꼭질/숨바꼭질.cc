#include<bits/stdc++.h>
using namespace std;
int a[200004];
int visited[200004];
int n, m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	visited[n] = 1;
	queue<int> q;
	q.push(n);
	while (!q.empty()) {
		int here = q.front();
		if (visited[m]) break;
		q.pop();
		for (int there : {here - 1, here + 1, 2 * here}) {
			if (there < 0 || there>200003) continue;
			if (visited[there]) continue;
			visited[there] = visited[here] + 1;
			q.push(there);
		}
	}
	cout << visited[m] - 1;
	return 0;
}