#include<bits/stdc++.h>
using namespace std;
int n, k;
int a[1004];
int cnt = 0;
int main() {
	cin >> n >> k;
	for (int i = 2; i < n + 1; i++) {
		a[i] = 1;
	}
	for (int i = 2; i < n + 1; i++) {
		if (!a[i]) continue;
		for (int j = i; j < n + 1; j++) {
			if (!a[j]) continue;
			if (j % i == 0) {
				a[j] = 0; cnt++;
			}
			if (cnt == k) {
				cout << j; return 0;
			}
		}
	}
}