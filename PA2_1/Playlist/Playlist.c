#include "Playlist.h"

//TO DO: pass newly made Record from load() into insertFront(), newnode->data = ndata <-from load() -- changed newnode->data in Record *data ptr. so it can point to new record struct
//UPDATE HEAD POINTER GLOBALLY  -- return head ptr to main so the head in main is updated globally?? --find out more about using double head ptr???
//how to return multiple cases of a node* function to multiple pointers? --(ARRAY OF POINTERS?)


int isEmpty(node **head) {
	int status = 0;

	if (head == NULL)
		status = 1;

	return status;
}

node *search(node **head, char* name) {
	
	node *curr = *head;
	node *target = NULL;


	while (strcmp((curr->data->title), name)!=0) {
		curr = curr->next;
	}
	target = &(curr->data);

	return target;

}

node *makenode(Record *ndata) {

	node *newnode = (node*)malloc(sizeof(node));

	if (!newnode) {
		newnode->data = ndata;
		newnode->next = NULL;
		newnode->prev = NULL;
	}

	return newnode;
}

/*///////////////////////////////////////////////////////////////////
//Pre: Reference to head pointer, a Record type struct///////////////
//Returns bool type if new node is created.//////////////////////////
//Creates a new node and inserts it in the list given record struct//
///////////////////////////////////////////////////////////////////*/

node** insertFront(node **head, node *newnode) {
	
	
	node *previous, *temp = NULL;

	if (isEmpty(head)) {
		newnode->next = NULL;
		newnode->prev = NULL;
		head = newnode;
		return newnode;
	}
	
	node *curr = *head;

	//adds newnode to head of list
	if ((newnode->data->title) <=(curr->data->title)) {
		newnode->next = curr;
		newnode->prev = NULL;
		**head = *newnode;
	}
	else {		//adds to middle/end of list
		temp = curr->next;
		previous = curr;
		while ((temp != NULL) && ((temp->data->title) < (newnode->data->title))) {
			previous = temp;
			temp = temp->next;
		}

		newnode->next = temp;
		previous->next = newnode;
		newnode->prev = previous;
	}

	if (newnode) {
		printf("\nNode created! \n");
		return head;
	}
	else {
		printf("\n ERROR! node not created! \n");
		return head;
	}

}

//puts data inside a record struct, then insert the freshly minted record inside the insertfront func
node *load(node **head, FILE *input) {
	char datain[999] = { 0 };
	char *token = "\0";
	char *temp = "\0";
	char strin[999] = { 0 };
	node *newnode = NULL;

	Record *ndata = (Record*)malloc(sizeof(Record));



	//if movie playlist.csv cannot be opened
	if (!input) {
		printf("\n Error! Movie list cannot be loaded\n");
		return NULL;
	}

	//begin loading data from .csv into the node, initializes all values as 0
	while (fgets(datain, sizeof(datain), input) && (!feof(input))) {
		for (int i = 0; i < 999; i++) {
			ndata->title[i] = '\0';
			ndata->director[i] = '\0';
			ndata->desc[i] = '\0';
			ndata->genre[i] = '\0';
		}
		ndata->time.hours = 0;
		ndata->time.minutes = 0;
		ndata->year = 0;
		ndata->played = 0;
		ndata->rating = 0;


			//identifier for first character in element
			temp = &(datain[0]);

			//creates comma token to seperate values
			//copies title field
			token = strtok(temp, ",");
			if (token == NULL) {
				strcpy(ndata->title, "Unknown Title");
			}
			else {
				strcpy(ndata->title, token);
				token = strtok(temp, ",");
			}

			//copies director field
			token = strtok(temp, ",");
			if (token == NULL) {
				strcpy(ndata->director, "Unknown Director");
			}
			else {
				strcpy(ndata->director, token);
			}

			//copies description field
			token = strtok(temp, ",");
			if (token == NULL) {
				strcpy(ndata->desc, "Unknown Description");
			}
			else {
				strcpy(ndata->desc, token);
			}

			//copies genre field
			token = strtok(temp, ",");
			if (token == NULL) {
				strcpy(ndata->genre, "Unknown Genre");
			}
			else {
				strcpy(ndata->genre, token);
			}

			//copies  hours value
			token = strtok(temp, ":");
			if (token == NULL) {
				ndata->time.hours = 0;
			}
			else {
				ndata->time.hours = atoi(token);
			}

			//copies minutes value
			token = strtok(temp, ",");
			if (token == NULL) {
				ndata->time.minutes = 0;
			}
			else {
				ndata->time.minutes = atoi(token);
			}

			//copies year field
			token = strtok(temp, ",");
			if (token == NULL) {
				ndata->year = 0;
			}
			else {
				ndata->year = atoi(token);
			}

			//copies times played field
			token = strtok(temp, ",");
			if (token == NULL) {
				ndata->played = 0;
			}
			else {
				ndata->played = atoi(token);
			}

			//copies rating field
			token = strtok(temp, ",");
			if (token == NULL) {
				ndata->rating = 0;
			}
			else {
				ndata->rating = atoi(token);
			}

	}

	//passes record to makenode, then assigns it to newnode
	newnode = makenode(ndata);

	head=insertFront(head, newnode);

		free(ndata);
		if (ndata) {
			printf("Loading successful!\n");
		}
		else {
			printf("Loading UNSUCCESSFUL\n");
		}

		return newnode;
}



