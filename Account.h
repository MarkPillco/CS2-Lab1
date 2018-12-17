#include <string>
#include <iostream>
#include <cmath>
class Account{

public:
	
Account(std::string accountName, int initialBalance,int AccNumber) 
:name{accountName}
{
		
     if (initialBalance > 0) 
     {
	 balance= initialBalance;
     }

     if (AccNumber > 0)
     {
         num = AccNumber;
     }

}

	
void deposit (int depositAmount)
{
    if (depositAmount>0 )
        {
	balance= balance + depositAmount;
	}
}

int getBalance() const
	{
	return balance;
	}


void setName( std::string accountName)
	{
	name = accountName;
	}


std::string getName() const
	{	
	return name; 
	} 

void setAccNumber(int AccNumber)
    {
    num=AccNumber;
    
    }


int getAccNumber ()
    {
    return num; 
    }
	   
void withdraw (int withdrawamount)  
{
    if (withdrawamount <= balance )
    {
    balance = balance - withdrawamount ;
    }
		   
    	else 
        {
        std::cout << " Error, not enough money to make this transaction" ; 
        }
}
void setcreditLimit (float amount)
    {
    credLimit= amount ; 
    }
				
void purchase (float amount) 
    {
    if (amount > credLimit) 
        {
        std::cout << " Sorry, could not purchase. It exceedes your limit." ;
        }
					
    else if (credLimit > amount)
    {
    std::cout << " Thank You for your purchase !"<< std::endl; 
    creditBalance= credLimit-amount; 
    }
}

void payBill()
{
    if (creditBalance < balance)
	{
	balance= balance-creditBalance;
	creditBalance=0;
	}
	else
	{
	balance=0;
	creditBalance=creditBalance-balance;
	std::cout << "You have insufficient funds to complete your transaction! Your Credit balance is: " << creditBalance << std::endl;
    	}
}

void refund (float amount)
    {
    creditBalance= creditBalance + amount ;
    }
		
void setInterestRate (float rate) 
    {
    IntRate = rate ;
    } 
		
float getInterestRate()
    {
    return IntRate;
    }	
		
void addAnnualInterest (int indicator)
{
     if (indicator == 0)
     {
         balance = balance * pow(1+(IntRate/365),365) ;
     }



	else if (indicator == 1)
    {
        balance= balance * pow(1+(IntRate/12),12) ;
    }
		
    
}
	

void queryAccount()
{ 
    std::cout << "****Account for "<< getName() << "****ID:" << getAccNumber() <<std::endl;
    std::cout << " Account Balance: " << balance << std::endl;
    std::cout << "Credit Card Info:" << std::endl;
    std::cout << "Credit Card Limit: " << credLimit << std::endl;
    std::cout << "Credit Balance: " << creditBalance << std::endl;
    std::cout << "Available Credit " << credLimit - creditBalance << std::endl;  	
    std::cout << "*****************" << std::endl;
}		
		
	private:

	std::string name;
	double balance {0} ;
	int AccNumber{0};
	int credLimit;
	int withdrawamount;
	int creditBalance{0};
	int creditleftover;
	float IntRate{0};
	float num{0};
};
