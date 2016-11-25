#include "cGobalDefine.h"

namespace Gobal
{
    UINT TimeLine::_CurrentTime=0;
    UINT PowerUniverse::_ThreadNum=0;

    ERR_CODE FileIO::SaveCitytoBinaryFile(const City & source_city, const string & tragt_name) const
    {
        string path=this->_OutPath+"\\"+tragt_name;
        cout<<path<<endl;
        ofstream o_file(path,ios::binary);
        if(o_file.fail())
        {
            cerr<<"output failed !!!"<<endl;
            return FAIL;
        }
        try
        {
           o_file.write((char*)&source_city,sizeof(source_city));
        }
        catch(string ex)
        {
            cerr<<ex<<endl;
            return FAIL;
        }
        o_file.close();
        return SUCCESS;
    }

    ERR_CODE FileIO::ReadCityfromBinaryFile(const string & source_name, City & traget_city, const int & target_size) const
    {
        string path=this->_InPath+"\\"+source_name;
        cout<<path<<endl;
        ifstream i_file(path);
        if(i_file.fail())
        {
            cerr<<"input failed !!!"<<endl;
            return FAIL;
        }
        try
        {
            i_file.read((char*)&traget_city,target_size);
        }
        catch(string ex)
        {
            cerr<<ex<<endl;
            return FAIL;
        }
        i_file.close();
        return SUCCESS;
    }
};
