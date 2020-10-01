#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using std::vector;
using namespace std;
int lcs2(vector<int> &a, vector<int> &b) {
  int m=a.size(),n=b.size();
  int x[m+1][n+1];
  for(int i=0;i<=m;i++){
  	x[i][0]=0;
  }
  for(int j=0;j<=n;j++){
  	x[0][j]=0;
  }
  int i,j;
  for (i = 1; i <= m; i++)  
    {  
        for (j = 1; j <= n; j++)  
        {  
        
      
        if (a[i - 1] == b[j - 1])  
            x[i][j] = x[i - 1][j - 1] + 1;  
      	else
            x[i][j] = max(x[i - 1][j], x[i][j - 1]);  
        }  
    }  
    return x[m][n];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
