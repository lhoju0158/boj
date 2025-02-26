#include<bits/stdc++.h>
using namespace std;
int n, m, x;
vector<int> vec;
int ret = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for(int i=0; i<n;i++) {
		cin >> m; vec.push_back(m);
	}
	cin >> x;
	int start = 0; int end = n - 1;
	sort(vec.begin(), vec.end());
	while (true) {
		if (start >= end) { break; }
		if (vec[start] + vec[end] == x) {
			ret++; start++; 
		}
		else if (vec[start] + vec[end] > x) {
			end--;
		}
		else { start++; }
	}
	cout << ret;
	return 0;
}