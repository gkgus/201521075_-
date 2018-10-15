#include <iostream>

using namespace std;

class AccountBalance
{
public:
	void deposit();
	//Precondition: ������ �ݾ��� �޾ƿ´�.
	//Postcondition: balance�� ���� �ݾ��� ���Ѱ��� �־��ش�.
	void withdraw();
	//Precondition: ����� �ݾ��� �޾ƿ´�.
	//Postcondition: balance�� ����� �ݾ��� ���ش�.
	AccountBalance(int tempbalance);
	//Precondition:tempbalance ���� �޾ƿ´�.
	//Postcondition:tempbalance ���� balance�� �����Ѵ�.
	AccountBalance();
	//Precondition: 
	//Postcondition: �ܰ� 0���� ������ش�.
	void balanceacess();
	//Precondition: 
	//Postcondition: balance ���� ����Ѵ�.
	void balancemutator();
	//Precondition: �ٲٰ� ���� balance ���� �Է� �޴´�.
	//Postcondition: �Է¹��� ���� balance�� �����Ѵ�.
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