#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
 
struct Element{
  int ID;
  int count;
};
 
int main()
{
  float phi, epsilon;
  cout << "Enter phi: ";
  cin >> phi;
  cout << "Enter epsilon: ";
  cin >> epsilon;
 
  Element items[(int)ceil(1/epsilon)];
  int len = ceil(1/epsilon);
 
  for(int i = 0; i < len; i++){
	items[i].ID = 0;
	items[i].count = 0;
  }
 
  int n;
  int m = 0;
 
  ifstream ifs;
  ifs.open("/Users/joannewardell/data.txt");
  ifs >> n;
  cout << n << endl;
  while(!ifs.eof()) {
	m++;
 
	bool found = false;
	for(int i = 0; i < len; i++){
  	if(items[i].ID == n){
    	items[i].count++;
    	found = true;
    	break;
  	}
	}
 
	bool full = true;
	int index;
	if(!found){
  	for(int i = 0; i < len; i++){
    	if(items[i].count == 0){
      	full = false;
      	index = i;
    	}
  	}
 
  	if(!full){
    	items[index].ID = n;
    	items[index].count = 1;
  	}
  	else{
    	for(int i = 0; i < len; i++)
          if(items[i].count > 0)
            items[i].count--;
  	}
	}
 
	ifs >> n;
  }
 
  cout << "\nNumbers:\n";
  int low = (phi - epsilon) * m;
  cout << "low: " << low << endl;
  for(int i = 0; i < len; i++)
	if(items[i].count >= low)
  	cout << items[i].ID << endl;
 
  cout << "\nArray:\n";
  for(int i = 0; i < len; i++)
	cout << items[i].ID << "   " << items[i].count << endl;
 
  ifs.close();
  return 0;
}

