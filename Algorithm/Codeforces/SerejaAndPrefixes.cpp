#include <bits/stdc++.h>

using namespace std;

struct node{
	long long op, index, len, val, c;
	node(){
		index = 0;
		val = len = c = 0;
	}
	bool operator< (const node& b)const{
		return index < b.index;
	}
}nodes[100000 + 10];

int n, m;

long long ans(long long p){
	node now;
	now.index = p;
	long long res = lower_bound(nodes, nodes + m, now) - nodes;
	if(nodes[res].op == 1 && nodes[res].index == p)
		return nodes[res].val;
	long long temp = nodes[res].index;
	temp -= nodes[res].c * nodes[res].len;
	p -= temp;
	p %= nodes[res].len;
	if(p == 0) p = nodes[res].len;
	return ans(p);
}

int main()
{
	ios::sync_with_stdio(false);  
	cout.tie(NULL);  
	cin >> m;
	long long count = 1;
	for(int i = 0; i < m; i++){
		long long t;
		cin >> t;
		if(t == 1){
			long long x;
			cin >> x;
			nodes[i].val = x;
			nodes[i].op = 1;
			nodes[i].index = count;
			count++;
		}else{
			long long p, c;
			cin >> p >> c;
			nodes[i].op = 2;
			nodes[i].len = p;
			nodes[i].c = c;
			count += p * c;
			nodes[i].index = count - 1;
		}
	}
	cin >>n;
	for(int i = 0; i < n; i++){
		long long p;
		cin >> p;
		cout << ans(p) << " ";
	}
	return 0;
}