//writes all current records to .csv file
void store(node **head, FILE *input, Record *datain) {
	

	if (!input) {
		printf("ERROR! Could not open file!\n");
		return;
	}

	fclose(input);
	input = fopen("movieListnew.csv", "w");
	node *curr = head;
	//stores data from list into .csv file
	while (datain != NULL) {
		fprintf(input, "%s,", datain->title);
		fprintf(input, "%s,", datain->director);
		fprintf(input, "%s,", datain->desc);
		fprintf(input, "%s,", datain->genre);
		fprintf(input, "%d:", datain->time.hours);
		fprintf(input, "%d,", datain->time.minutes);
		fprintf(input, "%d,", datain->year);
		fprintf(input, "%d,", datain->played);
		fprintf(input, "%d,", datain->rating);

		curr = curr->next;

		//deletes previous nodes from current pointer
		if (curr) {
			free(curr->prev);
		}
	}

	//updates *input (overwrites)
	fclose(input);
	input = fopen("movieListnew.csv", "r");

}

node *displayall(int direction, node *list) {
	node*curr = NULL;
	int i = 0;
	int year = 0;
	char director[50] = "";

	curr = list;

	//this displays all records
	if (direction == 1) {
		printf("Printing all records...\n");
		while (curr != NULL) {
			printf("\nTitle: %s", curr->data->title);
			printf("\nDirector: %s", curr->data->director);
			printf("\nDescription: %s", curr->data->desc);
			printf("\nGenre: %s", curr->data->genre);
			printf("\nRunning Time: %d:%d", curr->data->time.hours, curr->data->time.minutes);
			printf("\nYear: %d", curr->data->year);
			printf("\nTimes Played: %d", curr->data->played);
			printf("\nRating: %d", curr->data->rating);

			curr = curr->next;
		}
	}
	else if (direction == 2) {	//this displays all records matched by year
		printf("Which year would you like to search for?: ");
		scanf("%d", year);

		while (curr != NULL) {
			if (year != curr->data->year) {
				curr = curr->next;
			}
			else if (curr->next == NULL && year != curr->data->year) {
				printf("\nYear not found!\n");
				return;
			}
			else {
				printf("\nTitle: %s", curr->data->title);
				printf("\nDirector: %s", curr->data->director);
				printf("\nDescription: %s", curr->data->desc);
				printf("\nGenre: %s", curr->data->genre);
				printf("\nRunning Time: %d:%d", curr->data->time.hours, curr->data->time.minutes);
				printf("\nYear: %d", curr->data->year);
				printf("\nTimes Played: %d", curr->data->played);
				printf("\nRating: %d", curr->data->rating);
			}
		}

	}
	else if (direction == 3) {	//this displays all records matched by director
		printf("Which director would you like to search for? \n");
		fgets(director, sizeof(director), stdin);

		while (curr != NULL) {
			if (strcmp(director, curr->data->director) != 0) {
				curr = curr->next;
			}
			else if (curr->next == NULL && (strcmp(director, curr->data->director) != 0)) {
				printf("\nDirector not found!\n");
				return;
			}
			else {
				printf("\nTitle: %s", curr->data->title);
				printf("\nDirector: %s", curr->data->director);
				printf("\nDescription: %s", curr->data->desc);
				printf("\nGenre: %s", curr->data->genre);
				printf("\nRunning Time: %d:%d", curr->data->time.hours, curr->data->time.minutes);
				printf("\nYear: %d", curr->data->year);
				printf("\nTimes Played: %d", curr->data->played);
				printf("\nRating: %d", curr->data->rating);

			}
		}
		return curr;
	}
}




