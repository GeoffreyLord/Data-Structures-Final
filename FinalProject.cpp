#include "FinalProject.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


using namespace std;

userTree::userTree(){
	root = NULL;
}

void destructorHelper(userNode *node){
	if(node!=NULL){
		destructorHelper(node->left);
		destructorHelper(node->right);
		delete node;
		node = NULL;
	}
}

userTree::~userTree(){
	destructorHelper(root);
}

userTree *printHelper(userNode *node){
    if(node != NULL){
        printHelper(node->left);
        cout << "Username: " << node->userName << endl;
				cout << "                  User Location: " << node->userLocation << endl;
				cout << "                  User Age: " << node->age << endl;
        printHelper(node->right);
    }
	return 0;
}

void userTree::printUsers(){
    if(root == NULL){
        cout << "NO USERS" << endl;
    }else{
        printHelper(root);
    }
} //DONE

userNode *addUserHelper(userNode * node, string userName, string userLocation, string age, double hashedPasswd){ //Helper function for adding users to the BST
	if(node == NULL){
		userNode *newNode = new userNode(userName, userLocation, age, hashedPasswd);
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}else if(userName > node->userName){
		node->right = addUserHelper(node->right, userName, userLocation, age, hashedPasswd);
	}else if(userName < node->userName){
		node->left = addUserHelper(node->left, userName, userLocation, age, hashedPasswd);
	}
	return node;
}

void userTree::addUserNode(string userName, string userLocation, string age, double hashedPasswd){ //Add user function
    if(root == NULL){
       root = new userNode(userName, userLocation, age, hashedPasswd);
    }
  addUserHelper(root, userName, userLocation, age, hashedPasswd);
}

userNode *editUserHelper(userNode *node, string userName, string userLocation, string age, double hashedPass){ //Edit user helper. Must login to edit.
	if(node != NULL){
		if(node->userName == userName){
			if(node->hashedPasswd == hashedPass){
				cout << "Old User Info:" << endl;
				cout << "==================" << endl;
				cout << "User Name:" << node->userName << endl;
				cout << "User Location :" << node->userLocation << endl;
				cout << "User Age :" << node->age << endl;
				cout << "User Password :" << node->hashedPasswd << endl;
				node->userLocation = userLocation;
				node->age = age;
				cout << " " << endl;
				cout << " " << endl;
				cout << "Updated User Info:" << endl;
				cout << "==================" << endl;
				cout << "User Name: " << node->userName << endl;
				cout << "User Location: " << node->userLocation << endl;
				cout << "User Age: " << node->age << endl;
				cout << "User Password: " << node->hashedPasswd << endl;
			}else{
				cout << "ACCESS DENIED: INCORRECT PASSWORD" << endl;
				cout << " " << endl;
				cout << " " << endl;
				cout << " " << endl;
			}
		}
			editUserHelper(node->left, userName, userLocation, age, hashedPass);
			editUserHelper(node->right, userName, userLocation, age, hashedPass);
	}
	return 0;
}

void userTree::editUser(string userName, string userLocation, string age, double hashedPass){ //Edits user finction
  editUserHelper(root, userName, userLocation, age, hashedPass);
}

userNode *deleteUserInfoHelper(userNode *node, string userName, double hashedPass){ //Wipe user data function
	if(node != NULL){
		if(node->userName == userName){
			if(node->hashedPasswd == hashedPass){
				node->userLocation = "XXXXXXXX";
				node->age = "XXXXXXXX";
				node->userName = "XXXXXXXX";
				node->hashedPasswd = 0;
			}else{
				cout << "ACCESS DENIED: INCORRECT PASSWORD" << endl;
				cout << " " << endl;
				cout << " " << endl;
				cout << " " << endl;
			}
		}
			deleteUserInfoHelper(node->left, userName, hashedPass);
			deleteUserInfoHelper(node->right, userName, hashedPass);
	}
	return 0;
}

void userTree::deleteUserInfo(string userName, double hashedPass){
  deleteUserInfoHelper(root, userName, hashedPass);
}
