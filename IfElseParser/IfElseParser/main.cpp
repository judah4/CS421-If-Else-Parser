#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int state = 0;
vector<char> stack;


void Failure() {
	state = -1;
}

int process(char input) {
	switch (state) {
	case 0:
		switch (input) {
		case 'i':
			if (stack.at(stack.size() - 1) == 'z') {
				state = 1;
			}
			else {
				Failure();
			}
			break;
		default:
			Failure();
			return 1;
			break;
		}
		break;
	case 1:
		switch (input) {
		case 'f':
			if (stack.at(stack.size() - 1) == 'z') {
				stack.push_back('i');
				state = 2;
			}
			else {
				Failure();
			}
			break;
		default:
			state = -1;
			return 1;
			break;
		}
		break;
	default:
		state = -1;
		return 1;
		break;
	}

	return 0;
}

int main()
{
	stack.push_back('z');

	std::cout << "If Else Parsing" << endl;

	ifstream infile("sequence.txt");
	if (infile.is_open()) {
		while (!infile.eof()) {

			char read = infile.get();
			//cout << read;
			process(read);
				//cout << "Sequence is syntactically incorrect";
			

		}
	}
	infile.close();

	cout << endl << "Enter any to continue... " << endl;

	char end;
	cin >> end;
	return 0;

}