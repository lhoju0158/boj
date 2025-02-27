#include<bits/stdc++.h>
using namespace std;
string input, bomb, ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> input >> bomb;
	for (char c : input) {
		ret += c;
		if (ret.size() >= bomb.size() && ret.substr(ret.size() - bomb.size(), bomb.size()) == bomb)
			ret.erase(ret.end() - bomb.size(), ret.end());
	}
	if (ret.empty())cout << "FRULA";
	else cout << ret;
	return 0;
}