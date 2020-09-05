#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int n=stops.size();
    int start=0,end=0;
    int i=0,count=0;
    if(tank>=dist){
    	return 0;
	}
   while(i<n){
   	int check=0;
   	while(i<n&&stops[i]-start<=tank){
   			end=stops[i];
   			i++;
   			check++;
	   }
	   if(end==stops[n-1]){
	   	if(dist-start<=tank){
	   		return count;
		   }
		else{
			if(dist-end<=tank){
				count++;
				return count;
			}
			else if(dist-end>tank){
				return -1;
			}
		}
	   }
	   if(check==0){
	   	return -1;
	   }else{
	   	count++;
	   	start=end;
	   }
	   
   }
    return count;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
