#include<bits/stdc++.h>
using namespace std;
int n;
int a[14];
int p, m, s, d; // 1,2,3,4
vector<int> vec;
int MIN = 1e9 + 10;
int MAX = -MIN;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> p >> m >> s >> d;

	for (int i = 0; i < p; i++)vec.push_back(1);
	for (int i = 0; i < m; i++)vec.push_back(2);
	for (int i = 0; i < s; i++)vec.push_back(3);
	for (int i = 0; i < d; i++)vec.push_back(4);
	sort(vec.begin(), vec.end());
	do {
		int ret = a[0];
		for (int i = 1; i < n; i++) {
			if (vec[i-1] == 1) ret += a[i];
			else if (vec[i-1] == 2) ret -= a[i];
			else if (vec[i-1] == 3) ret *= a[i];
			else if (vec[i-1] == 4) ret /= a[i];
		}
		MIN = min(MIN, ret); MAX = max(MAX, ret);
	} while (next_permutation(vec.begin(), vec.end()));
	cout << MAX << "\n" << MIN;
	return 0;
}