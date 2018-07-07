#include <bits/stdc++.h>
using namespace std;

vector<int> helper(const string& s){
    int n = s.size();
    const int A = 256;

    vector<int> p(n), c(n), cnt(A);
    for(int i = 0; i < n; i++)
        cnt[s[i]]++;
    for(int i = 1; i < A; i++)
        cnt[i] += cnt[i - 1];
    for(int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for(int i = 1; i < n; i++){
        if(s[p[i]] != s[p[i - 1]])
            classes++;
        c[p[i]] = classes - 1;
    }

    vector<int> pn(n), cn(n);
    for(int h = 0; (1 << h) < n; h++){
        for(int i = 0; i < n; i++){
            pn[i] = p[i] - (1 << h);
            if(pn[i] < 0) 
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.end(), 0);
        for(int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for(int i = 1; i < classes; i++)
            cnt[i] += cnt[i - 1];
        for(int i = n - 1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];

        cn[p[0]] = 0;
        classes = 1;
        for(int i = 1; i < n; i++){
            pair<int, int> prev = make_pair(c[p[i - 1]],c[(p[i - 1] + (1 << h)) % n]);
            pair<int, int> cur = make_pair(c[p[i]], c[(p[i] + (1 << h)) % n]);
            if(cur != prev)
                classes++;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> getSA(const string& s){
    string in = s + '$';
    vector<int> res = helper(in);
    res.erase(res.begin());
    return res;
}

vector<int> getLCP(const string& s, vector<int>& sa){
    int n = s.size();
    vector<int> rank(n);
    for(int i = 0; i < n; i++){
        rank[sa[i]] = i;
    }
    int k = 0;
    vector<int> lcp(n, 0);
    for(int i = 0; i < n; i++){
        if(rank[i] == n - 1){
            k = 0;
            continue;
        }
        int j = sa[rank[i] + 1];
        while(i + k < n && j + k < n && s[i + k] == s[j + k])
            k++;
        lcp[rank[i]] = k;
        if(k) k--;
    }
    return lcp;
}

int main(){
    string s;
    cin >> s;
    vector<int> sa = getSA(s);
    vector<int> lcp = getLCP(s, sa);
    int n = s.size();
    for(int i = 0; i < n; i++){
        string cur = s.substr(sa[i], n - sa[i]);
        cout << "sa: " << sa[i] << " lcp: " << lcp[i] << ' ' << cur << endl;
    }
    
    return 0;
}