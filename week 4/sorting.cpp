#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
using std::vector;
using std::swap;

void partition2(vector<int> &a, int l, int r,int &m,int &n) {
   if (r - l <= 1) 
    { 
        if (a[r] < a[l]) 
            swap(a[l], a[r]); 
        m = l; 
        n = r; 
        return; 
    } 	
  int x = a[r];
  int j = l;
  int k = r;
  int i= l;
  while(i<=k){
  	if(a[i]<x){
  		swap(a[i],a[j]);
  		j++;
  		i++;
	  }
	else if(a[i]>x){
		swap(a[k],a[i]);
		k--;
	}
	else if(a[i]==x){
		i++;
	}
  }
  m=j-1;
  n=i;
  
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[r], a[k]);
  int m,n;
  partition2(a, l, r,m,n);

  randomized_quick_sort(a, l, m);
  randomized_quick_sort(a, n, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
