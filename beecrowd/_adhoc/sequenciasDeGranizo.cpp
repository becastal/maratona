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

int granizo(int i)
{
	int maior = i;
	while (i > 1)
	{
		maior = max(maior, i);
		if (i % 2)
			i = 3 * i + 1;
		else
			i /= 2;
	}
	return maior;
}

int main()
{
    _;

	vector<int> h(501);
	for (int i = 1; i < 501; i++)
		h[i] = granizo(i);

	int n;
	while (cin >> n and n)
		cout << h[n] << endl;
	
    
    return(0);
}
