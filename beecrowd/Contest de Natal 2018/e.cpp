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
    
    int e, d; cin >> e >> d;
    if (e > d) {
        cout << "Eu odeio a professora!" << endl;
    } else if (d - e >= 3) {
        cout << "Muito bem! Apresenta antes do Natal!" << endl;
    } else {
        cout << "Parece o trabalho do meu filho!" << endl;
        d += 2;
        if (d <= 24) {
            cout << "TCC Apresentado!" << endl;
        } else {
            cout << "Fail! Entao eh nataaaaal!" << endl;
        }
    }

    return(0);
}

