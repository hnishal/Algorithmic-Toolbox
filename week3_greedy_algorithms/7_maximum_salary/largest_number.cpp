#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using std::vector;
using std::string;
using namespace std;

struct comp{
 string s1;
 inline bool operator()(string s1, string s2) 
{ 
    
	string a=s1+s2;
	string b=s2+s1;
    int x=stoi(a),y=stoi(b);
    if(x>y){
		return true;
	}else{
		return false;
	}
} 
};



	

string largest_number(vector<string> a) {
	comp l;
	string no;
    sort(a.begin(),a.end(),comp());
    
	for(string i:a){

    	no=no+i;
	}
  	
  return no;
  
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
