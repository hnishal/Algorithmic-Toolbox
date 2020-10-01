#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int get_change(int m) {
	vector<int> coin_cnt(m+1,0);
	vector<int> deno={1,3,4};
	int no;
	for(int i=1;i<=m;i++){
		coin_cnt[i]=INT_MAX;
		for(int j=0;j<deno.size();j++){
			if(i>=deno[j])
				no=coin_cnt[i-deno[j]]+1;
			if(no<coin_cnt[i]){
				coin_cnt[i]=no;
			}
		}
	}
	return coin_cnt[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
