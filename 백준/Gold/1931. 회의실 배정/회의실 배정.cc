#include<bits/stdc++.h>
using namespace std;
int n, a, b;
vector<pair<int, int>> vec;
int start = 0;
int _end = 0;
int ret = 0;
//bool cmp(pair<int, int> a, pair<int, int> b) {
//	if (a.first == b.first) return a.second > b.second;
//	else return a.first < b.first;
//}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> a >> b; 
	/*	if (a == b) ret++;
		else */
		vec.push_back({ b,a });
	}
	sort(vec.begin(), vec.end());
	for (pair<int, int> p : vec) {
		if (_end <= p.second) {
			_end = p.first; ret++;
		}
		else { continue; }
	}
	cout << ret;
	return 0;
}