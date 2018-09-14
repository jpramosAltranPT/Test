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
	string end_of_sequence = "</xsd:sequence>";
	size_t found_Keyword, begin_of_K_schema=0, end_of_K_schema, start_of_Name_Complex, end_of_Name_Complex;
	bool isInsideSeq = false;
	vector<string> types_of_schemas; // Vector of all the schemas


	struct Element_of_sequece {
		
		string Element_name;
		string Element_type;
	};

	struct ComplexType {

		string Complex_Name;
		string Complex_Type;
	}Complex; // structure of complex and type (sequence / all) 

	vector <Element_of_sequece> Elements;

	enum XSD_Keywords {schema=0 , complex_type, sequence, element, wrapper, all, };

	void open_file(void);
	void searching_specific(string);
	void found_scheme(string Scheme_Line);
	void found_Complex(string Complex_line);
	void found_Sequence_or_All(string Stucture_line);
	void found_Element(string Element_line);
	string search_keywords_element(string Element_line, string Keyword);
	void create_Complex_Type();
	int define_values(string Keywords);


public:
	Reading_Xsd();
	~Reading_Xsd();
	void set_Xsd_file(string Path);
};

