#include <iostream>
#include <vector>
using namespace std;
int fibonacci_sum_naive(long long n) {
   if (n <= 1)
        return n;
    int sum=1;
    vector<int> a;
	a.push_back(0);
	a.push_back(1);
	for(int i=2;i<=100;i++){
		a.push_back((a[i-1]+a[i-2])%10);
		if(a[i]==1&&a[i-1]==0){
			a.pop_back();
			a.pop_back();
			break;
		}
	}
	for(long long i=2;i<=60;i++){
		sum+=a[i];
		a[i]=sum%10;
	}
	
	return a[n%60];
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n);
}
