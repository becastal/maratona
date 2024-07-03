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

	int n, d;

	while (cin >> n >> d and n and d)
	{
		int mp[n][d];
		for (auto& l : mp)
			for (int& c : l)
				cin >> c;

		bool res = false;
		for (int i = 0; i < n; i++)
		{
			bool aluno = true;
			for (int j = 0; j < d; j++)
				aluno = aluno and mp[i][j];
			res = res or aluno;
		}

		cout << (res ? "yes" : "no") << endl;
	}
    
    return(0);
}
