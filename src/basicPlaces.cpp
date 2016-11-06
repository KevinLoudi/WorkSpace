#include "basicPlaces.h"

void City::show() const
{
	cout<<"The city "<<_cityName<<" have "<<cal_inhabitants()<<" people "
	<<" and holded by"<<_cityHolder<<endl;
}

int City::cal_inhabitants() const
{
	int sum_of_inhabitants=0;
	for(int i=0;i<_area;++i)
	{
		sum_of_inhabitants+=_places[i].getPeople();
	}
	return sum_of_inhabitants;
}
