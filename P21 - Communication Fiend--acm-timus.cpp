//============================================================================
// Name        : hello.cpp
// Author      : FawzY
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii; // In this chapter, we will frequently use these
typedef pair<int, char> ic;
typedef pair<double, double> ff;
typedef pair<double, int> fi;
typedef vector<ii> vii; // three data type shortcuts. They may look cryptic
typedef vector<ic> vic;
typedef vector<int> vi; // but shortcuts are useful in competitive programming
typedef long long LL;
const LL INF = 1e10 + 7;
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define DFS_BLACK 1
#define DFS_WHITE 0
int n,m;
int lic_id(int x) { return ( x == 1 ? 0 : 2*x-3 ); }
int pir_id(int x) { return ( x == 1 ? 0 : 2*x-2 ); }

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	int x,y,t;
	string type;
	LL ans;
	vector<LL>dist;
    vector<vii> adj; // per edge: (destination, weight)
    char s[20];
    
    while ( ~scanf("%d %d", &n, &m) )
    {
        adj.assign(pir_id(n)+1, vii());
        fup(i,0,m)
        {
            scanf("%d %d %d %s", &x, &y, &t, s);
            if ( s[0] == 'L' ) // Licensed
            {
                adj[lic_id(x)].push_back(ii(lic_id(y),t));
            }
            else if ( s[0] == 'P' ) // Pirated
            {
                adj[lic_id(x)].push_back(ii(pir_id(y),t));
                adj[pir_id(x)].push_back(ii(pir_id(y),t));
            }
            else // Cracked
            {
                adj[lic_id(x)].push_back(ii(lic_id(y),t));
                adj[pir_id(x)].push_back(ii(pir_id(y),t));
            }
        }
		dist.assign(pir_id(n)+1, INF), dist[0] = 0;
		fup(u,0,(int)(pir_id(n)+1))
			fup(i,0,adj[u].size()){
				int v=adj[u][i].first,w=adj[u][i].second;
				dist[v]=min(dist[v],dist[u]+w);
		}
		ans = min(dist[lic_id(n)], dist[pir_id(n)]);
        if ( ans == INF ) puts("Offline");
        else printf("Online\n%I64d\n", ans);
		

	}
	
	return 0;
}

