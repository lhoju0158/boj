#include<bits/stdc++.h>
using namespace std;
int n, l, a, b;
priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
int _end = 0;
int ret = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> l;
	while (n--) {
		cin >> a >> b; pq.push({ a,b });
	}
	while (!pq.empty()) {
		pair<int, int> p = pq.top(); pq.pop();
		if (_end >= p.second) continue;
		if (_end <= p.first) {
			int num = (p.second - p.first) / l;
			int rest = (p.second - p.first) % l;
			if (rest) {
				ret += (num + 1);
				_end = p.first + (num + 1) * l;
			}
			else {
				ret += num;
				_end = p.second;
			}
		}
		else {
			int num = (p.second - _end) / l;
			int rest = (p.second - _end) % l;
			if (rest) {
				ret += (num + 1);
				_end = _end + (num + 1) * l;
			}
			else {
				ret += num;
				_end = p.second;
			}
		}
	}
	cout << ret;
	return 0;
}