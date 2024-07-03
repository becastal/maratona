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

string msg;

char minusculo(char c)
{
	if (c >= 'A' and c <= 'Z')
		return c - ('A' - 'a');
	return c;
}

char solve()
{
	char pri = minusculo(msg[0]);
	for (int i = 0; i < msg.size() - 1; i++)
		if (msg[i] == ' ' and minusculo(msg[i + 1]) != pri)
			return 'N';
	return 'Y';
}

int main()
{
    _;

	while (getline(cin, msg))
	{
		if (msg == "*") break;
		cout << solve() << endl;
	}
    
    return(0);
}
