#include<bits/stdc++.h>
using namespace std;
#define mx 200005
int arr[mx], strt[mx], cnt[mx], tree[mx*4];
void build(int pos, int b, int e)
{
	if(b>e) return;
	if(b==e){
		tree[pos] = cnt[b];
		return;
	}
	int m = (b+e)/2;
	int l = pos*2;
	int r = l+1;
	build(l,b,m);
	build(r, m+1, e);
	tree[pos] = max(tree[l], tree[r]);
}
int query(int pos, int b, int e, int i, int j)
{
	if(b>e || b>j || e<i) return 0;
	if(b>=i && e<=j) return tree[pos];
	int m = (b+e)/2;
	int l = pos*2;
	int r = l+1;
	return max(query(l,b,m, i, j), query(r, m+1, e, i, j));
}
int main()
{
	int n,q,l,r,a;
	while(scanf("%d",&n), n){
		memset(cnt, 0, sizeof cnt);
		scanf("%d",&q);
		for(int i=1; i<=n; i++){
			scanf("%d",&a);
			a+=100001;
			arr[i]= a;
			if(cnt[a]==0)
				strt[a] = i;
			cnt[a]++;
		}
		build(1,1,mx-2);
		while(q--){
			scanf("%d%d",&l,&r);
			int ans = 0;
			if(arr[l] == arr[r])
				ans = r-l+1;
			else{
				a = arr[l];
				int x = cnt[ a ] - ( l - strt[a] );
				l = strt[a] + cnt[a];
				a = arr[r];
				int y = r - strt[a] + 1;
				r = strt[a] - 1;
				x = max(x,y);
				cout<<l<<" --- "<<r<<endl;
				ans = max(x, query(1,1,mx-2,arr[l],arr[r]));
			}
			printf("%d\n", ans);
		}
	}
}
