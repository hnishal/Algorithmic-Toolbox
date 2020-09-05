#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <map>
using std::vector;
using namespace std;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  multimap<int,int> m;
  for(int i=0;i<segments.size();i++){
  	m.insert(pair<int,int>(segments[i].end,segments[i].start));
  }
  
  multimap<int,int>::iterator it;
  int i=0;
  it=m.begin();
  while(it!=m.end()){
  	points.push_back(it->first);
  	int prev=it->first;
  	while(prev<=it->first&&prev>=it->second&&it!=m.end()){
  		it++;
	  }
  }
  
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
