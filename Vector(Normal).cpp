 #include<bits/stdc++.h>
 using namespace std;

 int main()
 {
 	vector<int> vt;

 	vt.push_back(1);
 	vt.push_back(2);

 	for(int i=0; i<vt.size(); i++)
		cout<< vt[i]<<endl;

	vector<int>::iterator it;
	for(it=vt.begin(); it!=vt.end(); it++)
	    cout<<*it<<endl;


 	return 0;
 }
