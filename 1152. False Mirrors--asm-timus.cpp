#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <string.h>
#include <cmath>
#include<iomanip>
#include <cstring>
#include <ctype.h>
#include <stdio.h>
#include<sstream>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<list>
#include<set>
#include <stdio.h>
#include <stdlib.h>
#include<bitset>
#include<functional>
#include<bits/stdc++.h>
using namespace std;
#define INF 999999999
#define eps 1e-6
int n,inp[25];
int dp[1050000];
int rec(int bitMask,int sum){
	if(bitMask==((1<<n)-1))return 0;
	if(dp[bitMask]!=-1)return dp[bitMask];
	int minDmg=INF;
	for(int i=0;i<n;i++){
		int t1,t2,t0;
		t0=(1<<(i)%n);
		t1=(1<<(i+1)%n);
		t2=(1<<(i+2)%n);
		if(!(bitMask&t0)||!(bitMask&t1)||!(bitMask&t2)){
			int temp=bitMask,temp2;
			temp|=(t0|t1|t2);
			temp2=sum;
			if(!(bitMask&t0))temp2-=inp[i];
			if(!(bitMask&t1))temp2-=inp[(i+1)%n];
			if(!(bitMask&t2))temp2-=inp[(i+2)%n];
			minDmg=min(minDmg, rec(temp,temp2)+temp2);

		}


	}
	return dp[bitMask]=minDmg;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input","r",stdin);
	//freopen("output.txt","w",stdout);
#endif // !1

	memset(dp,-1,sizeof(dp));

	int sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&inp[i]);

		sum+=inp[i];
	}
	printf("%d\n",rec(0,sum));
	return 0;
}
