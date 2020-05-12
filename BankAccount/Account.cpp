#include "Account.h"

Account::Account() {
	balance = 0;
	deposits = 0;
	withdrawal = 0;
	interest = 0;
	service_charges = 0;
}

Account::~Account(){}

Account::Account(double b, int d, int w, double i, double sc) {
	balance = b;
	setdeposit(d);
	setwithdrawal(w);
	setinterest(i);
	setservice_charges(sc);
}

void Account::deposit(double cash_in) {

	setbalance(getbalance()+cash_in);

	setdeposit(getdeposit() + 1);
	return;
}


void Account::withdraw(double cash_out) {

	setbalance(getbalance() - cash_out);

	setwithdrawal(getwithdrawal() + 1);
	return;
}

void Account::calcInt() {

	double monthlyInt_rate = 0;
	double monthlyInt = 0;
	double rate_balance;

	/*𝑀𝑜𝑛𝑡ℎ𝑙𝑦 𝐼𝑛𝑡𝑒𝑟𝑒𝑠𝑡 𝑅𝑎𝑡𝑒 = 𝐴𝑛𝑛𝑢𝑎𝑙 𝐼𝑛𝑡𝑒𝑟𝑒𝑠𝑡 𝑅𝑎𝑡𝑒/12
		𝑀𝑜𝑛𝑡h𝑙𝑦 𝐼𝑛𝑡𝑒𝑟𝑒𝑠𝑡 = 𝐵𝑎𝑙𝑎𝑛𝑐𝑒 ∗ 𝑀𝑜𝑛𝑡ℎ𝑙𝑦 𝐼𝑛𝑡𝑒𝑟𝑒𝑠𝑡
		𝑅𝑎𝑡𝑒 𝐵𝑎𝑙𝑎𝑛𝑐𝑒 = 𝐵𝑎𝑙𝑎𝑛𝑐𝑒 + 𝑀𝑜𝑛𝑡ℎ𝑙𝑦 𝐼𝑛𝑡𝑒𝑟𝑒𝑠𝑡*/

	monthlyInt_rate = (getinterest() / 12);

	monthlyInt = getbalance() * monthlyInt_rate;
	rate_balance = getbalance() + monthlyInt;

	setbalance(rate_balance);
	
	return;
}


void Account::monthlyProc() {

	setbalance(getbalance() - getservice_charges());
	setwithdrawal(0);
	setdeposit(0);
	setservice_charges(0.0);
	return;
}

double Account::getbalance() {
	return balance;
}

int Account::getdeposit() {
	return this->deposits;
}

int Account::getwithdrawal() {
	return this->withdrawal;
}

double Account::getinterest() {
	return this->interest;
}

double Account::getservice_charges() {
	return this->service_charges;
}

void Account::setbalance(double balance) {
	this->balance = balance;
	return;
}

void Account::setwithdrawal(int withdraw) {
	this->withdrawal = withdraw;
	return;
}

void Account::setdeposit(int d) {
	this->deposits = d;
	return;
}

void Account::setinterest(double i) {
	this->interest = i;
	return;
}

void Account::setservice_charges(double sc) {
	this->service_charges = sc;
	return;
}








