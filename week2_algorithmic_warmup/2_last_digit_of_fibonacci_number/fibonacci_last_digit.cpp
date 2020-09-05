#include <iostream>
#include <vector>
using namespace std;
int get_fibonacci_last_digit_naive(int n) {
    vector<long long> m(n+1);
    m[0]=0;
    m[1]=1;
    for(int i=2;i<=n;i++){
    	m[i]=(m[i-1]+m[i-2])%10;
	}

    return m[n];
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    std::cout << c << '\n';
    }
