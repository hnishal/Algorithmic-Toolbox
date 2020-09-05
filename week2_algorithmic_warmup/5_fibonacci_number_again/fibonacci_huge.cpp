#include <iostream>
#include<vector>
using namespace std;
long long get_fibonacci_huge_naive(long long n, long long m) {
   vector<int> pis(2);
   pis[0]=0;
   pis[1]=1;
   for(long long int i=2;i<=n;i++){
   		pis.push_back((pis[i-1]+pis[i-2])%m);
   			if(pis[i]==1&&pis[i-1]==0){
   					pis.pop_back();
   					pis.pop_back();
   					break;
			   }
		   }
   
   return pis[n%pis.size()];
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
