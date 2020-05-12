#include "Savings.h"

Savings::~Savings(){}

void Savings::setstatus(bool stat) {
	this->status = stat;
}

//true if active, false if inactive
bool Savings::getstatus() {
	return this->status;
}

void Savings::checkbalance() {
	double bal = getbalance();

	if (bal >= 25) {
		setstatus(true);	//sets account as active
	}
	else {
		setstatus(false);	//sets account as inactive
	}
}

void Savings::withdraw(double cash_out) {
	checkbalance();

	if (getstatus()) {
		Account::withdraw(cash_out);
		//setbalance(getbalance() - cash_out);
	}
	else {
		cout << "Balance of account is less than $25" << endl;
	}

	return;

}

void Savings::deposit(double cash_in) {

	//puts the cash money in yo
	Account::deposit(cash_in);

	//checks balance and updates the status accordingly
	checkbalance();
}

void Savings::monthlyProc() {
	int num = getwithdrawal();

	//checks balance, update account status flag
	checkbalance();

	if (!getstatus())
		return;

	if (getwithdrawal() > 4) {
		setservice_charges(getservice_charges() * getwithdrawal());
		setbalance(getbalance() - getservice_charges());
	}

	//checks balance, update account status flag after increased service charge
	checkbalance();
}

