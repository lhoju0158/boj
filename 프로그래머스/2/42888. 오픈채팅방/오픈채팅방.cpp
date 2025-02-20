#include <string>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<string> _split(string s){
    vector<string> result;
    auto start= 0;auto end=s.find(" ");
    while(end!=string::npos){
        result.push_back(s.substr(start,end-start));
        start=end+1;end = s.find(" ",start);
    }
    result.push_back(s.substr(start));
    
    return result;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> mp;
    vector<pair<int,string>> output;
    for(string s:record){
        vector<string> result;
        result = _split(s);
        if(result[0]=="Enter"){
            if(mp.find(result[1])!=mp.end()){
                mp[result[1]]=result[2];
            }else{
                mp.insert({result[1],result[2]});
            }
            output.push_back({0,result[1]});
        }
        else if(result[0]=="Leave"){
            output.push_back({1,result[1]});
        }
        else if(result[0]=="Change"){
            mp[result[1]]=result[2];
        }
    }
    
    // 이제 answer만들기
    for(pair<int,string> p:output){
        string tem = mp[p.second]+(p.first==0?"님이 들어왔습니다.":"님이 나갔습니다.");
        answer.push_back(tem);
    }
    return answer;
}