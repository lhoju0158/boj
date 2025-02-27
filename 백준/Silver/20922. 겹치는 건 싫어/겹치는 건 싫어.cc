#include<bits/stdc++.h>
using namespace std;
int n, k, ret = 0;
int visited[100004];
int a[200004];
int st, en;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) { cin >> a[i]; }
	st, en = 0;
	while (en < n) {
		if (visited[a[en]] != k) {
			visited[a[en]]++; en++;
		}
		else{
			visited[a[st]]--; st++;
		}
		ret = max(ret, en - st);
	}
	cout << ret;
	return 0;
}