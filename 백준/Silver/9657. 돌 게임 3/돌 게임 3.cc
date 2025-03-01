#include<bits/stdc++.h>
using namespace std;
int n;
int d[1004];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	d[1] = 1; d[2] = 0; d[3] = 1; d[4] = 1;
	for (int i = 5; i < n + 1; i++) {
		if (d[i - 1] && d[i - 3] && d[i - 4]) d[i] = 0;
		else d[i] = 1;
	}
	if (d[n]) cout << "SK";
	else cout << "CY";
	return 0;
}