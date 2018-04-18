/**
Declaring a class
This class will be exported to DLL
*/

#ifdef  __EXPORT_CLASS_
#define DECLARE __declspec(dllexport)
#else
#define DECLARE __declspec(dllimport)
#endif

class DECLARE DllClass
{
private:
	int  m_size;
	char m_internal[64];
public:
	DllClass();
	
	int   set(const char* message);
	char* get();
};