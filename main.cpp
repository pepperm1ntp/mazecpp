#include<iostream>
#include "src/my_class.cpp"

using namespace std;

int main (int argc, char* argv[])
{
	cout << "Hello World!\n";
	for (int i = 1; i < argc; i++)
	{
		cout << "argv[" << i << "] = " << argv[i] << "\n";
	}

	cout << "Output from MyClass: " << MyClass::foo() << endl;

	return 0;
}