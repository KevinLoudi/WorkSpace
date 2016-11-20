#ifndef COMMUNITY_H
#define COMMUNITY_H
//Person act as a brick of a community, and can derived to 
//more specified type: nobel, warrior, priest, and king (now we limited
//person type to only political issues in mediaeval) 

//all class should work as template class since they present different
//in different culture, in China, is Wangye, Jiangjue, Daoshi, Huangdi,
//in western world or muslim world, things differs
#include <vector>
#include <iostream>
#include "GobalDefine.h"
const static unsigned short int ADULT_AGE=18;
//#define ADULT_AGE 18
using namespace std;

typedef unsigned short int USINT;
enum GENDER {MALE=0,FMALE=1};
//keep enum members in not-confusing order
enum ERR_CODE {FAIL,SUCCESS};
enum Judge {NO=false,YES=true};

//declaration of classes
//name of a person or a organization should be treat as 
//key 
class Person;
class Community;
class Noble;
class NobleFamily;
class King;
class Kingdom;
class Warrior;
class Army;

class find_name;

//C++ does not allow temporaries to be bound to non-const references.
//so define a defalut vector as defalut value is optimal
static vector<Army> DEFAULT_VECTOR_ARMY;

class Person
{
	protected: 
		//an common citzen have no name
		//only male above 16 are allowed to recurited as soldier
		GENDER _gender; 
		USINT _age;
	public:
		explicit Person(); //USINT age=0,GENDER gender=MALE
		//print out class information
		virtual ostream & printInfo(ostream & ros) const;
		//return class information
		virtual Person* clone() const;
		//update class information
		virtual ERR_CODE update(const Person & rPerson);
		//check if class information satisfy a given condition
		Judge isSatisfied(const GENDER & gender=MALE,const USINT & age=ADULT_AGE) const;
		virtual ~Person();
};

//community is the organized relationship between a group of people
//pure virtual, community is not an entity, it should be derived befor use
class Community
{
	private:
		//const string _organization_name;
		//vector<Person> _people;
	public:
		explicit Community(){}
		//print out class information
		virtual ostream & printInfo(ostream & ros) const=0;
		//return class information
		virtual Community* clone() const=0;
		//add new members of the community
		virtual ERR_CODE addMembers(const Person & rPerson)
		{
			_organizaed_people.push_back(rPerson);
			return SUCCESS;
		}
		//return organization name
		virtual string getName() const=0;
		virtual ~Community(){}
	protected:
		vector<Person> _organizaed_people;
};

//noble is a kind of person
class Noble: public Person
{
	private:
		string _first_name;
		USINT _political_influence;
	public:
		explicit Noble(string name, USINT influence):
		  _first_name(name),_political_influence(influence){}
		//print out class information
		ostream & printInfo(ostream & ros) const;
		//return class information
		Noble* clone() const;
		//update class information
		ERR_CODE update(const Noble & rNoble);
		//change influence
		ERR_CODE updateInfluence(const USINT & influence_margin);
	    //return organization name
		string getName() const;
		//return influence 
		USINT getInfluence() const {return _political_influence;}
		//is the same noble, since only noble have a name
		//same-person comparsion is only valid for noble and its derived
		//class
		bool operator==(const Noble & rnoble) const
		{
			return this->getName()==rnoble.getName();
		}
		//a noble greater than another when he has more influence;
		bool operator>(const Noble & rn2) const
		{
			return this->getInfluence()>rn2.getInfluence();
		}
		~Noble();
	protected:
};

class NobleFamily: public Community
{
    private:
    	const string _last_name;
    	//each family member have the same last name
		vector<Noble> _famliy_members;
		string _leader_name;
	public:
		explicit NobleFamily(const string & rname,const vector<Noble>& rmembers, 
	       const string & rleadername):_last_name(rname),_famliy_members(rmembers),
          _leader_name(rleadername){}
		ostream & printInfo(ostream & ros) const;
		NobleFamily* clone() const;
		//add a family member
		ERR_CODE addMembers(const Noble & rNoble);
		//find new leader with the largest political influence
		ERR_CODE isLeaderValid();
		//is the name, return if the string named the family
		ERR_CODE islastName(const string & nameStr) const;
		//change family leader
		ERR_CODE updateLeader(const string & rnewLeaderName);
	    //return organization name
		string getName() const;

		~NobleFamily(){}
	protected:
		
};

class King: public Noble
{
	private:
		//NobleFamily _king_s_family;
		Noble _heir;
		string _family_name;
		vector<NobleFamily> _controlled_families;
		USINT _prestige;

		const USINT _administration_ability;
		const USINT _diplomacy_ability;
		const USINT _military_ability;
    public:
    	explicit King(string name, USINT influence,const string & family_name, const Noble & heir,const vector<NobleFamily>
	       leading_family,const USINT prestige):Noble(name,influence),_heir(heir),_family_name(family_name),_controlled_families(leading_family),
          _prestige(prestige),_administration_ability(0),_diplomacy_ability(0),_military_ability(0){}
    	//print out class information
		ostream & printInfo() const;
		//return class information
		King* clone() const;
		//add controlled families
		ERR_CODE addMembers(vector<NobleFamily> & rFamilynewCotrolled);
		//update class information
		ERR_CODE update(const King & rKing);
		//change heir of the king
		ERR_CODE changeheir(const Noble & rnewheir);
		//modify prestige of the king
		ERR_CODE modifyPrestige(const USINT margins);
		//which family the king come from
		string getfamilyName() const {return _family_name;}
    	~King();
	protected:
};
class Kingdom: public NobleFamily
{
	private:
		King _country_leader;
		//NobleFamily _leader_family;
		vector<Warrior> _generals;
		vector<Army> _army_groups;
    public:
    	explicit Kingdom();
    	//print out class information
		ostream & printInfo() const;
		//return class information
		Kingdom* clone() const;
		//add new members of the community or army group
		//C++ does not allow temporaries to be bound to non-const references.
		ERR_CODE addMembers(vector<Warrior> & rWarrior, 
			vector<Army> & rnewArmies=DEFAULT_VECTOR_ARMY);
		//change king, meanwhile change ruler family or not
		//while a const reference is allowed
		ERR_CODE seizPowerbyotherFamily(const Noble & rnewking, 
			const NobleFamily & rnewFamily);
		//return organization name
		string getName() const;
		~Kingdom();
	protected:
};

class Warrior: public Noble
{
	private:
		//a warrior is a nobel work as a lan general
		//five import poperties for a general
		const USINT _shock_ability;
		const USINT _fire_ability;
		const USINT _maneuver_ability;
		const USINT _siege_ability;
		const USINT _intelligence;
	public:
		explicit Warrior();
		//print out class information
		ostream & printInfo() const;
		//return class information
		Warrior* clone() const;
		//update class information
		//ERR_CODE update(const Warrior & rWarrior);
		string getName() const;
		~Warrior();
	protected:
};

class Army: public Community
{
	private:
		//an army is organized by a general, own by a king and
		//consist of a group of common citizen
		//a noble or a king can take the job as the _army_leader
		Warrior _army_leader;
		vector<Person> _soldiers;
		USINT _morale; //power of the army
	public:
		explicit Army();
		//print out class information
		ostream & printInfo() const;
		//return class information
		Army* clone() const;
		//add new members of the community
		ERR_CODE addMembers(vector<Person> & rnewsoldiers);
		//change army lead
		ERR_CODE changeLeader(const Warrior & rnewGeneral);
		//modify morale
		ERR_CODE modifyMorale(const USINT morale_margin); 
		~Army();
	protected:
		
};


#endif
