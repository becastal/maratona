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

    ll n;

    cin >> n;

    ll zero = 0, um = 0;

    queue<ll>L1;
    queue<ll>L0;

    while(n--){
        int t, lado;

        cin >> t >> lado;

        if(lado == 0){
            zero = t;
            L0.push(t);

        }

        else{
            um = t;
            L1.push(t);
        }
    }

    if(zero == 0){
        cout << um + 10 << endl;
    }

    else if(um == 0){
        cout << zero + 10 << endl;
    }


    else{
        while(true){
            int tempo;
            if(L0.front() < L1.front()){

                if(tempo > L0.front()){
                    tempo += 10;
                }
                else{
                tempo = L0.front() + 10;
                }
                L0.pop();
                while(L0.front() < tempo && !L0.empty()){
                    tempo = L0.front() + 10;
                    L0.pop();
                }
            }
            else{
                if(tempo > L1.front()){
                    tempo += 10;
                }
                else{
                tempo = L1.front() + 10;
                }
                L1.pop();
                while(L1.front() < tempo && !L1.empty()){
                    tempo = L1.front() + 10;
                    L1.pop();
                }
            }
            if(L0.empty()){
                while(L1.size() != 1){
                    L1.pop();
                }
                if(tempo > L1.front()){
                    cout << 10 + tempo << endl;
                }
                else{
                    cout << L1.front() + 10 << endl;
                }
                break;
            }
            if(L1.empty()){
                while(L0.size() != 1){
                    L0.pop();
                }
                if(tempo > L0.front()){
                    cout << 10 + tempo << endl;
                }
                else{
                    cout << L0.front() + 10 << endl;
                }
                break;
            }
        }
    }

    return(0);
}
