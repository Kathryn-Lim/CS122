/*
Name: Kathryn Lim
CPTS 122 Spring 2020				LAB: 15L
PA7
*/

#include"Account.h"
#include "Checking.h"
#include "Savings.h"


int main(void) {
	//initialize objects with pass by value
	//values are placeholder to be overwritten by classes' setter functions
	Account A(100.40, 20, 10, 3.30, 5.50);
	Savings S(100.40, 20, 10, 3.30, 5.50, true);
	Checking C(100.40, 20, 10, 3.30, 5.50, 0) ;

	//test case for Account class
	cout << "=================Testing base class (Account class)==========" << endl;
	A.setbalance(200);
	cout << "Balance: ";
	cout << A.getbalance()<<endl;

	A.setdeposit(2);
	cout << "Times Deposited: ";
	cout << A.getdeposit()<<endl;

	A.setwithdrawal(1);
	cout << "Times withdrawn: ";
	cout << A.getwithdrawal() << endl;

	A.setinterest(3.2);
	cout << "Annual Interest rate: ";
	cout << A.getinterest() << endl;

	cout << "Applying monthly interest of "<<A.getinterest()<<" /12 .... "<<endl;
	A.calcInt();
	cout << "Balance after interest: " <<A.getbalance()<< endl;
 
	 cout << "Applying processing fees: "<<endl;
	 A.monthlyProc();
	 cout << "New Balance: ";
	 cout << A.getbalance();
	 cout << endl;






	 //test case for Savings class
	 cout << "\n==========Testing savings account functions=============="<<endl;
	 S.setbalance(420.67);
	 cout << "Balance: ";
	 cout << S.getbalance()<<endl;
	 S.setwithdrawal(2);
	 S.setdeposit(3);
	 S.setstatus(true);

	 cout << "Withdrawing $100.... " << endl;
	 S.withdraw(100);	
	 cout << "New Balance: ";
	 S.checkbalance();
	 cout << S.getbalance() << endl;
	 cout << "check status of account: ";
	 S.checkbalance();
	 if (S.getstatus()) {
		 cout << "Account is active"<<endl;
	 }
	 else {
		 cout << "Account balance less then $25, Account is inactive" << endl;
	 }
	 cout << "Depositing $200....." << endl;
	 S.deposit(200);
	 cout << "New Balance: ";
	 cout << S.getbalance() << endl;
	 cout << "Calculating service charges...." << endl;
	 S.monthlyProc();
	 cout << "Withdrawn: " << S.getwithdrawal() << " times." << endl;
	 cout << "New Balance: ";
	 cout << S.getbalance() << endl;

	 cout << "Withdraw 3 more times: " << endl;
	 for (int i = 0; i < 3; ++i) {
		 S.withdraw(10);
	 }
	 cout << "Calculate new service charges...." << endl;
	 S.monthlyProc();
	 cout << "Withdrawn: " << S.getwithdrawal() << " times." << endl;
	 cout << "New Balance: ";
	 cout << S.getbalance() << endl;

	 //test case for Checking class
	 cout << "============\nTesting Checking class===============" << endl;
	 C.setbalance(46.66);
	 C.setwithdraws(4);
	 cout << "Balance: ";
	 cout << C.getbalance() << endl;

	 C.withdraw(50);
	 cout << "Withdraw 50" << endl;
	 cout << "Balance (with service charge and extra fees of 15 applied: ";
	 cout << C.getbalance() << endl;
	 cout << "Times withdrawn: " << C.getwithdraws() << endl;
	 cout << "Balance with monthly processing fee applied (+0.10 * times withdrawn): ";
	 C.monthlyProc();
	 cout << C.getbalance();

	 cout << endl;
	system("pause");

	return 0;

}