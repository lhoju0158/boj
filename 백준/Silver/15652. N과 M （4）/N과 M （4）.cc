#include<bits/stdc++.h>
using namespace std;
int n, m;
void go(int start, vector<int> vec) {
	if (m == vec.size()) {
		for (int i : vec) cout << i << " ";
		cout << "\n"; return;
	}
	for (int i = start; i < n+1; i++) {
		vec.push_back(i);
		go(i, vec);
		vec.pop_back();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	vector<int>vec;
	go(1, vec);
	return 0;
}