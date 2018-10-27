#include <iostream>
#include "sha256.h"
#include "timer.h"
#include <map>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

struct Element{
	string ID;
	int count;
};

int main()
{
	Timer timer;
	unsigned long start = timer.get_time();
	float phi, epsilon;
	cout << "Enter phi: ";
	cin >> phi;
	cout << "Enter epsilon: ";
	cin >> epsilon;

	Element items[(int)ceil(1/epsilon)];
	int len = ceil(1/epsilon);

	//initialize array to empty key value pairs
	for(int i = 0; i < len; i++){
		items[i].ID = "";
		items[i].count = 0;
	}


	map<int, string> addresses;


	string n;
	int m = 0;
	string path = "/Users/joannewardell/Desktop/joanne/code/misc/etc/recreation/forfun/ips.txt";

	ifstream ifs;
	ifs.open(path);
	ifs >> n;
	cout << n << endl;
	while(!ifs.eof()) {
		m++;
		
		//if map is full, perform decriment
		if(addresses.size() == len) {
			map<string, int>::iterator it;
			for(it = symbolTable.begin(); it != symbolTable.end(); it++) {
				it -> second--;
			}

		}

		//insert hash data and insert into map with initial count 0
		//		if the item is not found in the list and the map has room
		if(addresses.size() < len) {
			addresses.insert(sha256(n), 0);
		}


		ifs >> n;
	}

	int low = (phi - epsilon) * m;
	cout << "low: " << low << endl;
	puts("\nheavy hitters\n");

	map<string, int>::iterator it;
	for(it = symbolTable.begin(); it != symbolTable.end(); it++) {
		it -> second--;
	}

	for(int i = 0; i < len; i++)
		if(items[i].count >= low)
			cout << items[i].ID << "\t\t" << items[i].count << endl;

	cout << "\nArray:\n";
	ifs.close();
	unsigned long end = timer.get_time();
	unsigned long total = end - start;
	printf("\n%s%lu%s\n", "total time: ", total, "ms");
	return 0;
}

