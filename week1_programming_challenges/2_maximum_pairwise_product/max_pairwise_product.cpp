#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    int max1=0, max2=0, previndex=0;
    for(int i=0;i<numbers.size();i++){
    	if(numbers[i]>max1){
    		max1=numbers[i];
    		previndex=i;
		}
	}
	for(int i=0;i<numbers.size();i++){
		if(numbers[i]>max2&&i!=previndex){
			max2=numbers[i];
		}
	}
	return (long long)max1*max2;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
