#include <iostream>
#include <vector>
#include <map> 
#include <iterator> 
using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  multimap<double,int,greater <double> > m;
  for(int i=0;i<weights.size();i++){
  	double ratio=(double)values[i]/weights[i];
  	m.insert(pair<double,int>(ratio,weights[i]));
  }
 
  while(capacity>0&&m.size()>0){
  	multimap<double,int> :: iterator it=m.begin();
  	if(capacity<=it->second){
  		value=value+(it->first)*capacity;
  		capacity=0;
	  }
	  else{
	  	capacity = capacity-(it->second);
	  	value+=(it->first)*(it->second);
	  	
	  }
	
	  m.erase(it);
  }
  

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);
  
  std::cout.precision(4);
  std::cout<<fixed << optimal_value << std::endl;
  return 0;
}
