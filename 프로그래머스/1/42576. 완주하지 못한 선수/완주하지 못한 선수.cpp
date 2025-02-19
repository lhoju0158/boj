#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string,int> pm; 
    for(string p:participant){
        pm[p]++;
    }
    for(string c:completion){
        pm[c]--;
    }
    for(auto it = pm.begin(); it != pm.end(); it++) {
        if(it->second==1) {answer=it->first;break;}
    }   
    return answer;
}