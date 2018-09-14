#pragma once
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>


using namespace std;

class Reading_Xsd
{
private:
	string Path_Xsd;
	string run_from_file;
	string end_of_word = " ";
	size_t found_Keyword, begin_of_K_schema=0, end_of_K_schema;
	vector<string> types_of_schemas; // Vector of all the schemas

	enum XSD_Keywords {schema=0 , complex_type, sequence, element};

	void open_file(void);
	void searching_specific(string);
	void found_scheme(string Scheme_Line);
	int define_values(string Keywords);

public:
	Reading_Xsd();
	~Reading_Xsd();
	void set_Xsd_file(string Path);
};

