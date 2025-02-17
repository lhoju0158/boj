#include<bits/stdc++.h>
using namespace std;
int k;
int _end;
int a[1030];
vector<int> ret[14]; // level 끼리 모아서 넣어놓은 것
void go(int start, int end, int level) {
	if (start > end) return;
	if (start == end) {
		ret[level].push_back(a[start]);
		return;
	}
	int mid = (start + end) / 2;
	ret[level].push_back(a[mid]);
	go(start, mid - 1, level + 1);
	go(mid + 1, end, level + 1);
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> k;
	_end = (int)pow(2, k) - 1;
	for (int i = 0; i < _end; i++) cin >> a[i];

	go(0, _end, 1);
	for (int i = 1; i < k + 1; i++) {
		for (int r : ret[i]) cout << r << " ";
		cout << "\n";
	}
	return 0;
}