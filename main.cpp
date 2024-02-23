/*************************************************************************
** Author : Brenden Drumm
** Program : hw2, q2
** Date Created : February 23, 2024
** Date Last Modified : February 23, 2024
** Usage : No command line arguments
**
** Problem:
Accept the following information from the user (keyboard):
- Hw1, hw2 and hw3 (out of 100)
- Midterm (out of 100)
- Final exam (out of 100)
Calculate the total grade out of 100 based on the following grading scale:
Hws --> 30% (10% each)
Midterm --> 30%
Final Exam --> 40%
*************************************************************************/
#include <iostream>
using namespace std;

struct Check{
    int CheckNum;
    string CheckMemo;
    int CheckAmount;
};

class Checkbook{
public:
    Checkbook():balance(0), numOfChecks(0), checkBookSize(4){}
    Checkbook(int initBal):balance(initBal), numOfChecks(0), checkBookSize(2){}

    float getBalance()const{return balance;}
    float getLast()const{return lastDeposit;}
    int getNumOfChecks()const{return numOfChecks;}
    int getCheckBookSize()const{return checkBookSize;}


    void deposit(float depositAmount);
    void displayChecks();
    bool writeCheck(float amount);
private:
    Check checkArray[5];
    float balance;
    float lastDeposit;
    int numOfChecks;
    int checkBookSize;
};

void Checkbook::deposit(float depositAmount){
    balance += depositAmount;
}

void Checkbook::displayChecks(){
    for(int i = 0; i < numOfChecks; i++){
        cout<<"Check "<<i<<" Memo "<<checkArray[i].CheckMemo<<endl;
        cout<<"Check "<<i<<" Amount "<<checkArray[i].CheckAmount<<endl;
    }

}

bool Checkbook::writeCheck(float amount){

    if(amount<balance){
        checkArray[numOfChecks].CheckAmount = amount;
        cout<<"Check memo?"<<endl;
        cin>>checkArray[numOfChecks].CheckMemo;
        balance-=amount;
        cout<<"New Balance: "<<balance<<endl;
        numOfChecks++;
    }
    else{
        cout<<"exceeding balance"<<endl;
        return false;
    }
}

ostream & operator<<(ostream &var, Check che)
{
    cout<<che.CheckNum<<" "<<che.CheckMemo<<" "<<che.CheckAmount<<endl;
}


int main()
{
    cout << "Hello world!!!!" << endl;

    Checkbook cheque(500);
    cheque.writeCheck(200);
    cheque.writeCheck(100);
    cheque.displayChecks();

    return 0;
}
