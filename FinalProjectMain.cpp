#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "FinalProject.hpp"

using namespace std;
vector <string> dataLog;
int logCounter = 0;


void pageBreak(){
	for(int i = 0; i < 60; i++)
		cout << " " << endl;
}

void addLog(string logInput){  //Log uses a queue (FIFO) with a max size of 10 entries
	dataLog.push_back(logInput);
	logCounter++;
	if(logCounter == 10){
		dataLog.erase(dataLog.begin());
		logCounter--;
	}
}

void printLog(){ //Prints Log
	for(int i = 0; i < dataLog.size(); i++){
		cout << dataLog[i] << endl;
	}
	cout << " " << endl;
}

void homePage(){
		cout << "HOMEPAGE" << endl;
		cout << "========" << endl;
		cout << "1. Add User" << endl;
	  cout << "2. Print Users" << endl;
		cout << "3. Edit User" << endl;
		cout << "4. Delete User Info" << endl;
		cout << "5. View Log" << endl;
		cout << "6. QUIT" << endl;
}

double passHash(string password){ //This function secures the users password by insuting the password is not stored in plain text
	double hashedPasswd;
	for(int i = 0; i < password.length(); i++){
		hashedPasswd = hashedPasswd + password[i]+((998/4)%8 + 449293);
	}
	return hashedPasswd;
}

userTree node;

int main(){
	string userChoice, password, userName, location, age, UserSearchName;
	double hashedPass;

	//Adding users to the User BST to pre populate the database
	node.addUserNode("Fred", "Colorado", "44", passHash("userpassword"));
	addLog("NEW USER,Fred,Colorado,44");
  node.addUserNode("Sarah", "Ohio", "36", passHash("userpasswordsara"));
	addLog("NEW USER,Sarah,Ohio,36");
	node.addUserNode("Brian", "California", "20", passHash("userBrian11010"));
	addLog("NEW USER,Brian,California,20");
	node.addUserNode("Tim", "New Mexico", "41", passHash("newMexicorox44"));
	addLog("NEW USER,Tim,NewMexico,41");
	node.addUserNode("Kate", "Florida", "84", passHash("kateisthebest"));
	addLog("NEW USER,Kate,Florida,84");

	while(userChoice != "6"){
		homePage();
		cout << " " << endl;
		cout << "Please select an action (1,2,3,4,5,6): ";
		getline(cin, userChoice);
		if(userChoice == "1"){ //Adding user is done here
			pageBreak();
			cout << "======================" << endl;
			cout << "       ADD USER" << endl;
			cout << "======================" << endl;
			cout << " " << endl;
			cout << "Please Enter UserName: " << endl;
			getline(cin, userName);
			cout << "Please Enter Password: " << endl;
			getline(cin, password);
			cout << "Please Enter Location: " << endl;
			getline(cin, location);
			cout << "Please Enter Age: " << endl;
			getline(cin, age);
			hashedPass = passHash(password);
			cout << " " << endl;
			cout << "   USER INFO" << endl;
			cout << "=================" << endl;
			cout << "User Name: " << userName << endl;
			cout << "User Location: " << location << endl;
			cout << "User Age: " << age << endl;
			cout << "Hashed Password: "<< hashedPass << endl;
			node.addUserNode(userName, location, age, hashedPass);
			cout << "User Added: " << endl;
			addLog("NEW USER," + userName + "," + location + "," + age);
			// CODE HERE TO ADD ENTRY TO THE LOG
		}else if(userChoice == "2"){ //Prints users name, location, and age. No login required to see the users
			pageBreak();
			cout << "======================" << endl;
			cout << "     PRINT USERS" << endl;
			cout << "======================" << endl;
			cout << " " << endl;
			cout << "Printing Users: " << endl;
			node.printUsers();
			addLog("...User Data Printed...");
		}else if(userChoice == "3"){ //This is used to edit "your" account. Must pass login verification to make changes
			pageBreak();
			cout << "======================" << endl;
			cout << "      EDIT USERS" << endl;
			cout << "======================" << endl;
			cout << " " << endl;
			cout << "Please Enter UserName: " << endl;
			getline(cin, userName);
			cout << "Please Enter Password: " << endl;
			getline(cin, password);
			pageBreak();
			cout << "Please Enter New Location: " << endl;
			getline(cin, location);
			cout << "Please Enter New Age: " << endl;
			getline(cin, age);
			hashedPass = passHash(password);
			node.editUser(userName, location, age, hashedPass);
			addLog("USER DATA CHANGE," + userName + "," + location + "," + age);
		}else if(userChoice == "4"){ //This allows a user to wipe there info from the database. Their node will not be deleted but the data will be changed.
			pageBreak();
			cout << "======================" << endl;
			cout << "     REMOVE USER DATA" << endl;
			cout << "======================" << endl;
			cout << " " << endl;
			cout << "Please Enter Username" << endl;
			getline(cin, userName);
			cout << "Please Enter Password: " << endl;
			getline(cin, password);
			hashedPass = passHash(password);
			node.deleteUserInfo(userName, hashedPass);
      addLog("USER: " + userName + "-- Info has been cleared from the system");
		}else if(userChoice == "5"){ //This prints the log
			pageBreak();
			cout << "======================" << endl;
			cout << "      USER LOG" << endl;
			cout << "======================" << endl;
			cout << " " << endl;
			printLog();
			addLog("...Log Viewed By User...");
		}
	}
	pageBreak();
	pageBreak();
	return 0;
}
