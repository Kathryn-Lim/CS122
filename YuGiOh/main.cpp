/*
Name: Kathryn Lim
CPTS122 SPRING 2020
PA5: Yu Gi Oh Card Game

-all monster card names and details are from db.yugioh-card.com
-templates are implemented when creating Queue and Stack for the cards, though it does not work
*/


#include "Cards.h"
#include "Queue.h"

// main function
int main()
{
	// create a queue of capacity 5
	queue<string> q(5);
	Cards<int> c(1);

	char choice = ' ';

	do {
		choice = menusys(q, c);
	} while (choice != 'n' || choice != 'N');

	system("pause");

	//q.enqueue("a");
	//q.enqueue("b");
	//q.enqueue("c");

	//cout << "Front element is: " << q.peek() << endl;
	//q.dequeue();

	//q.enqueue("d");

	//cout << "Queue size is " << q.size() << endl;

	//q.dequeue();
	//q.dequeue();
	//q.dequeue();

	//if (q.isEmpty())
	//	cout << "Queue Is Empty\n";
	//else
	//	cout << "Queue Is Not Empty\n";

	//return 0;
}

char menusys(queue<string> q, Cards<int> c) {
	int option = NULL;




	//passes the Cards one by on to enqueue, but does not work because cards are not passed on individually
	for(int i = 0; i < 6; ++i){
		q.enqueue(c.setdeets());
	}

	do {
		cout << "\n==========================================================\n";
		cout << "					  YU GI OH Card Game	";
		cout << "\n==========================================================\n";
		cout << "1. Create Players" << endl;
		cout << "2. Add Cards to Player" << endl;
		cout << "3. Trade Cards with another Player" << endl;
		cout << "4. BATTLE!" << endl;
		cout << "5. Quit Game" << endl;
		cout << "Input: ";
		cin >> option;

		switch (option) {
		case 1: q.putcards();
			break;

		default: break;
		}



	} while (option >= 1 && option < 5);

		if (option == 5) {
			return 'n';
		}
}