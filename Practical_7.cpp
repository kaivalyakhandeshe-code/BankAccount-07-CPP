
#include <iostream>
using namespace std;

// Base class
class BankAccount
{
public:
    // Compile-time polymorphism: function overloading
    float calculateInterest(float balance)
    {
        return balance * 4 / 100;
    }

    float calculateInterest(float balance, float rate, int years)
    {
        return balance * rate * years / 100;
    }

    // Run-time polymorphism: virtual function
    virtual float calculateInterest(float balance, int years)
    {
        return balance * 2 * years / 100;
    }

    virtual void displayAccountType()
    {
        cout << "Account Type: General Bank Account" << endl;
    }

    virtual ~BankAccount()
    {
    }
};

// Derived class for savings account
class SavingsAccount : public BankAccount
{
public:
    float calculateInterest(float balance, int years) override
    {
        return balance * 4 * years / 100;
    }

    void displayAccountType() override
    {
        cout << "Account Type: Savings Account" << endl;
    }
};

// Derived class for fixed deposit
class FixedDepositAccount : public BankAccount
{
public:
    float calculateInterest(float balance, int years) override
    {
        return balance * 7 * years / 100;
    }

    void displayAccountType() override
    {
        cout << "Account Type: Fixed Deposit Account" << endl;
    }
};

int main()
{
    int choice;
    float balance, rate, interest;
    int years;

    BankAccount account;
    SavingsAccount savings;
    FixedDepositAccount fixedDeposit;

    BankAccount *ptr;

    do
    {
        cout << "\n================================";
        cout << "\n BANK ACCOUNT POLYMORPHISM SYSTEM";
        cout << "\n================================";
        cout << "\n1. Function Overloading";
        cout << "\n2. Savings Account Interest";
        cout << "\n3. Fixed Deposit Interest";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "\nEnter Account Balance: Rs. ";
                cin >> balance;

                cout << "Interest using one parameter (4% for 1 year): Rs. "
                     << account.calculateInterest(balance) << endl;

                cout << "\nEnter Interest Rate (%): ";
                cin >> rate;

                cout << "Enter Number of Years: ";
                cin >> years;

                if (balance < 0 || rate < 0 || years < 0)
                {
                    cout << "Invalid input! Values cannot be negative."
                         << endl;
                    break;
                }

                interest = account.calculateInterest(balance, rate, years);

                cout << "Interest using three parameters: Rs. "
                     << interest << endl;
                cout << "Amount after interest: Rs. "
                     << balance + interest << endl;
                break;

            case 2:
                cout << "\nEnter Savings Balance: Rs. ";
                cin >> balance;
                cout << "Enter Number of Years: ";
                cin >> years;

                if (balance < 0 || years < 0)
                {
                    cout << "Invalid input! Values cannot be negative."
                         << endl;
                    break;
                }

                ptr = &savings;

                ptr->displayAccountType();
                interest = ptr->calculateInterest(balance, years);

                cout << "Interest Rate: 4%" << endl;
                cout << "Calculated Interest: Rs. "
                     << interest << endl;
                cout << "Maturity Amount: Rs. "
                     << balance + interest << endl;
                break;

            case 3:
                cout << "\nEnter Fixed Deposit Amount: Rs. ";
                cin >> balance;
                cout << "Enter Number of Years: ";
                cin >> years;

                if (balance < 0 || years < 0)
                {
                    cout << "Invalid input! Values cannot be negative."
                         << endl;
                    break;
                }

                ptr = &fixedDeposit;

                ptr->displayAccountType();
                interest = ptr->calculateInterest(balance, years);

                cout << "Interest Rate: 7%" << endl;
                cout << "Calculated Interest: Rs. "
                     << interest << endl;
                cout << "Maturity Amount: Rs. "
                     << balance + interest << endl;
                break;

            case 4:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}

