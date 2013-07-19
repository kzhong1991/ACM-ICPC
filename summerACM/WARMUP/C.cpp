#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector> 
#include <map>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

struct cmp
{
	bool operator()(pii a, pii b)
	{
		return a.second < b.second;
	}
};

int main()
{
	int r[100010];
	vector< vector<int> > vec;
	priority_queue< pii, vector<pii>, cmp> pq;
	map<int, int> m;
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &r[i]);
	sort(r, r+n);
	for(int i = 0; i < n; i++) m[r[i]]++;
	map<int, int>::iterator it = m.begin();
	for(; it!=m.end(); it++) 
		pq.push(make_pair((*it).first, (*it).second));
	
	while(pq.size() > 2)
	{
		pii b1 = pq.top();
		pq.pop();
		pii b2 = pq.top();
		pq.pop();
		pii b3 = pq.top();
		pq.pop();
		if(b1.second-1) pq.push(make_pair(b1.first, b1.second-1));
		if(b2.second-1) pq.push(make_pair(b2.first, b2.second-1));
		if(b3.second-1) pq.push(make_pair(b3.first, b3.second-1));
		vector<int> v;
		v.push_back(b1.first);
		v.push_back(b2.first);
		v.push_back(b3.first);
		sort(v.begin(), v.end());
		vec.push_back(v);
	}
	printf("%d\n", vec.size()); 
	vector< vector<int> >::iterator vit = vec.begin();
	for(; vit!=vec.end(); vit++)
	{
		printf("%d %d %d\n", (*vit)[2], (*vit)[1], (*vit)[0]);
	}
}
