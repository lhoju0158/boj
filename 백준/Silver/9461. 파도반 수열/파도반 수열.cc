#include<bits/stdc++.h>
using namespace std;
int t, n;
long long a[104];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;

	a[1] = 1;
	a[2] = 1;
	a[3] = 1;
	a[4] = 2;
	a[5] = 2;
	a[6] = 3;
	for (int i = 6; i <= 101 ; i++) {
		a[i] = a[i - 1] + a[i - 5];
	}
	for (int i = 1; i < t + 1; i++) {
		cin >> n;
		cout << a[n] << "\n";
	}

}