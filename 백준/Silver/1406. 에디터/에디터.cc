#include<bits/stdc++.h>
using namespace std;
string s;
stack<char> _left;
stack<char> _right;
int m;
char a;
char oper;
stack<char> ret;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> s >> m;
	for (char c : s) {
		_left.push(c);
	}

	while (m--) {
		cin >> oper;
		if (oper == 'L') {
			if (_left.size() != 0) {
				_right.push(_left.top()); _left.pop();
			}
		}
		else if (oper == 'D') {
			if (_right.size() != 0) {
				_left.push(_right.top()); _right.pop();
			}
		}
		else if (oper == 'B') {
			if (_left.size() != 0) {
				_left.pop();
			}
		}
		else {
			cin >> a;
			_left.push(a);
		}
		
	}
	while (!_left.empty()) {
		ret.push(_left.top()); _left.pop();
	}
	while (!ret.empty()) {
		cout << ret.top(); ret.pop();
	}
	while (!_right.empty()) {
		cout << _right.top(); _right.pop();
	}
	return 0;
}