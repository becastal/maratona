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

	vector<ll> fib;
	fib.push_back(0), fib.push_back(1), fib.push_back(1);
	while (true)
	{
		ll i = fib.back() + fib[fib.size() - 2];
		if (i > (ll) 1e16) break;

		fib.push_back(i);
	}


	ll n; cin >> n;
	vector<int> fat;

	function<void(int, ll, vector<int>)> fatora = [&] (int i, ll a, vector<int> v) {
		if (i == 2)
		{
			if (a == 1) fat = v;
			return;
		}

		if (a % fib[i] == 0)
		{
			if (fib[i] == 144) fatora(i - 1, a, v);
			// 144 eh o unico numero da sequencia de fibbonacci que compartilha primos com numeros anteriores.
			// entao eh preciso testar se vale a pena ou nao fatorar com ele
			// (como no caso 21.21.8.2 que vale a pena pular o 144).
			v.push_back(i - 2);
			fatora(i, a / fib[i], v);
		}
		else fatora(i - 1, a, v);
	};

	fatora(fib.size() - 1, n, vector<int>());

	if (fat.empty())
		cout << "IMPOSSIBLE" << endl;
	else
	{
		for (int i : fat)
			cout << string(i, 'A') << 'B';
		cout << endl;
	}
    
    return(0);
}
