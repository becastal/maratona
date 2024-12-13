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

	int b, l; cin >> b >> l;
	int mod = b + 1;

	vector<int> pot(l + 1), v(l);
	pot[0] = 1;
	for (int i = 1; i <= l; i++)
		pot[i] = (pot[i - 1] * b) % mod;

	for (int& vi : v)
		cin >> vi;
	reverse(v.begin(), v.end());

	int atual = 0;
	for (int i = 0; i < l; i++)
	{
		int at = v[i];
		at = (at * pot[i]) % mod;
		atual += at;
		atual %= mod;
	}

	if (!atual) return cout << "0 0" << endl, 0;

	for (int i = l - 1; i >= 0; i--)
	{
		int past = atual;
		int at = v[i];
		at = (at * pot[i]) % mod;
		atual -= at;
		atual += mod;
		atual %= mod;
		if (atual < v[i])
		{
			int x = atual;
			int past2 = atual;
			int at2 = (x * pot[i]) % mod;
			atual += at2;
			atual %= mod;
			if (atual == 0)
			{
				cout << l - i << " " << x << endl;
				return 0;
			}
			atual = past2;
		}
		if (past < v[i])
		{
			int x = v[i] - past;
			int past2 = atual;
			int at2 = (x * pot[i]) % mod;
			atual += at2;
			atual %= mod;
			if (atual == 0)
			{
				cout << l - i << " " << x << endl;
				return 0;
			}
			atual = past2;
		}
		atual = past;
	}
	cout << "-1 -1" << endl;

    return(0);
}
