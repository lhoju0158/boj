#include<bits/stdc++.h>
using namespace std;
int n;
int ret = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    string s;
    int i = 666;
    for (;; i++) {
        if (to_string(i).find("666") != string::npos)n--;
        if (n == 0)break;
    }
    cout << i;

    return 0;
}