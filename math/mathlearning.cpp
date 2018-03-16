#include<bits/stdc++.h>

int gcd(int a, int b){
	return b == 0? a : gcd(b, a%b);
}

int lcm(int a, int b){
	return a * b / gcd(a,b);
}

void swap(int& a, int& b){
	a ^= b;
	b ^= a;
	a ^= b;                      
}

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	swap(a, b);
	printf("%d, %d",a, b);
	return 0;
}