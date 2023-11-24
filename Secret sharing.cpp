#include <iostream>
#include <string>
using namespace std;
int main() {
	srand(time(0));
	string a, b, temp;
	char dc;
	int n, i, j, k, i1, i2;
	while (true) {
		cout << "Distribute or combine (d/c or press 0 to exit) ";
		dc = getchar();
		while (getchar() != '\n')continue;
		if (dc == '0')
			break;
		else if (dc == 'd') {
			cout << "Input your secret (trust me)\nS=";
			getline(cin, a);
			cout << "Input number of parts (n>1)\nn=";
			cin >> n;
			while (getchar() != '\n')continue;
			if (n <= 1)
				break;
			for (i = 0; i < n - 1; i++) {
				for (j = 0; j < size(a); j++) {
					b = b + to_string(rand() % 2);
				}
			}
			temp = a;
			for (i = 0; i < n - 1; i++) {
				for (j = 0; j < size(a); j++) {
					i1 = (int)temp[j] - 48;
					i2 = (int)b[j + i * size(a)] - 48;
					i1 = i1 ^ i2;
					temp[j] = (char)i1 + 48;
				}
			}
			k = 1;
			for (i = 0; i < size(b); i += size(a)) {
				cout << "S" << k << "="; k++; for (j = 0; j < size(a); j++) { cout << b[j + i]; } cout << endl;
			}
			cout << "S" << n << "=" << temp << endl;
		}
		else if (dc == 'c') {
			cout << "Input number of parts (n>1)\nn=";
			cin >> n;
			while (getchar() != '\n')continue;
			if (n <= 1)
				break;
			cout << "Input 1 part\nS1=";
			getline(cin, a);
			for (i = 1; i < n; i++) {
				cout << "Input " << i + 1 << " part\nS" << i + 1 << "=";
				getline(cin, temp);
				for (j = 0; j < size(a); j++) {
					i1 = (int)a[j] - 48;
					i2 = (int)temp[j] - 48;
					i1 = i1 ^ i2;
					a[j] = (char)i1 + 48;
				}
			}
			cout << "S=" << a << endl;
		}
		else {
			cout << "Are you crazy?!\nUgh, let's start over\n";
		}
	}
}