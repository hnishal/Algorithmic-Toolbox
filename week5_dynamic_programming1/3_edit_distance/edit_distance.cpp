#include <iostream>
#include <string>
using namespace std;
using std::string;
int min(int x, int y, int z) 
{ 
    return min(min(x, y), z); 
} 

int edit_distance(const string &str1, const string &str2) {
  int a[str1.length()+1][str2.length()+1]={0};
  int match,mmatch,del,ins;
  for(int i=0;i<=str1.length();i++){
  	a[i][0]=i;
  }
  for(int j=0;j<=str2.length();j++){
  	a[0][j]=j;
  }
  int i,j;
  for(i=1;i<=str1.length();i++){
		for(j=1;j<=str2.length();j++){
  			match=a[i-1][j-1];
			mmatch=a[i-1][j-1]+1;
			ins=a[i][j-1]+1;
			del=a[i-1][j]+1;	
		
			if(str1[i-1]==str2[j-1]){
  				a[i][j]=min(ins,del,match);
			  }
			else{
		  		a[i][j]=min(ins,del,mmatch);
		      }
  		}
  		
  }
  return a[str1.length()][str2.length()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
