#include<bits/stdc++.h>
using namespace std;
int t, n, ret;
int a[2][100004];
int result[3][100004];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t; // t의 개수를 모른다
	for (int it = 0; it < t; it++) {
		cin >> n;
		for (int i = 0; i < 2; i++)
			for (int j = 1; j < n + 1; j++)
				cin >> a[i][j];
		result[0][1] = a[0][1]; result[1][1] = a[1][1]; result[2][1] = 0;
		ret = max(a[0][1], a[1][1]);
		for (int j = 1; j < n + 1; j++) {
			result[0][j] = max(result[1][j - 1], result[2][j - 1]) + a[0][j];
			result[1][j] = max(result[0][j - 1], result[2][j - 1]) + a[1][j];
			result[2][j] = max(result[0][j - 1], max(result[1][j - 1], result[2][j - 1]));
			ret = max(ret, max(result[0][j], max(result[1][j], result[2][j])));
		}
		cout << ret<<"\n";
	}

	return 0;
}