#include<bits/stdc++.h>
using namespace std;
int x, y;
int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
string w[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT","SUN" };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> x >> y;
	int ret = 0;
	for (int i = 1; i < x; i++)ret += days[i];
	ret += (y - 1);
	cout << w[ret % 7];

	return 0;
}