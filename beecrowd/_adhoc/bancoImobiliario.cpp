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

	int I, n; cin >> I >> n;
	vector<int> v(3, I);

	while (n--)
	{
		char op; cin >> op;

		char quem, pagou, recebeu;
		int quanto;
		switch (op)
		{
			
			case 'C':
				cin >> quem >> quanto;
				v[quem - 'D'] -= quanto;

				break;
			case 'V':
				cin >> quem >> quanto;
				v[quem - 'D'] += quanto;

				break;
			case 'A':
				cin >> recebeu >> pagou >> quanto;
				v[pagou - 'D'] -= quanto;
				v[recebeu - 'D'] += quanto;

				break;
		}
	}
	cout << v[0] << ' ' << v[1] << ' ' << v[2] << endl;
    
    return(0);
}
