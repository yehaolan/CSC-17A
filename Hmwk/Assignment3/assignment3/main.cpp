/* 
 * File:   main.cpp
 * Author: Haolan Ye (Benjamin)
 * Created on April 3, 2015, 10:33 AM
 * Purpose:Homework assignment3
 */

//System libraries
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

//User libraries
#include "Weather.h"
#include "speakers.h"
#include "Class.h"
#include "Sales.h"
//Global Constants

//Function prototypes
void pg1();//Gaddis_8thEd_Chap10_ProgChal4
void pg2();//Gaddis_8thEd_Chap10_ProgChal6
void pg3();//Gaddis_8thEd_Chap10_ProgChal8
void pg4();//Gaddis_8thEd_Chap11_ProgChal4
void pg5();//Gaddis_8thEd_Chap11_ProgChal9
void pg6();//Gaddis_8thEd_Chap11_ProgChal12
void pg7();//Gaddis_8thEd_Chap12_ProgChal7
void pg8();//Gaddis_8thEd_Chap9_ProgChal8
void pg9();//Gaddis_8thEd_Chap9_ProgChal11
void pg10();//Gaddis_8thEd_Chap9_ProgChal9&10
int wordNum(char *,vector<int> &);
int wordNum(string,vector<int> &);
int vwCount(char *);//count vowel
int csCount(char *);//count consonant
Speaker *initArr(int);//initialize all data of speaker
void pntData(Speaker *,int n);//output all the data
void iptData(Speaker &);//input the information of one speaker
Student getData(int);
void pntScro(Student);
void arrayToFile(string,int *,int);
void fileToArray(string,int *,int);
int *filArr(int);
Sales *filDiv(int);

//Execution begins here
int main(int argc, char** argv) {
    //declare variables
    string ans;
    int sel;
    do {    
        cout<<"**************Program Menu**************"<<endl;
        cout<<"1.  10.4  Number letter of words"<<endl;
        cout<<"2.  10.6  Vowels and Consonants"<<endl;
        cout<<"3.  10.8  Sum of digits in a string"<<endl;
        cout<<"4.  11.4  Weather Statistics"<<endl;
        cout<<"5.  11.9  Speakers’ Bureau"<<endl;
        cout<<"6.  11.12 Course grade"<<endl;
        cout<<"7.  12.7  Sentence filter  "<<endl;
        cout<<"8.  12.8  Array/File Function"<<endl;
        cout<<"9.  12.11 Corporate Sales Data Output"<<endl;
        cout<<"10. 12.9&10 File Encryption & Decryption"<<endl;
        cout<<"0.Exit the program"<<endl;
        //select program
        bool invalid;
        do {
            invalid=false;
            cout<<"Please select the program(0 to 10)"<<endl;
            cin>>ans;
            if(ans.length()>2) {
                invalid=true;
                cout<<"Invalid input"<<endl;
            }
            if(ans.length()==1) {
                if(ans.at(0)<48||ans.at(0)>57) {
                    cout<<"Invalid input"<<endl;
                    invalid=true;
                }
            }
            if(ans.length()==2) {
                if(ans!="10") {
                    cout<<"Invalid input"<<endl;
                    invalid=true;
                }
            }
        }while(invalid);
        if(ans.length()==1) sel=static_cast<int>(ans.at(0)-48);
        if(ans.length()==2) sel=10;
        switch(sel) {
            case 1: pg1(); break;
            case 2: pg2(); break;
            case 3: pg3(); break;
            case 4: pg4(); break;
            case 5: pg5(); break;
            case 6: pg6(); break;
            case 7: pg7(); break;
            case 8: pg8(); break;
            case 9: pg9(); break;
            case 10: pg10(); break;
            case 0: {
                cout<<"This is the end of the program"<<endl;
                break;
            }
            default:;
        }
        if(sel!=0) {
            cout<<endl<<endl;
            cout<<"Press Enter to continue";
            cin.ignore();
        }
    }while(sel!=0);



    return 0;
}

//Gaddis_8thEd_Chap10_ProgChal4
void pg1() {
    char *sen=new char[1000];//sentence with c-string
    //string sen;  //sentence with string
    float ave=0;//The average number of letters in each word
    vector<int> ltrNum;//vector to store the number of letters of each word
    
    cout<<"Welcome to Word Counter"<<endl;
    cout<<"Press Enter to continue..."<<endl;
    cin.ignore();
    cin.ignore();
    //prompt user for sentence
    cout<<"Input sentence: ";
    cin.getline(sen,1000);
    //getline(cin,sen);
    
    //Output the result
    cout<<"The number of words is "<<wordNum(sen,ltrNum)<<endl;
    
    //calculate the number of letter
    for(int i=0;i<ltrNum.size();i++) {
        ave+=ltrNum.at(i);
        //cout<<ltrNum.at(i)<<" ";
    }
    //get the average 
    ave=ave/ltrNum.size();
    cout<<"The average number of letters in each word is "<<ave<<endl;
    delete [] sen;
    sen=0;
}

