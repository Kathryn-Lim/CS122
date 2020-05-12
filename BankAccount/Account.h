#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

//generic Account class
class Account {	
	double balance;		//balance of the account
	int deposits;	//times deposited
	int withdrawal;	//times withdrawed
	double interest;	//annual interest rate
	double service_charges;	//annual service charges

public:
	Account();

	virtual ~Account();

	//overload constructor
	Account(double, int, int, double, double);

	//accepts deposit amount, updates balance++ and deposits
	virtual void deposit(double);

	//accepts withdrawal amount, updates balance-- and withdrawal
	virtual void withdraw(double);

	//calculates monthly interest, updates balance++
	virtual void calcInt();

	//subtracts monthly service charges from the balance updates balance--
	//calls the calcInt function, and then sets the variables that hold the number
	//of withdrawals, number of deposits, and monthly service charges to zero.
	virtual void monthlyProc();

	//return account balance
	double getbalance();

	//return times deposited
	int getdeposit();

	//return times withdrawed
	int getwithdrawal();

	//return annual interest rate
	double getinterest();

	//returns service charge
	double getservice_charges();

	//sets bank balance
	void setbalance(double);

	//sets withdrawal times
	void setwithdrawal(int);

	//sets times deposited
	void setdeposit(int);

	//sets annual interest rate
	void setinterest(double);

	//sets service charges
	void setservice_charges(double);

};


#endif

