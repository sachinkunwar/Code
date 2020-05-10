/*
There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either of the given stairs at a time. Count the number of ways, the person can reach the top.
*/
#include <iostream>
#include<vector>
#include<algorithm>
#define ll long long int
#define mod 1000000007
using namespace std;
ll fun(ll a[],vector<ll> &b, ll n)
{
    // Recursive approach 
    // if(n==0){
    //     // return 1;
    //     // if(a[0]==-1)
    //     return 1;
    // }
    // if(n<0)return 0;
    // for(ll i=0;i<b.size() && n-b[i]>=0;i++){
    //     if(n-b[i]>=0 && a[n-b[i]]==0){
    //       a[n]+=fun(a,b,n-b[i]);
    //       a[n]%=mod;
    //     }
    //     else{
    //         a[n]+=a[n-b[i]];
    //         a[n]%=mod;
    //     }
    // }
    // return a[n];

    //Iterative approach
    a[b[0]]=1;
    a[0]=1;
    for(ll i=b[0]+1;i<=n;i++)
    {
        for(ll j=0;j<b.size();j++)
        {
            if(i-b[j]>=0)
            {
                a[i]=(a[i]+a[i-b[j]])%mod;
            }
        }
    }
    return a[n]%mod;
}
int main() {
	//code
	ll t;
	cin>>t;
	while(t--){
	    ll n,s,st,r;
	    cin>>n; // max no. of stairs to climb
	    vector<ll> steps;
        cin>>s; // no. of stairs, among them he can climb one at a time
        for(ll i=0;i<s;i++){
            cin>>st; // steps
            steps.push_back(st);
        }
	    ll a[n+1]={0};
	   // fun(a,steps,n);
	   sort(steps.begin(),steps.end());
	    cout<<fun(a,steps,n)<<'\n';
	}
	return 0;
}