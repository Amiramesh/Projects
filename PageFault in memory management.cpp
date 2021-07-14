//given memory size e.g(number of pages it can hold;
//string representing pages to be reffered;
//find number of pages fault;
#include<bits/stdc++.h>
using namespace std;
int countfault(string pages,int size)
{
	
	queue<char>q;
	int fault=0;
	  map<char,int>mp;
	int i=0;
	mp[pages[0]]++;
	fault++;
	q.push(pages[0]);

	for(i=1;i<pages.length();i++)
	{
		if(q.size()<size)
		{
			if(mp.count(pages[i])<=0)
			{
			q.push(pages[i]);
			mp[pages[i]]++;
			fault++;
		   }
		}
		else if(q.size()==size)
		{
			if(mp.count(pages[i])<=0)
			{
				char c=q.front();
				mp.erase(c);
			q.pop();
			q.push(pages[i]);
			mp[pages[i]]++;
			fault++;
			}	
		}
		/*else if(mp.count(pages[i])>0)
		{
			
		}
		q.push(pages[i]);
		fault++;
		mp[pages[i]]++;*/
	}
	/*for(;i<pages.length();i++)
	{
		if(mp.count(pages[i])>0)
		{
			1;
		}
		else
		{
			fault++;
			char c=q.front();
			mp[c]--;
			q.pop();
			q.push(pages[i]);
			mp[pages[i]]++;
		}
	}*/
	return fault;
}
int main()
{
	int size;
	cin>>size;
	string pages;
	cin>>pages;
	cout<<countfault(pages,size);
	
}
