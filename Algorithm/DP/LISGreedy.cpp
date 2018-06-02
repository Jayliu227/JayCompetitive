#include<bits/stdc++.h>

using namespace std;

/*
  idea is that l[i] stores the smallest ending value in a LIS of length i;
    the size of the l would be the longest LIS
    everytime we just find the position whose value is greater or equal to the current
    if it is not in the range, we simply add one.
*/

int main(){
    int N;
    cin >> N;
    int a[N];
    int l[N];
    memset(l, 0, sizeof(l));
    for(int i = 0; i < N; i++) cin >> a[i];

    int size = 0;
    for(int i = 0; i < N; i++){
        int pos = lower_bound(l, l + size, a[i]) - l;
        l[pos] = a[i];
        if(pos + 1 > size){
            size = pos + 1;
        }
    }

    for(int i = 0; i < size; i++) cout << l[i] << " ";

    cout << "\n" << size <<"\n";

}