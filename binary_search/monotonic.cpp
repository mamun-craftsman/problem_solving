#include<iostream>
#include<vector>
using namespace std;

int lastIndex(vector<int>&v, int x ) {
	int lo = 0, hi = v.size() - 1;
	int ans = -1;
	while(lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if(v[mid] == x) {
			ans = mid;
			lo = mid + 1;
		} else if(v[mid] < x) {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	return ans;
}

int main() {
	int n, target; cin>>n>>target;
	vector<int>v(n);
	for(int i = 0; i<n; i++) {
		cin>>v[i];
	}
	cout<<lastIndex(v, target)<<endl;
	return 0;
}