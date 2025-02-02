#include<bits/stdc++.h>
using namespace std;
int n, input, t, ret;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int q = 0; q < n; q++) {
        cin >> input;
        ret = 0;
        t = 1;
        while (input >= int(pow(5, t))) {
            ret += input / int(pow(5, t));
            t++;
        }
        cout << ret << "\n";
    }
    return 0;
}