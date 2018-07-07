/*
    heavy-light decomposition:
    decompose a tree into disjoint sets of vertices such that
    for any vertex, there are at most logn sets of vertices from it
    to the root. 
    every set is a linear structure to which segment tree or BIT or
    other DS can be easily applied.
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 123456;

namespace HLD{
    vector<int> adj[N];
    vector<int> subsize(N);
    int chainNo = 0, chainHead[N], chainPos[N], chainInd[N], chainSize[N];

    // do dfs to find subsize before calling hld;
    void hld(int cur){
        // if this chain hasn't been assigned with a head, then cur must be the head
        if(chainHead[chainNo] == -1)
            chainHead[chainNo] = cur;
        // chainInd indicates which set this node belongs to
        chainInd[cur] = chainNo;
        // chainPos means where this node is in its own set 
        chainPos[cur] = chainSize[chainNo];
        // chainSize means the number of nodes in a given set
        chainSize[chainNo]++;

        // find the special node
        int index = -1, mx = -1;
        for(int i = 0; i < adj[cur].size(); i++){
            if(subsize[adj[cur][i]] > mx){
                mx = subsize[adj[cur][i]];
                index = i;
            }
        }

        // every non-leaf node has a special node, and continue building from cur
        if(index >= 0)
            hld(adj[cur][i]);

        // for all non-special nodes, start a new chain set.
        for(int i = 0; i < adj[cur].size(); i++){
            if(i != index){
                chainNo++;
                hld(adj[cur][i]);
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}