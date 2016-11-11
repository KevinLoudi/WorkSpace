#include <iostream>
#include <string>
using namespace std;

struct PlaceInfo
{
	int id;
};
class Place
{
  protected:
  	PlaceInfo* _placeInfo;
  public:	
  	Place(PlaceInfo* pi={0}):_placeInfo(pi){}
  	int GetInfo() {return _placeInfo->id;}
  	~Place(){}
};

struct CityInfo
{
	string cityname;	
};
class City: Place
{
	protected:
		CityInfo* _cityInfo;
	public:
		City(PlaceInfo* pi={0},CityInfo* ci={"Xian"}):Place(pi),_cityInfo(ci){}
		{
//			_placeInfo->id = 0;
//			_cityInfo->cityname = "Xianyang";
		}
		string GetInfos(){ return _cityInfo->cityname;}
		~City(){}		
};

int main()
{
	PlaceInfo* pi;
	CityInfo* ci;
	Place p(pi);
	City c(pi,ci);
	return 0;
}

//#include <string>
//#include <iostream>
//#include <sstream>
//#include <fstream>
//using namespace std;
// 
//int main()
//{
//     greet the user
//    std::string name;
//    std::cout << "What is your name? ";
//    std::getline(std::cin, name);
//    std::cout << "Hello " << name << ", nice to meet you.\n";
// 
//     read file line by line
//    std::istringstream input;
//    input.str("1\n2\n3\n4\n5\n6\n7\n");
//    ifstream input("text.txt");
//    int sum = 0;
//    for (std::string line; std::getline(input, line); ) {
//    	cout<<line<<endl;
//        sum += std::stoi(line);
//    }
//    std::cout << "\nThe sum is: " << sum << "\n";
//}

//#include <fstream>
//#include <iterator>
//#include <vector>
//#include <iostream>
//using namespace std;
//
//struct CoordinatePair
//{
//    int x;
//    int y;
//};
//
//std::istream& operator>>(std::istream& is, CoordinatePair& coordinates)
//{
//    is >> coordinates.x >> coordinates.y;
//
//    return is;
//}
//
//int main()
//{
//    char filename[] = "text.txt";
//    vector<CoordinatePair> v;
//    ifstream ifs(filename);
//    if (ifs) {
//        std::copy(std::istream_iterator<CoordinatePair>(ifs), 
//                std::istream_iterator<CoordinatePair>(),
//                std::back_inserter(v));
//    }
//    else {
//        std::cerr << "Couldn't open " << filename << " for reading\n";
//    }
//    
//    // Now you can work with the contents of v
//    ifs.close();
//}


//#include <iostream>
//#include <fstream>
//std::ifstream infile("text.txt");
///* run this program using the console pauser or add your own getch, system("pause") or input loop */
//
//int main(int argc, char** argv) {
//	int a,b;
//	while(infile>>a>>b)
//	{
//		std::cout<<a<<" "<<b<<std::endl;
//	}
//	
//	return 0;
//}
