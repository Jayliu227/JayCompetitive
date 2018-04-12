#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define forn(i,n) for(int i = 0; i < (int)n; i++)
#define for1(i,n) for(int i = 1; i < (int)n; i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define ALL(x) (x).begin(), (x).end()
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

/*
    next time, if check two bounds are frequent, we can simply add dumy slots before and after
    the array, so no need to check two sides
*/

const int INF = (int) 1e9;
const int MODULO = (int) 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    string s; int n = nxt(); int m = nxt(); cin >> s;
    int segment = 0, length = 0;
    for(int i = 0; i < n; i++){
        length += s[i] == '.';
        segment += s[i] == '.' && ((i + 1 == n) || (s[i + 1] != '.'));
    }        

    LOG(length); LOG(segment);
    
    int index; char c;
    while(m--){
        cin >> index >> c;        
        index--;
        if(s[index] == '.' && c == '.')
            cout << (length - segment) << endl;
        else if(s[index] != '.' && c != '.')
            cout << (length - segment) << endl;
        else{
            if(c == '.'){
                segment++;
                length++;
                if(index + 1 < n && s[index + 1] == '.'){
                    segment--;
                }
                if(index - 1 >= 0 && s[index - 1] == '.'){
                    segment--;
                }
            }else{
                length--;
                if(index + 1 < n && index - 1 >= 0){
                    if(s[index + 1] == '.' && s[index - 1] == '.'){
                        segment++;
                    }
                }
                if((index - 1 < 0 || s[index - 1] != '.') && (index + 1 >= n || s[index + 1] != '.')){
                    segment--;
                }
            }
            s[index] = c;            
            cout << (length - segment) << endl;
        }                                        
    }        
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}