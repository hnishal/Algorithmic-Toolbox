#include <iostream>
#include <vector>

using std::vector;
using namespace std;
int optimal_weight(int W, const vector<int> &w) {
	vector< vector<int> > m(w.size()+1, vector<int> (W+1,0));
	int val;
	for(int i=1;i<=w.size();i++){
		for(int x=1;x<=W;x++){
			if (w[i - 1] <= x) 
            	m[i][x] = max(w[i - 1] + m[i - 1][x - w[i - 1]],  m[i - 1][x]);
        	else
          		m[i][x] = m[i - 1][x];
		}
	}
	return m[w.size()][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
