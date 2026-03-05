#include<iostream>
#include<string>
#include<iomanip>
#include<sstream> 
using namespace std;

class Account
{
	string owner;
	double balance;
public:
	Account() {}
	void set_name(const string& name)
	{
		owner = name;
	}
	void set_balance(double num)
	{
		balance = num;
	}
	int transferTo(Account& target, double amount)
	{
		if (balance < amount)
		{
			cout << "Transfer failed" << endl;
			return 1;
		}
		else
		{
			balance -= amount;
			target.balance += amount;
			return 0;
		}
	}
	void printFormattedBalance() const
	{
		stringstream ss;
		ss << fixed << setprecision(2) << balance;
		string num_str = ss.str();
		while (num_str.back() == '0')
		{
			num_str.pop_back();
		}
		if (num_str.back() == '.')
		{
			num_str.pop_back();
		}
		cout << owner << ":" << num_str << endl;
	}
	void display()
	{
		printFormattedBalance();
	}
};
int main()
{
	Account a, b;
	string name1, name2;
	double num1, num2, transfer_num;
	cin >> name1 >> num1;
	cin >> name2 >> num2;
	cin >> transfer_num;
	a.set_name(name1); a.set_balance(num1);
	b.set_name(name2); b.set_balance(num2);
	int flag = a.transferTo(b, transfer_num);
	a.display();
	b.display();
	return 0;
}