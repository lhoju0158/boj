#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> vec;
int input;
int ret = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> input;
		if (input == 0) {
			ret -= vec.back(); vec.pop_back();
		}
		else {
			ret += input; vec.push_back(input);
		}
	}
	cout << ret;
	return 0;
}