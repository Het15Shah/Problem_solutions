#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
bool comp(pair<ll,ll> a,pair<ll,ll> b){
 return a.second<b.second;
}
int main(){
ll n,ans=1;
cin>>n;
pair<ll,ll> p[n];
for(ll i=0;i<n;i++)
cin>>p[i].first>>p[i].second;
sort(p,p+n,comp);
int c=p[0].second;
for(ll i=1;i<n;i++){
	if(p[i].first>c){
		ans++;
		c=p[i].second;
	}
}
cout<<ans<<endl;
}