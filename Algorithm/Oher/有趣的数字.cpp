// swap algorithm example (C++98)
#include <iostream>     // std::cout
#include <algorithm>    // std::swap
#include <vector>       // std::vector
#include <string>

using namespace std;
int main() {

	string s1 = "123";
	string s2 = "123";
	char* c1 = "123";
	char* c2 = "123";
	
	cout << (&s1 == &s2) << endl << (c1 == c2) << endl;
	getchar();
	
}