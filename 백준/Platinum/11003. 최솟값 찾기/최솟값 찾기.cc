#include<bits/stdc++.h>
using namespace std;
int n, l, a;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> l;
	deque<pair<int,int>> dq; // value, idx
	for(int i=0;i<n;i++) {
		cin >> a;
		while (!dq.empty() && dq.front().second < i - l + 1) {
			dq.pop_front();
		}
		while (!dq.empty() && dq.back().first >= a) {
			dq.pop_back();
		}
		dq.push_back({ a,i });
		cout << dq[0].first << " ";
	}
	return 0;
}