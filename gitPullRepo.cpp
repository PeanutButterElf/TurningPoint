#include <iostream>

using namespace std;

bool checkInternet();

int main()
{
	if(checkInternet()) {
		system("git pull");
	}
	return 0;
}

bool checkInternet()
{
        if(system("ping github.com -c 1")) {
                cout << "Cannot Complete Git Update: No Internet Connection or Github Repo is Down!" << endl;
                cout << "Press any [Enter] to Continue..";
                cin.get();
                return false;
        }
        return true;
}

