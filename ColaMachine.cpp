#include <iostream>

using namespace std;

class coke {
    private:
    float cokeValue;
    string cokeName;
    static int numberOfCokes;
    public:
    string getCokeName(){return cokeName;}
    void setCokeName(string cokeName){this->cokeName = cokeName;}
    float getCokeValue(){return cokeValue;}
    void setCokeValue(float cokeValue){this->cokeValue = cokeValue;}
    void setAll(string cokeName, float cokeValue);
    coke(string cokeName, float cokeValue);
    coke();
    static int getNumOfCokes(){return numberOfCokes;}
    void sayCokeValues(int list[]);
};

int budget = 0;
int coke::numberOfCokes = 0;
void coke::setAll(string cokeName, float cokeValue){
    this->cokeName = cokeName;
    this->cokeValue = cokeValue;
    coke::numberOfCokes++;
}

coke::coke(string cokeName, float cokeValue){
    this->cokeName = cokeName;
    this->cokeValue = cokeValue;
    coke::numberOfCokes++;
}
 
coke::coke(){
    this->cokeName = "";
    this->cokeValue = 0;
    coke::numberOfCokes++;
}

void coke::sayCokeValues(int list[]){
    cout<<this->cokeName<<" cost "<<this->cokeValue<<endl;
}

void options(int option, coke listOfCokes[]){

    cout<<listOfCokes[option-1].getCokeName()<<" cost "<<listOfCokes[option-1].getCokeValue()<<endl;

    if (budget >= listOfCokes[option-1].getCokeValue()){
        budget = budget - listOfCokes[option-1].getCokeValue();
        cout<<"purchase successful! your return is "<<budget<<endl;
        cout<<"thanks for shopping!";

    } else
    {
        int option;
        double amount;
        cout<<"you don't have enough money\n1. Put more money 2. end"<<endl;
        cin>>option;
        if (option == 1)
        {
            cout<<"insert the amount: ";cin>>amount;
            budget = amount + budget;
            options(option, listOfCokes);

        } else {
            cout<<"goodbye!";
        }
    }
    
}

void start(coke listOfCokes[]){
    int option;
    cout<<"choose one\n";
    cout<<"1."<<listOfCokes[0].getCokeName()<<" "<<listOfCokes[0].getCokeValue()<<
    "\n2."<<listOfCokes[1].getCokeName()<<" "<<listOfCokes[1].getCokeValue()<<
    "\n3."<<listOfCokes[2].getCokeName()<<" "<<listOfCokes[2].getCokeValue()<<
    "\n4."<<listOfCokes[3].getCokeName()<<" "<<listOfCokes[3].getCokeValue()<<
    "\n5."<<listOfCokes[4].getCokeName()<<" "<<listOfCokes[4].getCokeValue()<<endl;
    cin>>option;
    
    options(option, listOfCokes);
}


int main(){
    coke listOfCokes[5];
    listOfCokes[0].setAll("coca cola", 4800);
    listOfCokes[1].setAll("pepsi", 4000);
    listOfCokes[2].setAll("colombiana", 4200);
    listOfCokes[3].setAll("postobon", 3000);
    listOfCokes[4].setAll("del valle", 3700);

    cout<<"Cola Machine 1.0, insert your money: ";cin>>budget;
    start(listOfCokes);

}   
