#include<iostream>
#include<windows.h>
using namespace std;

void yellow(string str)
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,14);
    cout<<str;
    SetConsoleTextAttribute(h,15);

}
void green(string str)
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,10);
    cout<<str;
    SetConsoleTextAttribute(h,15);
}
void red(string str)
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,12);
    cout<<str;
    SetConsoleTextAttribute(h,15);
}

void assignment_marks(string str,int &as_sub)
{
    bool flag;
    do{
        flag=true;
        cout<<str<<" Assignment Score = ";
        cin>>as_sub; 

        if(as_sub<0 || as_sub>20)
        {
            cout<<endl;
            red("SCORE MUST BE FROM 0 TO 20 ! TRY AGAIN");
            cout<<endl<<endl;
            flag=false;
        }

    }while(flag==false);
}

void quize_marks(string str,int &quz_topic)
{
    bool flag;
    do{
        flag=true;
        cout<<str<<" Score = "; 
        cin>>quz_topic;

        if(quz_topic<0 || quz_topic>10)
        {
            cout<<endl;
            red("SCORE MUST BE FROM 0 TO 10 ! TRY AGAIN");
            cout<<endl<<endl;
            flag=false;
        }
    }while(flag==false);
}

void subject_marks(string str,int &sub)
{
    bool flag;
    do{
        flag=true;
        cout<<str<<" Marks = "; 
        cin>>sub;

        if(sub<0 || sub>100)
        {
            cout<<endl;
            red("SCORE MUST BE FROM 0 TO 100 ! TRY AGAIN");
            cout<<endl<<endl;
            flag=false;
        }
    }while(flag==false);
}

float assignment_marks_calculation(int a,int b,int c,int d)
{
    int sum=a+b+c+d;
    float percent=(sum/80.0)*100;
    
    if(percent>=90)
        cout<<endl<<endl<<"Excellent ! You Got "<<percent<<"% "<<"in assignment with A+ grade.";
    else if(percent>=75 && percent<90)
        cout<<endl<<endl<<"Great ! You Got "<<percent<<"% "<<"in assignment with B grade.";
    else if(percent>=50 && percent<75)
        cout<<endl<<endl<<"OK ! You Got "<<percent<<"% "<<"in assignment with C grade.";
    else
        cout<<endl<<endl<<"Poor Marks ! You Got only "<<percent<<"% "<<"in assignment with D grade."; 
return percent;
}

float quiz_marks_calculation(int a,int b,int c)
{
    int sum=a+b+c;
    float percent=(sum/30.0)*100;
    
    if(percent>=90)
        cout<<endl<<endl<<"Excellent ! You Got "<<percent<<"% "<<"in qize competition with A+ grade.";
    else if(percent>=75 && percent<90)
        cout<<endl<<endl<<"Great ! You Got "<<percent<<"% "<<"in qize competition with B grade.";
    else if(percent>=50 && percent<75)
        cout<<endl<<endl<<"OK ! You Got "<<percent<<"% "<<"in qize competition with C grade.";
    else
        cout<<endl<<endl<<"Poor Marks ! You Got only "<<percent<<"% "<<"in qize competition with D grade.";
return percent;
}


float subject_marks_calculation(int a,int b,int c,int d,int e)
{
    int sum=a+b+c+d+e;
    float percent=(sum/500.0)*100;
    
    if(percent>=90)
        cout<<endl<<endl<<"Excellent ! You Got "<<percent<<"% "<<"in final exam with A+ grade."<<endl;
    else if(percent>=75 && percent<90)
        cout<<endl<<endl<<"Great ! You Got "<<percent<<"% "<<"in final exam with B grade."<<endl;
    else if(percent>=50 && percent<75)
        cout<<endl<<endl<<"OK ! You Got "<<percent<<"% "<<"in final exam with C grade."<<endl;
    else
        cout<<endl<<endl<<"Poor Marks ! You Got only "<<percent<<"% "<<"in final exam with D grade."<<endl;
return percent;
}

