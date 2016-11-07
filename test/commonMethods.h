#ifndef COMMONMETHODS_H
#define COMMONMETHODS_H

#include<vector>
using namespace std;

class Models
{
	private:

	protected:
		vector<int> seq;
	public:
		Models();
		virtual bool gen_seq(int beg,int len)=0;
		virtual ~Models();
};

class PopulationGrowthModel: public Models
{
	private:

	protected:
		//vector<int> population_seq;
	public:
		virtual bool gen_seq(int beg,int len);
};


#endif
