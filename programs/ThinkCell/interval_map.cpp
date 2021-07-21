#include <map>
#include <limits>
#include <iostream>
#include <iomanip>
using namespace std;

template<typename K, typename V>
class interval_map
{
	std::map<K,V> m_map;
	
public:
    // constructor associates whole range of K with val by inserting (K_min, val)
    // into the map
    interval_map( V const& val) {
        m_map.insert(m_map.end(),std::make_pair(std::numeric_limits<K>::lowest(),val));
    }

    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // Conforming to the C++ Standard Library conventions, the interval
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.
    void assign( K const& keyBegin, K const& keyEnd, V const& val )
	{
		if(val < std::numeric_limits<V>::lowest())
			return;
		
		if(val > std::numeric_limits<V>::max())
			return;
		
		if(keyBegin < std::numeric_limits<K>::lowest())
			return;
		
		if(keyBegin > std::numeric_limits<K>::max())
			return;
			
		if(keyEnd < std::numeric_limits<K>::lowest())
			return;
		
		if(keyEnd > std::numeric_limits<K>::max())
			return;
		
	  	if(!(keyBegin < keyEnd))
	  		return;
	
		/**	
		if(keyBegin > static_cast<K> (m_map.size())) 
		{
			auto condition =  keyBegin - static_cast<K> (m_map.size());
			
			typename std::map<K,V>::iterator it = m_map.end();
			auto lastValue = (--it)->second;
			cout << "Value @ end :- " << lastValue<< endl;
			
			while(condition--) 
				m_map[(++it)->first] = lastValue;
				
		}
		else
		{
			
		}
		**/
			 
		
        std::cout << '{' << i.first << ", " 
                  << i.second << "}\n"; 	 
			 
		auto itrKey = keyBegin;
		while(itrKey < keyEnd)
			m_map[itrKey++] = val;
			
    }

	void display()
	{
		std::map<float, char>::iterator itr = m_map.begin();

 		for (itr; itr != m_map.end(); ++itr)
    		std::cout << itr->first << std::fixed << std::setprecision(2) << " => " << itr->second  << endl;
	}

    // look-up of the value associated with key
    V const& operator[]( K const& key ) const {
        return ( --m_map.upper_bound(key) )->second;
    }
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of unsigned int intervals to char.

int main()
{
	interval_map<float, char> obj('A');
		
	obj.assign(0.10, 12.10, 'S');
	obj.assign(15.43, 20.10, 'X');

	obj.display();	
}
