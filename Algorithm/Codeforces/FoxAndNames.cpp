#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define forn(i,n) for(int i = 0; i < (int)n; i++)
#define for1(i,n) for(int i = 1; i < (int)n; i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define endl '\n'

using namespace std;

inline int nxt(){ int x; cin >> x; return x; }

template<class T> inline void LOG(T s){
#ifdef LOCAL_COMPILATION
    cout << "DEBUG: " << s << endl;
#endif
}

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef long long ll;

const int INF = (int) 1e9;
const int MODULO = (int) 1e9 + 7;

int indegree[26];
vvi adj_list;
int n;
bool circle = false;
int dfs_num[26];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    n = nxt();
    string s;
    adj_list.resize(26);
    FILL(dfs_num, -1);
    FILL(indegree, 0);
    string prev = "";
    forn(i, n){
        cin >> s;
        if(prev == ""){
            prev = s;
        }else{
            forn(j, prev.size()){
                if(j >= s.size()){
                    cout << "Impossible" << endl;
                    return 0;
                }
                
                if(s[j] != prev[j]){
                    adj_list[prev[j] - 'a'].pb(s[j] - 'a');
                    indegree[s[j] - 'a']++;
                    break;
                }
            }
            prev = s;
        }
    }
        
    string ans = "";
    priority_queue<int> pq;
    
    forn(i, 26) if(indegree[i] == 0) pq.push(i);
    while(!pq.empty()){
        int current = pq.top(); pq.pop();
        ans += (char)(current + 'a');
        forn(i, adj_list[current].size()){
            indegree[adj_list[current][i]]--;
            if(indegree[adj_list[current][i]] == 0){
                pq.push(adj_list[current][i]);
            }
        }
    }    
    
    if(ans.size() == 26){
        cout << ans << endl;
    }else{
        cout << "Impossible" << endl;
    }
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}



