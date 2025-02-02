#include<bits/stdc++.h>
using namespace std;
int n, i, mm, ss;
int w = 0; 
int score[3];
int Stime = 0;
int Etime = 0;
int result[3];
string s;
int main() {
	cin >> n;
	for (int q = 0; q < n; q++){
		cin >> i >> s;
		score[i]++;
		mm = stoi(s.substr(0, s.find(":")));
		ss = stoi(s.substr(s.find(":") + 1));
		Etime = mm * 60 + ss;
		result[w] += (Etime - Stime);

		if (score[1] > score[2]) w = 1;
		else if(score[2] > score[1]) w = 2;
		else w = 0;
		Stime = Etime;

	}
	result[w] += (48 * 60 - Stime);
	for (int i = 1; i < 3; i++) {
		mm = result[i] / 60;
		ss = result[i] % 60;
		cout.width(2);
		cout.fill('0');
		cout << mm << ":";
		cout.width(2);
		cout.fill('0');
		cout<< ss << "\n";
	}
	return 0;
}