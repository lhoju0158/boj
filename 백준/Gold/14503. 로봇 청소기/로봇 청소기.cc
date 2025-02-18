#include<bits/stdc++.h>
using namespace std;
int n, m, r, c, d, ny, nx;
int a[54][54];
int dy[4] = { -1,0,1,0 }; int dx[4] = { 0,1,0,-1 };

void go(int nowy, int nowx, int nowd) {
	// 1
	if (a[nowy][nowx] == 0) {
		// cout << "1\n"; 
		a[nowy][nowx] = 2;
	}
	// 2
	bool _return = true;
	for (int i = 0; i < 4; i++) {
		ny = dy[i] + nowy; nx = dx[i] + nowx;
		if (a[ny][nx] == 0) _return = false;
	}
	if (_return) {
		// 빈칸이 없는 경우
		
		int backy = -dy[nowd] + nowy; int backx = -dx[nowd] + nowx;
		if (a[backy][backx] == 1) { // 벽인 경우
			// cout << "2-1\n";
			return;
		}
		else {
			// cout << "2-2\n";
			go(backy, backx, nowd);
			return;
		}
	}
	// 3
	int _pred = nowd;

	while (true) {
		int _nextd = (_pred + 3) % 4;
		// cout << _nextd << " ";
		ny = dy[_nextd] + nowy; nx = dx[_nextd] + nowx;
		// cout << "3\n";
		if (a[ny][nx] == 0) {
			// 빈칸 존재
			// cout << "빈칸 발견\n";
			go(ny, nx, _nextd);
			return;
		}
		_pred = _nextd;
		if (_pred == nowd) break;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> r >> c >> d;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];


	go(r, c, d);
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 2) ret++;
		}
		
	}


	cout << ret;
	return 0;
}