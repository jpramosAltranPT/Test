#include "pch.h"
#include "Reading_Xsd.h"


Reading_Xsd::Reading_Xsd()
{
	string Path_Xsd = "template.xsd";

}


Reading_Xsd::~Reading_Xsd()
{
}

void Reading_Xsd::set_Xsd_file(string Path)
{
	Path_Xsd = Path;
}

void Reading_Xsd::open_file()
{
	ifstream f1(Path_Xsd);
	if (f1.is_open())
	{
		run_from_file = "";
		//Parser
		while (!f1.eof() || run_from_file.length() != 0)
		{
			getline(f1, run_from_file);
			searching_specific(run_from_file);
		}
	}

}

void Reading_Xsd::searching_specific(string search)
{
}

void Reading_Xsd::found_scheme(string Scheme_Line)
{
	do {
		end_of_K_schema = begin_of_K_schema;
		begin_of_K_schema = Scheme_Line.find(end_of_word, begin_of_K_schema + 1);
		types_of_schemas.push_back(Scheme_Line.substr(end_of_K_schema, begin_of_K_schema - end_of_K_schema));
	} while (begin_of_K_schema != string::npos);
}

void Reading_Xsd::found_Complex(string Complex_line)
{
	start_of_Name_Complex = Complex_line.find(name_search);
	if (start_of_Name_Complex != string::npos)
	{
		end_of_Name_Complex= Complex_line.find(">");
		if (end_of_Name_Complex != string::npos) 
		{
			Complex.Complex_Name = Complex_line.substr(start_of_Name_Complex + 6,
										end_of_Name_Complex - start_of_Name_Complex - 7);
		}
	}
}

int Reading_Xsd::define_values(string Keywords)
{
	if (Keywords == "<xsd:schema")
		return 0;
	if (Keywords == "<xsd:complexType")
		return 1;
	if (Keywords == "<xsd:sequence")
		return 2;
	if (Keywords == "<xsd:element")
		return 3;
	if (Keywords == "<xsd:wrapper")
		return 3;
}

