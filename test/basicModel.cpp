#include "basicModel.h"

bool FileIO::readTextFile(City* cities,UINT len)
{
  //be care of the default file folder
  ifstream infile(CITYLIST);
  if(infile.fail())
  {
      cout<<"Invalid input file..."<<endl;
    return false;
  }

  string cityname="Handan",cityholder="Zhao",products="Steel";
  int defencelev=8;
  double lat=112,lon=35,high=16;
  UINT pop_den=200, area=1900;
  UINT i=0;

  while((infile>>cityname>>cityholder>>products>>lat>>lon>>defencelev>>pop_den>>area)&&(i<len))
   {
    cout<<cityname<<" "<<cityholder<<" "<<products<<" "
    <<lat<<" "<<lon<<" "<<defencelev<<" "<<pop_den<<" "
    <<area<<endl;
    cities[i]._cityInfo->_CityName=cityname; cities[i]._cityInfo->_CityHolder=cityholder; 
    cities[i]._cityInfo->_ProductType=products; cities[i]._cityInfo->_Latitude=lat; 
    cities[i]._cityInfo->_Longitude=lon; cities[i]._cityInfo->_High=high; 
    cities[i]._cityInfo->_DenfenceLevel=defencelev;
    cities[i]._cityInfo->_Area=area; cities[i]._cityInfo->_PopulationDensity=pop_den;
    //cities[i].GetInfo();
    i++;
   }
  
  infile.close();
  return true;
}

inline void FileIO::resetFilename(const string & newname)
{
	_Filename=newname;
}

bool FileIO::saveBinaryFile(City* c,UINT len) const
{
	cout<<"Please input city information.\n";
	string state="c";
	int ix=0;

	while(state=="c"&&ix<len)
	{
		cout<<"Please input city name and holder and products...\n";
		cin>>c[ix]._cityInfo->_CityName;
		cin>>c[ix]._cityInfo->_CityHolder;
		cin>>c[ix]._cityInfo->_ProductType;
		cout<<"Please input city lat and lon and high...\n";
		cin>>c[ix]._cityInfo->_Latitude;
		cin>>c[ix]._cityInfo->_Longitude;
		cin>>c[ix]._cityInfo->_High;
		cout<<"Please input city denfencelevel and pop_den and area...\n";
		cin>>c[ix]._cityInfo->_DenfenceLevel;
		cin>>c[ix]._cityInfo->_PopulationDensity;
		cin>>c[ix]._cityInfo->_Area;

		cout<<"Continue input (Yes=c/No=q)..."<<endl; 
		cin>>state;

		//output data as file
		string tmpfilename=c[ix]._cityInfo->_CityName+".dat";
		ofstream output_file(tmpfilename,ios::binary);
		if (output_file.fail())
		{
			cerr<<"cannot save console input data!"<<endl;
		}
		output_file.write((char*)&c[ix],sizeof(c[ix]));
		output_file.close();

		ix++;
	}
  return true;
}

bool FileIO::readBinaryFile(string* filename,City* c,UINT len)
{
  string state="c";
  int ix=0;
  while((ix<len)&&(state=="c"))
  {
  	string tmpname=filename[ix]+".dat";
  	ifstream input_file(tmpname);
  	if (input_file.fail())
  	{
  		cerr<<"cannot read city info file!"<<endl;
  	}
  	input_file.read((char*)&c[ix],sizeof(c[ix]));
  	input_file.close();
  	cout<<c[ix].getInfo(cout);
  	ix++;
  }
  return true;
}


void Rank::rankbyValue()
{
	vector<PAIR_STRING_UINT> scoreVector;
  for(MAP_STRING_UINT::const_iterator it=_rank.begin();it!=_rank.end();it++)
  {
    scoreVector.push_back(*it);
  }

  sort(scoreVector.begin(),scoreVector.end(),compareValue());

  for(auto x:scoreVector)
  {
    cout<<x.first<<" : "<<x.second<<endl;
  }

  return;
}

bool Rank::addCityname(const string & cityname)
{
	if(isexist(cityname))
  {
    cerr<<"the input city is already in the set"<<endl;
    return false;
  }

  UINT pop_num=0;
  cout<<"Please input the population density of the above city "<<cityname<<endl;
  cin>>pop_num;
  _citynames.insert(cityname);
  _rank[cityname]=pop_num;
  return true;
}

