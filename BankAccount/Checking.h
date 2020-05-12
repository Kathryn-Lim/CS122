#ifndef CHECKING_H
#define CHECKING_H

#include "Account.h"
#include "Savings.h"


class Checking : public Account {
	int withdraws;

public:
	//Checking(int w = 0) : withdraws(w) {};
	Checking() : Account() {
		Account a;
		withdraws = 0;
		getbalance();
	}

	~Checking() {};

	Checking(double balance, int deposits, int withdrawal, double interest, double service_charges, int withdraws) : Account(balance, deposits, withdrawal, interest, service_charges) {
		setbalance(balance);
		setdeposit(deposits);
		setwithdrawal(withdrawal);
		setinterest(interest);
		setservice_charges(service_charges);
		setwithdraws(withdraws);
	}


	void setwithdraws(int);

	int getwithdraws();

	//if a withdrawal causes bal <0, service_charge of 15 will be taken.
	void withdraw(double);

	//adds a monthly fee of $5 + 0.10 per withdrawal to the base class's service_charges
	void monthlyProc();
};
#endif
