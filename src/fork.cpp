//============================================================================
// Name        : fork.cpp
// Author      : Tyler Koch
// Version     :
// Copyright   : Your copyright notice
// Description : lab2 forking
//============================================================================

#include <stdio.h>
#include <unistd.h>
#include <iostream>l

using namespace std;

//helpful command for checking specific processes
//ps -A | grep PIDgoeshere
int forkDepth(int nn) {

	int i;
		//print out parent.
		cout << "I am the parent.  My process ID is " << getpid()
				<< " and my parent’s process ID is " << getppid() << "."
				<< endl;
		//loop for entered number
		for (i = 1; i < nn; i++) {
			//fork child
			if (fork()) {
				//do division
				double div = 1000000.0;
				for (int i = 0; i < 10000000; i++) {
					div /= i;
				}
				//sleep child
				sleep(30);

				return 0;
			}

			if (i == 1) {

				cout << "I am the child.  My process ID is " << getpid()
						<< " and my parent’s process ID is " << getppid() << "."
						<< endl;
			}
			if (i == 2) {
				cout << "I am the grandchild. My process ID is " << getpid()
						<< " and my parent’s process ID is " << getppid() << "."
						<< endl;
			}
			if (i == 3) {
				cout << "I am the great grandchild. My process ID is "
						<< getpid() << " and my parent’s process ID is "
						<< getppid() << "." << endl;
			}

		}

		return 1;

}

int main()
{
	int nn;
	cout << "Please enter the depth of the family tree: ";
	cin >> nn;
	//loop to ask for number of children unless zero is entered
	while (nn > 0)
	{

		if(forkDepth(nn)){
			cout << "Please enter the depth of the family tree: ";
			cin >> nn;
		}else{
			break;
		}

	}

	return 0;
}
