#include<iostream>
#include <fstream>
#include<string>

using namespace std;

//<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>> Functions Declaration <<<<<<<<<<>>>>>>>>>>>>//

void login(); // Login Page
void reg(); // register page
void start(); // start menu 
void mainmenu(); /// main menu
void detail(); // details about employee
void add(); // add more employee details
void del(); // edit employee details
void delfile(); // delete all data





// <<<<<<<<<>>>>>>>>>>> Global Variables declaration <<<<<<<<<>>>>>>>>>>>


string username;
string logo = "\n\n\n\t\t\t------------------------------------------\n\t\t\t|\t\tOffice System\t\t |\n\t\t\t------------------------------------------";
string gap = "\n\t\t\t\t";



string name[100];
string job[100];
int age[100],attendence[100],year[100],salary[100],bonus[100];

int main(){
	// Start Menu Function
	start();
	
return 0;
}




void reg(){
	int c;
	system("CLS");
	cout<<logo;
	cout<<gap<<"\t>>Registration Page<<\n";
	cout<<gap<<"Welcome To Registration Page\n";
	cout<<gap<<"Please Enter Desired Username (Without spaces) : \n";
	cout<<gap<<"Username (Without spaces) : ";
	cin>>username;
	
	// Writing username to file to save 
	ofstream user_data(username+".txt");
//	user_data<<username;
	user_data.close();
	system("CLS");
	cout<<logo;
	cout<<gap<<"You have been Registered Successfully ";
	
	again:
	cout<<gap<<"Press 1 to Goto Login Page";
	cout<<gap<<"Press 2 to Exit Program";
	cout<<gap<<"Choice : ";
	cin>>c;
	switch (c){
	
	case 1:
		login();
		break;
	case 2:
		break;
	default:
		goto again;

		
}
	
	
	


}
void login()
{
log:
	system("CLS");
	cout<<logo;
	cout<<gap<<"\tLogin Page\n";
	cout<<gap<<"Welcome To Login Page\n";
	cout<<gap<<"Enter username to login (Without spaces) : \n";
	cout<<gap<<"Username (Without spaces) : ";
	cin>>username;
	
	ifstream input_file(username+".txt");
	
  if (input_file.good()) {
    
    mainmenu();
    
  	} 
	else {
  	
  	again:
  	system("CLS");
  	cout<<logo;

  	int c;
  	cout<<gap<<"You Have Entered Incorrect USERNAME\n";
  	
	cout<<gap<<"Press 1 to Goto Register Page";
	cout<<gap<<"Press 2 to Try Again ";
	cout<<gap<<"Choice : ";
	cin>>c;
	switch (c){
	
	case 1:
		reg();
		break;
	case 2:
		goto log;
		break;
	default:
		goto again;
    
  }

	
}}
void start(){
again:
int c=0;
system("CLS");
cout<<logo;
cout<<gap<<"Welcome to Office System";
cout<<gap<<"Please login or Register\n";
cout<<gap<<"Press 1 to Login";
cout<<gap<<"Press 2 to Register  \n";
cout<<gap<<"Choice : ";
cin>>c;

switch (c){
	
	case 1:
		login();
		break;
	case 2:
		reg();
		break;
	default:
		goto again;

		
}
		
}

void mainmenu(){
	int c;
	again:
	system("CLS");
	cout<<logo;
	cout<<gap<<"\t MAIN MENU ";
	
cout<<gap<<"Select From Below \n";
cout<<gap<<"Press 1 to Add New Employee";
cout<<gap<<"Press 2 to Print Details About Employee";
cout<<gap<<"Press 3 to Delete Details of All Employee\n";
cout<<gap<<"Choice : ";
cin>>c;

switch (c){
	
	case 1:
		add();
		break;
	case 2:
		detail();
		break;
	case 3:
		del();
		break;
	
	default:
		goto again;

		
}
	
}

