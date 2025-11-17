#include<iostream>
#include<vector>
using namespace std;
const int MAXN = 1e6 + 5;
vector<bool> is_prime(MAXN, true);
void seive() {
		is_prime[0] = is_prime[1] = false;
		for (int i = 2; i * i < MAXN; i++) {
				if (is_prime[i]) {
						for (int j = i * i; j < MAXN; j += i) {
								is_prime[j] = false;
						}
				}
		}
}

int main() {
	seive();
	for (int i = 0; i < 100; i++) {
		if (is_prime[i]) {
			cout << i << " ";
		}
	}
}
/*
if a prime number is p then it can cut >= p*p. Example: 25 who will cut it first? sqrt(25)=5.
We can use this technique into segemned seive also. if the range is [L,R] then we can start from L to sqrt(R).
*/