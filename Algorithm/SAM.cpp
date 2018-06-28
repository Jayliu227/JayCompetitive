#include<bits/stdc++.h>
using namespace std;

struct state {
    // len is the length of longest suffix that belongs to this state
    // link is suffix link
    int len, link;
    // next represents transitions from this state
    map<char,int>next;
};
  
const int MAXLEN = 100000;
state st[MAXLEN*2];
int sz, last;
  
void sa_init() {
    sz = last = 0;
    st[0].len = 0;
    st[0].link = -1;
    ++sz;
}
  
void sa_extend (char c) {
    // create new state
    int cur = sz++;
    // update len field
    st[cur].len = st[last].len + 1;
    // iterator, set to LAST at first
    int p;
    // keep going via suffix link and set its transition via c to current state 
    // until:
    //      1. we arrive at initial state
    //      2. we've found a state which already has a transition with character c
    for (p = last; p != -1 && !st[p].next.count(c); p=st[p].link)
        st[p].next[c] = cur;
    // if we've ended up arriving at initial state
    // we just set current's suffix link to 0 (initial state)
    if (p == -1)
        st[cur].link = 0;
    else {
    // else we have found some state that has already existed a transition via c
        int q = st[p].next[c];
        // now we need to consider two conditions
        // if q is direct descendent of p
        if (st[p].len + 1 == st[q].len)
            st[cur].link = q;
        else {
            int clone = sz++;
            // make the clone state's len be p's len + 1
            st[clone].len = st[p].len + 1;
            // clone process
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            // make all of p and all states that are suffix linked by p
            // transition to clone via c
            // they originally transition to q 
            for (; p != -1 && st[p].next[c] == q; p = st[p].link)
                st[p].next[c] = clone;
            // then set both q and cur's suffix link to clone
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

int main(){

    return 0;
}