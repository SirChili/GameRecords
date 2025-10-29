//Reading rows of data from a file (spreadsheet), storing them in an array of struct objects, and doing some data analytics
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

struct GameRecord {

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

int displayHeader() {

	cout << "Date" << setw(60) << "Game" << setw(20) << "Earnings" << setw(10) << "Players" << setw(15) << "Tournaments\n";
	cout << "\n__________________________________________________________________________\n";

	return 0;

};

int main() {

	displayHeader();

	//File needs to be in the same folder as this script
	ifstream file("HistoricalEsportData.csv");

	if (!file) {

		cout << "File not Found";
		return -1;
	}

	string currentLine;
	vector<GameRecord> records;

	int loopCount = 0;

	while (std::getline(file, currentLine)) {

		auto splitRecord = splitRecord_withStringStream(currentLine, ',');

		cout << splitRecord[0] << setw(60) << splitRecord[1]
			<< setw(15) << splitRecord[2]
			<< setw(10) << splitRecord[3]
			<< setw(10) << splitRecord[4]
			<< std::endl;

		loopCount++;

		GameRecord currentRecord{

			splitRecord[0],
			splitRecord[1],
			std::stoi(splitRecord[2]), //need to call stoi to convert string to integer
			std::stoi(splitRecord[3]),
			std::stoi(splitRecord[4]),

		};

		records.push_back(currentRecord);
	}


}


