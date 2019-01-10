#include <iostream>

using namespace std;

bool checkInternet();

int main() 
{
	if(checkInternet()) 
	{
		string input;
		cout << "What would you like the message to be: ";
		cin >> input;
		input = "git commit -m '" + input + "'"; 
		//system("cd /Documents/Vex/TurningPoint/");
		system("git pull");
		system("git add -A");
		system(input.c_str());
		system("git push");
	}

	return 0;
}

bool checkInternet() 
{
	if(system("ping github.com -c 1")) {
		cout << "Cannot Complete Git Update: No Intenet Connection or Github Repo is Down!" << endl;
	 	cout << "Press any [Enter] to Continue..";
		cin.get();
		return false;
	}
	return true;
}
