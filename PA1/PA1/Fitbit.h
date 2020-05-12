
#ifndef FITBIT_H
#define FITBIT_H

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <math.h>

#define ARRAY 1441
#define COLUMN 7

typedef enum sleep {
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
}Sleep;

typedef struct fitbit {
	char patient[10];
	char minute[9];
	double calories;
	double distance;
	 int floors;
	 int heartRate;
	 int steps;
	Sleep sleepLevel;
}FitbitData;


//traverses list, returns sleep range with poor sleep levels
void sleep_range(char *start, char *end, FitbitData *rec[]);

//calculates total calories
double total_calories(FitbitData *rec[]);

//calculates total distance
double total_distance(FitbitData *rec[]);

//calculates total floors
int total_floors(FitbitData *rec[]);

//calculates total steps
int total_steps(FitbitData *rec[]);

//calculates average heart rate
double avg_hr(FitbitData *rec[]);

//calculates max steps taken in 24 hrs, returns the minute which has the max steps
int max_steps(FitbitData *rec[]);

//converts char to string
char *conv(char *str);

//function to write to the array of FItbitData structs
void write(FILE *input, FitbitData *rec[]);

//initiaizes csv file, writes to Result.csv file.
void execute();




#endif