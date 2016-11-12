#ifndef BASIC_MODEL_H
#define BASIC_MODEL_H

#include <list>
#include <vector>
#include <map>

#include <fstream>
#include <sstream>
#include <string>

#include <algorithm>
#include <iostream>
#define CITYLIST "CityList.txt"
using namespace std;

typedef unsigned long UINT;



//reserve is-a relationship for potential usage
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
  	bool saveBinaryFile(City* c,UINT len) const;
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
class Rank: public Method
{
	private:
    map<string,UINT> _rank;
    vector<City> _cities;
    vector<string> _citynames;
    vector<vector<double>> _locations;
	protected:
		
	public:
    Rank(vector<City> & incity):_cities(incity)
    {
      vector<City>::iterator it = incity.begin();
      vector<City>::iterator it_end = incity.end();

      for (;it != it_end;it++)
      {
         _citynames.push_back((*it)._cityInfo->_CityName);
         _rank.insert(make_pair((*it)._cityInfo->_CityName,(*it)._cityInfo->_PopulationDensity)); 
      } 
    }

    bool cmp = [](pair<string,UINT> const & a, pair<string,UINT> const & b);
    ofstream & outputRank(ofstream & os) const;

    ~Rank(){}
};

ofstream & Rank::outputRank(ofstream & os) const
{
    //check if iterate through all elements are successful
    map<string,UINT>::iterator it=_rank.begin();

    //sort by value
    sort(_rank.begin(),_rank.end(),cmp);

    //sort by key

    //print out
    while(it!=_rank.end())
    {
      cout<<it->first" : "<<it->second<<endl;
      it++;
    }
}

bool Rank::cmp = [](pair<string,UINT> const & a, pair<string,UINT> const & b)
{
   return a.second!=b.second?a.second<b.second:a.first<b.first;
}


#endif
