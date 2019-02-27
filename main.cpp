#include <iostream>
using namespace std;

int transferMargorp(int e) {
	int transfer = 0;
	e = e * 1;
	return e;
}

int transferEdoc(int e) {
	int transfer = 0;
	e = e * 3;
	return e;
}
bool edocTest(int e) {
	bool test = false;
	e = e % 12;
	if((1 == e) || (2 == e)){
		test = true;
		}
	return test;
}

int xpCalculator( int edoc, int margorp, int candy) {
	int xp = 0;
	for (int n = candy; n >= 12; n--) {
		// sum = n % 12
		if((0 == n % 12) && (edoc >= 1)){
			xp = xp + 500;
			edoc--;
			margorp++;
			candy = candy - 12;
			candy++;
			//cout << "you have " << xp << " XP\n";
		if(1 == n / 12)		
			cout << "you have " << candy << "pieces of candy left\n";
			cout << "you will have evolved " << margorp << " Margorps\n";
		} if(edoc < 1) {
			cout << "You can't evolve anymore edocs try again.\n";
			break;
		}
}
	
	return xp;
}

int main() {

	int edoc = 0 , candy = 0 , margorp = 0, transfer = 0 , choice = 0 , totalXp ,  remainder;
	bool test = false;
	
	cout << "How many Edocs have you caught? "; 
	cin >> edoc;
	cout << "How many margorps do you have? ";
	cin >> margorp;
	cout << "How much candy do you have? ";
	cin >> candy;

	do{
		cout << "Edoc = " << edoc << " Margorps = " << margorp << " Candy = " << candy << endl;
	
	
		if(edoc < 1) {
			cout << "You can't evolve any edoc, catch more.\n";
		}
		
		test = edocTest(edoc);
		if(test == true){
			cout << "Catch more Edoc before evolving\n";
		} else
			cout <<"You should evolve your Edoc\n";
		
		cout << "Choose 1 to use the Edoc calculator.\n";
		cout << "Choose 2 to transfer Edocs for candy.\n";
		cout << "Choose 3 to transfer Margorps for candy.\n";
		cout << "Choose 4 to quit.\n";
		cin >> choice;
	
		switch(choice)
		{
			case 1:
				totalXp = xpCalculator( edoc , margorp, candy); 
				cout << "You will earn " << totalXp << " If you evolve your Edocs.\n";
				cout << " You will have " << candy << " pieces of candy left.\n";
				cout << " You will have " << edoc << " Edocs left.\n";
			break;
			case 2:
				cout << " How many Edocs do you wish to transfer for candy? ";
				cin	>> transfer;
				if(transfer <= edoc) {
					edoc = transfer - edoc;
					candy = transferEdoc(transfer) + candy;
					cout << "You have gained " << candy << " candy.\n"; 
				} else {
				cout << "You dont have that many Edocs try again!";
				}
			break;
			case 3:
				cout << " How many Margorps do you wish to transfer for candy? ";
				cin	>> transfer;
				if(transfer <= margorp) {
					edoc = transfer - margorp;
					candy = transferMargorp(transfer) + candy;
					cout << "You have gained " << candy << " candy.\n"; 
				} else {
				cout << "You dont have that many Margorps try again!";
				}
		
			break;
			case 4:
				cout << "End of program\n";
			break;
	}
	}while (choice != 4);
return 0;
}