#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct duration {
	int hours;
	int minutes;

}Duration;

typedef struct record {
	char title[999];
	char director[999];
	char desc[999];
	char genre[999];
	Duration time;
	int year;
	int played;
	int rating;

}Record;

typedef struct Node {
	Record *data;
	struct Node *next;
	struct Node *prev;
}node;

//checks if list is empty
int isEmpty(node **head);

//searches record by title
node *search(node **head,char* name);

//creates a Node
node *makenode(Record *ndata);


/*///////////////////////////////////////////////////////////////////
//Pre: Reference to head pointer, a Record type struct///////////////
//Returns bool type if new node is created.//////////////////////////
//Creates a new node and inserts it in the list given record struct//
///////////////////////////////////////////////////////////////////*/
node **insertFront(node **head, node* newnode);

//reads all records from file, loads the data into respective fields of node
node *load(node **head,FILE *input);

//writes all current records to .csv file
void store(node **head, FILE *input, Record *datain);

//displays all records in file
node *displayall(int direction, node *list);


//provides menu for display options
void display(node **head);

////insert
//void insert();

////searches by record's director and deletes record
//bool del();

//finds record in list via "director" field, can modify all elements in the record
void edit(node *head);

////sort func
//void sort();

//searches and edits rating field in record struct
void rate(node *head);

//display contects of the record for a short period of time, then show next record on the list until eof
void play(node *head);

////shuffffle
//void shuffle();


//overwrites with most recent file, then exit
void exit();



//displays the main menu
void menu();


#endif