bool Rank::removeCityname(const string & cityname)
{
  if(!isexist(cityname))
  {
    cerr<<"the input city is not found"<<endl;
    return false;
  }

  _citynames.erase(cityname);
  _rank.erase(cityname);
  return true;
}

bool Rank::isexist(const string & cityname)
{
  //find in the name set
  SET_STRING::const_iterator ie=_citynames.find(cityname);
  
  //find in _rand map
  MAP_STRING_UINT::const_iterator ir=_rank.find(cityname);
  
  //check if found
  if(ie!=_citynames.end()&&ir!=_rank.end())
  {
    //cout<<"Element "<<*ie<<" found."<<endl;
    return true;
  }
  else
  {
  	//if the element has not been found, ie will point to one-past-the-end
  	//thus access *ie will cause memory valiate, run-time error
    //cout<<"Element "<<cityname<<" not found."<<endl;
    return false;
  }
}

void Rank::printRank()
{
  printAssContainer(_rank);
}

void Rank::printCityname()
{
	//output citynames by order
	printContents(_citynames);
}

template<typename Container>
void Rank::printContents(const Container & stlcontainer)
{
  //need to add "typename" before iterator 
  typename Container::const_iterator ie=stlcontainer.begin();
  while(ie!=stlcontainer.end())
  {
    cout<<*ie<<endl;
    ++ie;
  }
  cout<<endl;
}

template<typename assConatiner>
void Rank::printAssContainer(const assConatiner & asscontainer)
{
  typename assConatiner::const_iterator ie=asscontainer.begin();
  for(;ie!=asscontainer.end();ie++)
  {
    cout<<ie->first<<" : "<<ie->second<<endl;
  }
}

void Rank::findLargerItems(const UINT & stand, vector<string>& v_find_result) const
{
  vector<string> v_city_names;
  vector<UINT> v_city_pop;
	//find cities in _rank that have a population density larger than the "stand"

  //load map to build map two vector
  //because the function has been defined as const, so the iterator to the class member
  //has to be named constant, attention!
  MAP_STRING_UINT::const_iterator ie= _rank.begin();
  for(ie;ie!=_rank.end();ie++)
  {
  	//*ie.first is error ??? why
    v_city_names.push_back(ie->first);
    v_city_pop.push_back(ie->second);
  }
  
  vector<UINT>::iterator it_find;
  vector<UINT>::iterator it_start=v_city_pop.begin();
  const vector<UINT>::iterator it_end=v_city_pop.end();
  int dis=0; //distance from the found element to the begin point
  
  //I intend to find out all satisfied elements
  while(it_start!=it_end)
  {
  	//begin and end iterator in find_if should be identical
  	it_find=find_if(it_start,it_end,isLarger<UINT>(stand));
  	if(it_find!=v_city_pop.end())
  	{
  	  dis=distance(v_city_pop.begin(),it_find);
  	  cout<<"a larger than "<<stand<<" element is found at the "<<dis
     <<" element named "<<v_city_names[dis]<<endl;
      v_find_result.push_back(v_city_names[dis]);
      it_start+=(dis+1); //make adjustment for the next finding loop
	}
	else
	{
		break; //finding finished
	}
  }
 return;
}

void Rank::transformtoPopluation(const UINT & citynum,vector<UINT>& pop) const
{
  //create 3 vector to hold result
  vector<UINT> area;
  vector<UINT> pop_den;

  //iterator for look through cities
  VECTOR_CITY::const_iterator ic=_cities.begin();

  //transfer information from object vector to int vector
  int ix=0;
  while((ix<citynum)&&(ic!=_cities.end()))
  {
    area.push_back(ic->_cityInfo->_Area);
    pop_den.push_back(ic->_cityInfo->_PopulationDensity);
    ix++; ic++;
  }

  //make space for result vecot
  pop.resize(ix+1);
  //calculate, the 2-parmeters form of "transform"
  transform(area.begin(),area.begin()+ix,pop_den.begin(),pop.begin(),Multiplyer<UINT>());

  //print out result
  ix=0;
  while((ix<citynum)&&(ix<pop.size()))
  {
    cout<<"city "<<_cities[ix]._cityInfo->_CityName<<" have a popluation of "<<pop[ix]<<endl;
    ix++;
  }

  return;
}
