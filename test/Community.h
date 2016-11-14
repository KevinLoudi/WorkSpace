#ifndef COMMUNITY_H
#define COMMUNITY_H

//Person act as a brick of a community, and can derived to 
//more specified type: nobel, warrior, priest, and king (now we limited
//person type to only political issues in mediaeval) 

//all class should work as template class since they present different
//in different culture, in China, is Wangye, Jiangjue, Daoshi, Huangdi,
//in western world or muslim world, things differs
class Person
{
	public:
		
	protected: 
};
//community is the organized relationship between a group of people
class Community
{
	public:
		Community();
		~Community();
	protected:
};

class Noble: public Person
{
	public:
		
	protected:
};
class NobleFamily: public Community
{
	public:
		
	protected:
		
};

class Warrior: public Person
{
	public:
		
	protected:
};
class Army: public Community
{
	public:
		
	protected:
		
};

class Priest: public Person
{
	public:
		
	protected:
};
class Religious_organization: public Community
{
	public:
		
	protected:
		
};

#endif
