#include <iostream>
using namespace std;

class restrict
{
	public:
		
		// ctor
		restrict()
		{
			m_iSecret = 78;
			cout << "retrict ctor" << endl;
		}
		
		~restrict()
		{
			cout << "retrict dtor" << endl;
		}
		
		void* operator new(size_t size);
		/**
		{
			// Do nothing
			void *ptr;
			return ptr;
		}**/
		
		void display()
		{
			cout << "Secret Key :- " << m_iSecret << endl;
		}
		
	private:
		int m_iSecret;
		
};

int main()
{
	cout << "Let's restrict dynamic allocation of the objects" << endl;
	
	restrict o1;
	o1.display();
	
	restrict *p = new restrict;
	p->display();
	
	return 0;
}
