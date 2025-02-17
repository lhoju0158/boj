#include<bits/stdc++.h>
using namespace std;
int f, s, g, u, d;
int a[1000004];
int visited[1000004];
queue<int> q;
int ret = -1;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> f >> s >> g >> u >> d;
	visited[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int _now = q.front();
		q.pop();
		if (_now == g) { ret = visited[_now]; break; }
		for (int _next : {_now + u, _now - d}) {
			if (_next<=0 || _next>f) continue;
			if (visited[_next])continue;
			visited[_next] = visited[_now] + 1;
			q.push(_next);
		}
	}
	
	if (ret == -1)cout << "use the stairs";
	else cout << ret - 1;
	return 0;
}