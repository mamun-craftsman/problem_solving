/*`````````````````````````````````````````````.
.											   .
.	My Lord, increase me in knowledge          .
.                                              .
...............................................*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
// Template for ordered set using PBDS (Policy-based data structure)
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#pragma GCC optimize("Ofast,unroll-loops")
#define int long long
#define memset(a, x) memset(a, x, sizeof(a))
#define PI 3.1415926535897932384626433832795l
#define yes cout << "YES" << '\n'
#define no cout << "NO" << '\n'
const int mod = 1e9 + 7;
#define vi vector<int>
#define vtd vector<vector<int>>
#define vp vector<pair<int, int>>
#define pqu priority_queue<int>
#define all(x) x.begin(), x.end()
#define setbit(n) __builtin_popcount(n);

bool cmp(pair<int, int> &x, pair<int, int> &y)
{
	if (x.second != y.second)
	{
		return x.second < y.second;
	}

	return x.first < y.first;
}

void input(vector<int> &v)
{
	for (auto &i : v)
		cin >> i;
}

void printV(vi &v) {
	for(auto it:v) {
		cerr<<it<<" ";
	}
	cerr<<'\n';
}
void printM(map<int, int>&mp) {
	for(auto it:mp) {
		cerr<<it.first<<" -> "<<it.second<<'\n';
	}
}

void PreSum(vector<int> &prefixSum, vector<int> &v, int n)
{
	prefixSum[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		prefixSum[i] = prefixSum[i - 1] + v[i - 1];
	}
}
double calcTax(double income) {
    double allowance = 12500.0;
    double reduction = 0.0;
    if (income > 100000.0) {
        reduction = (income - 100000.0) / 2.0;
        if(reduction > allowance) {
						reduction = allowance;
				}
    }
    double extra = 0.4 * reduction; 
    double taxable = income - allowance;
    if (taxable < 0.01) taxable = 0.0;

    double b1 = min(taxable, (50000.0-12500.0)); 
    double rem = taxable - b1;
    if (rem < 0.01) rem = 0.0;
    double b2 = min(rem, (150000.0-50000.0)); 
    double rem2 = rem - b2;
    if (rem2 < 0.01) rem2 = 0.0;
    double b3 = rem2; 

    double tax_standard = 0.20 * b1 + 0.40 * b2 + 0.45 * b3;
    return tax_standard + extra;
}

void uttor()
{
	double tax; cin>>tax;
	if(tax<0.01){
		cout<<0<<'\n';
		return;
	}
	double low = 0.0, high = 1e12;
	for (int it = 0; it < 160; ++it) {
		double mid = 0.5*(low + high);
		double predict = calcTax(mid);
		if (predict < tax) low = mid; 
		else high = mid;
	}
	cout<<0.5*(low + high)<<'\n';
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout<<setprecision(10);
	int tc = 1;
	cin >> tc;
	for (int t = 1; t <= tc; t++)
	{
		// cout << "Case #" << t << ": ";
		uttor();
	}
	return 0;
}

/*________________________________________________________________________




 _______  _______  _______           _           _
(       )(  ___  )(       )|\     /|( (    /|   ( (    /||\     /|
| () () || (   ) || () () || )   ( ||  \  ( |   |  \  ( |( \   / )
| || || || (___) || || || || |   | ||   \ | |   |   \ | | \ (_) /
| |(_)| ||  ___  || |(_)| || |   | || (\ \) |   | (\ \) |  \   /
| |   | || (   ) || |   | || |   | || | \   |   | | \   |   ) (
| )   ( || )   ( || )   ( || (___) || )  \  | _ | )  \  |   | |
|/     \||/     \||/     \|(_______)|/    )_)(_)|/    )_)   \_/




.........................................................................*/
