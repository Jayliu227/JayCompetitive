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

int r = 0, g = 0, b = 0, n;

set<char> s;
bool mem[256][256][256];

void dfs(int x, int y, int z){
	if(x < 0 || y < 0 || z < 0) return;
	if(mem[x][y][z] == true) return;
	mem[x][y][z] = true;
	if(x + y + z == 1){
		if(x == 1) s.insert('R');
		if(y == 1) s.insert('G');
		if(z == 1) s.insert('B');
	}else{
		dfs(x - 1, y - 1, z + 1);
		dfs(x - 1, y + 1, z - 1);
		dfs(x + 1, y - 1, z - 1);
		if(x >= 2) dfs(x - 1, y, z);
		if(y >= 2) dfs(x, y - 1, z);
		if(z >= 2) dfs(x, y, z - 1);
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    
    cin >> n;
    forn(i, n){
    	char x;
    	cin >> x;
    	r += (x == 'R');
    	g += (x == 'G');
    	b += (x == 'B');
    }

    FILL(mem, false);
    dfs(r, g, b);

    for(auto i : s) cout << i;

    return 0;
}