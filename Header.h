#pragma once

#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <assert.h>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <iomanip>

using std::string;
using std::cout;
using std::endl;
using std::to_string;
using std::cin;
using std::vector;

struct Stopwatch 
{
	std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
	std::chrono::duration<float> duration;

	void Start();
	void End(string operation);
};

string encryptDecrypt(string toEncrypt, int &cycle, string word);
void vectorToChar(vector<int> &values, vector<string> word);
void intToHex(vector<int> &intValues, vector<string> &hexValues);
int sumOfNumbers(int numbers);
void charHextoStringHex(vector<string> values, string &hashedWord);
void input(string &decision, int &file);
void read(string &temp, int &file);
