#include "Header.h"

int main(int argc, char* argv[])
{
	//string decision = "";
	int file = 0;
	//cout << argv[1] << endl;
	string temp = argv[1];
	//string temp = "100k2.txt";
	vector<int> values;
	vector<string> word;
	vector<char> word2;
	vector<string> hexValues;
	string hashedWord = "";
	read(temp, file);
	Stopwatch a;
	if (file != 2)
	{	
		word.push_back(temp);
		a.Start();
		vectorToChar(values, word);
		intToHex(values, hexValues);
		charHextoStringHex(hexValues, hashedWord);
		a.End("Trukme: ");
		cout << hashedWord << endl;
	}
	system("PAUSE");
}
