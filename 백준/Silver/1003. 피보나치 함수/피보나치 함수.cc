#include<bits/stdc++.h>
using namespace std;
int n, c;
int fibo[44][2];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	fibo[0][0] = 1;
	fibo[0][1] = 0;
	fibo[1][0] = 0;
	fibo[1][1] = 1;
	for (int i = 2; i < 44; i++) {
		fibo[i][0] = fibo[i - 1][0] + fibo[i - 2][0];
		fibo[i][1] = fibo[i - 1][1] + fibo[i - 2][1];
	}
	for (int i = 0; i < n; i++) {
		cin >> c;
		cout << fibo[c][0] << " " << fibo[c][1] << "\n";
	}
}