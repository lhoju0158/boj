#include<bits/stdc++.h>
using namespace std;
int n;
int a[24][24];
int favor[404][4];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void whereSeat(int stu) {
	int stuy = n; int stux = n;
	// stu 어디 앉냐
	map<pair<int, int>, int> mp;
	// 좌표 / 인접칸 + 비어있는 칸 정보
	vector<pair<int, int>> levels[5];
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			// 인접칸
			if (a[y][x] != 0)continue;
			int level = 0; int empty = 0;
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i]; int nx = x + dx[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				for (int fri : favor[stu]) {
					if (fri == a[ny][nx]) level++;
				}
				if (a[ny][nx] == 0) empty++;
			}
			levels[level].push_back({ y,x });
			mp.insert({ {y,x},empty });
		}
	}
	for (int i = 4; i >= 0; i--) {
		if (levels[i].empty()) continue;
		int empty = 0;
		for (pair<int, int> p : levels[i]) {
			int y = p.first; int x = p.second; 
			if (empty < mp[p]) {
				// 많은 칸으로
				stuy = y; stux = x;
				empty = mp[p];
			}
			else if (empty == mp[p]) {
				// 행과 열 따지기
				if(stuy>y) { stuy = y; stux = x; }
				else if(stuy==y&&stux>x){ stuy = y; stux = x; }
			}
		}
		break;
	}
	a[stuy][stux] = stu;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < pow(n,2); i++) {
		int tem; cin >> tem;
		for (int j = 0; j < 4; j++) cin >> favor[tem][j];
		// 자리 배치하기
		whereSeat(tem);
	}
	int ret = 0;
	// 만족도 구하기
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			int tem = 0;
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i]; int nx = x + dx[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				for (int fri : favor[a[y][x]]) {
					if (fri == a[ny][nx]) tem++;
				}
			}
			if (tem == 0) continue;
			ret += (int)pow(10, tem-1);

		}
	}
	cout << ret;
	return 0;
}