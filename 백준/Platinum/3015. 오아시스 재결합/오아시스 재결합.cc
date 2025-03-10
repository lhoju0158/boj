#include<bits/stdc++.h>
using namespace std;
int n, a;
stack<pair<int,int>> st;
long long ret = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		pair<int, int> p = { a,1 };
		while (!st.empty()&&st.top().first<a) {
			ret += st.top().second;
			st.pop();
		}
		if (!st.empty() && st.top().first == a) {
			p.second = st.top().second + 1;
			ret += st.top().second;
			st.pop();
		}
		if (!st.empty()) ret++;
		st.push(p);
	}
	cout << ret;
	return 0;
}