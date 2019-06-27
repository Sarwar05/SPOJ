#include<bits/stdc++.h>
using namespace std;
struct Point
{
    int x;
    int y;
    int id;
    Point(int _x, int _y, int _id)
    {
        x = _x;
        y = _y;
        id = _id;
    }
};
bool compX(const Point& a, const Point& b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
bool compY(const Point& a, const Point& b)
{
    if(a.y==b.y)
        return a.x<b.x;
    return a.y<b.y;
}
vector<Point> point;
double minDist;
pair<int, int> best;
double dist(const Point& a, const Point& b)
{
    return sqrt(pow(a.x-b.x,2.0) + pow(a.y-b.y,2.0));
}
void Update(const Point& a, const Point& b, const Point& c)
{
    double d = 0;
    d = dist(a,b) + dist(a,c) + dist(b,c);
    if(d<minDist) minDist = d;
}
void solve(int l, int r)
{
    if(r-l+1 <=5){
        for(int i=l; i<=r; i++){
            for(int j = i+1; j<=r; j++)
                for(int k = j+1; k<=r; k++)
                Update(point[i], point[j], point[k]);
        }
        return;
    }
    int m = (l+r)/2;
    solve(l,m);
    solve(m,r);
    vector<Point> tem;
    for(int i=l; i<=r; i++){
        if(abs(point[i].x-point[m].x)<minDist){
            tem.push_back(point[i]);
        }
    }
    sort(tem.begin(), tem.end(),compY);
    for(int i=0; i<tem.size(); i++){
        for(int j=i+1; j<tem.size(); j++){
            if(tem[j].y - tem[i].y >= minDist) break;
            for(int k=j+1; k<tem.size(); k++){
                if(tem[k].y - tem[j].y >= minDist || tem[k].y - tem[i].y >= minDist) break;
                Update(tem[i], tem[j],tem[k]);
            }
        }
    }
}
int main()
{
    int n,x,y;
    while(scanf("%d",&n)){
        if(n==-1) break;
        point.clear();
        for(int i=0; i<n; i++){
            scanf("%d%d",&x,&y);
            point.push_back(Point(x,y,i));
        }
        sort(point.begin(), point.end(),compX);
        minDist = 1e20;
        solve(0,n-1);
        cout<<fixed<<setprecision(3)<<minDist<<endl;
    }
}
