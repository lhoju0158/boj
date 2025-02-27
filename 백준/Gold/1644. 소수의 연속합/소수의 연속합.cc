#include<bits/stdc++.h>
using namespace std;
int n;
int sum = 0;
int ret = 0;
int che[4000001];
int a[2000001];
int p = 0; // 갯수
int st = 0, en = 0;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n; 
	for (int i = 2; i < n + 1; i++) {
		if (che[i]) continue;
		for (int j = 2 * i; j < n + 1; j += i) {
			che[j] = 1;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (!che[i]) a[p++] = i;
	}

	while (true) {
		if (sum >= n) sum -= a[st++];
		else if (en == p) break;
		else sum += a[en++];
		if (sum == n)ret++;
	}
	cout << ret;
	
	return 0;
}