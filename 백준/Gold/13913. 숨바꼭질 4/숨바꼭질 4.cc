#include<bits/stdc++.h>
using namespace std;
int n, k;
int visited[200004], path[200004];
queue<int> q;
int go(int n) {
	visited[n] = 1;
	q.push(n);
	while (!q.empty()) {
		int n = q.front();
		q.pop();
		if (visited[k]) break;
		for (int nn:{n+1,n-1,2*n}) {
			if (nn < 0 || nn >= 200004) continue;
			if (visited[nn]) continue; // 다시 돌아온 것 => 무시
			path[nn] = n;
			visited[nn] = visited[n] + 1;
			q.push(nn);
		}
	}
	return visited[k] - 1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	visited[n] = 1;
	cout << go(n)<<"\n";

	vector<int> print;
	for (int i = k; i != n; i = path[i]) {
		print.push_back(i);
	}
	print.push_back(n);
	reverse(print.begin(), print.end());
	for (int i : print) {
		cout << i << " ";
	}
}