#include<bits/stdc++.h>
using namespace std;
int n, ret;
int a[100004];
int result[100004];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		cin >> a[i];
	}
	ret = a[1];
	result[1] = a[1];
	for (int i = 2; i < n + 1; i++) {
		result[i] = max(result[i - 1] + a[i], a[i]);
		ret = max(result[i], ret);
	}
	cout << ret;
}