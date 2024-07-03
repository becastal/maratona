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
		if (x % i == 0) return false;
	return true;
}

int main()
{
    _;

	int n; cin >> n;
	int v = 0, c = 0;
	
	while (c < 10)
	{
		if (primo(n))
			v += n, c++;
		n++;
	}

	cout << v << " km/h" << endl;
	cout << 59996400 / v << " h / " << 59996400 / v / 24 << " d" << endl;
    
    return(0);
}
