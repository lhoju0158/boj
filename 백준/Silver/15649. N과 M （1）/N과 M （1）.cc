#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[10];
int visited[10];
void go(int k) {
	if (k == m) {
		for (int i = 0; i < m;i++) cout << a[i] << " ";
		cout << "\n"; return;
	}
	for (int i = 1; i < n + 1; i++) {
		if (!visited[i]) {
			a[k] = i;
			visited[i] = 1;
			go(k + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	go(0);

	return 0;
}