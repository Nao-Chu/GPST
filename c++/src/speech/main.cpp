#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <deque>
#include <numeric>
#include "speaker.h"
using namespace std;

int GenSpeaker(map<int,Speaker> &mapSpeaker,vector<int> &v);
int speech_contest_draw(vector<int> &v);
int speech_contest(int i,vector<int> &v1,map<int,Speaker> &mapSpeaker,vector<int> &v2);
int speech_contest_print(int index,vector<int> &v,map<int,Speaker> &mapSpeaker);

int main()
{
	map<int,Speaker> mapSpeaker;
	vector<int>	v1;
	vector<int>	v2;
	vector<int>	v3;
	vector<int>	v4;
	// one
	GenSpeaker(mapSpeaker,v1);
	speech_contest_draw(v1);
	speech_contest(0,v1,mapSpeaker,v2);
	speech_contest_print(0,v2,mapSpeaker);

	//two 
	GenSpeaker(mapSpeaker,v3);
	speech_contest_draw(v3);
	speech_contest(1,v3,mapSpeaker,v4);
	speech_contest_print(1,v4,mapSpeaker);

	return 0;
}

int GenSpeaker(map<int,Speaker> &mapSpeaker,vector<int> &v)
{
	string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	random_shuffle(str.begin(),str.end());
	for (int i = 0; i < 24; i++)
	{
		Speaker tmp;
		tmp.m_name = "player";
		tmp.m_name = tmp.m_name + str[i];
		mapSpeaker.insert(pair<int,Speaker>(100+i,tmp));
	}

	for (int i = 0; i < 24; i++)
	{
		v.push_back(100+i);
	}
	return 0;
}

int speech_contest_draw(vector<int> &v)
{
	random_shuffle(v.begin(),v.end());
	return 0;
}

int speech_contest(int index,vector<int> &v1,map<int,Speaker> &mapSpeaker,vector<int> &v2)
{
	multimap<int,int,greater<int> > multmapGroup;
	int tmpCount = 0;
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		tmpCount++;
		deque<int> dscore;
		for (int j = 0; j < 10; j++)
		{
			int score = 50+rand()%50;
			dscore.push_back(score);
		}
		sort(dscore.begin(),dscore.end());
		dscore.pop_back();
		dscore.pop_front();
		int scoresum = accumulate(dscore.begin(),dscore.end(),0);
		int scoreavg = scoresum/dscore.size();
		mapSpeaker[*it].m_score[index] = scoreavg;
		multmapGroup.insert(pair<int,int>(scoreavg,*it));
		if (tmpCount % 6 == 0)
		{
			cout << "No." << tmpCount/6 << ":" << endl;
			for (multimap<int,int,greater<int> >::iterator mit=multmapGroup.begin();mit != multmapGroup.end();mit++)
			{
				cout << mit->second << "\t" << mapSpeaker[mit->second].m_name << "\t" << mit->first << endl;
			}
			while(multmapGroup.size() > 3)
			{
				multimap<int,int,greater<int> >::iterator it1 = multmapGroup.begin();
				v2.push_back(it1->second);
				multmapGroup.erase(it1);
			}
			multmapGroup.clear();
		}
	}
	return 0;
}

int speech_contest_print(int index,vector<int> &v,map<int,Speaker> &mapSpeaker)
{
	cout << "NO::" << index << " result" <<endl;
	int tmpCount = 0;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "\t" << mapSpeaker[*it].m_name << "\t" << mapSpeaker[*it].m_score[index] << endl; 
		if ((++tmpCount % 3) == )
		{
			cout << endl;
		}
	}
	return 0;
}