//Gaddis_8thEd_Chap10_ProgChal6
void pg2() {
    cout<<"Welcome to counter of vowels and consonants"<<endl;
    //allocate the dynamic array
    char *arr=new char[1000];//sentence with c-string

    //prompt user for sentence
    cout<<"Input sentence: ";
    cin.ignore();
    cin.getline(arr,1000);

    //output the result
    cout<<"The length is "<<strlen(arr)<<endl;
    cout<<"The number of vowel is "<<vwCount(arr)<<endl;
    cout<<"The number of consonant is "<<csCount(arr)<<endl;
    
    delete [] arr;
    arr=0;
}

//Gaddis_8thEd_Chap10_ProgChal8
void pg3() {
    bool valid;//whether or not input is valid
    int sum=0;//sum of all digit
    string str;//string of digit
    //prompt user for numbers
    do {
        valid=true;
        cout<<"Input the number without separation: ";
        cin>>str;
        for(int i=0;i<str.length();i++) {
            if(str.at(i)<48||str.at(i)>57)
                valid=false;
        }
        if(!valid)
            cout<<"Invalid input"<<endl;
    }while(!valid);
    //sum all digit
    for(int i=0;i<str.length();i++) {
        sum+=static_cast<int>(str.at(i)-48);
    }
    //sort
    for(int i=0;i<str.length()-1;i++) {
        for(int j=i+1;j<str.length();j++) {
            if(str.at(i)<str.at(j)) {
                char temp=str.at(i);
                str.at(i)=str.at(j);
                str.at(j)=temp;
            }
        }
    }
    //output result
    cout<<"The sum of all the single digit numbers is "<<sum<<endl;
    cout<<"The sorted numbers(From highest to lowest is "<<str<<endl;
    cin.ignore();
}

//Gaddis_8thEd_Chap11_ProgChal4
void pg4() {
    const int SIZE=12;
    Weather month[SIZE];
    //prompt user to fill in the weather
    for(int i=0;i<SIZE;i++) {
        cout<<"Month #"<<(i+1)<<": "<<endl;
        //get the total rainfall
        do {
            //Get the total rainfall
            cout<<"     Total Rainfall(mm): ";
            cin>>month[i].totRain;
            if(month[i].totRain<0)
                cout<<"**Invalid input**"<<endl;
        } while(month[i].totRain<0);
        //get the high temperature
        do {
            //Get the high temperature
            cout<<"     High temperature(F): ";
            cin>>month[i].hTemp;
            if(month[i].hTemp<-100||month[i].hTemp>140)
                cout<<"**Invalid input(out of range)**"<<endl;
        } while(month[i].hTemp<-100||month[i].hTemp>140);
        //get the low temperature
        do {
            //Get the total rainfall
            cout<<"     Low temperature(F): ";
            cin>>month[i].lTemp;
            if(month[i].lTemp<-100||month[i].lTemp>140)
                cout<<"**Invalid input(out of range)**"<<endl;
            if(month[i].lTemp>month[i].hTemp)
                cout<<"**Low temperature cannot greater than high temperature! Input again!**"<<endl;
        } while(month[i].lTemp<-100||month[i].lTemp>140||month[i].lTemp>month[i].hTemp);
        //calculate the average temperature
        month[i].aveTemp=0.5f*(month[i].hTemp+month[i].lTemp);
        
    }
    int yrRain=0;//total rainfall in a year
    float aveRain=0;//average rainfall each month
    float aveTem=0;//average temperature of each average temperature of all months
    int hgstTem=month[0].hTemp;//highest temperature
    int lwstTem=month[0].lTemp;//lowest temperature
    int ihg=0,ilw=0;//the index of month
    for(int i=0;i<SIZE;i++) {
        //sum all total rainfall
        yrRain+=month[i].totRain;
        aveTem+=month[i].aveTemp;//average temperature
        if(month[i].hTemp>hgstTem) {
            hgstTem=month[i].hTemp;
            ihg=i;
        } else if(month[i].lTemp<lwstTem) {
            lwstTem=month[i].lTemp;
            ilw=i;
        }
    }
    //calculate average temperature and average rainfall
    aveTem=static_cast<float>(aveTem)/SIZE;
    aveRain=static_cast<float>(yrRain)/SIZE;
    
    //output the results
    cout<<setprecision(2)<<fixed;
    cout<<"The average monthly rainfall(mm) is "<<aveRain<<endl;
    cout<<"The total rainfall(mm) for the year is "<<yrRain<<endl;
    cout<<"Highest temperature(F) is "<<hgstTem<<" in "<<"Month "<<"#"<<(ihg+1)<<endl;
    cout<<"Lowest temperature(F) is "<<lwstTem<<" in "<<"Month "<<"#"<<(ilw+1)<<endl;
    cout<<"The average of all the monthly average temperatures(F) is "<<aveTem<<endl;
    cin.ignore();
}


