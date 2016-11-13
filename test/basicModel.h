#ifndef BASIC_MODEL_H
#define BASIC_MODEL_H

#include <list>
#include <vector>
#include <set>
#include <map>

#include <fstream>
#include <sstream>
#include <string>

#include <algorithm>
#include <iostream>
#define CITYLIST "CityList.txt"
using namespace std;

typedef unsigned long UINT;

//reserved is-a relationship for potential usage;
class Method
{
  private:
  	list<int> _num;
  	list<string> _name;
  protected:

  public:
  	Method(){}
  	virtual ~Method(){}
};

//inital class object through I/O
class FileIO: public Method
{
  private:
  	string _Filename; 
  protected:
  	static UINT _IO_Num;
  public:
  	FileIO(const string & fn):_Filename(fn){_IO_Num++;}

  	//reset the number of objects need operation
  	void resetFilename(const string & newname);

  	//I/O operations for an array of city objects
  	bool readBinaryFile(string* filename,City* c, UINT len);
  	//save city object in binary file
  	bool saveBinaryFile(City* c,UINT len) const;
  	//read text file
    bool readTextFile(City* c,UINT);
  	//bool saveBinaryFile(City* c,UINT len) const;

  	~FileIO(){_IO_Num--;}
};

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


//rank cities by different keys (population, denfence level)
struct comperhensive_comparer
{
	bool operator()(const UINT& c1, const UINT& c2) const
  {
	return((c1+200)<c2);
  };
};
class Rank: public Method
{
	private:
    map<string,UINT> _rank;
    map<string,UINT,comperhensive_comparer> _com_rank;
    vector<City> _cities;
    set<string> _citynames; //city name is unqiue
    
    //print contents of sequence container
    template<typename Container>
    void printContents(const Container & stlcontainer);

    //print contents of associative container
    template<typename assConatiner>
    void printAssContainer(const assConatiner & asscontainer);
	protected:
		
	public:
    Rank(vector<City> & incity):_cities(incity)
    {
     //initialize city rank and name dir
     vector<City>::iterator it = incity.begin();
     vector<City>::iterator it_end = incity.end();
	
     for (;it != it_end;it++)
     {
        _citynames.insert((*it)._cityInfo->_CityName);

        //_rank.insert(make_pair((*it)._cityInfo->_CityName,(*it)._cityInfo->_PopulationDensity)); 
        _rank.insert(pair<string,UINT>((*it)._cityInfo->_CityName,(*it)._cityInfo->_PopulationDensity));
        //_rank[(*it)._cityInfo->_CityName]=(*it)._cityInfo->_PopulationDensity);
     } 
    }

    //add city to rank
    bool addCityname(const string & cityname);
	//remove city from rank
    bool removeCityname(const string & cityname);
    //print cityname and rank by order
	void printCityname();
    void printRank();
	//look up a city with name
	bool isexist(const string & cityname) const;
	//customerize functor for ranking
	UINT compliactRank(); 
    ~Rank(){}
};

UINT Rank::compliactRank()
{
	if (_com_rank.size()==0)
  {
    //the target map is empty, so make it initalized
    _com_rank.insert(_rank.begin(),_rank.end());
  }

//  cout<<"Now print out all members of the comperhensive rank by order: \n";
//  map<string,UINT,comperhensive_comparer>::const_iterator it=_com_rank.begin;
//  for(;it!=_com_rank.end();it++)
//  {
//    cout<<it->first<<" : "<<it->second<<endl;
//  }

  return _com_rank.size();
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

bool Rank::isexist(const string & cityname) const
{
  //find in the name set
  set<string>::const_iterator ie=_citynames.find(cityname);
  
  //find in _rand map
  map<string,UINT>::const_iterator ir=_rank.find(cityname);
  
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



#endif
