#include<bits/stdc++.h>
using namespace std;
list<int> lt;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, k;
	cin >> n >> k;

	cout << "<";
	for (int i = 1; i <= n; i++) { lt.push_back(i); }
	auto it = lt.begin();

	while (!lt.empty()) {
		for (int i = 1; i < k; i++) {
			if (++it == lt.end()) it = lt.begin();
		}
		cout << *it;
		it = lt.erase(it); if (it == lt.end())it = lt.begin();
		if (lt.empty()) cout << ">";
		else cout << ", ";
	}
	return 0;
}