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

	int h, m;
	char x;
	while (cin >> h >> x >> m)
	{
		string bh = bitset<4>(h).to_string();
		string bm = bitset<6>(m).to_string();
		for (auto& c : bh)
			if (c == '1')
				c = 'o';
			else 
				c = ' ';

		for (auto& c : bm)
			if (c == '1')
				c = 'o';
			else 
				c = ' ';

		printf(" ____________________________________________\n");
		printf("|                                            |\n");
		printf("|    ____________________________________    |_\n");
		printf("|   |                                    |   |_)\n");
		printf("|   |   8         4         2         1  |   |\n");
		printf("|   |                                    |   |\n");
		printf("|   |   %c         %c         %c         %c  |   |\n", bh[0], bh[1], bh[2], bh[3]);
		printf("|   |                                    |   |\n");
		printf("|   |                                    |   |\n");
		printf("|   |   %c     %c     %c     %c     %c     %c  |   |\n", bm[0], bm[1], bm[2], bm[3], bm[4], bm[5]);
		printf("|   |                                    |   |\n");
		printf("|   |   32    16    8     4     2     1  |   |_\n");
		printf("|   |____________________________________|   |_)\n");
		printf("|                                            |\n");
		printf("|____________________________________________|\n");
		printf("\n");

	}
    
    return(0);
}
