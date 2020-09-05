#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using std::vector;
using namespace std;
long long max_dot_product(vector<int> a, vector<int> b) {
  sort(a.begin(), a.end(),greater<int>());
  sort(b.begin(), b.end(),greater<int>());
  int n=a.size();
  cout<<endl;
  long long result = 0;
  vector<int>::iterator it1=a.begin();
  vector<int>::iterator it2=b.begin();
  for (size_t i = 0; i < n; i++) {
  	it1=a.begin();
    it2=b.begin();
    result+=(long long)a[0]*b[0];
    a.erase(it1);
    b.erase(it2);
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
