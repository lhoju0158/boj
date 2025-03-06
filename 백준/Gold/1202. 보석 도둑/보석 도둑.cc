#include<bits/stdc++.h>
using namespace std;
long long n, k;
priority_queue<long long> pq;
vector<long long> bags;
vector<pair<long long, long long>> vec;
long long ret = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k; 
	vector<long long> bags(k);
	vector<pair<long long, long long>> vec(n);
	for (int i = 0; i < n; i++) cin >> vec[i].first >> vec[i].second;
	
	for (int i = 0; i < k; i++) cin >> bags[i];
	
	sort(bags.begin(), bags.end()); sort(vec.begin(), vec.end());

	int j = 0;
	for (int i = 0; i < k; i++) {
		while (j < n && vec[j].first <= bags[i]) pq.push(vec[j++].second);
		if (!pq.empty()) { ret += pq.top(); pq.pop(); }
	}
	cout << ret;
	return 0;
}