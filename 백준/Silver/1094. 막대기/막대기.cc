#include<bits/stdc++.h>
using namespace std;
int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n;

	priority_queue<int,vector<int>,greater<int>> pq;
	pq.push(64); int total = 64;
	while (true) {
		if (total <= n) break;
		int small = pq.top(); pq.pop(); 
		small /= 2; total -= small;
		if (total >= n) { pq.push(small); }
		else { pq.push(small); pq.push(small); total += (small); }
	}
	cout << pq.size();

	return 0;
}