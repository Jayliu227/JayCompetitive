#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define forn(i,n) for(int i = 0; i < (int)n; i++)
#define for1(i,n) for(int i = 1; i < (int)n; i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define debug(x) cerr << #x << " = " << (x) << ";" << endl
#define debug2(x, y) cerr << #x << " = " << (x) << "; " << #y << " = " << (y) << ";" << endl

template<typename T> inline bool chkmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

typedef long long ll;

const int INF = (int) 1e9;
const int MOD = (int) 1e9 + 7;

int K = 26;

struct Vertex{
    int next[K];
    bool leaf = false;
    vertex(){
        FILL(next, -1);
    }
};

vector<Vertex> trie(1);

void add_string(string& s){
    int v = 0;
    for(char c : s){
        int to = c - 'a';
        if(trie[v].next[to] == -1){
            trie[v].next[to] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[to];
    }
    trie[v].leaf = true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
        
    
    
    return 0;
}