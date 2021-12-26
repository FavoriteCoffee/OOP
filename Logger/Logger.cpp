#include "Logger.h"
#include "Field/Cell.h"


Logger::Logger(IObject* player, IObject* goblin, IObject* troll, IObject* orc, IObject* battery, IObject* healthPotion, IObject* powerPotion, IObject* mandalorianArmor){

	oldLogMap[player] = player->printObj();
	oldLogMap[goblin] = goblin->printObj();
	oldLogMap[orc] = orc->printObj();
	oldLogMap[troll] = troll->printObj();
	oldLogMap[battery] = battery->printObj();
	oldLogMap[healthPotion] = healthPotion->printObj();
	oldLogMap[powerPotion] = powerPotion->printObj();
	oldLogMap[mandalorianArmor] = mandalorianArmor->printObj();
	//fout.open("file.txt");
}


void Logger::getNewData() {

	for (newIt = oldLogMap.begin(); newIt != oldLogMap.end(); ++newIt) {
		newLogMap[newIt->first] = newIt->first->printObj();
	}
}

void Logger::deleteOldData() {
	for (oldIt = oldLogMap.begin(); oldIt != oldLogMap.end(); ++oldIt) {
		for (int i = 0; i < 2; ++i) {
			delete[] oldIt->second[i];
		}
		delete[] oldIt->second;
	}
}

void Logger::updateOldData() {
	for (oldIt = oldLogMap.begin(), newIt = newLogMap.begin(); oldIt != oldLogMap.end() && newIt != newLogMap.end(); ++oldIt,++newIt) {
		oldLogMap[oldIt->first] = newIt->second;
	}
}

std::string Logger::logAllObjects() {
	
	std::string tempstrNew = "";
	

	getNewData();

	tempstrNew += newIt->second[0][0];

	for (oldIt = oldLogMap.begin(), newIt = newLogMap.begin(); oldIt != oldLogMap.end(); ++oldIt, ++newIt) {
		
		tempstrNew += newIt->second[0][0];

		for (int count = 1; count < atoi(newIt->second[1][0].c_str()); ++count) {
			if (newIt->second[1][count] != oldIt->second[1][count]) {
				tempstrNew += newIt->second[0][count];
				tempstrNew += newIt->second[1][count];
				++count;
			}
		}

		tempstrNew += "\n";
	}

	deleteOldData();
	updateOldData();
	return tempstrNew;
}

//std::ostream& operator<< (std::ostream& out, const Logger& loger) {
//	return out << loger.tempstrNew/*loger.logAllObjects()*/;
//}

//std::ofstreamfout.open("file.txt"); operator << (std::ofstream& fout, const Logger& loger) {
//	
//	 fout << loger.tempstrNew /*loger.logAllObjects()*/;
//	 fout.open("file.txt");return fout << loger;;
//}
