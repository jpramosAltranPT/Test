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
	string name_search = "name=";
	string type_search = "type=";
	size_t found_Keyword, begin_of_K_schema=0, end_of_K_schema, start_of_Name_Complex, end_of_Name_Complex;
	vector<string> types_of_schemas; // Vector of all the schemas

	struct Element_of_sequece {
		
		string Element_name;
		string Element_type;
	};

	struct ComplexType {

		string Complex_Name;
		vector <Element_of_sequece> Elements;
	}Complex;

	enum XSD_Keywords {schema=0 , complex_type, sequence, element, wrapper};

	void open_file(void);
	void searching_specific(string);
	void found_scheme(string Scheme_Line);
	void found_Complex(string Complex_line);
	void create_Complex_Type();
	int define_values(string Keywords);

public:
	Reading_Xsd();
	~Reading_Xsd();
	void set_Xsd_file(string Path);
};

