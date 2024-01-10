//Q2_22K-4054_Nihal_Ali
#include <iostream>
using namespace std;

class BankAccount {
    private:
         double balance;
    
    public:
        BankAccount() {
            this->balance = balance;
        }
    
        BankAccount(double balance) {
            this->balance = balance;
        }
        
        BankAccount(const BankAccount &other) {
            balance = (other.balance - 200);
        }
        
        void display() {
            cout<<"Balance: "<<balance << endl;
        }
        
};

int main() {
    BankAccount account1;
    account1.display();
    BankAccount account2(1000);
    account2.display();
    BankAccount account3(account2);
    account3.display();
}
