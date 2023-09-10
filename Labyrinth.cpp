#include <iostream>
using namespace std;

const string W = "==";
const string H = "||";

int main()
{
	int enter = 0;
	do {
		int width, height = 0;
		cout << "Enter width:";
		cin >> width;
		cout << "Enter height:";
		cin >> height;

		cout << endl;
		cout << "  ";
		for (int i = 0; i < width;i++) {
			cout << W;
		}

		cout << endl;

		for (int j = 0; j < height;j++) {
			cout << H;
			for (int i = 0; i < width;i++) {
				cout << "  ";
			}
			cout << H << endl;
		}

		cout << "  ";

		for (int i = 0; i < width;i++) {
			cout << W;
		}

	} while (enter);
}

