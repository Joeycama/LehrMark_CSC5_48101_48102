/* 
   File:   main
   Author: Dr. Mark E. Lehr
   Created on October 26th, 2016, 10:00 AM
   Purpose:  
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
bool isLpYr(int);  //Is it a leap year
int  getCVal(int); //Get the century value
int  getYVal(int); //Get the year value
int  getMVal(int,int);//Get the month value
string dayOfWk(int,int,int);//Return day of week

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    
    //Input values
    
    //Process values -> Map inputs to Outputs
    cout<<"Day of week = "<<dayOfWk(7,4,2008)<<endl;
    //Display Output

    //Exit Program
    return 0;
}

string dayOfWk(int m,int d,int y){
    int nDay=(d+getMVal(m,y)+getYVal(y)+getCVal(y))%7;
    switch(nDay){
        case 0:return "Sunday";
        case 1:return "Monday";
        case 2:return "Tuesday";
        case 3:return "Wednesday";
        case 4:return "Thursday";
        case 5:return "Friday";
        case 6:return "Saturday";
        default:return "Bad Day";
    }
}

int  getMVal(int m,int y){
    switch(m){
        case 1:return isLpYr(y)?6:0;
        case 2:return isLpYr(y)?2:3;
        case 3:return 3;
        case 4:return 6;
        case 5:return 1;
        case 6:return 4;
        case 7:return 6;
        case 8:return 2;
        case 9:return 5;
        case 10:return 0;
        case 11:return 3;
        default:return 5;
    }
}

int getYVal(int year){
    int dig2=year%100;
    return dig2+dig2/4;
}

int getCVal(int year){
    return 2*(3-year%4);
}

bool isLpYr(int year){
    return ((year%400==0)||((year%4==0)&&(year%100!=0)));
}