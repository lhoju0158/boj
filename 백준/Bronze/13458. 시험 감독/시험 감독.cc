#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000004];
int b, c;
long long nb, nc = 0;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> b >> c;
	for (int i = 0; i < n; i++) {
		a[i] -= b; nb++;
		if (a[i] <= 0) continue;
		nc += (a[i] / c);
		if (a[i] % c != 0) nc++;
	}
	cout << nb + nc;
	return 0;
}