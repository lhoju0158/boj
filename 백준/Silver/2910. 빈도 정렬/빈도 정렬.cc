#include<bits/stdc++.h>
using namespace std;
int n, c, a[1004];
vector<pair<int, int>> v;
map<int, int> mp, mp_first;
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) // 횟수가 같다
		return mp_first[a.second] < mp_first[b.second];
	else // 횟수가 다르다 => 그러면 횟수가 많은 것이 앞으로 가기
		return a.first > b.first; 
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> a[i]; mp[a[i]]++;
		if (mp[a[i]] == 1) mp_first[a[i]] = i; // mp는 횟수를 저장, mp_first는 가장 처음으로 해당
	}
	// vector는 출력을 위해서 생성
	for (auto it : mp) {
		v.push_back({ it.second, it.first }); // 횟수가 앞, 해당 숫자가 뒤
	}
	sort(v.begin(), v.end(), cmp);
	for (auto i : v) {
		for (int j = 0; j < i.first; j++) {
			cout << i.second << " ";
		}
	}
	return 0;
}