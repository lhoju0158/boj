#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> s;
		list<char> ret;
		auto it = ret.begin();
		for (char c : s) {
			if (c == '<') {
				if (it != ret.begin()) { it--; }
			}
			else if (c == '>') {
				if (it != ret.end()) { it++; }
			}
			else if (c == '-') {
				if (it!=ret.begin()) {  it--; it = ret.erase(it); }
			}
			else {
				it = ret.insert(it, c); it++;
			}
		}
		for (char ch : ret) {
			cout << ch;
		}

		cout << "\n";
	}
	return 0;
}