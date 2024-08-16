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

	int t; cin >> t;
	while (t--)
	{
		int n, soma = 0; cin >> n;
		for (int i = 1; i * i <= n; i++)
			if (!(n % i))
			{
				soma += i;
				if (n / i != i) soma += n / i;
			}
		soma -= n;
		
		if (soma > n) 
			cout << "abundant" << endl;
		else if (soma < n) 
			cout << "deficient" << endl;
		else
			cout << "perfect" << endl;
	}
    
    return(0);
}
