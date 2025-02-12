#include<bits/stdc++.h>
using namespace std;
int n, t;
long long a[1000004];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	a[1] = 1; a[2] = 2; a[3] = 4;
	for (int i = 4; i < 1000004; i++) {
		a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % 1000000009;
	}
	for (int i = 1; i < n + 1; i++) { cin >> t; cout << a[t] << "\n"; }
	return 0;
}