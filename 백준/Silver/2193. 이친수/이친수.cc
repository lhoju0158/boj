#include<bits/stdc++.h>
using namespace std;
int n;
long long a[104][2];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	a[1][1] = 1;
	a[1][0] = 0;
	a[2][1] = 0;
	a[2][0] = 1;
	for (int i = 3; i < n + 1; i++) {
		a[i][0] = a[i - 1][0] + a[i - 1][1];
		a[i][1] = a[i - 1][0];
	}
	cout << a[n][0]+a[n][1];
}