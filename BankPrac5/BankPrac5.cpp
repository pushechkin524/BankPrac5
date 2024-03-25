#include <iostream>
using namespace std;

class BankAccount {
private:
    int _accountNumber;
    double _balance;
    double _interestRate;
public:
    BankAccount(int accountNumber, double balance) : _accountNumber(accountNumber), _balance(balance), _interestRate(0) {}

    void deposit(double amount) {
        if (amount > 0) {
            _balance += amount;
            cout << "Пополнение на сумму: " << amount << " руб." << endl;
        }
        else {
            cout << "Ошибка: Нельзя пополнить баланс на отрицательное число или ноль." << endl;
        }
    }

    bool withdraw(double amount) {
        if (amount <= _balance) {
            _balance -= amount;
            cout << "Снятие на сумму: " << amount << " руб." << endl;
            return true;
        }
        else {
            cout << "Ошибка: Недостаточно средств на счете." << endl;
            return false;
        }
    }

    double getBalance() const {
        return _balance;
    }

    void setInterest(double interest) {
        if (interest >= 0) {
            _interestRate = interest;
            cout << "Процентная ставка успешно установлена: " << interest << "%" << endl;
        }
        else {
            cout << "Ошибка: Процентная ставка должна быть больше или равна нулю." << endl;
        }
    }

    double calculateInterest() const {
        return _balance * _interestRate / 100.0;
    }

    int getAccountNumber() const {
        return _accountNumber;
    }
};

bool transfer(BankAccount& from, BankAccount& to, double amount) {
    if (from.withdraw(amount)) {
        to.deposit(amount);
        cout << "Перевод успешно выполнен." << endl;
        return true;
    }
    else {
        cout << "Ошибка: Невозможно выполнить перевод из-за недостаточного баланса." << endl;
        return false;
    }
}

int main()
{
    setlocale(LC_ALL, "");
    BankAccount account_1(2987, 20);
    BankAccount account_2(1590, 90);

    account_1.deposit(0);
    account_2.deposit(113);

    cout << "Баланс пользователя 1: " << account_1.getBalance() << " руб." << endl;
    cout << "Баланс пользователя 2: " << account_2.getBalance() << " руб." << endl;

    account_1.setInterest(-1); // проверка на процентную ставку 
    account_2.setInterest(15); // процентная ставка в процентах

    cout << "Проценты пользователя 1: " << account_1.calculateInterest() << " руб." << endl;
    cout << "Проценты пользователя 2: " << account_2.calculateInterest() << " руб." << endl;

    account_1.withdraw(11);
    account_2.withdraw(22);

    cout << "Баланс пользователя 1: " << account_1.getBalance() << " руб." << endl;
    cout << "Баланс пользователя 2: " << account_2.getBalance() << " руб." << endl;

    cout << "Перевод средств с пользователя 1 на пользователя 2: ";
    transfer(account_1, account_2, 200);
    cout << "Перевод средств с пользователя 1 на пользователя 2: ";
    transfer(account_1, account_2, 200);
}
