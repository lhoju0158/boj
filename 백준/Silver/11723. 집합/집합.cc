#include<bits/stdc++.h>
using namespace std;
int m;
string s; int x;
int S;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> m;
	while (m--) {
		cin >> s;
		if (s == "add") {
			cin >> x;
			S |= (1 << x);
		}
		else if (s == "remove") {
			cin >> x;
			S &= ~(1 << x);
		}
		else if (s == "check") {
			cin >> x;
			if (S & (1 << x)) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (s == "toggle") {
			cin >> x;
			S ^= (1 << x);
		}
		else if (s == "all") {
			S = (1 << 21) - 1;
		}
		else if (s == "empty") {
			S = 0;
		}
	}

	return 0;
}