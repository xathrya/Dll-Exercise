/**
Declaring a class
*/

class __declspec(dllimport) DllClass
{
private:
	int  m_size;
	char m_internal[64];
public:
	DllClass();
	
	int   set(const char* message);
	char* get();
};