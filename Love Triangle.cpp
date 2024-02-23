#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
bool vis[N];
bool anc[N];

bool test(int t){
	int s=0;
	for(int i=0;i<t;i++){
		if(anc[i]==true){
			s++;
		}
	}
	return s>=3;
}

bool dfs(int pos,vector<int> graph[],int t){
	vis[pos]=true;
	anc[pos]=true;
	for(int i=0;i<graph[pos].size();i++){
		int x=graph[pos][i];
		if(vis[x]==true && anc[x]==true && test(t)==true){
			return true;
		}
		if(!vis[x] && dfs(x,graph,t)){
			return true;
		}
	}
	anc[pos]=false;
	return false;
}

bool isCyclic(int v,vector<int> graph[]) {
	memset(vis,false,sizeof(vis));
	memset(anc,false,sizeof(anc));
	for(int i=0;i<v;i++){
		if(!vis[i] && dfs(i,graph,v)) {
			return true;
		}
	}
	return false;
}

int main() {
	int n,u;cin>>n;
	vector<int>graph[n];
	for(int i=0;i<n;i++){
		cin>>u;
		u--;
		graph[i].push_back(u);
	}
    
    isCyclic(n,graph)==1 ? cout<<"YES"<<endl : cout<<"NO"<<endl;
	
	
	
	return 0;
}

