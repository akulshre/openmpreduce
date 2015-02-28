#include <iostream>
#include <vector>
#include <string.h>
#include<stdlib.h>
#include<stdio.h>
#include <dirent.h>
#include<fstream>
using namespace std;

typedef struct data
{
	int key;
	string word;
}DATA;



class mapReduce{
	public:	
	mapReduce();	
	void fileRead(string filename);
	void populateFileVector();
	vector<DATA> readQ;
	vector<DATA> fileNameQ;
	void printQ(vector<DATA> printQueue);

};