//Gaddis_8thEd_Chap11_ProgChal9
void pg5() {
    int spkrNum;//the number of speaker
    string choice;//choice of menu
    int spk;//the number of speaker
    //prompt user for the number of speaker
    do {
        cout<<"Input the number of speaker: ";
        cin>>spkrNum;
        if(spkrNum<10)
            cout<<"At least 10. Please input again!"<<endl;
    }while(spkrNum<10);
    //initialize the speaker
    Speaker *arr=initArr(spkrNum);
    do {
        do {
            //display menu
            cout<<endl<<"***********Menu***********"<<endl;
            cout<<"1.Input/Change information"<<endl;
            cout<<"2.Display all data"<<endl;
            cout<<"3.Exit the program"<<endl;
            cout<<"Input your choice(1, 2 or 3): ";
            cin>>choice;
            if(choice!="1"&&choice!="2"&&choice!="3")
                cout<<"Invalid input"<<endl;
        }while(choice!="1"&&choice!="2"&&choice!="3");
        
        if(choice=="1") {
            do {
                //ask user for edit which speaker
                cout<<"Input the speaker you want to edit(1 to "<<spkrNum<<"): ";
                cin>>spk;
                if(spk<1||spk>spkrNum)
                    cout<<"Invalid input"<<endl;
            }while(spk<1||spk>spkrNum);
            //edit
            iptData(arr[spk-1]);
        }
        //output all data
        if(choice=="2")
            pntData(arr,spkrNum);
        if(choice!="3") {
            cout<<"Press Enter to continue..."<<endl;
            cin.ignore();
            cin.ignore();
        }  
    }while(choice!="3");
    delete [] arr;
    arr=0;

}


//Gaddis_8thEd_Chap11_ProgChal12
void pg6() {
    int tstNum,//the number of test
        stuNum;//the number of student
    //prompt user for the number of test
    do {
        cout<<"The number of test: ";
        cin>>tstNum;
        if(tstNum<1)
            cout<<"Invalid input"<<endl;
    } while(tstNum<1);
    //prompt user for the number of student
    do {
        cout<<"The number of student: ";
        cin>>stuNum;
        if(stuNum<1)
            cout<<"Invalid input"<<endl;
    } while(stuNum<1);
    
    //dynamic allocate memory for all student
    Student *stud=new Student[stuNum];
    
    //prompt user input data
    for(int i=0;i<stuNum;i++) {
        cout<<endl<<"Student #"<<(i+1)<<": "<<endl;
        stud[i]=getData(tstNum);
    }
    
    //output the result
    for(int i=0;i<stuNum;i++) {
        cout<<"Student #"<<(i+1)<<": ";
        pntScro(stud[i]);
    }
    
    //deallocate memory
    delete [] stud;
    stud=0;
    cin.ignore();
}


//Gaddis_8thEd_Chap12_ProgChal7
void pg7() {
   ifstream input;
    ofstream output;
    string inFileN;//input file name
    string otFileN;//output file name
    char ch;
    int count=0;
    //get the input file name
    cout<<"Enter the file(for input) name: ";
    cin>>inFileN;
    //get the output file name
    cout<<"Enter the file(for output) name: ";
    cin>>otFileN;
    cout<<"Now, open the file..."<<endl;
    input.open(inFileN);//open the input file
    if(!input.fail()) { //if open successfully
        cout<<"Open the input file successfully"<<endl;
        output.open(otFileN);
        if(!output.fail()) {
            cout<<"Open the output file successfully"<<endl;
            input.get(ch);
            while(input) {
                if(count==0) output.put(toupper(ch)); 
                else    output.put(tolower(ch));
                count++;
                if(ch=='.') count=0;
                input.get(ch);
                
            }
            cout<<"Finish copy a sentence from input file to output file"<<endl;
        } else { //if it's fail to open output file
            cout<<"Cannot open the output file"<<endl;
        }
    } else { //if fail to open input file
        cout<<"Cannot open the input file"<<endl;
    }
    input.close();
    output.close();
    cin.ignore();
}

