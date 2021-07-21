#include <iostream>
using namespace std;

class OprLoading
{	
	public:	
	
		// ctor with no arg
		OprLoading()
		{
			cout << "OprLoading ctor .." << endl;	
			m_count = 10;
		}

		// ctor with one arg
		OprLoading(int n)
		{
			cout << "OprLoading ctor .." << endl;	
			m_count = n;
		}
	
		~OprLoading()
		{
			cout << "OprLoading dtor .." << endl;	
		}
		
		// Overload ++ opr
		int operator++()
		{
			return ++m_count;	
		} 
		
		// Overload ++ opr
		int operator++(int dummy)
		{
			return m_count++;	
		} 
		
		void display()
		{
			cout << "Value of m_count :-  " << m_count << endl;	
		}
		
	private:
		int m_count;
		
};

int main()
{
	cout << "Welcome to world of operator overloading" << endl;
	
	// pre - increment
	OprLoading obj1;
	obj1.display();
	++ obj1;
	obj1.display();

	// post - increment
	OprLoading obj2(56);
	obj2.display();
	obj2++;
	obj2.display();
	
	return 0;
}
