#include<bits/stdc++.h>
using namespace std;
int a[5][8];
int Turn[5];
int k;
int num, d;
int ret = 0;
string s;
void checkRight(int now, int nowD) {
	if (now == 4) return;
	int next = now + 1;
	if (a[now][2] != a[next][6]) {
		// 돌리기
		Turn[next] = -nowD;
		// 다음거
		checkRight(next, -nowD);
	}
}
void checkLeft(int now, int nowD) {
	if (now == 1) return;
	int next = now - 1;
	if (a[now][6] != a[next][2]) {
		// 돌리기
		Turn[next] = -nowD;
		// 다음거
		checkLeft(next, -nowD);
	}
}
void setForNext() {
	for (int i = 1; i <= 4; i++) {
		if (Turn[i] == 0) continue;
		if (Turn[i] == -1) {
			// 반시계
			int tem = a[i][0];
			for (int j = 0; j < 7; j++) {
				a[i][j] = a[i][j + 1];
			}
			a[i][7] = tem;
		}
		else if (Turn[i] == 1) {
			// 시계
			int tem = a[i][7];
			for (int j = 7; j > 0; j--) {
				a[i][j] = a[i][j - 1];
			}
			a[i][0] = tem;
		}
	}
}
int main() {
	for (int i = 1; i <= 4; i++) {
		cin >> s;
		for (int j = 0; j < 8; j++) {
			a[i][j] = s[j] - '0';
		}
	}
	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> num >> d;
		fill(Turn, Turn + 5, 0);
		Turn[num] = d;
		checkRight(num, d); checkLeft(num, d);
		setForNext();
	}
	for (int i = 1; i <= 4; i++) {
		ret += (a[i][0] * int(pow(2, i - 1)));
	}
	cout << ret;
	return 0;
}