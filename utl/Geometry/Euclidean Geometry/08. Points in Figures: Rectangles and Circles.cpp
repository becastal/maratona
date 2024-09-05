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
#define sq(x) ((x)*(x))

int main()
{
    _;

	char c; int cont = 1; 
	vector<array<double, 6>> figs;
	while (cin >> c and c != '*') {
		figs.push_back({0, 0, 0, 0, (double)cont++, (double)(c=='r')});
		if (c == 'r') {
			for (int i = 0; i < 4; i++) {
				cin >> figs.back()[i];
			}
		} else {
			for (int i = 0; i < 3; i++) {
				cin >> figs.back()[i];
			}
		}
	}

	double x, y; 
	int p = 1;
	while (cin >> x >> y and x != 9999.9 and y != 9999.9) {
		bool foi = 0;
		for (int i = 0; i < (int)figs.size(); i++) {
			if ((int)figs[i][5]) {
				if (x > figs[i][0] and y < figs[i][1] and x < figs[i][2] and y > figs[i][3]) {
					foi = 1;
					cout << "Point " << p << " is contained in figure " << i+1 << endl;
				}
			} else {
				if (sqrt(sq(x - figs[i][0]) + sq(y - figs[i][1])) < figs[i][2]) {
					foi = 1;
					cout << "Point " << p << " is contained in figure " << i+1 << endl;
				}
			}
		}

		if (!foi) {
				cout << "Point " << p << " is not contained in any figure" << endl;
			
		}
		p++;
	}
    
    return(0);
}