//displays all records in file
void display(node **head) {
	int choice = 0;
	char a= "";
	int direction = 0;

	if (isEmpty(head)) {
		printf("Your list is empty!\n");
		return;
	}

	node *curr = *head;

	do {
		printf("\n1. Print all movies\n");
		printf("2.Print all records that match a director\n");
		printf("3. Print all records that match a year\n");

		printf("Enter choice: ");
		scanf("%d", choice);

		if (choice < 1 || choice >3) {
			printf("Invalid choice! Try again? y/n \n ");
			scanf("%c", a);
			system("cls");
		}


	} while (choice >= 1 && choice <= 3 && a!='n');	
	
	if (a == 'n') {
			return;
		}

	switch (choice) {
	case 1: direction = 1;
			displayall(direction,curr);
		break;

	case 2: direction = 3;
		displayall(direction, curr);
		break;

	case 3: direction = 2;
			displayall(direction,curr);

	default: break;
			
	}


		
}




//finds record in list via "director" field, can modify all elements in the record
void edit(node **head) {
	char director[40] = "";
	const int direction = 3;
	node *curr = NULL;
	node *target = NULL;
	int i = 1;
	int choice = 0;

	char buffer[50] = "";
	
	curr = *head;

	do {

		if (isEmpty(head)) {
			printf("List is Empty!\n");
			return;
		}

		target = displayall(direction, curr);


		if (!target) {
			printf("\nDirector not found!\n");
			return;
		}
	

		printf("Which field do you want to edit? \n");
		printf("1. Title 2. Director 3. Description 4. Genre \n5. Running Time 6. Year 7. Played 8. Rating 9.Quit updating / Next record\n");

		switch (choice) {
		case 1: printf("Update movie title: ");
			getchar();
			fgets(buffer, sizeof(buffer), stdin);
			strcpy((target->data->title), buffer);
			break;

		case 2: printf("Update director: ");
			getchar();
			fgets(buffer, sizeof(buffer), stdin);
			strcpy((target->data->director), buffer);
			break;

		case 3: printf("Update description: ");
			getchar();
			fgets(buffer, sizeof(buffer), stdin);
			strcpy((target->data->desc), buffer);
			break;

		case 4: printf("Update genre: ");
			getchar();
			fgets(buffer, sizeof(buffer), stdin);
			strcpy((target->data->genre), buffer);
			break;

		case 5: printf("Update running time: ");
			getchar();
			printf("\nEnter hours: ");
			scanf("%d", &target->data->time.hours);
			printf("\nEnter minutes: ");
			scanf("%d", &target->data->time.minutes);
			break;
		
		case 6:printf("Update year: ");
			getchar();
			scanf("%d", &target->data->year);
			break;

		case 7:printf("Update times played: ");
			getchar();
			scanf("%d", &target->data->played);
			break;

		case 8: rate(curr);
			break;

		case 9: break;

		}
	} while (curr != NULL && choice!=9);
}

