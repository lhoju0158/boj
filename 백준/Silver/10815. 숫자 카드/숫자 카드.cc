#include<bits/stdc++.h>
using namespace std;
int n, m;
int b[500004];
map<int,int> mp;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tem;
		cin >> tem;
		mp.insert({ tem,1 });
	}
	cin >> m;
	for (int i = 0; i < m; i++)cin >> b[i];
	for (int i = 0; i < m; i++) {
		if (mp.find(b[i]) != mp.end()) cout << 1;
		else cout << 0;
		cout << " ";
	}

	return 0;
}