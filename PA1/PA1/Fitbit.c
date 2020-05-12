#include "Fitbit.h"


//traverses list, returns sleep range with poor sleep levels
void sleep_range(char *start, char *end, FitbitData *rec[]) {
	int i, j = 0;
	int max = 0;
	int prev = 0;

	for (i = 0; i < ARRAY; i++) {
		if ((rec[i]->sleepLevel > ASLEEP) && j < 1) {
			j = 1;
			max = rec[i]->sleepLevel;
		}
		else if (rec[i]->sleepLevel > ASLEEP && j > 0) {
			j++;
			max += rec[i]->sleepLevel;
		}
		else if (rec[i]->sleepLevel <= ASLEEP && j > 0) {
			if (max >= prev) {
				prev = max;
				strcpy(start, rec[i - (j + 1)]->minute);
				strcpy(end, rec[i - 1]->minute);
			}
			max = 0;
			j = 0;
		}

	}

}

//calculates total calories
double total_calories(FitbitData *rec[]) {
	double sum = 0;
	int i = 0;
	for (i = 0; i < ARRAY; i++)
		sum += rec[i]->calories;

	return sum;
}

//calculates total distance
double total_distance(FitbitData *rec[]) {
	double sum = 0;
	int i = 0;
	for (i = 0; i < ARRAY; i++)
		sum += rec[i]->distance;

	return sum;
}

//calculates total floors
int total_floors(FitbitData *rec[]) {
	int sum = 0;
	int i = 0;
	for (i = 0; i < ARRAY; i++)
		sum += rec[i]->floors;

	return sum;
}

//calculates total steps
int total_steps(FitbitData *rec[]) {
	int sum = 0;
	int i = 0;
	for (i = 0; i < ARRAY; i++)
		sum += rec[i]->steps;

	return sum;
}

//calculates average heart rate
double avg_hr(FitbitData *rec[]) {
	double sum = 0;
	int i = 0;
	double avg;

	for (i = 0; i < ARRAY; i++)
		sum += rec[i]->heartRate;

	avg = ((double)sum / (double)i);

	return avg;

}

//calculates max steps taken in 24 hrs, returns the minute which has the max steps
int max_steps(FitbitData *rec[]) {
	int max = 0;
	int i = 0;
	for (i = 0; i < ARRAY; i++) {
		if (max <= rec[i]->steps)
			max = rec[i]->steps;
	}

	return max;
}

//function to write to the array of FItbitData structs
void write(FILE *input, FitbitData *rec[]) {
	char data[999];
	int first = 0;
	char *token;

	while (fgets(data, sizeof(data), input) != NULL) {
		if (first < 0) {
			token = strtok(data, ",");
			token = strtok(NULL, ",");
			token = strtok(NULL, ",");
			token = strtok(NULL, ",");
			token = strtok(NULL, ",");
			token = strtok(NULL, ",");
			token = strtok(NULL, ",");
			first = 7;
		}
		else {
			conv(data);
			token = strtok(data, ",");
			if (token == NULL)
				strcpy(rec[first - COLUMN]->minute, "N/A");
			else
				strcpy(rec[first - COLUMN]->minute, token);

			token = strtok(data, ",");
			if (token == NULL)
				rec[first - COLUMN]->calories = 0.0;
			else
				rec[first - COLUMN]->calories = atof(token);

			token = strtok(data, ",");
			if (token == NULL)
				rec[first - COLUMN]->distance = 0.0;
			else
				rec[first - COLUMN]->distance = atof(token);

			token = strtok(data, ",");
			if (token == NULL)
				rec[first - COLUMN]->floors = 0;
			else
				rec[first - COLUMN]->floors = atoi(token);

			token = strtok(data, ",");
			if (token == NULL)
				rec[first - COLUMN]->heartRate = 0;
			else
				rec[first - COLUMN]->heartRate = atoi(token);

			token = strtok(data, ",");
			if (token == NULL)
				rec[first - COLUMN]->steps = 0;
			else
				rec[first - COLUMN]->steps = atoi(token);

			token = strtok(data, ",");
			if (token == NULL)
				rec[first - COLUMN]->sleepLevel = 0;
			else
				rec[first - COLUMN]->sleepLevel = atoi(token);
		}
		first++;

	}


}

//converts char to string
char *conv(char *str) {
	char temp[100] = { 0 };
	for (int count = 0; str[count] != 0; count++) {
		if (str[count] == ',' && str[count + 1] == ',') {
			for (int size = 0; str[count + size + 1] != 0; size++)
				temp[size] = str[count + size + 1];
			str[count + 1] = '0';
			for (int length = 0; temp[length] != 0; length++)
				str[count + 2 + length] = temp[length];
		}
	}
	return str;
}

//initiaizes csv file, writes to Result.csv file.
void execute() {
	FILE *input;    //FILE pointer for input
	FitbitData **rec = malloc(ARRAY * sizeof(FitbitData*));
	int i = 0;
	int j = 0;
	char* start[10], end[10];

	//**rec=malloc(ARRAY * sizeof(FitbitData*));

	for (i = 0; i < ARRAY; i++) {
		rec[i] =  malloc(ARRAY*sizeof(struct FitbitData*));
		rec[i]->calories = 0;
		rec[i]->distance = 0;
		rec[i]->floors = 0;
		rec[i]->heartRate = 0;
		rec[i]->steps = 0;
		rec[i]->sleepLevel = NONE;
	}

	input = fopen("FitbitData.csv", "r");
	if (input == NULL)
		printf("ERROR! File cannot be opened\n");

	write(input, rec);
	sleep_range(start, end, rec);


	FILE *out;  //FILE pointer for output
	out = fopen("Results.csv", "w");

	fprintf(out, "Total Calories, Total Distance, Total Floors, Total Steps, Avg Heartrate, Max Steps, Sleep\n");
	fprintf(out, "%lf, %lf, %d, %d, %lf, %d, %s - %s", total_calories(rec), total_distance(rec), total_floors(rec), total_steps(rec), avg_hr(rec), max_steps(rec), start, end);


	//close operations
	for (j = 0; j < ARRAY; j++) {
		free(rec[j]);
	}
	free(rec);

	fclose(input);
	fclose(out);
}