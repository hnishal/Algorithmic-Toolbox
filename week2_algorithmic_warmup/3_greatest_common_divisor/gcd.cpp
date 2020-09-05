#include <iostream>

int gcd_naive(int a, int b) {
	if(a==0)
		return b;
	if(b==0)
		return a;
  while(a!=b){
  	if(a>b){
  		a=a%b;
	  }
	else{
		b=b%a;
	}
	if(b==0)
		return a;
	if(a==0)
		return b;
  }
  return a;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_naive(a, b) << std::endl;
  return 0;
}
