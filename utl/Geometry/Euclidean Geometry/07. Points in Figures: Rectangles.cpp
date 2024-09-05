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

	char c; 
	vector<array<double, 4>> rect;
	while (cin >> c and c != '*') {
		rect.push_back({0, 0, 0, 0});
		for (int i = 0; i < 4; i++) {
			cin >> rect.back()[i];
		}
	}

	double x, y; 
	int p = 1;
	while (cin >> x >> y and x != 9999.9 and y != 9999.9) {
		bool foi = 0;
		for (int i = 0; i < (int)rect.size(); i++) {
			if (x > rect[i][0] and y < rect[i][1] and x < rect[i][2] and y > rect[i][3]) {
				foi = 1;
				cout << "Point " << p << " is contained in figure " << i+1 << endl;
			}
		}

		if (!foi) {
				cout << "Point " << p << " is not contained in any figure" << endl;
			
		}
		p++;
	}
    
    return(0);
}
