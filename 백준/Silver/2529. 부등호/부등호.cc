#include<bits/stdc++.h>
using namespace std;
int n;
char a[20];
int visited[10];
vector<string> ret;
bool good(int a, int b, char c) {
	if (a < b && c == '<') return true;
	else if (a > b && c == '>') return true;
	return false;
}
void go(int idx, string s) {
	if (s.size() == n + 1) {
		ret.push_back(s); return;
	}
	for (int i = 0; i <= 9; i++) {
		if (visited[i]) continue;
		if (idx == 0 || good(s[idx - 1] - '0', i, a[idx - 1]) ){
			visited[i]=1;
			go(idx + 1, s + to_string(i));
			visited[i] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	go(0, "");
	sort(ret.begin(), ret.end());
	cout << ret.back() <<"\n" << ret[0];
	return 0;
}