void final_result(int a,int b,int c)
{
    int sum=a+b+c;
    float avg=sum/3;
    
    if(avg>=80)
    {
        cout<<endl<<endl;
    green("OverAll ! Your cumulative grades are EXCELLENT.");
cout<<endl<<endl;
    }        
    else if(avg>=60 && avg<80)
    {
        cout<<endl<<endl;
    green("OverAll ! Your cumulative grades are GOOD.");
cout<<endl<<endl;
    }
    else if(avg>=50 && avg<60)
    {
        cout<<endl<<endl;
    green("OverAll ! Your cumulative grades are OK.");
cout<<endl<<endl;
    }
    else
    {
        cout<<endl<<endl;
    green("OverAll ! Your cumulative grades are VERY POOR. You need work hard.");
cout<<endl<<endl;
    }
}

int main(){
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,15);
    
    // ! student details
    char stu_name[20];
    int stu_id;
    int stu_class;

    //! assignement scores
    int coa_as;
    int wd_as;
    int oops_as;
    int dbms_as;

    //! quizzes score
    int maths_olum;
    int gk_quiz;
    int subject_quiz;

    //! subject marks 
    int maths_marks;
    int phy_marks;
    int chem_marks;
    int hindi_marks;
    int english_marks;

bool consent=true;
char consent_check='0';

cout<<endl<<"\t\t\t\t\t";
green("STUDENT GRADE CALCULATION SYSTEM");
cout<<endl;
do{

    // ! student details
    cout<<endl<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    cout<<endl<<endl;
    yellow("Enter Student Details");
    cout<<endl;
    cout<<"------------------------\n";
    cout<<"Student Name = ";
    cin.getline(stu_name, sizeof(stu_name));

    cout<<"Class = ";
    cin>>stu_class;

    cout<<"Student ID = ";
    cin>>stu_id;

    cout<<"==============================================================\n";
    cout<<"Student Found -> Name = "<<stu_name<<", ID = "<<stu_id<<endl<<endl;

// ! assignment marks
 yellow("Enter Score of Assignments out of 20");
    cout<<"\n----------------------------------------\n";

assignment_marks("COA",coa_as);
assignment_marks("DBMS",dbms_as);
assignment_marks("WD",wd_as);
assignment_marks("OOPS",oops_as);


// ! quize marks

    cout<<endl<<endl;
 yellow("Enter Score of Quizzes out of 10");
    cout<<"\n----------------------------------------\n";
    
quize_marks("Maths Olumpiad",maths_olum);
quize_marks("GK Quize",gk_quiz);
quize_marks("Subject Quize",subject_quiz);

// ! SUBJECT MARKS
    cout<<endl<<endl;
 yellow("Enter Examination Marks out of 100");
    cout<<"\n----------------------------------------\n";
    
subject_marks("Maths",maths_marks);
subject_marks("Physic",phy_marks);
subject_marks("Chemisty",chem_marks);
subject_marks("Hindi",hindi_marks);
subject_marks("English",english_marks);

cout<<endl<<"=============================================="<<endl<<endl;
 yellow("SEPARATE RESULTS FOR EACH");
cout<<endl;
cout<<endl<<"==============================================";


//! assignment marks calculation
float as_marks_cal=assignment_marks_calculation(wd_as,dbms_as,oops_as,coa_as);
    cout<<"\n------------------------------------------------------";

//! quize marks calculation
float quiz_marks_cal=quiz_marks_calculation(maths_olum,gk_quiz,subject_quiz);
    cout<<"\n------------------------------------------------------";

//! subject marks calculation
float sub_marks_cal=subject_marks_calculation(maths_marks,phy_marks,chem_marks,hindi_marks,english_marks);

cout<<endl<<"======================================================================="<<endl;
    //! overall calculation cumulative average
    final_result(as_marks_cal,quiz_marks_cal,sub_marks_cal);
cout<<endl<<"======================================================================="<<endl;

cout<<endl;
yellow("Do You want to calculate another student's marks (y/n) = ");

cin>>consent_check;
cin.ignore();

if(consent_check=='n')
{
consent=false;
}
}while(consent==true);

    return 0;
}



















