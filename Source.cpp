//Reading rows of data from a file (spreadsheet), storing them in an array of struct objects, and doing some data analytics

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct BreastCancerRecord {

	int age;
	double BMI;
	double insulin;
	bool classification;

};

std::vector<std::string> splitRecord_withStringStream(const std::string& record, char delimiter) {

	std::vector<std::string > fields;
	std::stringstream ss(record);
	std::string field;

	while (std::getline(ss, field, delimiter)) {
		fields.push_back(field);
	}
	return fields;
}

int main() {
	
	std::ifstream inputFile("C://Users//A00593870//Documents//DataSet//dataR2.csv");

	if (!inputFile) {

		std::cout << "File Not Found.";
		return -1;
	}

	std::string currentLine;

	while (std::getline(inputFile, currentLine)) {
		std::cout << currentLine << "\n\n\n";

		auto splitRecord = splitRecord_withStringStream(currentLine, '.');

		BreastCancerRecord currentRecord = {

			std::stoi(splitRecord[0]),
			std::stoi(splitRecord[1]),
			std::stoi(splitRecord[2]),
			std::stoi(splitRecord[3]),

		};

		int a;

	}
	


}

//Different way of printing a file into the output
/*
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//Currently commented out, use later

struct HistoricalEsportsData {

	int date;
	string game;
	double earnings;
	int players;
	int tournaments;

};


int main() {

	char chars{};
	ifstream File;
	File.open("C://Users//A00593870//Downloads//HistoricalEsportData.csv");

	while (!File.eof()) { 
		//eof stands for "End of File"

		cout << chars;
		File.get(chars);

	}

}
*/
