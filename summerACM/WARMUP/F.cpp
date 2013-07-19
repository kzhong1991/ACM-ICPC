#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
#define eps 1e-8

struct Point{
	double x, y;
	bool operator<(const Point &p) const{
		return (fabs(p.x-x)<eps)?((fabs(p.y-y)<eps)?false:p.y<y):p.x<x;
	}
	bool operator==(const Point &p) const{
		return fabs(p.x-x)<eps && fabs(p.y-y)<eps;
	}
	bool operator!=(const Point &p) const{
		return fabs(p.x-x)>eps || fabs(p.y-y)>eps;
	}
};

Point p[2000010];

int main()
{
	int n, k;
	set<Point> s;
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; i++) scanf("%lf %lf", &p[i].x, &p[i].y);
	if(k>=n){printf("-1\n"); return 0;}
	sort(p, p+n);

	int km, i, pre;
	Point c;
	for(int l=0; l<=k ; l++)
		for(int r=0; r<=k; r++) {
			if(r+l>k)break;
			km=0;
			i=1;
			pre = n-1-r-1;
			c.x = (p[l].x+p[n-1-r].x)/2;
			c.y = (p[l].y+p[n-1-r].y)/2;
			while(l+i <= pre) {	
				Point tmp = {2*c.x-p[l+i].x, 2*c.y-p[l+i].y};
				if(tmp == p[pre]) {i++; pre--; continue;}
				else {
					int f = 0;
					int km2 = 0;
					int j;
					for(j = pre; j >= pre-k && j >= l+i; j--)
						if(tmp != p[j]) km2++;
						else { f = 1; break;}
						if (f == 0) km++; 
						else { km += km2; pre = j-1;}
						i++;
				}
				if(r+l+km > k) break;
			}
			if (r+l+km<=k) s.insert(c);
		}
	if(s.empty()) { printf("0\n"); return 0;}
	printf("%d\n", s.size());
	set<Point>::iterator it = s.begin();
	for(; it!=s.end(); it++)
		printf("%lf %lf\n", (*it).x, (*it).y);
	return 0;
} 
