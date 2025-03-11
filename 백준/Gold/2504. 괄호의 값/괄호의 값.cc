#include<bits/stdc++.h>
using namespace std;
string s;
int ret = 0;
int tem = 1;
stack<char> st;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> s;
	for (int i = 0;i<s.size();i++) {
		if (s[i] == '(') {
			st.push(s[i]); tem *= 2;
		}
		else if (s[i] == '[') {
			st.push(s[i]); tem *= 3;
		}
		else {
			if (st.empty()) { ret = 0; break; }
			if (s[i] == ')' && st.top() != '(') { ret = 0; break; }
			if (s[i] == ']' && st.top() != '[') { ret = 0; break; }
			if (s[i] == ')') {
				if(s[i-1]=='(')	ret += tem; 
				tem /= 2; 
			}
			if (s[i] == ']') {
				if (s[i - 1] == '[') ret += tem;
				tem /= 3;
			}
			st.pop();
		}
	}
	if (!st.empty())ret = 0;
	cout << ret;
	
	return 0;
}