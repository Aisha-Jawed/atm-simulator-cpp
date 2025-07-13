/*
  ATM Simulator Project
  Developed by Aisha Jawed
  Features:
  - Login with PIN
  - Balance check
  - Withdraw/Deposit
  - Change PIN
  Language: C++
*/

#include<iostream>
#include<vector>
using namespace std;
struct account{
    int balance=5000;
    string pin="1234";

};
bool pinVerification(account& myacc){
    int maxAttempts=3;
    string enteredPin;
    while(maxAttempts>0){
        cout<<" Enter Your Pin : ";
        cin>>enteredPin;
        if(enteredPin==myacc.pin) return true;
           maxAttempts--;
           cout<<"You Entered Wrong pin, total number of attempts left : "<<maxAttempts<<endl;
    }
    return false;
}
void currBalance(account& myacc){
    cout<<"Your current balance is : "<<myacc.balance<<endl;
    return;
}
void deposit(account& myacc){
    int dAmount;
    cout<<"Enter the amount you want to deposit : "<<endl;
    cin>>dAmount;
   myacc.balance+=dAmount;
   cout<<"You have deposited successfully, your current balance is : "<<myacc.balance<<endl;
   return;

}
void withdraw(account& myacc){
    int wAmount;
    cout<<"Enter the amount you want to withdraw : "<<endl;
    cin>>wAmount;
    if(wAmount > myacc.balance){
        cout<<"You don't have enough balance to withdraw the amount you entered."<<endl;
    } else {
        myacc.balance -= wAmount;
        cout<<"Withdrawal successful! Your current balance is : "<<myacc.balance<<endl;
    }
    return;
}

void changePin(account& myacc) {
    string currPin, newPin, confirmPin;

    cout << "Enter the current PIN: ";
    cin >> currPin;

    if (currPin != myacc.pin) {
        cout << "❌ Incorrect current PIN.\n";
        return;
    }

    cout << "Enter the new PIN: ";
    cin >> newPin;

    if (newPin == myacc.pin) {
        cout << "⚠️  New PIN cannot be the same as the old one.\n";
        return;
    }

    cout << "Confirm the new PIN: ";
    cin >> confirmPin;

    if (confirmPin != newPin) {
        cout << "❌ PIN confirmation does not match.\n";
        return;
    }

    myacc.pin = newPin;
    cout << "✅ Your PIN has been successfully updated.\n";
}


int main(){
account myacc;
cout<<" 🏧 Welcome to the ATM-Simulator 🏧 "<<endl;

    if(!(pinVerification(myacc))){
        cout<<"Too many failed attempts! Exiting....."<<endl;
        return 0;
    }
     int choice;
    do{
        cout<<"\n 🌟 Menu 🌟 \n";
        cout<<"1.🧾 Check current balance"<<endl;
        cout<<"2.💰 Deposit"<<endl;
        cout<<"3.💵 Withdraw"<<endl;
        cout<<"4.🔢 Change pin "<<endl;
        cout<<"5.🔓 Exit"<<endl;
        cout<<"Enter the choice : ";
        cin>>choice;

        switch(choice){
            case 1: currBalance(myacc); break;
            case 2: deposit(myacc); break;
            case 3: withdraw(myacc); break;
            case 4: changePin(myacc); break;
            case 5: cout<<"Exiting..."<<endl; break;
            default: cout<<" You have entered Invalid Number"<<endl; break;
        }
    } while(choice!=5);

}