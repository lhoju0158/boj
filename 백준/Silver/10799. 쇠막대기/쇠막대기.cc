#include<bits/stdc++.h>
using namespace std;
stack<int> st;
string s;
int ret = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') st.push(i);
		else {
			int idx = st.top(); st.pop();
			if (i - idx == 1) ret += st.size();
			else ret++;
		}
	}
	cout << ret;
	return 0;
}