#include<bits/stdc++.h>
using namespace std;
int n;
deque<int> dq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}
	while (true) {
		if(dq.size()!=1) dq.pop_front();
		if (dq.size() == 1) break;
		dq.push_back(dq.front());
		dq.pop_front();
	}
	cout << dq[0];
	return 0;
}