#include<bits/stdc++.h>
using namespace std;
int n, ret;
string s;
int result[88];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		ret = 0;
		if (s[0] == 'O') {
			result[0] = 1; ret++;
		}
		else result[1] = 0;
		for (int j = 1; j < s.size(); j++) {
			if (s[j] == 'O') { 
				if (s[j - 1] == 'O')
					result[j] = result[j - 1] + 1;
				else
					result[j] = 1;
			}
			else result[j] = 0;
			ret += result[j];
		}
		//for (int j = 0; j < s.size(); j++) cout << result[j] << " ";
		
		cout << ret << "\n";
	}
	return 0;
}