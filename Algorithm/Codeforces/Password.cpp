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
const int N = (int) 1e6 + 100;

/*
    prefix function would tell all the lengths of equal prefix and suffix
    we just need to find all such length by retrieving the pi[n - 1] and pi[pi[n - 1] - 1]
    and do kmp on key + "#" + orignal string stripped of the first and last char
    until we find at least one occurence

    better solution: simply find all pi[n - 1], pi[pi[n - 1] - 1] and check if there is another
    pi[k] such that pi[k] = current pi[]
*/

string s;
int n, pi1[N], pi2[N];

void kmp(int which, string& s){
    int n = s.size();
    pi1[0] = 0;
    for(int i = 1; i < n; i++){
        int j = pi1[i - 1];
        while(j > 0 && s[j] != s[i]){
            j = pi1[j - 1];
        }
        if(s[j] == s[i]) j++;
        pi1[i] = j;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    
    cin >> s;
    n = s.size();

    kmp(1, s);
    string s2;
    for(int i = 1; i < n - 1; i++) s2 += s[i];

    int k = pi1[n - 1];
    while(k > 0){       
        string key = s.substr(0, k); 
        string ss = key + '#' + s2;

        pi2[0] = 0;
        for(int i = 1; i < (k + 1 + n - 2); i++){
            int j = pi2[i - 1];
            while(j > 0 && ss[j] != ss[i]){
                j = pi2[j - 1];
            }
            if(ss[j] == ss[i]) j++;
            
            pi2[i] = j;
            
            if(i > k && pi2[i] == k){
                cout << key << endl;
                return 0;
            }
        }

        k = pi1[k - 1];
    }

    cout << "Just a legend" << endl;
    return 0;
}