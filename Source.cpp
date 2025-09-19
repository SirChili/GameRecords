//Reading rows of data from a file (spreadsheet), storing them in an array of struct objects, and doing some data analytics

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

struct GameRecord{

	string date;
	string game;
	double earnings;
	int players;
	int tournaments;

};

std::vector<std::string> splitRecord_withStringStream(const std::string& record, char delimiter)
{
	std::vector<std::string> fields;
	std::stringstream ss(record);
	std::string field;

	while (std::getline(ss, field, delimiter))
	{
		fields.push_back(field);
	}

	return fields;
}

int main() {

	ifstream file("D://RandomFiles//HistoricalEsportData.csv");

	if (!file){
	
		cout << "File not Found";
		return -1; //do this if you don't want to go any further down in the code
	}

	string currentLine;

	vector<GameRecord> records;

	//auto splitTokens = splitRecord_withStringStream("a.bc,de.fg", '.');



	//int loopCount = 0; | Variable for commented out code in the while loop
	while(std::getline(file, currentLine)) {

		cout << currentLine << "\n\n";
		
		auto splitRecord = splitRecord_withStringStream(currentLine, ',');
		
		/*
		int earnings = std::stoi(splitRecord[splitRecord.size() -1]);
		loopCount++;
		*/
		
		GameRecord currentRecord{
			//keep getting stoi error for reason unknown
			/*
			splitRecord[0],
			splitRecord[1],
			std::stoi(splitRecord[2]), //need to call stoi to convert string to integer
			std::stoi(splitRecord[3]),
			std::stoi(splitRecord[4]),
			*/
		};
	
		records.push_back(currentRecord);
	}

}
