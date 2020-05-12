#ifndef SAVINGS_H
#define SAVINGS_H

#include "Account.h"

class Savings : public Account {
	bool status;	//true for active, false for inactive

public:
	//Savings(bool stats = true) : status(stats) {};
	Savings() : Account() {
		status = false;
	}

	~Savings();

	Savings(double b, int d, int w, double i, double sc, bool st) : Account(b,d,w,i,sc) {
		setbalance(b);
		setdeposit(d);
		setwithdrawal(w);
		setinterest(i);
		setservice_charges(sc);
		setstatus(st);
	}

	void setstatus(bool);

	bool getstatus();

	//checks balance, sets status
	void checkbalance();

	//checks if status==true, then calls withdraw()
	void withdraw(double);

	//if account is inactive & cash_in brings balance >=25, change status to active
	void deposit(double);

	//checks number of withdrawals, if withdrawals for a month is >4, servive charge +1 for each withdrawal.
	void monthlyProc();

};



#endif
