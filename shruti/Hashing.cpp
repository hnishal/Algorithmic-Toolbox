#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int prime =7;
set<int>s;

bool check(int x,string &s1,string &s2)
{
    int a,b;
    int m=1;
    for(int i=0;i<x;++i){
         a=(s1[i]*m)%mod,m=(m*prime)%mod;
    }
    s.insert(a);
    m/=prime;
    for(int i=x;i<s1.length();++i)
    {
        b=((a-s1[i-x])/prime)%mod;
        b=(b+(s1[i]*m))%mod;
        s.insert(b);
        a=b;
    }
    m=1;
      for(int i=0;i<x;++i){
         a=(s2[0]*m)%mod,m=(m*prime)%mod;
    }
    if(s.find(a)!=s.end()) return 1;
    m/=prime;
    for(int i=x;i<s2.length();++i)
    {
        b=((a-s2[i-x])/prime)%mod;
        b=(b+(s2[i]*m))%mod;
        if(s.find(b)!=s.end()) return 1;
        a=b;
    }
    return 0;
}
int main() {
    string s1,s2;
    cin>>s1>>s2;
    int lb=0,rb=min(s1.length(),s2.length());
    while(lb<rb)
    {
        int mb=(lb+rb)/2;
        if(check(mb,s1,s2))
        lb=mb+1;
        else rb=mb;

    }
    cout<<lb-1;
}