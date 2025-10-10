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

bool primo(int x)
{
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}

int main()
{
    _;
	int c = 0;

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n; n++;
		cout << (n % 7 == 0 and n % 2 == 1 and primo(n + 2) ? "Yes" : "No") << endl;
	}

    return(0);
}
