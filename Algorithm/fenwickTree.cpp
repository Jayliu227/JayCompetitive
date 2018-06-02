#include<bits/stdc++.h>

using namespace std;

int LSOne(int k){
    return (k & -k);
}

class fenwickTree{
public:
    fenwickTree(int N){
        tree.assign(N+1, 0);        
    }

    // change kth element by n
    void adjust(int k, int n){
        for(; k < (int) tree.size(); k += LSOne(k)){
            tree[k] += n;   
        }
    }

    // range sum query
    int rsq(int i){
        int sum = 0;
        for(; i; i -= LSOne(i)){
            sum += tree[i];
        }
        return sum;
    }

    int rsq(int i, int j){
        return rsq(j) - (i == 0 ? 0 : rsq(i - 1));
    }
private:
    vector<int> tree;
};

int main(){              
    int f[] = {2,4,5,5,6,6,6,7,7,8,9};

    fenwickTree ft(10);

    for(int i = 0; i < 11; i++) ft.adjust(f[i], 1);
    
    printf("%d\n", ft.rsq(1,1));
    printf("%d\n", ft.rsq(1,6));

    return 0;
}