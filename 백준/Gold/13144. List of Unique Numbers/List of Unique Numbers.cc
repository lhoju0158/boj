#include<bits/stdc++.h>
using namespace std;
int a[100004];
int visited[100004];
int n;
long long ans;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	int st = 0; int en = 0; visited[a[0]] = 1;
	while (true) {
		while (visited[a[en + 1]] == 0 && en < n - 1) { en++; visited[a[en]]++; }
		if (en >= n || st >= n) break;
		ans += (en - st + 1);
		visited[a[st]]--; st++;
	}
	cout << ans;
	return 0;
}