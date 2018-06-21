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

vector<int> cal_shifts(string& s){
    int n = s.size();
    const int alphabet = 256;
    
    vector<int> p(n), c(n), cnt(alphabet);
    for(int i = 0; i < n; i++){
        cnt[s[i]]++;
    }
    for(int i = 1; i < alphabet; i++){
        cnt[i] += cnt[i - 1];
    }
    for(int i = 0; i < n; i++){
        p[--cnt[s[i]]] = i;
    }
    c[p[0]] = 0;
    int classes = 1;
    for(int i = 1; i < n; i++){
        if(s[p[i]] != s[p[i - 1]]) classes++;
        c[p[i]] = classes - 1;
    }
    
    vector<int> pn(n), cn(n);
    for(int h = 0; (1 << h) < n; h++){
        for(int i = 0; i < n; i++){
            pn[i] = p[i] - (1 << h);
            if(pn[i] < 0) pn[i] += n;
        }
                
        fill(cnt.begin(), cnt.end(), 0);
        for(int i = 0; i < n; i++){
            cnt[c[pn[i]]]++;
        }
        for(int i = 1; i < classes; i++){
            cnt[i] += cnt[i - 1];
        }
        for(int i = n - 1; i >= 0; i--){
            p[--cnt[c[pn[i]]]] = pn[i];
        }
        classes = 1;
        cn[p[0]] = 0;
        for(int i = 1; i < n; i++){
            pair<int, int> cur = make_pair(c[p[i]], c[(p[i] + (1 << h)) % n]);
            pair<int, int> prev = make_pair(c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]);
            if(cur != prev) classes++;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    
    return p;
}

vector<int> suffix_array_construct(string& s){
    string in = s + '&';
    vector<int> res = cal_shifts(in);
    res.erase(res.begin());
    return res;    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

    string s = "aaba";// "dabbb";
    vector<int> res = suffix_array_construct(s);
    for(auto i : res) cout << i << " ";   

    return 0;
}