#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){
	int n;
	int chance1; //will be used to generate random times and node breakdown chance
	srand(time(NULL));

	cout << "Enter the number of nodes (stations per lane):" << endl;
	cin >> n;
	cout << endl;

	//creating arrays with node times for each line
	int *line1;
	line1 = new int[n];
	int *line2;
	line2 = new int[n];
	int *line3;
	line3 = new int[n];


	//populating each line with time values
	//populating line 1
	for (int i = 0; i < n; i++){
		chance1 = rand() % 10; //random number between 0 and 10 inclusive
		if (chance1 >= 8){ //20% chance that a node will break down
			line1[i] = 1000000; //this counts as broken node
		}
		else{
			chance1 = rand() % 10 + 1;
			line1[i] = chance1; //random number between 1 and 10 inclusive
		}
	}

	//populating line 2
	for (int i = 0; i < n; i++){
		chance1 = rand() % 10;
		if (chance1 >= 8){
			line2[i] = 1000000; //this counts as broken node
		}
		else{
			chance1 = rand() % 10 + 1;
			line2[i] = chance1; //random number between 1 and 10 inclusive
		}
	}

	//populating line 3
	for (int i = 0; i < n; i++){
		chance1 = rand() % 10;
		if (chance1 >= 8){
			line3[i] = 1000000; //this counts as broken node
		}
		else{
			chance1 = rand() % 10 + 1;
			line3[i] = chance1; //random number between 1 and 10 inclusive
		}
	}

	//printing of all node times for reference
	for (int i = 0; i < n; i++){
		cout << line1[i] << "\t";
	}
	cout << endl;
	for (int i = 0; i < n; i++){
		cout << line2[i] << "\t";
	}
	cout << endl;
	for (int i = 0; i < n; i++){
		cout << line3[i] << "\t";
	}

	cout << endl << endl;
	int mincost=0;

	cout << "Shortest path : " << endl;
	for (int i = 0; i < n; i++){
		if (line1[i] < line2[i] && line1[i] < line3[i]){
			cout << "node " << i + 1 << ": lane 1, time: "<< line1[i] << endl;
			mincost += line1[i];
		}
		if (line2[i] < line1[i] && line2[i] < line3[i]){
			cout << "node " << i + 1 << ": lane 2, time: " << line2[i] << endl;
			mincost += line2[i];
		}
		if (line3[i] < line1[i] && line3[i] < line2[i]){
			cout << "node " << i + 1 << ": lane 3, time: " << line3[i] << endl;
			mincost += line3[i];
		}
		if (line1[i] == line2[i] && line1[i] != 1000000){
			cout << "node " << i + 1 << ": lane 1, time: " << line1[i] << endl;
			mincost += line1[i];
		}
		if (line1[i] == line3[i] && line1[i] != 1000000){
			cout << "node " << i + 1 << ": lane 1, time: " << line1[i] << endl;
			mincost += line1[i];
		}
		if (line2[i] == line3[i] && line2[i] != 1000000){
			cout << "node " << i + 1 << ": lane 1, time: " << line2[i] << endl;
			mincost += line2[i];
		}
	}



	cout << "minimum cost for 1 PC: " << mincost<<endl;

	system("pause");
}