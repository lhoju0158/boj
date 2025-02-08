#include<bits/stdc++.h>
using namespace std;
int n;
int a[1004];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	a[1] = 1;
	a[2] = 3;
	for (int i = 3; i < 1004; i++) {
		a[i] = (a[i - 1] + 2 * a[i - 2])%10007;
	}
	cout << a[n];
}