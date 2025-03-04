#include<bits/stdc++.h>
using namespace std;
int n;
int a[10004];
int x, y;
vector<pair<int, int>> vec;
int ret = 0;
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y; vec.push_back({ y,x });
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; i++) {
		pq.push(vec[i].second);
		if (pq.size() > vec[i].first) pq.pop();
	}
	while (!pq.empty()) {
		ret += pq.top(); pq.pop();
	}

	cout << ret;

	return 0;
}