#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int main()
{
    _;

	auto primo = [](int x) {
		for (int i = 2; i * i <= x; i++) {
			if (x % i == 0) return 0;
		}
		return 1;
	};
	// se impar eu ganho
	// se nao, nao pode ser 1 << x
	// se nao, nao pode ser 2 * primo

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;

		int eu = (n != 1);
		if (n > 2 and n % 2 == 0) {
			if (int(n & (n - 1)) == 0) eu = 0;
			else if (n % 4 != 0 and primo(n / 2)) eu = 0;
		}

		cout << (eu ? "Ashishgup" : "FastestFinger") << endl;
	}
    
    return(0);
}
