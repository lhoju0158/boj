#include<bits/stdc++.h>
using namespace std;
int n, a, b;
int ret = 0;
vector<pair<int, int>> cows;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> a >> b;
		cows.push_back({ a,b });
	}
	sort(cows.begin(), cows.end());
	for (pair<int, int> p : cows) {
		if (ret <= p.first) { ret = p.first + p.second; }
		else { ret += p.second; }
	}
	cout << ret;
}