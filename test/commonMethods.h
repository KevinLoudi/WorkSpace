#ifndef COMMONMETHODS_H
#define COMMONMETHODS_H

#include <vector>
#include"basicPlaces.h"
#include <cstdlib>
#include <ctime>
using namespace std;

class Models
{
	private:

	protected:
		vector<int> seq;
	public:
		Models();
		virtual bool gen_seq(int len)=0;
		virtual ~Models();
};

class PopulationGrowthModel: public Models
{
	private:

	protected:
		//vector<int> population_seq;
	public:
		virtual bool gen_seq(int len);
		City _acity; 
};

bool PopulationGrowthModel::gen_seq(int len)
{
	//load the current Population of the city
	if (seq.size()==0)
	{
		seq.push_back(_acity.GetPopulation())
	}

	for (int i = 0; i < len; ++i)
	{
		srand(time(0));
		//random bitrh
		int random_birth=seq[i-1]*(rand())%1;
		//random death
		int random_death=seq[i-1]*(rand())%1
		//combine random
		seq.push_back(seq[i-1]+random_birth-random_death);
	}
	return true;
}
#endif
