/**************TicketMachine.h*********************/
class TicketMachine
{
publice:
	void showPrice();
	void showBalance();
	void insertMoney(int money);
	void printTicket();
	void showTotal();
	
private:
	const int PRICE;
	int balance;
	int total;
};

/**************TicketMachine.cpp******************/
#include"TicketMachine.h"
#include <iostream>
using namespace std;

void TicketMachine::showPrice()
{
	cout<<""Price"<<endl;
}

void TicketMachine::insertMoney(int money)
{
	balance+=money;
}

void TicketMachine::showBalance()
{
	cout<<"Balance"<<endl;
}

/**************main*****************/
#include "TicketMachine.h"

int main()
{
	TicketMachine tm;
	tm.insertMoney(100);
	tm.showBalance();
	tm.showPrice();
	return 0;
}
