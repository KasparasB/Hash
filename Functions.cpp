#include "Header.h"

std::ifstream in;
std::ofstream out;

void Stopwatch::Start() {
	start = std::chrono::high_resolution_clock::now();
}

void Stopwatch::End(string action) {
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	cout << action << std::fixed << std::setprecision(3) << duration.count() << "s" << endl;
}


string encryptDecrypt(string toEncrypt, int &cycle, string word) {
	int keyLength = word.length();
	//unsigned char key[10000000];

	vector<char> key(keyLength);

	//string key2 = "uQvWoEzRsTjYgU4IkOqP2AfSrDtF7GaHiJbK8L6Z3xyCmVhBnN9Mwxc1dp5el";
	key[0] = word[0] ^ '}' ^ '_';
	for (int i = 1; i < word.length()-1; i++)
	{
		key[i] = word[i-1] * 3;
	}
	string output = toEncrypt;
	output[0] = word[0] ^ (toEncrypt[0] + 1);
	output[1] = output[0] ^ (toEncrypt[1] + 1);

	for (int i = cycle; i < toEncrypt.size(); i++)
	{
		output[i] = toEncrypt[i] ^ key[i - 1] ^ key[i - 2] ^ word[i] * 15;
		cycle++;
	}
	key.clear();
	key.shrink_to_fit();
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
	std::reverse(word.begin(), word.end());
	tmpReversed = word[0];

	word.push_back(tmpReversed);
	word[0] = tmp1;

	string tmp2 = encryptDecrypt(tmp1, cycle, tmpReversed);
	word.push_back(tmp2);

	int ciklas = 3;
	while (true)
	{
		if ((word[ciklas - 1].length() > 64) && ciklas > 7)break;
		std::reverse(word[ciklas - 1].begin(), word[ciklas - 1].end());
		string key1 = word[ciklas - 1];
		tmp2 = tmp2 + encryptDecrypt(word[ciklas - 2], cycle, key1);
		word.push_back(tmp2);
		ciklas++;
		//cout << ciklas << endl;
	}
	tmp1 = tmp2;
	//cout << tmp2 << endl;
	for (int i = 0; i < tmp1.length(); i++)
	{
		temp = (int)tmp1[i];
		if (temp < 0) temp *= -1;
		values.push_back(temp * (i*(i+i)));
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
		num /= intValues.size() * 3;
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
	in.close();
	out.close();
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
	string temp = "";
	for (int i = 0; i < values.size(); i++)
	{
		//if (x >= 63) break;
		if (values[i] == "")
		{
			continue;
		}
		
		if (values[i].length() == 1)
		{
			hashedWord += values[i][0];
			x++;
		}
		else
		{
			for (int j = 0; j < values[i].length() - 1; j++)
			{
				//if (x >= 63) break;
				hashedWord += values[i][j];
				x++;
			}
		}
	}
	std::reverse(hashedWord.begin(), hashedWord.end());
	for (int i = 0; i < 64; i++)
	{
		temp += hashedWord[i];
	}

	hashedWord = temp;


}

void read(string &temp, int &file)
{
	vector<string> word;
	int argLength = temp.length();
	vector<int> values(1000000,0);
	

	string tmp = "";

	if (temp[argLength - 1] == 't' && temp[argLength - 2] == 'x' && temp[argLength - 3] == 't' && temp[argLength - 4] == '.')
	{
		file = 1;
		
		in.open(temp);
		//temp = "";
		while (in.peek() != EOF)
		{
			in >> tmp;
			word.push_back(tmp);
		}

		int sk = 0;
		// 1 tikrint ar yra tik vienas  normalus žodis
		// 2 tikrint ar yra tik vienas simbolis 
		// 3 tikrint ar yra normalus zodziai
		// 4 
		//sukurti kazka, kas tikrintu ar yra zodziai "Nerastas failas arba faile nera zodziu"
		if (word.size() > 1)
		{
			for (int i = 0; i < word.size() - 1; i++)
			{

				if (word[i].length() == 1)
				{
					sk = (int)word[i][0];
					values[0] += sk;
				}
				else
				{
					for (int j = 0; j < word[i].length() - 1; j++)
					{
						sk = (int)word[i][j];
						values[j] += sk;
					}
				}


			}
		}
		else
		{
			if (word.size() == 1)
			{
				tmp = "";
				temp = word[0];
			}
			else
			{
				if((word.size() > 1))
					for (int i = 0; i < values.size() - 1; i++) temp += (char)values[i];
				else
				{
					file = 2;
					cout << "Neteisingas failas arba zodziu/ simboliu faile nera." << endl;
				}
			}
			
		}
		word.clear();
		word.shrink_to_fit();
		
		values.clear();
		values.shrink_to_fit();
		values.resize(0);
	}
}