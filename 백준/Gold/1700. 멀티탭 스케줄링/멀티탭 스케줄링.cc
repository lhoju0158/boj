#include<bits/stdc++.h>
using namespace std;
int n, k;
int visited[104];
int ret = 0;
int multiSize = 0;
vector<int> multi;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	vector<int> vec(k);
	for (int i = 0; i < k; i++) cin >> vec[i];
	for (int i = 0; i < k; i++) {
		bool no = false;
		for (int m : multi) {
			if (vec[i] == m) {
				no = true; break;
			}	// 이미 있는 경우
		}
		if (no) continue;
		if (multi.size() < n) { multi.push_back(vec[i]); continue; } // 새로 꽂는 경우
		// 있는거 빼야하는 경우
		int multiIdx = -1; int vecIdx = -1;
		for (int m = 0; m < multi.size(); m++) {
			int nowIdx = k; // vec 중 어디에 있는지
			for (int j = i + 1; j < k; j++) {
				if (vec[j] == multi[m]) { nowIdx = j; break; }
			}
			if(nowIdx == k){
				// 없는 것
				multiIdx = m; break;
			}
			else {
				// 있는 것
				if (vecIdx < nowIdx) { multiIdx = m, vecIdx = nowIdx; }
			}
		}
		// 빼기

		multi[multiIdx] = vec[i];
		ret++;
		/*for (int m = 0; m < multi.size(); m++) {
			cout << multi[m] << " ";
		}	cout << "\n";*/
	}
	cout << ret;


	return 0;
}