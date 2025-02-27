#include<bits/stdc++.h>
using namespace std;
int n, m, ret;
int a[10003];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) { cin >> a[i]; }
	int en = 0; int sum = a[0];
	for (int st = 0; st < n; st++) {
		while (en < n && sum < m) { en++; sum += a[en]; }
		if (sum == m) { ret++; }
		sum -= a[st];
	}
	cout << ret;
	return 0;
}