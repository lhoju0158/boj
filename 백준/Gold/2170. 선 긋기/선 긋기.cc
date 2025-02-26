#include<bits/stdc++.h>
using namespace std;
int n, a, b;
vector<pair<int, int>>vec;
int s = 0; int e = 0;
int ret = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> a >> b; vec.push_back({ a,b });
	}
	sort(vec.begin(), vec.end());
	s = vec[0].first; e = vec[0].second;
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i].first > e) {
			ret += (e - s);
			s = vec[i].first; e = vec[i].second;
		}
		else {
			e = max(e, vec[i].second);
		}
		
	}
	ret += (e - s);
	cout << ret;
	return 0;
}