
#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
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
	to=to%60;
	from=from%60;
	if(from>to||a[to]<a[from-1]){
		return (10+a[to]-a[from-1]);
	}
	return a[to]-a[from-1];
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}


