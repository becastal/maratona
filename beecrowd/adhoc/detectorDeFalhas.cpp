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

	int n = -INF;
	int a, erro = 0;
	while (cin >> a)
	{
		if (a > n)
			swap(a, n);
		else if (!erro)
			erro = n + 1;
	}

	if (!erro) erro = n + 1;

	cout << erro << endl;
    
    return(0);
}
