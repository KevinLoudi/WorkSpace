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
  	//bool saveBinaryFile(City* c,UINT len) const;

  	~FileIO(){_IO_Num--;}
};

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


////rank cities by different keys (population, denfence level)
//template<typename C,typename P>
//class Rank: public Method
//{
//	private:
//		vector<C> _city;
//
//
//	protected:
//		
//	public:
//};


#endif
