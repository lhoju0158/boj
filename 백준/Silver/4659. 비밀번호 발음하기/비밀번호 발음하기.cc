#include<bits/stdc++.h>
using namespace std;
string s;
bool first = false;
bool second = true;
bool third = true;
bool aeiou(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    else
        return false;
}
int main() {
    cin >> s;
    while (s != "end") {
        for (int i = 0; i < s.size(); i++) {
            if (aeiou(s[i])) first = true;
            if (i >= 2) {
                if ((aeiou(s[i - 2]) && aeiou(s[i - 1]) && aeiou(s[i])) || (!aeiou(s[i - 2]) && !aeiou(s[i - 1]) && !aeiou(s[i]))) second=false;
            }
            if (i >= 1) {
                if (s[i] == s[i - 1] && !(s[i] == 'e' || s[i] == 'o'))
                    third = false;
            }
        }
        if (first && second && third)
            cout << "<" << s << "> is acceptable.\n";
        else
            cout << "<" << s << "> is not acceptable.\n";

        cin >> s;
        first = false;
        second = true;
        third = true;
    }
    return 0;
}