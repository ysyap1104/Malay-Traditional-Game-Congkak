/**********|**********|**********|
Program: TT04_P2_YAP_YUNG_SENG.cpp
Course: Bachelor of Computer Science
Year: 2016/17 Trimester 1
Name: YAP YUNG SENG
ID: 1141128589
Email: yungseng1314@hotmail.com
Phone: 010-203-2628
**********|**********|**********/
//house_store[0] - house_store[6] = Player 1 House 1 to House 7
//house_store[7]=  Player 1 Store House
//house_store[8] - house_store[14]= Player 2 House 1 to House 7
//house_store[15]= Player 2 Store House

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//function declaration
void printMenuCongkak(int house_store[]);
//Print Congkak board with all the houses

void house_checker(string& house_selection,int identifier,int round);
//Check whether the house location enter by users is 1 to 7

void printP1Congkak(int house_store[],int round);
//Print player 1 congkak and update the amount of the seed

void printP2Congkak(int house_store[],int round);
//Print player 2 congkak and update the amount of the seed

//function definition
void printMenuCongkak(int house_store[])
{
    cout.width(22);cout<<"Player 1\n"<<endl;
    cout.width(29);cout<<"--1--2--3--4--5--6--7--"<<endl;
    cout.width(30);cout<<"-------------------------"<<endl;
    cout.width(7);cout<<"|";
    cout.width(2);
    for (int a=0;a<7;a++){
        cout<<house_store[a]<<"|";
        cout.width(2);
    }
    cout<<endl;
    cout.width(4);cout<<house_store[15]<<" ------------------------- "<<house_store[7]<<endl;
    cout.width(7);cout<<"|";
    cout.width(2);
    for (int a=14;a>7;a--){
        cout<<house_store[a]<<"|";
        cout.width(2);
    }
    cout<<endl;
    cout.width(30);cout<<"-------------------------"<<endl;
    cout.width(29);cout<<"--7--6--5--4--3--2--1--"<<endl;
    cout.width(22);cout<<"Player 2\n"<<endl;
}

void house_checker(string& house_selection,int identifier,int round)
{
    while (house_selection!= "1" and house_selection!= "2" and house_selection!= "3" and house_selection!= "4" and house_selection!= "5" and house_selection!="6" and house_selection!="7"){
            cout<<"You entered wrong input !!\n\n";
            cout<< "Player "<<identifier<<" (Round "<<round<<")\nPlease Choose your location <1 to 7> ->";
            getline(cin,house_selection);
    }
}

void printP1Congkak(int house_store[],int round)
{
    if (house_store[0]==0 and house_store[1]==0 and house_store[2]==0 and house_store[3]==0 and house_store[4]==0 and house_store[5]==0 and house_store[6]==0){
            cout<<"Player 1 turn will be skipped due to 0 seed in all houses"<<endl<<endl;
    }
    else{
        cout<< "Player 1 (Round "<<round<<")\nPlease Choose your location <1 to 7> -> ";
        int identifier=1;                       //use in function to print player 1 or 2 statement
        int number_store=0,num1=0;
        string player1_house;
        while (number_store==0){                //Test house location 1-7 and 0 seed
            getline(cin,player1_house);
            house_checker(player1_house,identifier,round);              //Call house_checker function to check the input 1-7
            int p1_selection_int= std::atoi(player1_house.c_str());     //change data type from string to integer
            num1=p1_selection_int-1;            //Player 1 house selection, for example when Player 1 select house 7 , In array house 7 is house_store[6] 7-1=6
            number_store=house_store[num1];     //store the selected house seed in here
            if (number_store==0){               // If the house selected with 0 seed, program will get the input again from Player 1
                cout<<"You have selected a house with 0 seed,Please try other houses\n"<<endl;
                cout<< "Player 1 (Round "<<round<<")\nPlease Choose your location <1 to 7> -> ";
            }
        }
        number_store=number_store+1;            //To print selected house to 0 seed
        house_store[num1]=0;                    //set Player 1 selected house to 0 seed
        do{

            printMenuCongkak(house_store);
            number_store=number_store-1;        //to determine how many seed left in hand
            num1=num1+1;                        //house location add by 1
            if (num1>14){                       //to skip player 2 store house because Player 1 cannot place seed in opponent store house
                num1=0;
            }
            if (number_store != 0){
                    house_store[num1]=house_store[num1]+1;      //Because of Do-While loop, this line is used to stop adding the seed to next house while 0 seed left
            }
            string run;
            getline(cin,run);                   // To print the congkak one by one (Requested by Instructor
        }while(number_store!=0);
    }
}

