#include<bits/stdc++.h>
using namespace std;
int a[100004];
int n, m, k;
int en;
int MIN = 0x7fffffff;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	en = 0;
	for (int st = 0; st < n; st++) {
		while (en < n && a[en] - a[st] < m) en++;
		if (en == n)break;
		MIN = min(MIN, a[en] - a[st]);
	}
	cout << MIN;
	return 0;
}