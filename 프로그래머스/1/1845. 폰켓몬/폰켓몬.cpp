#include <vector>
#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map<int,int> mp;
    for(int i:nums){
        if(mp.find(i)==mp.end()) mp.insert({i,1});
    }
    answer=min(mp.size(),nums.size()/2);
    return answer;
}