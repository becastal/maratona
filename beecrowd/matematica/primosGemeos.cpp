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
	if (n % 2 == 0)
		n--;
	
	int i; 
	for(i = n; i >= 5; i -= 2)
		if (primo(i) and primo(i - 2))
			break;


	cout << i - 2 << ' ' << i << endl;
    
    return(0);
}
