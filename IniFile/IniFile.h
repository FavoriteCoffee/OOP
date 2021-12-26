#pragma once

#include <iostream>
#include <string>

#include <fstream>
#include <map>
#include "Field/Field.h"
#include "Point.h"

using Section = std::map <std::string, std::string>;

class IniFile
{
private:

	std::map <std::string, Section> sMap;

	void writeSection(const Section&, std::fstream& ) const;
	
	std::string fileName;

public:
	IniFile(std::string fileName);
	void deleteTabs(std::string& str);
	bool load();
	void save();
	void addData(std::string section, std::string key, std::string val);
	std::string getData(std::string section, std::string key) const ;
};

