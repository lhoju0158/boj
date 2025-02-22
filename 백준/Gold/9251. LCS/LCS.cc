#include<bits/stdc++.h>
using namespace std;
string s1, s2;
int a[1004][1004];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s1 >> s2; 

	for(int i=1;i<s1.size()+1;i++)
		for (int j = 1; j < s2.size()+1; j++) {
			if (s1[i - 1] == s2[j - 1]) a[i][j] = a[i - 1][j - 1] + 1;
			else a[i][j] = max(a[i - 1][j], a[i][j - 1]);
		}
	cout << a[s1.size()][s2.size()];
	return 0;
}