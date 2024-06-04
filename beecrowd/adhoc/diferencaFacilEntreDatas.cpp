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

vector<int> meses = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int solve(int d, int m)
{
	int soma = 0;
	for (int i = 1; i < m; i++)
		soma += meses[i];
	soma += d;
	return soma;
}

int main()
{
    _;

	int d1, m1, d2, m2;
	cin >> d1 >> m1 >> d2 >> m2;

	cout << solve(d2, m2) - solve(d1, m1) << endl;
    
    return(0);
}
