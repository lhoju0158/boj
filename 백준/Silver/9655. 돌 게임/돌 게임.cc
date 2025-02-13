#include<bits/stdc++.h>
using namespace std;
int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	if (n % 3 == 0) {
		if ((n / 3) % 2 == 0) cout << "CY";
		else cout << "SK";
		return 0;
	}
	else if (n % 3 == 1) {
		if ((n / 3) % 2 == 0) cout << "SK";
		else cout << "CY";
		return 0;
	}
	else {
		if ((n / 3) % 2 == 0) cout << "CY";
		else cout << "SK";
		return 0;
	}
	return 0;
}