//Gaddis_8thEd_Chap12_ProgChal8
void pg8() {
    //set seed for random number
    srand(static_cast<unsigned int>(time(0)));
    int size;
    string fileN;//file name
    do {
        cout<<"Size of array: "<<endl;
        cin>>size;
        if(size<1)
            cout<<"Invalid input"<<endl;
    } while(size<1);
   
    cout<<"File name: "<<endl;
    cin>>fileN;
       
    //allocate the memory
    int *arr=filArr(size);
    int *arrIn=new int[size];
    
    //Before write to file,o output the array
    cout<<"Before writing to file"<<endl;
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
        if(i%5==4) cout<<endl;
    }
    cout<<endl<<endl;;
    
    arrayToFile(fileN,arr,size);//write the array to file
    fileToArray(fileN,arrIn,size);//get the array from the file
    
    //After write to file, output the array
    cout<<"Read the array from the file"<<endl;
    for(int i=0;i<size;i++) {
        cout<<arrIn[i]<<" ";
        if(i%5==4) cout<<endl;
    }
    //deallocate memory
    delete arr;
    delete arrIn;
    cin.ignore();
}

//Gaddis_8thEd_Chap12_ProgChal11
void pg9() {
    //set seed for random number
    srand(static_cast<unsigned int>(time(0)));
    fstream out;//output file object
    //open file
    out.open("Info.txt",ios::out|ios::binary);
    //allocate memory
    Sales *div=filDiv(16);
    Sales *res=new Sales[16];
    //prompt user for each quarter sales
    for(int i=0;i<16;i++) {
        do {
            cout<<div[i].name<<"(quarter "<<div[i].quarter<<"): ";
            cin>>div[i].qrtSale;
            if(div[i].qrtSale<0)
                cout<<"Invalid input"<<endl;
        } while(div[i].qrtSale<0);
        
        //div[i].qrtSale=rand()%90+10; //random get the quarter sales
        
    }
    //write into file
    if(!out.fail()) {
        out.write(reinterpret_cast<char *>(div),sizeof(Sales)*16);
    }
    out.close();
    fstream in;//input file object
    in.open("Info.txt",ios::in|ios::binary);//open file
    if(!in.fail()) {
        in.read(reinterpret_cast<char *>(res),sizeof(Sales)*16);
    }
    //output the quarter sales 
    cout<<endl<<"Press Enter to read from the file..."<<endl;
    cin.ignore();
    cin.ignore();
    for(int i=0;i<16;i++) {
        cout<<res[i].name<<"(quarter "<<res[i].quarter<<"): ";
        cout<<res[i].qrtSale<<endl;
    }
    
    in.close();
    //deallocate memory
    delete [] div;
    delete [] res;
    res=0;
    div=0;
}

