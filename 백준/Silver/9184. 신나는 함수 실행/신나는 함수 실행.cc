#include<bits/stdc++.h>
using namespace std;
int a, b, c;
int result[54][54][54];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for(int i=0;i<21;i++)
		for(int j=0;j<21;j++)
			for (int k = 0; k < 21; k++) {
				if (i == 0 || j == 0 || k == 0) result[i][j][k] = 1;
				else if (i < j && j < k)
					result[i][j][k] = result[i][j][k - 1] + result[i][j - 1][k - 1] - result[i][j - 1][k];
				else
					result[i][j][k] = result[i - 1][j][k] + result[i - 1][j - 1][k] + result[i - 1][j][k - 1] - result[i - 1][j - 1][k - 1];
			}
	while (true) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		cout << "w(" << a << ", " << b << ", " << c<<") = ";
		if (a <= 0 || b <= 0 || c <= 0) cout << 1;
		else if (a > 20 || b > 20 || c > 20) cout << result[20][20][20];
		else cout << result[a][b][c];
		cout << "\n";
	}
	return 0;
}