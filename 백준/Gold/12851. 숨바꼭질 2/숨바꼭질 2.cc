#include<bits/stdc++.h>
using namespace std;
int n, k;
int cnt[200005]; // 갯수와 범위 혼동하지 말기!!
int visited[200005];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	queue<int> q;
	visited[n] = 1;
	cnt[n] = 1;
	q.push(n);
	while (!q.empty()) {
		int nn = q.front();
		q.pop();
		for (int i : {nn - 1, nn + 1, 2 * nn}) {
			if (i < 0 || i>= 200001) continue;
			if (!visited[i]) {
				visited[i] = visited[nn] + 1;
				q.push(i);
				cnt[i] += cnt[nn];
			}
			else if (visited[i] == visited[nn] + 1) cnt[i] += cnt[nn];
		}
	}
	cout << visited[k] - 1 << "\n" << cnt[k];
}