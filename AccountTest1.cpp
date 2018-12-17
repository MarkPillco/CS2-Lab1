#include <iostream>
#include "Account.h"

using namespace std;

int main()
{
Account a{"John Doe", 2000, 5000};
        a.setcreditLimit(1000);
	a.queryAccount();


	a.purchase(500);	
	a.queryAccount();
	
	a.payBill();
	a.queryAccount();

	a.setInterestRate(0.1);
		a.addAnnualInterest(0);
		a.queryAccount(); 



	a.addAnnualInterest(1);
		a.queryAccount();
return 0;

}

