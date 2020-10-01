#include <iostream>
#include <vector>
using namespace std;
using std::vector;
int merge(int a[],int b[],size_t left,size_t mid,size_t right){
	int count=0;
	int i=left,j=mid,k=left;
	while((i<=mid-1)&&(j<=right)){
		if(a[i]<=a[j]){
			b[k++]=a[i++];
			
		}else{
			b[k++]=a[j++];
			
			count+=mid-i;
		}
	}
	while (i<=mid-1) 
        b[k++] = a[i++]; 
  	
	  while(j<=right){
  		b[k++]=a[j++];
	  }
  
    for (i = left; i <= right; i++) 
        a[i] = b[i]; 
        
    return count;
}

int get_number_of_inversions(int a[], int b[], size_t left, size_t right) {
  int number_of_inversions = 0;
  
  size_t ave;
  if(right>left){
  
  ave =(right + left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave+1, right);
  number_of_inversions +=merge(a,b,left,ave+1,right);
  
  }
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  int a[n];
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  int b[n];
  std::cout << get_number_of_inversions(a, b, 0, n-1) << '\n';
}
