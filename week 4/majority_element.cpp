#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int count(vector<int> &a,int x, int left, int right){
	int c=0;
	for(int i=left;i<=right;i++){	
		if(x==a[i])
			c++;
	}
	return c;
}
int get_majority_element(vector<int> &a, int left, int right) {
  int l1,l2;
  if(left==right){
  	return a[left];
  }
  
  if(left<right){
  	int mid=left+(right-left)/2;
  	l1=get_majority_element(a,left,mid);
  	l2=get_majority_element(a,mid+1,right);
  }
  //cout<<"l1="<<l1<<"\t"<<"l2="<<l2<<endl;

  int c1=count(a,l1,left,right);
  int c2=count(a,l2,left,right);
  //cout<<"left="<<left<<"\t"<<"right="<<right<<endl;
 // cout<<"c1="<<c1<<"\t"<<"c2="<<c2<<endl;
  if(l1==l2){
  	return l1;
  }
  
  if(c1>(right-left+1)/2){
  	//cout<<l1<<endl;
  	return l1;
  }else if(c2>(right-left+1)/2){
  	//cout<<l2<<endl;
  	return l2;
  }else{
  	//cout<<-1<<endl;
  	return -1;
  }
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()-1)!=-1)  << '\n';
}
