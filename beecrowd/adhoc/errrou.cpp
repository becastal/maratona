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
		int a, b, res;
		char op, lixo;
		cin >> a >> op >> b >> lixo >> res;
		
		int cor = (op == '+' ? a + b : (op == '-' ? a - b : a * b));
		cout << "E" << string(abs(res - cor), 'r') << "ou!" << endl;
	}
    
    return(0);
}
