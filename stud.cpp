#include<iostream>
using namespace std;

class Student{
    string name;
    int roll;
    public:
    studentDetails(string name,int roll){
        this->name=name;
        this->roll=roll;
    }
    show(){
        cout<<"name:"<<name<<endl;
        cout<<"roll:"<<roll<<endl;
    }
};
class Subject1:public virtual Student{
    int marks;
    public:
    subject1Marks(int marks){
        this->marks=marks;
    }
    show(){
        cout<<endl;
        Student::show();
        cout<<"Marks 1: "<<marks<<endl;
    }
};
class Subject2:public virtual Student{
    int marks;
    public:
    subject2Marks(int marks){
        this->marks=marks;
    }
    show(){
        cout<<endl;
        Student::show();
        cout<<"Marks 2: "<<marks<<endl;
    }
};
class Details:public Subject1,public Subject2{
    public:
    string name;
    int roll;
    int marks1,marks2;
    enterDetails(){
        studentDetails(name,roll);
        subject1Marks(marks1);
        subject2Marks(marks2);
    }
    static void bestPerformer(Details students[],int n){
        int max=0;
        string name;
        int roll;
        for(int i=0;i<n;i++){
            if(max<students[i].marks1+students[i].marks2){
                max=students[i].marks1+students[i].marks2;
                name=students[i].name;
                roll=students[i].roll;
            }
        }
        cout<<"Best Performer is: "<<name <<" , roll is: "<<roll;
    }
    showMarks1(){
        Subject1::show();
    }
    showMarks2(){
        Subject2::show();
    }
};
int main(){
    cout<<"enter the number of students: ";
    int n;
    cin>>n;
    Details student[n];
    for(int i=0;i<n;i++){
        cout<<"id:"<<i+1<<":\nenter the :"<<endl<<"Name: ";
        cin>>student[i].name;
        cout<<"Roll: ";
        cin>>student[i].roll;
        cout<<"Marks1: ";
        cin>>student[i].marks1;
        cout<<"Marks2: ";
        cin>>student[i].marks2;
        student[i].enterDetails();
    }
    Details::bestPerformer(student,n);
    cout<<"\nEnter the student id:"<<endl;
    int i;
    cin>>i;
    if(i>0&&i<=n){
    cout<<"Want to see press \n1.subject1 Marks \n2.subject2 Marks\n:";
    int no;
    cin>>no;
    if(no==1){
        student[i-1].showMarks1();
    }else{
        student[i-1].showMarks2();
    }
    }else{
        cout<<"Invalid input!!\n";
    }
}
