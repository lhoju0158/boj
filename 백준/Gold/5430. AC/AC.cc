#include<bits/stdc++.h>
using namespace std;
int n, m, x;
bool flag = false;
bool no;
string s1, s2;
deque<int> input;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while (n--) {
		input.clear();
		cin >> s1 >> m >> s2;
		x = 0;
		for (char c : s2) {
			if (c == '[' || c == ']') continue;
			if (c >= '0' && c <= '9') x = x * 10 + c - '0';
			else { if (x > 0)input.push_back(x); x = 0; }
		}
		if (x > 0)input.push_back(x);

		// string s1
		no = false; flag = false;
		for (char c : s1) {
			if (c == 'R') {
				flag = !flag;
			}
			else {
				if (input.size()) {
					if (flag) input.pop_back();
					else input.pop_front();
				}
				else { no = true; break; }
			}
		}
		if (no) { cout << "error\n"; continue; }
		else {
			if (flag) reverse(input.begin(), input.end());
			cout << "[";
			for (int i = 0; i < input.size(); i++) {
				cout << input[i];
				if (i < input.size() - 1) cout << ",";
			}
			cout << "]\n";
		}	
	}
	return 0;
}