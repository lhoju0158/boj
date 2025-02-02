#include<bits/stdc++.h>
using namespace std;
int a[101][101];
int h, w, tem;
string s;
int main() {
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        cin >> s;
        for (int j = 0; j < w; j++) {
            if (s[j] == '.') a[i][j] = -1;
            else a[i][j] = 0;
        }
    }
    tem = w+1;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] == 0) {
                tem = j;
            }
            else if (tem < j) {
                a[i][j] = j - tem;
            }
        }
        tem = w+1;
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}