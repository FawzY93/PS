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
using namespace std;
#define INF 1000000007
#define eps 1e-6
int dp[8101][901];
int rec(int sumSquare,int sum){
	if(sumSquare>8100||sum>900)
		return INF;

	if(sumSquare<0||sum<0)
		return INF;

	if(!sumSquare&&!sum)
		return 0;

	if(dp[sumSquare][sum]!=-1)
		return dp[sumSquare][sum];

	int result=INF;
	for(int i=1;i<=9;i++)
		result=min(result,1+rec(sumSquare-i*i,sum-i));
	

	return dp[sumSquare][sum]=result;

}

void print(int sumSquare,int sum){


	if(sumSquare<0||sum<0)
		return ;

	if(!sumSquare&&!sum)
		return;

	int result=INF;
	for(int i=1;i<=9;i++)
		if(rec(sumSquare,sum)==1+rec(sumSquare-i*i,sum-i))
		{
		cout<<i;
		print(sumSquare-i*i,sum-i);
		return;
		}
	

}

 
int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif // !1

	memset(dp,-1,sizeof(dp));
	int n;
	cin>>n;
	while(n--){
		int x,y;
		cin>>x>>y;
		
		int ans=rec(y,x);
		if(ans==INF||ans>100)
			cout<<"No solution"<<endl;
		else
		{
			print(y,x);
			cout<<endl;
		}
	}


	return 0;
}
