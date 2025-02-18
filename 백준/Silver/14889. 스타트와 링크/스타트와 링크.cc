#include<bits/stdc++.h>
using namespace std;
int n;
int a[24][24];
int ret = 150;
vector<vector<int>> result;
vector<vector<int>> result2;
int temnum;

void go(int start, vector<int> vec) {
	if (vec.size() == n / 2) {
		result.push_back(vec);
		return;
	}
	for (int i = start + 1; i < n; i++) {
		vec.push_back(i);
		go(i, vec);
		vec.pop_back();
	}
	return;
}
void go2(int start, vector<int> vec) {
	if (vec.size() == 2) {
		result2.push_back(vec);
		return;
	}
	for (int i = start + 1; i < n/2; i++) {
		vec.push_back(i);
		go2(i, vec);
		vec.pop_back();
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
	vector<int> vec;
	go(-1, vec);
	vec.clear();
	go2(-1, vec);

	
	for (vector<int> _first : result) {
		int tem[24] = { 0 }; vector<int> _second;
		for (int i = 0; i < n / 2; i++) {
			tem[_first[i]] = 1;
		}
		for (int i = 0; i < n; i++) {
			if (tem[i] == 0) _second.push_back(i);
		}
		int f = 0; int s = 0;
		for(vector<int> two: result2){
			f += a[_first[two[0]]][_first[two[1]]];
			f += a[_first[two[1]]][_first[two[0]]];
			s += a[_second[two[0]]][_second[two[1]]];
			s += a[_second[two[1]]][_second[two[0]]];
		}		

		//cout << "\nfirst\n";
		//for (int i = 0; i < n/2; i++) {
		//	cout << _first[i] << " ";
		//}
		//cout << "\nsecond\n";
		//for (int i = 0; i < n / 2; i++) {
		//	cout << _second[i] << " ";
		//}
		//cout << " <= " << f << " " << s << " " << "\n";

		ret = min(ret, abs(f - s));
	}
	cout << ret;

	return 0;
}