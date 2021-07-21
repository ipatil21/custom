#include <map>
#include <set>
#include <list>
#include <utility> 
#include <fstream>
#include <iostream>
#include <iterator> 

using namespace std;

typedef pair<unsigned int, unsigned int> myPair;
typedef map<myPair, myPair> myMap;
typedef unsigned int myInt;

int main()
{		
	myInt careTakerCount = 0;
	myInt careTakerRemoveCount = 0;
		
	myMap careTakersMap;
	set<myInt> mySet;
	
	std::ifstream infile;
  	infile.open ("caretakers.in");
	
	int in1, in2;
	infile >> careTakerCount >> careTakerRemoveCount; 
	cout << "careTakerCount : "  << careTakerCount << endl;
	cout << "careTakerRemoveCount : "  << careTakerRemoveCount << endl;
	
	if(careTakerCount <= careTakerRemoveCount)
	{
		cout << "Care taker count is less than or equal to care taker remove count" << endl;
		exit(0);
	}
	
	myPair startEndTime;
	myPair totalUniqueInterval;
	
	myInt readIndex = 0;
	while (infile >> in1 >> in2)
	{
		readIndex = careTakersMap.size();
		startEndTime.first = in1;
		startEndTime.second = in2;
				
		if(0 > in2 || 0 > in2 || 0 > in2 - in1)
		{
			cout << "Shift timimgs are not properly defined" << endl;
			exit(0);
		}		
				
		// cout << "in1 - in2 "  << in2 - in1 << endl;
		totalUniqueInterval.first = in2 - in1;
		totalUniqueInterval.second = 0;
		
		careTakersMap.insert(careTakersMap.end(), make_pair(startEndTime, totalUniqueInterval));
    	cout << "in1 : "  << in1 << " in2 :  "<< in2 << endl;
    	
    	while(in1 <= in2)
    		mySet.insert(in1++);
			
		if(readIndex == careTakersMap.size()) 
			careTakerRemoveCount--;
			
	}
	infile.close();
		
	//careTakersMap.insert(careTakersMap.end(), make_pair(startEndTime, totalUniqueInterval));
			
	int dupCount = 0;
    set<myInt>::iterator itSet;
	map<myPair, myPair>::iterator itMap;
		
  	for (itSet = mySet.begin(); itSet != mySet.end(); ++itSet)
  	{	
		for (itMap = careTakersMap.begin(); itMap != careTakersMap.end(); ++itMap)
    	{
    		if(*itSet >= itMap->first.first && *itSet <= itMap->first.second)
					dupCount++;
		}
    	
    	if(1 == dupCount)
    	{
    		for (itMap=careTakersMap.begin(); itMap!=careTakersMap.end(); ++itMap)
    		{	
    			// cout << "Dup count is " << dupCount << endl;
    			if(*itSet >= itMap->first.first && *itSet <= itMap->first.second)
				{
					itMap->second.second += 1;
					break;
				} 
			}
		}
		
		// cout << "Time :- " << *itSet << " unit covered by " << dupCount << " care taker"<< endl;
    	dupCount = 0;
	}
  	cout << endl;
  	
    map<myPair, myPair>::iterator itInnerMap;
	map<myPair, myPair>::iterator itOuterMap;
	
		
	myInt fireInterval = 0;
	int index = 0;
	map<myPair, myPair>::iterator itrMap;
	map<myPair, myPair>::iterator itErase;
	
	while(careTakerRemoveCount > 0)
	{
		itrMap = careTakersMap.begin();
		fireInterval =  itrMap->second.first;

		cout << "Still to fire " << careTakerRemoveCount << endl;
	
		for (itMap; itrMap != careTakersMap.end(); ++itrMap)
		{
			if(0 == itrMap->second.second)
			{
				// cout << "found zero unique" << endl;
				if(fireInterval > itrMap->second.first)
				{
					itErase = itrMap;
					fireInterval =  itrMap->second.first;
					index++;
				}
			}
			
		}

		cout << "index : -" << index << endl;
		cout << "Fire Interval :- " << fireInterval << endl;
		
		itMap = careTakersMap.begin();
		while(index > 0)
		{
			itMap++;
			index--;
		}
		index = 0;
		careTakersMap.erase(itMap);
				
		careTakerRemoveCount--;
		
		cout << "******" << endl;
		map<myPair, myPair>::iterator iMap;
			
    	for (iMap = careTakersMap.begin(); iMap != careTakersMap.end(); ++iMap)
		{	
			cout << iMap->first.first << " " 
				<< iMap->first.second << " "
				<< iMap->second.first << " "
				<< iMap->second.second <<endl;
		}
		
		cout << "******" << endl; 
	}
	
	map<myPair, myPair>::iterator iMap;
	iMap = careTakersMap.begin();
	myInt startResult = iMap->first.first;

	iMap = careTakersMap.end();
	--iMap;
	myInt endResult = iMap->first.second;

	std::ofstream opfile;
  	opfile.open ("caretakers.out");
  	opfile<< endResult - startResult;
  	opfile.close();
	
	cout << "Result :- " << endResult - startResult << endl;
	
	return 0;
}
