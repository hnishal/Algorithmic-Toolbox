#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int i=1;
  int prev=0;
  while(n>0){
  	if(n>=i&&i>prev){
  		summands.push_back(i);
	  }
	  else{
	  	summands[summands.size()-1]+=n;
	  }
	
  	n=n-i;
  	i++;
  	prev=summands[summands.size()-1];
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
