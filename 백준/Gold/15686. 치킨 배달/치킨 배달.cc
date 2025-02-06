#include<bits/stdc++.h>
using namespace std;
int n, m, ny, nx;
int a[54][54];
vector<pair<int, int>> twos,ones;
queue<pair<int, int>> q;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
vector<int> vec[54][54];
vector<vector<int>> forChecking;
void combi(int start, vector<int> tem) {
	if (tem.size() == m) {
		forChecking.push_back(tem);
		return;
	}
	for (int i = start + 1; i < twos.size(); i++) {
		tem.push_back(i);
		combi(i, tem);
		tem.pop_back();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 2) {
				twos.push_back({ i,j });
			}
			else if (a[i][j] == 1) {
				ones.push_back({ i,j });
			}
		}
	}
	vector<int> v;
	combi(-1, v);
	int result = 1e7;
	for (vector<int> vec : forChecking) {
		int temresult = 0;
		for (pair<int, int> p : ones) {
			int tem = 1e7;
			for (int i : vec) {
				tem = min(tem, abs(p.first - twos[i].first) + abs(p.second - twos[i].second));
			}
			temresult += tem;
		}
		result = min(result, temresult);
	}
	cout << result;

	return 0;
}