#ifndef PLACE_H
#define PLACE_H

#include<string>
using namespace std;

class Place
{
	public:
		Place();
		virtual double* getPosition() const
		{return new double[2]{_latitude,_longitude};}
		virtual int getPeople() const {return _inhabitants_num;}
		virtual bool update_products(string &new_pro)=0;
		virtual bool move_people(int _in_out_people)=0;
		//Place(double lat,double lon,double high,int sc,string & pro, int num):
		virtual ~Place();
	protected:
		virtual void inhabitants_growth_bytime(int timepassed)=0;
	private:
		double _latitude;
		double _longitude; 
		double _high;
		int _scope;
		string _products;
		int _inhabitants_num;
};

#endif
