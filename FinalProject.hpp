#include <string>

using namespace std;

struct userNode{
    string userName;
    string userLocation;
    string age;
    double hashedPasswd;

    userNode* left;
    userNode* right;

    userNode(string uN, string uL, string a, double hP) {
        userName = uN;
        userLocation = uL;
        age = a;
        hashedPasswd = hP;
    }
};


class userTree{
    private:
        userNode* root;
    public:
        userTree();
        ~userTree();
        void printUsers();
        void editUser(string userName, string userLocation, string age, double hahsedPass);
        void addUserNode(string userName, string userLocation, string age, double hashedPasswd);
        void deleteUserInfo(string userName, double hashedPass);
};
