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

void input(vector<int> &v, int &mx)
{
	for (auto &i : v){
		cin>>i;
		mx = max(mx, i);
	}

}

void printV(vi &v)
{
	for (auto it : v)
	{
		cerr << it << " ";
	}
	cerr << '\n';
}
void printM(map<int, int> &mp)
{
	for (auto it : mp)
	{
		cerr << it.first << " -> " << it.second << '\n';
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


const int MX = 1e5 + 1;
vector<int> prime;
bool isPrime[MX];
int mu[MX];
void linearSieve()
{
	memset(isPrime, true);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i < MX; i++)
	{
		if (isPrime[i])
		{
			prime.push_back(i);
		}
		for (int j = 0; j < prime.size() && i * prime[j] < MX; j++)
		{
			isPrime[i * prime[j]] = false;
			if (i % prime[j] == 0)
			{
				break;
			}
		}
	}

}
void calcMu()
{
	mu[1] = 1;
	for (int i = 2; i <= MX; i++) {
			int x = i;
			int cntDistinct = 0;
			bool squareFree = true;

			for (int p : prime) {
					if (1LL * p * p > x) break;
					if (x % p == 0) {
							cntDistinct++;
							x /= p;
							if (x % p == 0) {
									squareFree = false; 
									break;
							}
					}
			}
			if (!squareFree) {
					mu[i] = 0;
					continue;
			}
			if (x > 1) cntDistinct++; 

			if (cntDistinct % 2 == 0) mu[i] = +1;
			else mu[i] = -1;
	}
}
void uttor()
{
	int n; cin>>n;
	vector<int>a(n), b(n);
	int mx = INT_MIN;
	input(a, mx);
	input(b, mx);
	vector<int>freqA(mx+1, 0), freqB(mx+1, 0);
	for(int i=0;i<n;i++) {
		freqA[a[i]]++;
		freqB[b[i]]++;
	}

	vector<int>cdA(mx+1, 0), cdB(mx+1, 0);
	for(int i=1;i<=mx;i++) {
		for(int j=i;j<=mx;j+=i) {
			cdA[i] += freqA[j];
			cdB[i] += freqB[j];
		}
	}

	int ans = 0;
	for(int p:prime) {
		if(p > mx) break;
		int sum = 0;
		for(int k=1; k*p <= mx; k++) {
			sum += mu[k] * cdA[k*p] * cdB[k*p];
		}
		ans+=sum;
	}
	cout<<ans<<'\n';
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc = 1;
	cin >> tc;
	linearSieve();
	calcMu();
	//printV(prime);
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