void add(){
	float perc;
	string answer;
	int size;
	cout<<"checkadd";
	system("CLS");
	cout<<logo;
	cout<<gap<<"Welcome To ADD Employee Section"<<endl<<gap<<"Please Refer to Instructions below";
	cout<<gap<<"Enter How many employees you want to add\n";
	cout<<gap<<"Choice : ";
	cin>>size;
	ofstream file;
	file.open(username+".txt",ios::app);
	for(int i;i<=size;i++)
	{
		
		cout<<gap<<"Enter Employee Name : ";
		cin>>name[i];
		file<<name[i]<<"\t";
		cout<<gap<<"Enter Employee Age : ";
		cin>>age[i];
		file<<age[i]<<"\t";
		cout<<gap<<"Enter Employee Job Title : ";
		cin>>job[i];
		file<<job[i]<<"\t\t";
		cout<<gap<<"Enter Employee Salary : ";
		cin>>salary[i];
		file<<salary[i]<<"\t";
		cout<<gap<<"Enter Years of Service : ";
		cin>>year[i];
		file<<year[i]<<"\t";
		x:
		cout<<gap<<"Add Bonus?";
		cout<<gap<<"Type YES to add";
		cout<<gap<<"Type NO to Skip and continue";
		cout<<gap<<"Choice : ";
		cin>>answer;
		
		// IF condition for bonus only
		
		if(answer=="yes"){
		int c ;
		cout<<gap<<"How much Percentage";
		cout<<gap<<"1 - 5%";
		cout<<gap<<"2 - 10%";
		cout<<gap<<"3 - 15%";
		cout<<gap<<"4 - 20%";
		cout<<gap<<"5 - go back";
		
		cout<<gap<<"Choice : ";
		cin>>c;
		
		switch(c){
		
		case 1:
//			cout<<"check";
			perc=0.05;
			bonus[i]=salary[i]*perc;
			cout<<gap<<"Bonus is :"<<bonus[i];
			file<<bonus[i]<<endl;
			break;
		case 2:
//			cout<<"check";
			perc=0.10;
			bonus[i]=salary[i]*perc;
			cout<<gap<<"Bonus is :"<<bonus[i];
			file<<bonus[i]<<endl;
			break;
		case 3:
//			cout<<"check";
			perc=0.15;
			bonus[i]=salary[i]*perc;
			cout<<gap<<"Bonus is :"<<bonus[i];
			file<<bonus[i]<<endl;
			break;
		case 4:
//			cout<<"check";
			perc=0.20;
			bonus[i]=salary[i]*perc;
			cout<<gap<<"Bonus is :"<<bonus[i];
			file<<bonus[i]<<endl;
			break;
		case 5:
			goto exit;
			break;
	
		default:
			goto x;
		}
		
		}
		exit:
		cout<<gap<<"Added "<<name[i]<<"'s Information\n";
		
	}

	int c;

	cout<<logo;
	cout<<gap<<"All data was Submitted ! ";
	cout<<gap<<"Type 1 to go to main menu";
	cout<<gap<<"Type 2 to EXIT";
	cout<<gap<<"Choice : ";
	cin>>c;
	switch(c){
	
	case 1:
	mainmenu(); 
		break;
	case 2:
		cout<<"Exit";
		break;	
}
	



}
void detail(){
	int c;
	system("CLS");
	string details;
	ifstream file;

	file.open(username+".txt");
	cout<<gap<<"Name\tAge\tJob Title\tSalary\tYears\tBonus\n";
	while(!file.eof())
		{
		getline(file, details);
		cout<<endl<<gap<<details<<"\t";
		cout<<endl;
		}
		
	x:
	cout<<logo;
	cout<<gap<<"All data was printed ! ";
	cout<<gap<<"Type 1 to go to main menu";
	cout<<gap<<"Type 2 to EXIT";
	cin>>c;
	switch(c){
	
	case 1:
	mainmenu(); 
		break;
	case 2:
		cout<<"Exit";
		break;
	default:
		goto x;
}
	
}

void del(){
x:
	int c;
	cout<<logo;
	cout<<gap<<"Are You Sure?";
	cout<<gap<<"Type 1 To Agree";
	cout<<gap<<"Type 2 To Disagree";
	cout<<gap<<"Choice : ";cin>>c;
	

	switch(c){
	
	case 1:
	delfile(); // function to clear out all information in file
		break;
	case 2:
		mainmenu();
		break;
	default:
		goto x;
}
}


void delfile(){
	x:
	int c;
	ofstream file(username+".txt");
	file<<"";
	file.close();
	cout<<logo;
	cout<<gap<<"All data was deleted ! ";
	cout<<gap<<"Type 1 to go to main menu";
	cout<<gap<<"Type 2 to EXIT";
	cout<<gap<<"Choice : ";
	cin>>c;
	switch(c){
	
	case 1:
	mainmenu(); 
		break;
	case 2:
		cout<<"Exit";
		break;
	default:
		goto x;
}
	
}