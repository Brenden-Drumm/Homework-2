/*************************************************************************
** Author : Brenden Drumm
** Program : hw2, q2
** Date Created : February 23, 2024
** Date Last Modified : February 25, 2024
**
** This program creates check structs as a data member of a checkbook
class, along with balance, lastDeposit, numOfChecks, checkBookSize,
and checkArray
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
    Checkbook():balance(0), numOfChecks(0), checkBookSize(4), checkArray(new Check[4]){}
    Checkbook(int initBal):balance(initBal), numOfChecks(0), checkBookSize(2), checkArray(new Check[2]){}

    float getBalance()const{return balance;}
    float getLast()const{return lastDeposit;}
    int getNumOfChecks()const{return numOfChecks;}
    int getCheckBookSize()const{return checkBookSize;}

    void deposit(float depositAmount);
    void displayChecks();
    bool writeCheck(float amount);
    //void checkTest(CheckBook testCheck, float testBal);
private:
    Check *checkArray;
    float balance;//good
    float lastDeposit;//good
    int numOfChecks;//good
    int checkBookSize;//good
};

void Checkbook::deposit(float depositAmount){
    balance += depositAmount;
    //cout<<"deposited! new balance: "<<balance<<endl;
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

        if(numOfChecks >= checkBookSize/2){
            Check *tempCheckArray = new Check [checkBookSize * 2];
            for(int i = 0; i < checkBookSize; i++){
                tempCheckArray[i] = checkArray[i];
            }

            checkBookSize = checkBookSize * 2;
            delete[] checkArray;
            checkArray = tempCheckArray;
        }
    }
    else{
        cout<<"exceeding balance"<<endl;
        return false;
    }
}

void checkTest(Checkbook testCheck, float testBal){
    while(testCheck.getBalance() > testBal){
            testCheck.writeCheck(testBal);
    }
    testCheck.displayChecks();
}

ostream & operator<<(ostream &var, Check che)
{
    cout<<che.CheckNum<<" "<<che.CheckMemo<<" "<<che.CheckAmount<<endl;
}

/*
Checkbook operator =(Checkbook const &c1, Checkbook const &c2){
            c1.setBalance(c2.getBalance());
            c1.setLast(c2.getLast());
            c1.setNumOfChecks(c2.getNumOfChecks());
            c1.setCheckBookSize(c2.getCheckBookSize());

    return Vector(xx,yy);
}
*/


int main()
{
    cout << "Hello world!!!!" << endl;

    Checkbook cheque(10000);
    checkTest(cheque, 1999);


    return 0;
}
