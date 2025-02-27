#include<bits/stdc++.h>
using namespace std;
int n, s;
int ret = 0x7fffffff;
int sum = 0;
int a[100004];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> s;
	for (int i = 0; i < n; i++) { cin >> a[i]; }
	// sort(a, a + n);
	int en = 0; sum = a[0];
	for (int st = 0; st < n; st++) {
		while (en < n && sum < s) { en++; if(en!=n) sum += a[en];  }
		if (en == n) break;
		ret = min(ret, en - st + 1);
		sum -= a[st];
	}
	if (ret == 0x7fffffff) ret = 0;
	cout << ret;
	return 0;
}