//Gaddis_8thEd_Chap12_ProgChal9&10
void pg10() {
    string ans;
    char ch;
    int count;
    cout<<"1. Encryption"<<endl;
    cout<<"2. Decryption"<<endl;
    do {
        cout<<"Your Choice(1-2): ";
        cin>>ans;
        if(ans!="1"&&ans!="2") 
            cout<<"Invalid input"<<endl;
    } while(ans!="1"&&ans!="2");
    if(ans=="1") {
        fstream in;
        fstream out;
        char ofn[]="EnFile.dat";//output file name
        char ifn[]="Original.dat";//original file name
        count=0;
        in.open(ifn,ios::in);
        out.open(ofn,ios::out);
        if(!in.fail()) { //if open successfully
            cout<<"Open the input file successfully"<<endl;
            if(!out.fail()) {
                cout<<"Open the output file successfully"<<endl;
                /*
                do {
                    if(in.get(ch)) {
                        in.get(ch);
                        ch+=count;
                        count++;
                        out.put(ch);
                        if(count==10) count=0;
                    }
                }while(!in);
                */
                //Encryption digit%10 if it's 1 add 1 to ch, if 2,add 2...
                in.get(ch);
                ch+=count;
                while(in) {
                    out.put(ch);
                    count++;
                    if(count==10) count=0;
                    in.get(ch);
                    ch+=count;
                }
                cout<<"Finish Encryption"<<endl;
            } else { //if it's fail to open output file
                cout<<"Cannot open the output file"<<endl;
            }
        } else { //if fail to open input file
            cout<<"Cannot open the input file"<<endl;
        }
        out.close();
        in.close();
    } else if(ans=="2") {
        fstream in;
        fstream out;
        char ofn[]="DeFile.dat";//output file name
        char ifn[]="Enfile.dat";//original file name
        count=0;
        in.open(ifn,ios::in);
        out.open(ofn,ios::out);
        if(!in.fail()) { //if open successfully
            cout<<"Open the input file successfully"<<endl;
            if(!out.fail()) {
                cout<<"Open the output file successfully"<<endl;
                /*
                do {
                    if(in.get(ch)) {
                        in.get(ch);
                        ch+=count;
                        count++;
                        out.put(ch);
                        if(count==10) count=0;
                    }
                }while(!in);
                */
                //Decryption digit%10 if it's 1 minus 1 to ch, if 2,minus 2...
                in.get(ch);
                ch-=count;
                while(in) {
                    out.put(ch);
                    count++;
                    if(count==10) count=0;
                    in.get(ch);
                    ch-=count;
                }
                cout<<"Finish Decryption"<<endl;
            } else { //if it's fail to open output file
                cout<<"Cannot open the output file"<<endl;
            }
        } else { //if fail to open input file
            cout<<"Cannot open the input file"<<endl;
        }
        out.close();
        in.close();
    }
    cin.ignore();

}

//return number of words with c-string
int wordNum(char *arr,vector<int> &ltrNum) {
    int wrdCnt=0;//count of the words
    int ltrCnt=0;//count of number of letters in the word
    bool isWord=false;
    //loop for every letter
    for(int i=0;i<strlen(arr);i++) {
        //if it not space
        if(!isspace(arr[i])) {
            isWord=true;
            ltrCnt++;
        }
        //if it is space and previous one is word
        if(isspace(arr[i])&&isWord) {
            wrdCnt++;
            isWord=false;
            ltrNum.push_back(ltrCnt);
            ltrCnt=0;
        }
    }
    //if the last char is not space, number of word+1
    if(!isspace(arr[strlen(arr)-1])) {
        wrdCnt++; 
        ltrNum.push_back(ltrCnt);
    }
    return wrdCnt;
}

//return number of words with string
int wordNum(string str,vector<int> &ltrNum) {
    int wrdcnt=0;//count of the words
    int ltrCnt=0;//count of number of letters in the word
    bool isWord=false;
    //loop for every letter
    for(int i=0;i<str.length();i++) {
        //if it not space
        if(!isspace(str.at(i))) {
            isWord=true;
            ltrCnt++;
        }
        //if it is space and previous one is word
        if(isspace(str.at(i))&&isWord) {
            wrdcnt++;
            isWord=false;
            ltrNum.push_back(ltrCnt);
            ltrCnt=0;
        }
    }
    //if the last char is not space, number of word+1
    if(!isspace(str.at(str.length()-1))) {
        wrdcnt++;    
        ltrNum.push_back(ltrCnt);
    }
    return wrdcnt;
}

int vwCount(char *arr) {
    int count=0;//counter
    for(int i=0;i<strlen(arr);i++) {
        if(arr[i]=='a'||arr[i]=='e'||arr[i]=='i'||arr[i]=='o'||arr[i]=='u'||
           arr[i]=='A'||arr[i]=='E'||arr[i]=='I'||arr[i]=='O'||arr[i]=='U')  {
            count++;
        }
    }
    return count;
}

int csCount(char *arr) {
    int count=0;//counter
    for(int i=0;i<strlen(arr);i++) {
        //when char is in alphabet
        if(isalpha(arr[i])) {
            if(!(arr[i]=='a'||arr[i]=='e'||arr[i]=='i'||arr[i]=='o'||arr[i]=='u'||
               arr[i]=='A'||arr[i]=='E'||arr[i]=='I'||arr[i]=='O'||arr[i]=='U'))  {
                count++;
            }
        }
    }
    return count;
}

//initialize
Speaker *initArr(int n) {
    Speaker *arr=new Speaker[n];
    for(int i=0;i<n;i++) {
        arr[i].fee=0;
        arr[i].name="";
        arr[i].number="";
        arr[i].speTopc="";
    }
    return arr;
}

