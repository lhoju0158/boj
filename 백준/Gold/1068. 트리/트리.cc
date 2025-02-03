#include<bits/stdc++.h>
using namespace std;
int n, p, root, r, ret;
vector<int> adj[50];
void go(int i) {
	if (i == r) return;
	if (adj[i].empty()) {
		ret++;
	}
	else {
		for (int child : adj[i]) {
			if (child == r && adj[i].size() == 1) ret++;
			go(child);
		}
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	ret = 0;
	for (int i = 0; i < n; i++) {
		cin >> p;
		if (p == -1) root = i;
		else adj[p].push_back(i);
	}
	cin >> r;
	if (r == root) { cout << 0; return 0; }
	go(root);
	cout << ret;
	return 0;
}