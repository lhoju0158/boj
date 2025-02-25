#include<bits/stdc++.h>
using namespace std;
string s1, s2;
string _add(string s1, string s2) {
	string result = "";
	if (s1.size() > s2.size()) { string tem1; tem1 = s1; s1 = s2; s2 = tem1; }
	// s1이 더 size작다
	reverse(s1.begin(), s1.end()); reverse(s2.begin(), s2.end());
	int carry = 0;
	for (int i = 0; i < s1.size(); i++) {
		int tem = s1[i] - '0' + s2[i] - '0' + carry;
		if (tem >= 10) { carry = tem/ 10; tem %= 10; }
		else { carry = 0; } 
		result.push_back((char)(tem + '0'));
	}
	for (int i = s1.size(); i < s2.size(); i++) {
		int tem = s2[i] - '0' + carry;
		if (tem >= 10) { carry = tem / 10; tem %= 10; }
		else { carry = 0; }
		result.push_back((char)(tem + '0'));
	}
	if (carry) result.push_back((char)(carry + '0'));
	reverse(result.begin(), result.end());
	return result;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s1 >> s2;
	cout << _add(s1, s2);
	return 0;
}
