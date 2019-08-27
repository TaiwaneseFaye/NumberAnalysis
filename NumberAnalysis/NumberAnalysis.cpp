//Chris Sun
//COSC 1320 C++
//Number analysis program to ask user for a file name and read in the numbers, then outputs to the user the max, min, sum, and average of the numbers
#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

double getHighest(const double[], int);
double getLowest(const double[], int);
double getTotal(const double[], int);
double getAverage(const double[], int);

int main()
{

	//variables
	ifstream inputFile;
	string filename;
	double highest, lowest, total, average;
	int count = 0;
	const int ARRAY_SIZE = 50;
	double numbers[ARRAY_SIZE];			//initilizing the array

	//asking the user for the filename
	cout << "Enter filename: " << endl;
	cin >> filename;

	//opening the file
	inputFile.open(filename);

	//reading the numbers from the file into an array
	if (inputFile) {
		while (count < ARRAY_SIZE && inputFile >> numbers[count]) {
			count++;
		}
		inputFile.close();
	}
	else {
		cout << "Can't open the file. \n\n";
	}
	
	//outputs to the user the highest number
	highest = getHighest(numbers, count);
	cout << "The highest number is: " << highest << endl;

	//outputs to the user the lowest number
	lowest = getLowest(numbers, count);
	cout << "The lowest number is: " << lowest << endl;

	//outputs the total to the numbers in the array to the user
	total = getTotal(numbers, count);
	cout << "The total is: " << total << endl;

	//outputs the average to the user
	average = getAverage(numbers, count);
	cout << fixed << setprecision(2) << "The average is: " << average << endl;


	return 0;
}

//function for getting the highest number in the array
double getHighest(const double numbers[], int count) {
	double highest;
	highest = numbers[0];	//setting the first number to be compared against the rest of the elements in the array for the larger number
	for (int size = 1; size < count; size++) {		//loop to check each element for which number is higher
		if (numbers[size] > highest)
			highest = numbers[size];
	}
	return highest;			//returns the highest number
}

//function for getting the lowest number in the array
double getLowest(const double numbers[], int count) {
	double lowest;
	lowest = numbers[0];	//setting the first number to be compared against the rest to see which is lowest
	for (int size = 1; size < count; size++) {		//loop to check each element for which number is lowest
		if (numbers[size] < lowest)
			lowest = numbers[size];
	}
	return lowest;			//returns the lowest number
}

//function for getting the total of all the numbers in the array
double getTotal(const double numbers[], int count) {
	double total = 0;

	for (int size = 0; size < count; size++) 	//loop to iterage through each element
		total += numbers[size];						//adds the numbers together from each array element
	
	return total;										//returns the total
}

//function for getting the average of the numbers from the file
double getAverage(const double numbers[], int count) {
	double average = 0;
	double total = getTotal(numbers, count);	//gets the total of the numbers from the getTotal function
	average = total / count;					//calculating the average
	return average;								//returns the average
}