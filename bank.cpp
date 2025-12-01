#include <iostream>
 #include <string>
 #include <windows.h>
 using namespace std;
 class bank {
 private:
    long long balance;
    string name;
    int age;
    string phone;
    string govtId;
    int type;
    bool isAccountCreated;
 public:
    bank() {
        balance = 0.0;
        isAccountCreated = false;
        age = 0;
    }
    void get_ca() {
        cin.ignore();
        cout << "Enter your name: ";
         getline(cin, name);
        cout << "Enter your age: ";
        cin >> age;
        cout << "Enter your mobile number: ";
        cin >> phone;
        cout << "Enter your govt id number: ";
        cin >> govtId;
        isAccountCreated = true;
        cout << "Congratulations your account is created!\n";
         Sleep(3000);
    }
    void show_ca() {
        cout << "\nAccount Details\n";
        cout << "Name: "<<name << endl ;
        cout << "Age: " << age << endl;
        cout << "Mobile: " << phone << endl;
        cout << "Govt ID: " << govtId << endl;
        cout << "Balance: $" << balance << endl;
    }
    void dp() {
        if (!isAccountCreated) {
            cout << "Please create an account first.\n";
            return;
        }
        int amount;
        cout << "Enter deposit amount: $";
        cin >> amount;
        if (amount <= 0) {
            cout << "Invalid amount\n";
            return;
        }
        balance += amount;
        cout << "New balance: $" << balance << "\n";
    }
    void wd() {
        if (!isAccountCreated) {
        }
            cout << "Please create an account first.\n";
            return;
        cout << "Select account type:\n";
        cout << "1. Saving\n2. Current\n3. Business\n";
        cin >> type;
        if (type >= 1 && type <= 3) {
            int amount;
            cout << "Enter withdrawal amount: $";
            cin >> amount;
             if (amount <= 0)
              {
                cout << "Invalid amount\n";
                return;
              }
            if (amount > balance)
             {
                cout << "Insufficient balance!\n";
                return;
             }
            balance -= amount;
            cout << "Withdrawal successful. New balance: $" << balance << endl;
        } else {
            cout << "Invalid account type!\n";
        }
    }
    bool accountExists() const {
        return isAccountCreated;
    }
 };
 int main() {
    const int MAXU = 10; 
    bank users[MAXU];     
    int current = 0;    
    int choice,ac;
    int wa = 0;
    const int ma = 3;
    do {
        cout << "\n=== Bank Management System ===\n";
        cout << "1. Create New Account\n2. Select Account\n";
        cout << "3. Show All Accounts\n4. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        if (choice < 1 || choice > 4) {
            wa++;
            cout << "Invalid choice! Attempts remaining: " << (ma-wa) << endl;
            if (wa >= ma) {
                cout << "Too many wrong attempts. Exiting.\n";
                return 0;
            }
            continue;
        }
        switch (choice) {
            case 1:
                if (current < MAXU) {
                    users[current].get_ca();
                    users[current].show_ca();
                    current++;
                } else {
                    cout << "Maximum user limit reached!\n";
                }
                break;
            case 2:
                if (current == 0) {
                    cout << "No accounts exist. Create one first!\n";
                    break;
                }
                cout << "Enter account number (0-" << current-1 << "): ";
                cin >> ac;
                if (ac >= 0 && ac < current) {
                    int subChoice;
                    do {
                        cout << "\n1. Deposit\n2. Withdraw\n";
                        cout << "3. Show Details\n4. Back to Main Menu\n";
                        cout << "Choice: ";
                        cin >> subChoice;
                        switch (subChoice) {
                            case 1: users[ac].dp(); break;
                            case 2: users[ac].wd(); break;
                            case 3: users[ac].show_ca(); break;
                            case 4: cout << "Returning to main menu...\n"; 
break;
                            default: cout << "Invalid choice!\n";
                        }
                    } while (subChoice != 4);
                } else {
                    cout << "Invalid account number!\n";
                }
                break;
            case 3:
                if (current == 0) {
                    cout << "No accounts exist.\n";
                } else {
                    cout << "\nAll Accounts:\n";
                    for (int i = 0; i < current; i++) {
                        cout << "\nAccount #" << i << ":\n";
                        users[i].show_ca();
                    }
                }
                break;
            case 4:
                cout << "Thank you for using our service!\n";
                break;
        }
    } while (choice != 4);
    return 0;
 }