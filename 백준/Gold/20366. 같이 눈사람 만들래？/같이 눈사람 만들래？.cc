#include<bits/stdc++.h>
using namespace std;
int a[604];
int n, st, en, anna, elsa;
int ans = 0x7fffffff;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> a[i]; }
	sort(a, a + n);
	for (int i = 0; i < n - 3; i++) {
		for (int j = 3; j < n; j++) {
			anna = a[i] + a[j];
			st = i + 1; en = j - 1;
			while (st < en) {
				elsa = a[st] + a[en];
				ans = min(ans, abs(elsa - anna));
				// cout << i << " and " << j << " / " << st << " and " << en << " => ans " << abs(elsa - anna) << "\n";
				if (elsa < anna) { st++; }
				else if (elsa > anna) { en--; }
				else { cout << "0"; return 0; }
			}
		}
	}
	cout << ans;
	return 0;
}