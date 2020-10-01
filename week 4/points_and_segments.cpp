
#include <bits/stdc++.h> 
#include <iostream>
#include <vector>

using namespace std;
using std::vector;
struct A{
	int x;
	char y;
};
 bool compareA(A a1,A a2){
	if(a1.x==a2.x)
		return (a1.y<a2.y);
	return (a1.x<a2.x);	
}

vector<int> fast_count_segments( vector<A> m, vector<int> points) {
  vector<int> cnt(points.size());
  multimap<int,int> j;
  for(int i=0;i<points.size();i++){
  	j.insert({points[i],i});
  }
  int c=0;
  
  vector<A>::iterator it=m.begin();
  while(it!=m.end()){
  	if(it->y=='l')
  		c++;
  	if(it->y=='r')
  		c--;
  	if(it->y=='p'){
  		multimap<int,int>::iterator it1;
  		int l=it->x;
  		it1=j.find(l);
  	
  		cnt[it1->second]=c;
  		j.erase(it1);
	  }
	it++;
  }
  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  vector<A> l;
  for(size_t i = 0;i<starts.size();i++){
  	l.push_back({starts[i],'l'});
  }
  for(size_t i = 0;i<starts.size();i++){
  	l.push_back({ends[i],'r'});
  }
  for(size_t i = 0;i<points.size();i++){
  	l.push_back({points[i],'p'});
  }
  sort(l.begin(),l.end(),compareA);

  vector <int> cnt1=fast_count_segments(l,points);
  //vector<int> cnt = naive_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt1.size(); i++) {
    std::cout << cnt1[i] << ' ';
  }
  return 0;
}
