#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

const vector<pair<int, int>> movimentos = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };
vector<vector<char>> mapa;
vector<pair<int, int>> robos;
map<vector<pair<int, int>>, int> distancia;
int n;

bool movimentosValidos(vector<pair<int, int>> posicoes, pair<int, int> movimento)
{
    bool resposta = false;
    vector<pair<int, int>> novasPosicoes;
    for (int i = 0; i < 3; i++)
    {
        pair<int, int> pos = posicoes[i];
        pair<int, int> novaPos = { pos.f + movimento.f, pos.s + movimento.s };
        if (novaPos.f >= 0 && novaPos.f < n && novaPos.s >= 0 && novaPos.s < n && mapa[novaPos.f][novaPos.s] != '#') resposta = true;
    }
    if (resposta) if (distancia.find(novasPosicoes) != distancia.end()) resposta = false;
    return(resposta);
}

bool chegaramJunto(vector<pair<int, int>> posicoes)
{
    for (auto pos : posicoes)
    {
        if (mapa[pos.f][pos.s] != 'X') return(false);
    }
    return(true);
}

bool vetorUnico(vector<pair<int, int>> vetor)
{
    set<pair<int, int>> s;
    for (auto v : vetor) s.insert(v);
    return(vetor.size() == s.size());
}

vector<pair<int, int>> atualizaPosicoes(vector<pair<int, int>> posicoes, pair<int, int> movimento)
{
    vector<pair<int, int>> resposta;
    for (int i = 0; i < 3; i++)
    {
        pair<int, int> pos = posicoes[i];
        pair<int, int> novaPos = { pos.f + movimento.f, pos.s + movimento.s };
        if (novaPos.f >= 0 && novaPos.f < n && novaPos.s >= 0 && novaPos.s < n && mapa[novaPos.f][novaPos.s] != '#')
        {
            resposta.push_back(novaPos); 
        }
        else
        {
            resposta.push_back(pos); 
        }
    }

    return(resposta);
}

int bfs()
{
    distancia.clear();
    queue<vector<pair<int, int>>> q;
    q.push(robos);
    distancia[robos] = 0;

    while (!q.empty())
    {
        vector<pair<int, int>> posicoesAtuais = q.front(); q.pop();
        if (chegaramJunto(posicoesAtuais)) return(distancia[posicoesAtuais]);
        for (pair<int, int> mov : movimentos)
        {
            if (movimentosValidos(posicoesAtuais, mov))
            {
                vector<pair<int, int>> posicoesNovas = atualizaPosicoes(posicoesAtuais, mov);
                if (vetorUnico(posicoesNovas))
                {
                    q.push(posicoesNovas);
                    distancia[posicoesNovas] = distancia[posicoesAtuais] + 1;
                }
            }
        }
    }
    return (-1);
}

// algum problema com linhas e colunas.
int main()
{
    int T; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> n;
        mapa = vector<vector<char>>(n, vector<char>(n));
        robos = vector<pair<int, int>>(3);
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
        {
            cin >> mapa[i][j];
            if (mapa[i][j] >= 'A' && mapa[i][j] <= 'C') robos[mapa[i][j] - 'A'] =  { i, j };
        }

        int resposta = bfs();
        cout << "Case " << t << ": ";
        if (resposta == -1) cout << "trapped" << endl; else cout << resposta << endl;
    }
    return(0);
}
