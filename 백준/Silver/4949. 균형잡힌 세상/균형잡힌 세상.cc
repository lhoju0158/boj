#include<bits/stdc++.h>
using namespace std;
string s;
stack<char> st;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (true) {
		getline(cin, s);
		if (s == ".") break;
		for (char c : s) {
			if (c == '[' || c == '(')
				st.push(c);
			else if (c == ']') {
				if (!st.empty() && st.top() == '[') {
					st.pop();
				}
				else {
					st.push(c);
					break;
				}
			}
			else if (c == ')') {
				if (!st.empty() && st.top() == '(') {
					st.pop();
				}
				else {
					st.push(c);
					break;
				}
			}
		}
		if (st.empty()) cout << "yes\n";
		else cout << "no\n";
		while (!st.empty())
			st.pop();
	}
	
	return 0;
}