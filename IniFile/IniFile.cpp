#include <cstdlib>
#include "IniFile.h"
#include "iostream"
#include "Game/IGame.h"
#include "Field/Cell.h"
#include "Player/Player.h"
#include "Field/Field.h"

IniFile::IniFile(std::string setFileName)
{
	fileName = setFileName;
}

void IniFile::deleteTabs(std::string& str) {

	/*while (str.find(" ") == 0) {
		
			str.erase(0, 1);
	}*/

	while (((str.find(" ") == 0) || (str.find("\t") == 0) || (str.rfind(" ") == str.size() - 1) || (str.rfind("\t") == str.size() - 1)) && str.size() != 0) {
		if ((str.find(" ") == 0) || (str.find("\t") == 0))
			str.erase(0, 1);

		if (((str.rfind(" ") == str.size() - 1) || (str.rfind("\t") == str.size() - 1)) && str.size() != 0)
			str.erase(str.size() - 1, 1);
	}
}

void IniFile::writeSection(const Section& section, std::fstream& inifile) const{


	for (Section::const_iterator oMapIt = section.begin(); oMapIt != section.end(); ++oMapIt) {

		inifile << "\t" << oMapIt->first << " = " << oMapIt->second << "\n";

	}
	inifile << std::endl;
}


bool IniFile::load() {
	sMap.clear();
	std::fstream inifile;

	sMap = std::map <std::string, Section>();

	std::string str;
	std::string val;
	std::string sectionName;
	std::string key;
	int valInt;

	

	inifile.open(fileName, std::fstream::in);

// Если мы не можем открыть этот файл для чтения данных,
	if (!inifile.is_open())
	{
		std::cerr << "Uh oh, inifile.txt could not be opened for reading!" << std::endl;
		exit(1);
		return false;
	}

	while (!inifile.eof()) {

		getline(inifile, str);

		if ((str.find("[") != -1) && (str.find("]") != -1)) {
			sectionName = "";
			sectionName.assign(str, str.find("[") + 1, str.find("]") - 1);

			deleteTabs(sectionName);

			sMap[sectionName] = Section();
		}
		/*else if (((str.find("[") != -1) && (str.find("]") == -1)) || ((str.find("[") == -1) && (str.find("]") != -1)))
				std::cout << "EXEPTION" << std::endl;*/


		if (str.find("=") != -1) {
			key = "";
			key.assign(str, 0, str.find("="));

			deleteTabs(key);

			sMap[sectionName][key] = "";

			val = "";
			val.assign(str, str.find("=") + 1, str.length());

			deleteTabs(val);
			sMap[sectionName][key] = val;
		}
		/*else if (str.find("=") == -1)
			std::cout << "EXEPTION" << std::endl;*/
	}

	//testfile.close();
	inifile.close();
	return true;
}

void IniFile::save() {
	std::fstream inifile;

	// Если мы не можем открыть этот файл для записи данных,
	if (!inifile)
	{
		std::cerr << "Uh oh, inifile.txt could not be opened for writing!" << std::endl;
		exit(1);
	}

	inifile.open(fileName, std::fstream::out);
	

	for (std::map <std::string, Section> ::iterator sMapIt = sMap.begin(); sMapIt != sMap.end(); ++sMapIt) {

		inifile << "[" << sMapIt->first << "]\n";

		writeSection(sMapIt->second, inifile);
	}

	sMap.clear();
}

void IniFile::addData(std::string section, std::string key, std::string val) {
	sMap[section][key] = val;

	/*if (sMap.find(section) != sMap.end()) {
		
		if (sMap.find(section)->second.find(key) != sMap.find(section)->second.end()) {
			sMap.find(section)->second.find(key)->second = val;
		}
		return "";
	}
	return true;*/
}

std::string IniFile::getData(std::string section, std::string key) const {

	if (sMap.find(section) != sMap.end()) {
	
		if (sMap.find(section)->second.find(key) != sMap.find(section)->second.end()) {
			return sMap.find(section)->second.find(key)->second;
		}
		
	}
	return "not found";
}