//get the information of one speaker
void iptData(Speaker &sp) {
    bool valid;
    //get the name
    cout<<"Name: ";
    cin.ignore();
    getline(cin,sp.name);
    //get the telephone number
    do {
        valid=true;
        cout<<"Input the phone number: ";
        cin>>sp.number;
        for(int i=0;i<sp.number.length();i++) {
            if(sp.number.at(i)<48||sp.number.at(i)>57)
                valid=false;
        }
        if(!valid)
            cout<<"Invalid input"<<endl;
    }while(!valid);
    //get the speaking topic
    cout<<"Speaking topic: ";
    cin.ignore();
    getline(cin,sp.speTopc);
    //get the fee required
    do {
        cout<<"Fee required: ";
        cin>>sp.fee;
        if(sp.fee<0)
            cout<<"Invalid input"<<endl;
    } while(sp.fee<0);
    
}

//output all data
void pntData(Speaker *arr,int n) {
    for(int i=0;i<n;i++) {
        if(arr[i].name!="") {
            cout<<"Speaker #"<<(i+1)<<endl;
            cout<<"  Name: "<<arr[i].name<<endl;
            cout<<"  Phone number: "<<arr[i].number<<endl;
            cout<<"  Speaking topic: "<<arr[i].speTopc<<endl;
            cout<<"  Fee Required: "<<arr[i].fee<<endl;
        } else {
            cout<<"Speaker #"<<(i+1)<<": ";
            cout<<"Empty file"<<endl;
        }
        cout<<endl;
    }
}

Student getData(int tstNum) {
    Student stu;
    stu.score=new int[tstNum];
    stu.ave=0;
    bool valid;
    //get the name
    cout<<"Name"<<": ";
    cin.ignore();
    getline(cin,stu.name);

    //get the id number
    do {
        valid=true;
        cout<<"Student ID: ";
        cin>>stu.id;
        //check the id number
        for(int j=0;j<stu.id.length();j++) {
            if(stu.id.at(j)<48||stu.id.at(j)>57)
                valid=false;
        }
        if(!valid)
            cout<<"Invalid input"<<endl;
    }while(!valid);

    //prompt user for all the test score for each student and add all test score
    for(int j=0;j<tstNum;j++) {
        do {
            cout<<"Test #"<<(j+1)<<": ";
            cin>>stu.score[j];
            if(stu.score[j]<0||stu.score[j]>100)
                cout<<"Invalid input"<<endl;
        } while(stu.score[j]<0||stu.score[j]>100);
        stu.ave+=stu.score[j];
    }
    //calculate the average
    stu.ave=stu.ave/static_cast<float>(tstNum);
    //Grade
    if(stu.ave>=91) {
        stu.grade='A';
    } else if(stu.ave>=81) {
        stu.grade='B';
    } else if(stu.ave>=71) {
        stu.grade='C';
    } else if(stu.ave>=61) {
        stu.grade='D';
    } else {
        stu.grade='F';
    }
    //deallocate memory
    delete [] stu.score;
    //return the structure
    return stu;
}

void pntScro(Student s) {
    cout<<"Name: "<<s.name<<"  ID: "<<s.id<<endl;
    cout<<"         Average test Score: "<<s.ave<<"  Course grade: "<<s.grade<<endl;
}

int *filArr(int n) {
    int *arr=new int[n];
    for(int i=0;i<n;i++) {
        arr[i]=rand()%90+10;
    }
    return arr;
}

void arrayToFile(string fileN,int *a,int n) {
    fstream file;
    file.open(fileN,ios::out|ios::binary);
    if(!file.fail())
        file.write(reinterpret_cast<char *>(a),sizeof(int)*n);
    file.close();
}

void fileToArray(string fileN,int *a,int n) {
    fstream file;
    file.open(fileN,ios::in|ios::binary);
    if(!file.fail()) {
        file.read(reinterpret_cast<char *>(a),sizeof(int)*n);
    }
    
    file.close();
}

//fill the name and quarter automatically
Sales *filDiv(int n) {
    Sales *div=new Sales[n];
    //element 0-3 is South, 4-7 West, 8-11 North, 12-15 South
    for(int i=0;i<n;i++) {
        if(i<4) div[i].name="East";
        else if(i<8) div[i].name="West";
        else if(i<12) div[i].name="North";
        else if(i<16) div[i].name="South";
        if(i%4==0) div[i].quarter=1;
        else if(i%4==1) div[i].quarter=2;
        else if(i%4==2) div[i].quarter=3;
        else if(i%4==3) div[i].quarter=4;
        
    }
    return div;
}