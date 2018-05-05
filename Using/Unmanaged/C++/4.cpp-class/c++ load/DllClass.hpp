/**
Declaring a class
This class will be imported from DLL
*/

class __declspec(dllimport) DllClass
{
private:
	int  m_size;
	char m_internal[64];
public:
	DllClass();
	
	void  set(const char* message);
	char* get();
};