void printP2Congkak(int house_store[],int round)
{
    if (house_store[8]==0 and house_store[9]==0 and house_store[10]==0 and house_store[11]==0 and house_store[12]==0 and house_store[13]==0 and house_store[14]==0){
            cout<<"Player 2 turn will be skipped due to 0 seed in all houses"<<endl<<endl;
    }
    else{
        cout<< "Player 2 (Round "<<round<<")\nPlease Choose your location <1 to 7> ->";
        int identifier=2;
        int number2_store=0,num2=0;
        string player2_house;
        while (number2_store==0){
            getline(cin,player2_house);
            house_checker(player2_house,identifier,round);
            int p2_selection_int= std::atoi(player2_house.c_str());
            num2=p2_selection_int+7;        //Player 2 house selection, for example when Player 2 select house 1 , In array house 1 is house_store[8] 1+7=8
            number2_store=house_store[num2];
            if (number2_store==0){
                cout<<"You have selected a house with 0 seed,Please try other houses\n"<<endl;
                cout<< "Player 2 (Round "<<round<<")\nPlease Choose your location <1 to 7> ->";
            }
        }
        number2_store=number2_store+1;      //To print the selected house to 0 seed
        house_store[num2]=0;                //set Player 2 selected house to 0 seed
        do{
            printMenuCongkak(house_store);
            number2_store=number2_store-1;  //to determine how many seed left in hand
            num2=num2+1;                    //house location add by 1
            if (num2>15){       //When Player 2 reach their store house , then it start again from Player 1 house 1
                num2=0;
            }
            if(num2==7){        //for example when player 2 house 7 with 20 seed , this line is used to skip player 1 store house because player 2 cannot place seed in opponent store house
                num2=num2+1;
            }
            if (number2_store!=0){
                house_store[num2]=house_store[num2]+1;
            }
            string run;
            getline(cin,run);               // To print the congkak one by one (Requested by Instructor
        }while(number2_store!=0);
    }
}

//main function
int main()
{
    system("MODE CON COLS=80 LINES=10000");
    int house_store[16]={7,7,7,7,7,7,7,0,7,7,7,7,7,7,7,0},identifier,round,total;       //store all the amount of seed in array , set variable to int type
    round=1;        //Initialize the round to 1
    cout<<"     -._.-._.-._.-._.-._.-._.-." <<endl;
    cout<<"     ._.-.._.-.._.-.._.-._.-._ "<<endl;
    cout<<"     -.  The Game of Congkak .-  " <<endl;   //design based on river
    cout<<"     ._.-.._.-.._.-.._.-._.-._ "<<endl;
    cout<<"     _.-._.-._.-._.-._.-._.-._.\n" <<endl;
    printMenuCongkak(house_store);
    string player1_house,player2_house;
    srand(time(0));
    int rand_number=1+(rand()%2);                   //generate number 1 and 2 to find out which player start first
    cout<<"Player "<<rand_number<<" begin first"<<endl<<endl;
    do{                                             //loop until all the houses become 0
        if (rand_number==1){                        //Player 1 start first
            printP1Congkak(house_store,round);      //Player 1 Congkak
            total=house_store[7]+house_store[15];
            if (total!=98){                         // to prevent the statement "Player 2 turn will be skipped due to 0 seed in all houses" repeated when all houses become 0
                printP2Congkak(house_store,round);  //Player 2 Congkak
                round=round+1;
            }
        }
        else{                                       //Player 2 start first
            printP2Congkak(house_store,round);      //Player 2 Congkak
            total=house_store[7]+house_store[15];
            if (total!=98){                         // to prevent the statement "Player 1 turn will be skipped due to 0 seed in all houses" repeated when all houses become 0
                printP1Congkak(house_store,round);  //Player 1 Congkak
                round=round+1;
            }
        }
    }while (house_store[0]!=0 or house_store[1]!=0 or house_store[2]!=0 or house_store[3]!=0 or house_store[4]!=0 or house_store[5]!=0 or house_store[6]!=0 or house_store[8]!=0 or house_store[9]!=0 or house_store[10]!=0 or house_store[11]!=0 or house_store[12]!=0 or house_store[13]!=0 or house_store[14]!=0);

    if (house_store[7]>house_store[15]){
        cout<<"Player 1 wins";
    }
    else if(house_store[7]==house_store[15]){
        cout<<"Tie";
    }
    else{
        cout<<"Player 2 wins";
    }
    return 0;
}

