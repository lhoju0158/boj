#include<bits/stdc++.h>
using namespace std;
string s;
string pi[3] = { "pi","ka","chu" };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s;
	for (int i = 0; i < s.size();) {
		bool yes = false;
		for (string p : pi) {
			if (s.substr(i, p.size()) == p) {
				i += p.size(); yes = true; break;
			}
		}
		if (!yes) { cout << "NO"; return 0; }
	}
	cout << "YES";	
	return 0;
}
