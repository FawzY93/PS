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
#define MAX 100010
#define eps 1e-6
pair<int,int> acc[MAX];
vector<pair<int,int> >inp;
// A utility function to get minimum of two integers
int min(int a, int b) {
	return (a < b) ? a : b;
}

// Returns the minimum number of cuts needed to partition a string
// such that every part is a palindrome


int main() {

#ifndef ONLINE_JUDGE
	freopen("input", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif // !1
	int M,x,y;
	scanf("%d",&M);
	memset(acc,0,sizeof(acc));
	while(scanf("%d %d",&x,&y)!=EOF&&(x||y)){
		inp.push_back(make_pair(x,y));
		if(x<0)x=0;
		if(y<0)y=0;
		if(x<=M &&y){
			if(acc[x].first<y){
				acc[x].first=y;
				acc[x].second=inp.size()-1;

			}
		}
	}
	bool noSol=false;
	for(int i=1;i<=M&&!noSol;i++){
		if(acc[i-1].first<i){
			noSol=true;
			continue;
		}
		if(acc[i-1].first>acc[i].first){

			acc[i].first=acc[i-1].first;
			acc[i].second=acc[i-1].second;
		}
	}
	if(!noSol){
		pair<int,int>j=acc[0];
		vector<pair<int ,int > >ans;
		ans.push_back(inp[j.second]);
		while(j.first<M){
			j=acc[j.first];
			ans.push_back(inp[j.second]);
		}
		printf("%d\n",ans.size());
		for(int i;i<ans.size();i++){
			printf("%d %d\n",ans[i].first,ans[i].second);

		}
	}
	else printf("No solution\n");
	return 0;
}
