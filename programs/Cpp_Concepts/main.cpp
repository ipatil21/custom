// Difference betn copy ctor & assign opr
#include <iostream>
using namespace std;

class CpAs
{
	public:
		
		// Default Ctor 
		CpAs(int v1, int v2)
		{
			cout << "CpAs Ctor" << endl;
			m_v1 = v1;
			m_v2 = v2;
			
			/** Mem allocated to pointer & assigned value 99 to it **/
			m_p1 = new int(99);
		}
		
		// Copy Ctor
		CpAs(const CpAs& obj)
		{
			cout << "CpAs Copy Ctor" << endl;	
					
			m_v1 = obj.m_v1;
			m_v2 = obj.m_v2;
			m_p1 = obj.m_p1;
		}
		
		// Assign Opr
		void operator = (const CpAs& obj)
		{
			/** Watch this carefully **/
			if(this != &obj)
			{
				cout << "CpAs Ass Opr" << endl;
				
				if(NULL != m_p1)
					delete m_p1;	
			
				m_v1 = obj.m_v1;
				m_v2 = obj.m_v2;
				m_p1 = obj.m_p1;
			}
		}
		
		void display()
		{
			cout << "==========display()==========" << endl;
			cout << "m_v1  :- " << m_v1 << endl;
			cout << "m_v2  :- " << m_v2 << endl;
			cout << "m_v1  :- " << m_v1 << endl;
			cout << "Address of m_p1  :- " << &m_p1 << endl;
			cout << "Memory inside m_p1  :- " << m_p1 << endl;
			cout << "Value of m_p1  :- " << *m_p1 << endl;
			cout << "==========display()==========" << endl;
			
		}
		
	private:	
		int  m_v1;
		int  m_v2;	
		int* m_p1;
};

int main()
{
	CpAs obj(66, 77);
	obj.display();

	CpAs obj1(obj);
	obj1.display();
	
	obj = obj1;
	obj = obj1;
	
	return 0;
}

