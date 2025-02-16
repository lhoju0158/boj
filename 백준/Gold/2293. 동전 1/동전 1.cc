#include<bits/stdc++.h>
using namespace std;
int n, m, tem;
int a[10004];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	vector<int> vec(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> vec[i];
	}

	a[0] = 1;
	sort(vec.begin(), vec.end());
	for (int i = 1; i <= n; i++) {
		for (int j = vec[i]; j <= m; j++) {
			a[j] += a[j - vec[i]];
		}
	}
	cout << a[m];
	return 0;
}