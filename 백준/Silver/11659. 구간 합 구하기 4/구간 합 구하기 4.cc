#include<bits/stdc++.h>
using namespace std;
int a[100004];
int n, m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i < n + 1; i++) {
		int input;
		cin >> input;
		a[i] = input + a[i - 1];
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		cout << a[y] - a[x - 1]<<"\n";
	}

}