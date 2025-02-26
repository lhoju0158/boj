#include<bits/stdc++.h>
using namespace std;
int n, k;
string s;
vector<int> strings;
int chars[26];
int count(int mask) {
	int ret = 0;
	for (int s : strings) {
		if ((s & mask)== s) ret++;
	}
	return ret;
}
int go(int index,int k,int mask) {
	if (k < 0) return 0;
	if (index == 26) return count(mask);
	int ret = go(index + 1, k - 1, mask | (1 << index));
	if (index != 'a' - 'a' && index != 'n' - 'a' && index != 't' - 'a' && index != 'i' - 'a' && index != 'c' - 'a') 
		ret = max(ret,go(index + 1, k, mask)); // 현재 index 포함시키지 않기
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	while (n--) {
		cin >> s; int tem = 0;
		for (char c : s) {
			tem |= (1 << (c - 'a'));
		}
		strings.push_back(tem);
	}
	cout << go(0, k, 0);

	return 0;
}