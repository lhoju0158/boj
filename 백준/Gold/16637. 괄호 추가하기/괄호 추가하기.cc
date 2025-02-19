#include<bits/stdc++.h>
using namespace std;
int n, ret = -987654321;
string s;
vector<int> nums;
vector<char> oper;

int _operation(char a, int b, int c) {
	if (a == '+') return b + c;
	if (a == '*') return b * c;
	if (a == '-') return b - c;
}
void go(int _now, int _num) {
	// _now nums의 현재 index, _num 누적합
	if (_now == nums.size() - 1) {
		// 끝에 도달
		ret = max(ret, _num);
		return;
	}
	// a,b,c가 있을 경우 (a b) c / a (b c)  이렇게 두 가지가 존재
	go(_now + 1, _operation(oper[_now], _num, nums[_now + 1]));
	if (_now + 2 <= nums.size() - 1) {
		// a (b c)를 할 수 있는 경우
		int tem = _operation(oper[_now + 1], nums[_now + 1], nums[_now + 2]);
		go(_now + 2, _operation(oper[_now], _num, tem));
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0)nums.push_back(s[i] - '0');
		else oper.push_back(s[i]);
	}
	go(0, nums[0]);
	cout << ret;
	
}