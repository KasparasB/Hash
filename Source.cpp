#include <C:\Users\Kasparas\source\repos\Hash\Hash\Header.h>

/*
string encryptDecrypt(string toEncrypt, int &cycle, string word) {
	char key[100]; 

	//string key2 = "uQvWoEzRsTjYgU4IkOqP2AfSrDtF7GaHiJbK8L6Z3xyCmVhBnN9Mwxc1dp5el";
	for (int i = 0; i < word.length(); i++)
	{
		key[i] = word[i] * pow(key[i], 5);
	}
	string output = toEncrypt;
	output[0] = word[0] ^ (toEncrypt[0]+1);
	output[1] = output[0] ^ (toEncrypt[1]+1);

	for (int i = cycle; i < toEncrypt.size(); i++)
	{
		output[i] = toEncrypt[i] ^ key[i-1] ^ key[i-2] ^ word[i] * 15;
		cycle++;
	}

	return output;
}

void vectorToChar(vector<int> &values, vector<string> word)
{
	string tmp1 = word[0];
	int temp;
	string tmpReversed;
	int cycle = 2;
	int gg = 456;

	if (word[0].length() == 1 || word[0].length() == 2)
	{
		string temporary;
		temporary = word[0][0] ^ (char)gg;
		word.push_back(temporary);
	}
	std::reverse(word[0].begin(), word[0].end());
	tmpReversed = word[0];

	word.push_back(tmpReversed);
	word[0] = tmp1;

	string tmp2 = encryptDecrypt(tmp1, cycle, tmpReversed);
	word.push_back(tmp2);

	int ciklas = 3;
	while (word[ciklas-1].length()<60)
	{
		std::reverse(word[ciklas-1].begin(), word[ciklas-1].end());
		string key1 = word[ciklas-1];
		tmp2 = tmp2 + encryptDecrypt(word[ciklas-2], cycle,key1);
		word.push_back(tmp2);
		ciklas++;
	}
	tmp1 = tmp2;
	//cout << tmp2 << endl;
	for (int i = 0; i< tmp1.length(); i++)
	{
		temp = (int)tmp1[i];
		if (temp < 0) temp *= -1;
		values.push_back(temp * (pow(i,3)));
	}

}

void intToHex(vector<int> &intValues, vector<string> &hexValues)
{
	char hexNumber;
	
	int num;


		for (int i = 0; i < intValues.size(); i++)
		{
				hexValues.push_back("");
				num = intValues[i];
				num /= intValues.size() * 3 ;
				if (num < 0) num *= -1;
				while (num != 0)
				{
					int temp = 0;
					temp = num % 16;

					if (temp < 10)
					{
						hexNumber = temp + 48;
					}
					else
					{
						hexNumber = temp + 55;
					}
					hexValues[i] += hexNumber;
					num /= 16;
				}
		}
}

int sumOfNumbers(int numbers)
{
	int c = 0;
	int sum = 0;
	while (numbers != 0)
	{
		c = numbers % 10;
		sum += c;
		numbers /= 10;
	}
	return sum;
}

void charHextoStringHex(vector<string> values, string &hashedWord)
{
	int x = 0;
	
	for (int i = 10; i < 60; i++)
	{
		if (x >= 100) break;
		if (values[i] == "") continue;
		if (values[i].length() == 1)
		{
			hashedWord += values[i][0];
			x++;
		}
		else
		{
		for (int j = 0; j < values[i].length()-1; j++)
		{
			if (x >= 100) break;
			hashedWord += values[i][j];
			x++;
		}
		}
	}
	
}

void input(string &decision, int &file)
{
	char symbol;
	cout << "Zodzio irasymas - R. Zodzio nuskaitymas is failo - F." << endl;
	cin >> symbol;

	switch (symbol)
	{
		case 'R':
			cin >> decision;
			file = 0;
			break;
		case 'F':
			cout << "Iveskite failo pavadinima!" << endl;
			cin >> decision;
			file = 1;
			break;
		default:
			cout << "Error. Try again!" << endl;
			break;
	}
}
*/


int main(int argc, char* argv[])
{
	//string decision = "";
	int file = 0;
	//cout << argv[1] << endl;
	//string temp = argv[1];
	string temp = "simb1.txt";
	vector<int> values(100,0);
	vector<string> word;
	vector<char> word2;
	vector<string> hexValues;
	string hashedWord = "";
	
	read(temp, file);
	if (file != 2)
	{
		word.push_back(temp);
		vectorToChar(values, word);
		intToHex(values, hexValues);
		charHextoStringHex(hexValues, hashedWord);
		cout << hashedWord << endl;
	}
	system("PAUSE");
}