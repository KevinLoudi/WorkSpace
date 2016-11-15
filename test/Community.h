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
using namespace std;


typedef unsigned short int USINT;
enum GENDER {MALE=0,FMALE=1};
enum ERR_CODE {SUCCESS,FAIL};
enum Judge {YES,NO};

//declaration of classes
class Person;
class Community;
class Noble;
class NobleFamily;
class King;
class Kingdom;
class Warrior;
class Army;

//C++ does not allow temporaries to be bound to non-const references.
//so define a defalut vector as defalut value is optimal
static vector<Army> DEFAULT_VECTOR_ARMY;

class Person
{
	private:
		//an common citzen have no name
		//only male above 16 are allowed to recurited as soldier
		GENDER _gender; 
		USINT _age;
	public:
		Person();
		//print out class information
		virtual ostream & printInfo() const;
		//return class information
		virtual Person* getInfo() const;
		//update class information
		virtual ERR_CODE update(const Person & rPerson);
		//check if class information satisfy a given condition
		Judge isSatisfied(const GENDER & gender,const USINT & _age) const;
		virtual ~Person();
	protected: 
};
//community is the organized relationship between a group of people
//pure virtual
class Community
{
	private:
		const string _organization_name;
		vector<Person> _people;
	public:
		Community();
		//print out class information
		virtual ostream & printInfo() const;
		//return class information
		virtual Community* getInfo() const;
		//add new members of the community
		virtual ERR_CODE addMembers(vector<Person> & rPeople);
		//return organization name
		virtual string getName() const;
		virtual ~Community();
	protected:
};

//noble is a kind of person
class Noble: public Person
{
	private:
		string _first_name;
		USINT _political_influence;
	public:
		Noble();
		//print out class information
		ostream & printInfo() const;
		//return class information
		Noble* getInfo() const;
		//update class information
		ERR_CODE update(const Noble & rNoble);
		//change influence
		ERR_CODE updateInfluence(const USINT & influence_margin);
	    //return organization name
		string getName() const;
		~Noble();
	protected:
};
class NobleFamily: public Community
{
    private:
    	const string _last_name;
    	//each family member have the same last name
		vector<Noble> _famliy_members;
		string _family_lead_s_first_name;
	public:
		NobleFamily();
		//overload
		ostream & printInfo() const;
		//redefine
		NobleFamily* getInfo() const;
		//add a family member
		ERR_CODE addMembers(vector<Noble> & rNoble);
		//change family leader
		ERR_CODE updateLeader(const string & rnewLeaderName);
	    //return organization name
		string getName() const;
		~NobleFamily();
	protected:
		
};

class King: public Noble
{
	private:
		NobleFamily _king_s_family;
		Noble _heir;
		vector<NobleFamily> _king_s_controlled_families;
		USINT _king_s_prestige;

		const USINT _administration_ability;
		const USINT _diplomacy_ability;
		const USINT _military_ability;
    public:
    	King();
    	//print out class information
		ostream & printInfo() const;
		//return class information
		King* getInfo() const;
		//add controlled families
		ERR_CODE addMembers(vector<NobleFamily> & rFamilynewCotrolled);
		//update class information
		ERR_CODE update(const King & rKing);
		//change heir of the king
		ERR_CODE changeheir(const Noble & rnewheir);
		//modify prestige of the king
		ERR_CODE modifyPrestige(const USINT margins);
    	~King();
	protected:
};
class Kingdom: public NobleFamily
{
	private:
		King _country_leader;
		NobleFamily _leader_family;
		vector<Warrior> _generals;
		vector<Army> _army_groups;
    public:
    	Kingdom();
    	//print out class information
		ostream & printInfo() const;
		//return class information
		Kingdom* getInfo() const;
		//add new members of the community or army group
		//C++ does not allow temporaries to be bound to non-const references.
		ERR_CODE addMembers(vector<Warrior> & rWarrior, 
			vector<Army> & rnewArmies=DEFAULT_VECTOR_ARMY);
		//change king, meanwhile change ruler family or not
		//while a const reference is allowed
		ERR_CODE seizPowerbyotherFamily(const Noble & rnewking, 
			const NobleFamily & rnewFamily=NobleFamily());
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
		Warrior();
		//print out class information
		ostream & printInfo() const;
		//return class information
		Warrior* getInfo() const;
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
		Army();
		//print out class information
		ostream & printInfo() const;
		//return class information
		Army* getInfo() const;
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
