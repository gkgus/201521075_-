#include <iostream>

using namespace std;

class AccountBalance
{
public:
	void deposit();
	//Precondition: 예금할 금액을 받아온다.
	//Postcondition: balance에 예금 금액을 더한값을 넣어준다.
	void withdraw();
	//Precondition: 출금할 금액을 받아온다.
	//Postcondition: balance에 출금한 금액을 빼준다.
	AccountBalance(int tempbalance);
	//Precondition:tempbalance 값을 받아온다.
	//Postcondition:tempbalance 값을 balance로 설정한다.
	AccountBalance();
	//Precondition: 
	//Postcondition: 잔고를 0으로 만들어준다.
	void balanceacess();
	//Precondition: 
	//Postcondition: balance 값을 출력한다.
	void balancemutator();
	//Precondition: 바꾸고 싶은 balance 값을 입력 받는다.
	//Postcondition: 입력받은 값을 balance에 저장한다.
private:
	int balance;
};

AccountBalance::AccountBalance() : balance(0)
{
	cout << "Initialize..." << endl;
}

AccountBalance::AccountBalance(int tempbalance)
{
	balance = tempbalance;
}

void AccountBalance::deposit()
{
	int tempdeposit;
	cout << "How much money will you deposit on your account? " << endl;
	cin >> tempdeposit;
	balance += tempdeposit;
}

void AccountBalance::withdraw()
{
	int tempwithdraw;
	cout << "How much money will you witdraw from your account? " << endl;
	cin >> tempwithdraw;
	if (tempwithdraw > balance) 
	{
		cout << "Error!! You need " << (tempwithdraw - balance)<<endl;
	}
	else
	balance -= tempwithdraw;
}
void AccountBalance::balanceacess()
{
	cout << "Current balance : " << balance << endl;
}

void AccountBalance::balancemutator()
{
	int tempbalance;
	cout << "You can change your balance : ";
	cin >> tempbalance;
	balance = tempbalance;
}

int main()
{
	AccountBalance account1= AccountBalance(1000000);
	account1.balanceacess();
	account1.balancemutator();
	account1.deposit();
	account1.balanceacess();
	account1.withdraw();
	account1.balanceacess();
	account1.balancemutator();
	account1.balanceacess();
	account1 = AccountBalance();
	account1.balanceacess();


}