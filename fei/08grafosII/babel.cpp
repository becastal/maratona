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

int m;

int dijkstra(int origem, int destino, map<string, int>& mapa, vector<vector<pair<int, string>>>& grafo)
{   
    priority_queue<pair<int, pair<int, char>>, vector<pair<int, pair<int, char>>>, greater<pair<int, pair<int, char>>>> pq;
    vector<vector<int>> dist(mapa.size(), vector<int>(26, INF)); // 26 eh o numero de letras no alfabeto. 
    
    for (auto& distLetra : dist[origem])
        distLetra = 0;

    pq.push({ 0, {origem, 'a'} });

    while (!pq.empty())
    {
        pair<int, pair<int, char>> va = pq.top(); pq.pop();

        for (pair<int, string> vb : grafo[va.s.f])
        {
            if (va.s.f != origem && va.s.s == vb.s[0]) continue;
            int w = vb.s.size();

            if (dist[vb.f][vb.s[0] - 'a'] > dist[va.s.f][va.s.s - 'a'] + w)
            {
                dist[vb.f][vb.s[0] - 'a'] = dist[va.s.f][va.s.s - 'a'] + w;
                pq.push( {dist[vb.f][vb.s[0] - 'a'], {vb.f, vb.s[0]}} );
            }
        }
    }

    int menor = INF;
    for (auto caminho : dist[destino])
        menor = min(menor, caminho);

    return menor;
}

int main()
{
    while (cin >> m && m != 0)
    {
        string origem, destino; cin >> origem >> destino;
        vector<vector<pair<int, string>>> grafo;
        map<string, int> mapa;
        int contador = 0;
        for (int i = 0; i < m; i++)
        {
            string x, y, w; cin >> x >> y >> w;
            int xi, yi;
            if (mapa.count(x) == 0)
            {
                mapa[x] = contador;
                xi = contador;
                contador++;
                grafo.push_back(vector<pair<int, string>>());
            }
            else xi = mapa[x];
            if (mapa.count(y) == 0)
            {
                mapa[y] = contador;
                yi = contador;
                contador++;
                grafo.push_back(vector<pair<int, string>>());
            }
            else yi = mapa[y];

            grafo[xi].push_back({yi, w});
            grafo[yi].push_back({xi, w});
        }

        int resp = INF;
        if (mapa.count(destino) != 0)
            resp = dijkstra(mapa[origem], mapa[destino], mapa,  grafo);
        cout << (resp == INF || resp == 0 ? "impossivel" : to_string(resp)) << endl;
    }

    return 0;
}