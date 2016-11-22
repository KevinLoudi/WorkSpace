#include "basicPlace.h"


UINT Place::_itemNum=0;
UINT City::_cityNum=0;

inline PlaceInfo* Place::getInfo() const
{
	return _placeInfo;
}

inline bool Place::updateInfo(PlaceInfo & P)
{
	*(this->_placeInfo)=P;
	return true;
}

ostream & Place::getInfo(ostream & os) const
{
	os<<"This is a place with an area of "<<_placeInfo->_Area<<endl;
	return os;
}

ostream & City::getInfo(ostream & os) const
{
	os<<_cityInfo->_CityName<<" is holded by "<<
	_cityInfo->_CityHolder<<" and have a population of "<<
	getPopulation()<<endl;
	return os; //actually return is not needed
}

void City::investMoney(const UINT cash)
{
	srand((UINT)time(0));
	int population_add=(rand()+cash)%10;
	//investment leads to some kind of population growth
	_cityInfo->_PopulationDensity+=(population_add/_cityInfo->_Area);

}

bool City::alterHolder(const string & newHolder)
{
	_cityInfo->_CityHolder=newHolder;
	return true;
}

UINT City::getPopulation() const
{
	return _cityInfo->_Area*_cityInfo->_PopulationDensity;
}

PlaceInfo* City::getInfo() const
{
	return _cityInfo;
}

bool City::updateInfo(CityInfo &  C)
{
	*(this->_cityInfo)=C;
	return true;
}
