#include<bits/stdc++.h>
using namespace std;

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
	return (a.second < b.second);
}

int main()
{
	vector<pair<int, int>>vt;
	int n,a,b;
	cin>> n;
	for(int i=0; i<n; i++)
	{
		cin>> a >> b;
		vt.push_back(make_pair(a, b));
	}
	cout<<"---------------------"<<endl;
	for(int i=0; i<n; i++)
		cout<< vt[i].first<<" "<<vt[i].second<<endl;

	sort(vt.begin(), vt.end());
	cout<<"---------------------"<<endl;
	for(int i=0; i<n; i++)
		cout<< vt[i].first<<" "<<vt[i].second<<endl;

	sort(vt.begin(), vt.end(), sortbysec);
	cout<<"---------------------"<<endl;
	for(int i=0; i<n; i++)
		cout<< vt[i].first<<" "<<vt[i].second<<endl;

	return 0;
}
