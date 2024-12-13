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
typedef pair<int, int> ii;

vector<vector<int>> o(10, vector<int>(10, 0));
bool seg = false;
int d, l, r, c; 

bool valido(ii a)
{
	return a.f >= 0 and a.s >= 0 and a.f < 10 and a.s < 10;
}

void pinta()
{
	r--, c--;
	ii mov;
	if (d) mov = {1, 0}; else mov = {0, 1};
	for (int i = 0; i < l; i++)
	{
		ii v = {r + mov.f * i, c + mov.s * i};
		if (valido(v))
			o[v.f][v.s]++;
		else
			seg = true;
	}
}

int main()
{
    _;

	int n; cin >> n;	
	while (n--)
	{
		cin >> d >> l >> r >> c;	
		pinta();
	}

	if (seg)
	{
		cout << 'N' << endl;
		return 0;
	}

	bool res = true;
	for (auto li : o)
		for (auto ci : li)
			res &= (ci <= 1);

	cout << (res ? 'Y' : 'N') << endl;
    
    return(0);
}
