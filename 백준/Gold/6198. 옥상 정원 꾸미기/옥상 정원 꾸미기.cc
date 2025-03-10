#include<bits/stdc++.h>
using namespace std;
int n, a;
stack<int> st;
long long ret = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a; 
		while (!st.empty() && st.top()<=a) {
			st.pop();
		}
		ret += st.size();
		st.push(a);
	}
	cout << ret;
	return 0;
}