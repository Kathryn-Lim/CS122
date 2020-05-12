#include "Checking.h"


void Checking::setwithdraws(int w) {
	this->withdraws = w;
}

int Checking::getwithdraws() {
	return this->withdraws;
}

void Checking::withdraw(double cash_out) {
	double tmp = getbalance();
	double bal = tmp - cash_out;

	if (bal < 0) {
		setservice_charges( + 15);
		setbalance(bal - getservice_charges());
	}

	setwithdraws(getwithdraws() + 1);
	

	return;
}

void Checking::monthlyProc() {
	double fee = 5;		//extra monthly fee
	double Wfee = 0.10;	//fee per withdrawal (check written)
	
	setservice_charges(getservice_charges() + fee);	//increases monthly fee by 5

	double totalFee = Wfee * getwithdraws();	//calculates addtl fees reccured by check withdrawals
	
	setservice_charges(getservice_charges() + totalFee);

	setbalance( ( getbalance()  -  getservice_charges() ) );

	return;
}