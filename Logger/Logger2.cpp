#include "Logger2.h"
#include "Field/Cell.h"


//Logger2::Logger(IObject* obj) {
//	oldLogMap2[obj] = obj->printObj2();
//}

void Logger2::getNewData(IObject* obj) {

	newLogMap2[obj] = obj->printObj2();
}

void Logger2::updateOldData(IObject* obj) {
		oldLogMap2[obj] = newLogMap2[obj];
}


////std::string Logger2::logAllObjects() {
////
////	std::string tempstr = "";
////
////
////	for (oldIt = oldLogMap2.begin(), newIt = newLogMap.begin(); oldIt != oldLogMap.end(); ++oldIt, ++newIt) {
////
////		tempstrNew += newIt->second[0][0];
////
////		for (int count = 1; count < atoi(newIt->second[1][0].c_str()); ++count) {
////			if (newIt->second[1][count] != oldIt->second[1][count]) {
////				tempstrNew += newIt->second[0][count];
////				tempstrNew += newIt->second[1][count];
////				++count;
////			}
////		}
////
////		tempstrNew += "\n";
////	}
////
////
////	for ()
//
//	getNewData(obj);
//
//	//for (oldIt = oldLogMap.begin(), newIt = newLogMap.begin(); oldIt != oldLogMap.end(); ++oldIt, ++newIt) {
//
//	if (newLogMap2[obj] != oldLogMap2[obj]) tempstrNew2 = newLogMap2[obj] + "\n";
//
//
//	updateOldData(obj);
//	return tempstrNew2;
//
//}
//void Logger::deleteOldData(IObject* obj) {
//		for (int i = 0; i < 2; ++i) {
//			delete[] oldLogMap2[obj][i];
//		}
//	delete[] oldLogMap2[obj];
//}

Logger2::Logger2(IObject* player, IObject* goblin, IObject* orc, IObject* troll, IObject* healthPotion, IObject* powerPotion, IObject* mandalorianArmor, IObject* battery) {

	oldLogMap2[player] = player->printObj2();
	std::cout << oldLogMap2[player] << std::endl;
	oldLogMap2[goblin] = goblin->printObj2();
	std::cout << oldLogMap2[goblin] << std::endl;
	oldLogMap2[orc] = orc->printObj2();
	std::cout << oldLogMap2[orc] << std::endl;
	oldLogMap2[troll] = troll->printObj2();
	std::cout << oldLogMap2[troll] << std::endl;
	oldLogMap2[battery] = battery->printObj2();
	std::cout << oldLogMap2[battery] << std::endl;
	oldLogMap2[healthPotion] = healthPotion->printObj2();
	std::cout << oldLogMap2[healthPotion] << std::endl;
	oldLogMap2[powerPotion] = powerPotion->printObj2();
	std::cout << oldLogMap2[powerPotion] << std::endl;
	oldLogMap2[mandalorianArmor] = mandalorianArmor->printObj2();
	std::cout << oldLogMap2[mandalorianArmor] << std::endl;
	//fout.open("file.txt");
}

std::string Logger2::logObject(IObject* obj) {
	if (obj != nullptr) {
		tempstrNew2 = "";

		getNewData(obj);

		//for (oldIt = oldLogMap.begin(), newIt = newLogMap.begin(); oldIt != oldLogMap.end(); ++oldIt, ++newIt) {

		if (newLogMap2[obj] != oldLogMap2[obj]) tempstrNew2 = newLogMap2[obj] + "\n";


		updateOldData(obj);

		return tempstrNew2;
	}
	else {
		tempstrNew2 = "";
	}

	return tempstrNew2;
}

std::ostream& operator<< (std::ostream& out, const Logger2& logger) {
	std::string str = logger.tempstrNew2;
	out << str;
	return out; 
}

//std::ofstream& operator<< (std::ofstream& fout, const std::string& tempstrNew2){
//
//	 fout << tempstrNew2 /*loger.logAllObjects()*/;
//	 fout.open("file.txt");
//	 return fout << tempstrNew2;
//}

//Logger::Logger(IObject* player, IObject* goblin, IObject* orc, IObject* troll, IObject* battery, IObject* healthPotion, IObject* powerPotion, IObject* mandalorianArmor) {
//
//	oldLogMap[player] = player->printObj();
//	oldLogMap[goblin] = goblin->printObj();
//	oldLogMap[orc] = orc->printObj();
//	oldLogMap[troll] = troll->printObj();
//	oldLogMap[battery] = battery->printObj();
//	oldLogMap[healthPotion] = healthPotion->printObj();
//	oldLogMap[powerPotion] = powerPotion->printObj();
//	oldLogMap[mandalorianArmor] = mandalorianArmor->printObj();
//	//fout.open("file.txt");
//}
//

//void Logger::getNewData() {
//
//	for (newIt = oldLogMap.begin(); newIt != oldLogMap.end(); ++newIt) {
//		newLogMap[newIt->first] = newIt->first->printObj();
//	}
//}
//
//void Logger::deleteOldData() {
//	for (oldIt = oldLogMap.begin(); oldIt != oldLogMap.end(); ++oldIt) {
//		for (int i = 0; i < 2; ++i) {
//			delete[] oldIt->second[i];
//		}
//		delete[] oldIt->second;
//	}
//}
//
//void Logger::updateOldData() {
//	for (oldIt = oldLogMap.begin(), newIt = newLogMap.begin(); oldIt != oldLogMap.end() && newIt != newLogMap.end(); ++oldIt, ++newIt) {
//		oldLogMap[oldIt->first] = newIt->second;
//	}
//}
//
//std::string Logger::logAllObjects() {
//
//	std::string tempstrNew = "";
//
//
//	getNewData();
//
//	for (oldIt = oldLogMap.begin(), newIt = newLogMap.begin(); oldIt != oldLogMap.end(); ++oldIt, ++newIt) {
//
//		tempstrNew += newIt->second[0][0];
//
//		for (int count = 1; count < atoi(newIt->second[1][0].c_str()); ++count) {
//			if (newIt->second[1][count] != oldIt->second[1][count]) {
//				tempstrNew += newIt->second[0][count];
//				tempstrNew += newIt->second[1][count];
//				++count;
//			}
//		}
//
//		tempstrNew += "\n";
//	}
//
//	deleteOldData();
//	updateOldData();
//	return tempstrNew;
//}
////
////std::stream& operator<< (std::ostream& out, const Logger& loger) {
////	return out << loger.tempstrNew/*loger.logAllObjects()*/;
////}
//
////std::ofstreamfout.open("file.txt"); operator << (std::ofstream& fout, const Logger& loger) {
//
//	 //fout << loger.tempstrNew /*loger.logAllObjects()*/;
//	 //fout.open("file.txt");return fout << loger;;
////}
