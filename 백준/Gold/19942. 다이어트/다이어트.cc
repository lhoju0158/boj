#include<bits/stdc++.h>
using namespace std;
int n;
int _min[4];
int food[20][5];
int ret = -1;
vector<vector<int>> results;
void go(int start, vector<int> vec, int size) {
	if (vec.size() == size) {
		// total 합
		int _now[4] = { 0,0,0,0 };
		int tem = 0;
		for (int i = 0; i < 4; i++) {
			for (int v : vec) {
				_now[i] += food[v][i];
			}
			if (_min[i] > _now[i]) return;
		}
		for (int v : vec) {
			tem += food[v][4];
		}
		if (ret == -1 || ret >= tem) {
			if (ret == tem) {
				results.push_back(vec);
			}
			else {
				results.clear(); results.push_back(vec);
				ret = tem;
			}
		}
		return;
	}
	for (int i = start + 1; i < n; i++) {
		vec.push_back(i);
		go(i, vec, size);
		vec.pop_back();
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < 4; i++) cin >> _min[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> food[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		vector<int> vec;
		go(-1, vec, i);
	}
	cout << ret << "\n";
	if (ret != -1) {
		sort(results.begin(), results.end());
		for (int r : results[0]) { cout << r + 1 << " "; }
	}
	return 0;
}