#include<iostream>
#include<vector>
using namespace std;
vector<bool> is_composite(1e6 + 5, false);
vector<int> prime;
void sieve(int n)
{
    for (int i = 2; i < n; ++i)
    {
        if (!is_composite[i])
            prime.push_back(i);
        for (int j = 0; j < prime.size() && i * prime[j] < n; ++j)
        {
            is_composite[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

int main()
{
	int n; cin>>n;
    sieve(n);

    for(int i=0;i<prime.size() && prime[i]<n;i++)
        cout<<prime[i]<<" ";

	return 0;
}

/*

a number n will be cut only by the spf(n). In this way no number is marked more than once.
i%prime[j] == 0  means from now and beyond there is another number q where i/p = q and spf(q) <= prime[j]

*/