void rate(node **head) {
	node *curr = head;
	char buffer[40] = "";
	node *target = 0;
	const int direction = 3;

	if (isEmpty(head)) {
		printf("List is Empty!\n");
		return;
	}

	printf("\nUpdating movie ratings...\n");
	printf("Search movie by title: ");
	fgets(buffer, sizeof(buffer), stdin);

	target = search(curr, buffer);

	printf("\nCurrent rating is: %d", target->data->rating);
	printf("\nEnter new rating: ");
	scanf("%d", target->data->rating);

}




//display contents of the record for a short period of time, then show next record on the list until eof
void play(node *head) {
	node* curr = head;

	if (isEmpty(head)) {
		printf("ERROR! List is not loaded!\n");
		return;
	}

	printf("\nTitle: %s", curr->data->title);
	printf("\nDirector: %s", curr->data->director);
	printf("\nDescription: %s", curr->data->desc);
	printf("\nGenre: %s", curr->data->genre);
	printf("\nRunning Time: %d:%d", curr->data->time.hours, curr->data->time.minutes);
	printf("\nYear: %d", curr->data->year);
	(curr->data->played)++;
	printf("\nTimes Played: %d", curr->data->played);
	printf("\nRating: %d", curr->data->rating);

	curr = curr->next;

	//prints remaining songs with pause of 2 seconds in between 
	while (curr != NULL) {
		time_t pause = time(NULL) + 2;
		while (pause >= time(NULL));
		system("cls");

		printf("\nTitle: %s", curr->data->title);
		printf("\nDirector: %s", curr->data->director);
		printf("\nDescription: %s", curr->data->desc);
		printf("\nGenre: %s", curr->data->genre);
		printf("\nRunning Time: %d:%d", curr->data->time.hours, curr->data->time.minutes);
		printf("\nYear: %d", curr->data->year);
		(curr->data->played)++;
		printf("\nTimes Played: %d", curr->data->played);
		printf("\nRating: %d", curr->data->rating);

		curr = curr->next;
	}

}



void exit() {
		printf("Exiting....\n");
		system("pause");
		return;
}



void menu() {
	int choice = 0;
	node **head = 0;
	int status = 0;

	FILE *input = fopen("moviePlayList.csv", "r");	//initializes the .csv file for read mode

	if (!input) {
		printf("\nERROR! File cannot be opened!\n");
		return;
	}

	node *newnode = NULL;

	do {

		printf("===========================================\n");
		printf("                MAIN MENU                  \n");
		printf("===========================================\n");
		printf(" 1. Load\n");
		printf(" 2. Store\n");
		printf(" 3. Display\n");
		printf(" 4. Insert\n");
		printf(" 5. Delete\n");
		printf(" 6. Edit\n");
		printf(" 7. Sort\n");
		printf(" 8. Rate\n");
		printf(" 9. Play\n");
		printf(" 10. Shuffle\n");
		printf(" 11. Exit\n");
		printf("============================================\n\n");



		printf("Input selection: ");
		scanf("%d", &choice);
		system("cls");

		if (choice < 1 || choice > 11) {
			printf("\nINVALID CHOICE! TRY AGAIN! \n\n");
		}

		switch (choice) {
		case 1: newnode=load(head, input);
			break;

		case 2: store(head,input, (newnode->data));
			break;

		case 3: display(head);
			break;

		case 4: //insert();
			printf("Not implemented yet :P\n");
			break;

		case 5: //del();
			printf("Not implemented yet :P\n");
			break;

		case 6: edit(head);
			break;

		case 7: //sort();
			printf("Not implemented yet :P\n");
			break;

		case 8: rate(head);
			break;

		case 9: play(head);
			break;

		case 10: //shuffle();
			printf("Not implemented yet :P\n");
			break;

		case 11: //store(head, input, (newnode->data));
			exit();
			break;

		default: break;

		}

	} while (choice != 11);


}
