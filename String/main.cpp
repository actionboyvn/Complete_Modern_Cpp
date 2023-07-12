#include <iostream>
#include <sstream>
enum class Case { SENSITIVE, INSENSITIVE };

size_t Find(
	const std::string& source,         //Source string to be searched
	const std::string& search_string,  //The string to search for
	Case searchCase = Case::INSENSITIVE,//Choose case sensitive/insensitive search
	size_t offset = 0) {                //Start the search from this offset
	
	if (searchCase == Case::SENSITIVE)
		return source.find(search_string, offset);

	for (int i = offset; i <= source.length() - search_string.length(); ++i) {
		bool check = true;
		for (int j = 0; j < search_string.length(); ++j)
			if (toupper(source[i + j]) != toupper(search_string[j])) {
				check = false;
				break;
			}
		if (check)
			return i;
	}		

	return std::string::npos;
}
void TestStringStream() {
	std::stringstream ss;
	int x{ 5 }, y{ 2 };
	int sum = x + y;	
	ss << "Sum of " << x << " and " << y << " is " << sum << std::endl;
	std::cout << ss.str();
	ss.str(""); // Reset string stream
	std::string data{"5.2 3.1 4.5"};
	ss.str(data);
	float f;
	while (ss >> f)
		std::cout << f << ' ';	
}

int main() {
	/*
	std::string s = "123Abc";
	std::string x = "abc";
	size_t pos = Find(s, x, Case::INSENSITIVE, 0);
	std::cout << pos;*/
	TestStringStream();
	return 0;
}