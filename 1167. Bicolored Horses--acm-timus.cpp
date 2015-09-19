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
int n,k;
int arr[501];
int acc[501][2];
int dp[501][501];
long long rec(int start,int stable){
if(start==n)
	return 0;
if(stable==k)
	return INF;
if(dp[start][stable]!=-1)
	return dp[start][stable];
long long count=INF;
for(int i=start;i<=(n-k+stable);i++)
{
	int white=acc[i][0]-acc[start][0]+(1-arr[start]);
	int black=acc[i][1]-acc[start][1]+arr[start];
	int result=white*black;
	count=min(count,rec(i+1,stable+1)+result);
}
return dp[start][stable]=count;

}
int main()
{

#ifndef ONLINE_JUDGE
	freopen("input","r",stdin);
	//freopen("output.txt","w",stdout);
#endif // !1

	memset(dp,-1,sizeof(dp));
	memset(acc,0,sizeof(acc));
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
		{
		scanf("%d",&arr[i]);
		if(i==0)
			acc[i][arr[i]]++;
		else {
			acc[i][arr[i]]=acc[i-1][arr[i]]+1;
			acc[i][1-arr[i]]=acc[i-1][1-arr[i]];
		}
		}

	cout<<rec(0,0)<<endl;

		return 0;
}
