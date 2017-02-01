#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
char *String_pointer;
int Array_size;
public:
String() {
String_pointer = NULL;
Array_size = 0;
}
String(char *str) {
Array_size = strlen(str) + 1;
String_pointer = new char[Array_size];
strcpy(String_pointer, str);
}
int size() {
return Array_size;
}
~String() {
delete []String_pointer;
}

void Print()
{
for(int i=0; i<Array_size; i++)
cout<<String_pointer[i];
}

char Get(int i)
{
return String_pointer[i];
}

void Set(int i, char c)
{
String_pointer[i] = c;
}

int Find(String str)
{
bool ch = false;
int index;
int ind1=0;
for(int i = 0; i < Array_size; i++)
{
if (!ch)
{
if(String_pointer[i] == str.Get(0))
ch = true;
index = i;
ind1 = 1;
}
else
if (ch)
{
if (!String_pointer[i] == str.Get(ind1))
{
ch = false;
index = 0;
ind1 = 0;
}
}
}
return index;
}

void Concat(String s)
{
Array_size += s.size();
char* tmp = new char[Array_size + 1];
::strcpy(tmp, String_pointer);
::strcat(tmp, s.String_pointer);
delete [] String_pointer;
String_pointer = tmp;
}


};




int main() {
String Example1("kekekek.");
String Example2("Blablabla");
Example2.Concat(Example1);
cout<<Example2.Find("abl")<<endl;
Example2.Print();
cout<<'.';

return 0;
}
