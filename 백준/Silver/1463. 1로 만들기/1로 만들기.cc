#include<bits/stdc++.h>
using namespace std;
int visited[1000001];
int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	queue<int> q;
	q.push(n);
	visited[n] = 1;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < 3; i++) {
			int next=0;
			if (i == 0 && here % 3 == 0) next = here / 3;
			else if (i == 1 && here % 2 == 0) next = here / 2;
			else if (i == 2) next = here - 1;
			if (visited[next]) continue;
			visited[next] = visited[here] + 1;
			q.push(next);
		}
	}
	cout << visited[1] - 1;

}