#include<bits/stdc++.h>
using namespace std;
int n, a;
stack<pair<int,int>> st;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a; 
		while (!st.empty()) {
			if (st.top().first > a) {
				cout << st.top().second << " ";
				break;
			}
			st.pop();
		}
		if (st.empty()) cout << 0 << " ";
		st.push({ a,i });
	}
	return 0;
}