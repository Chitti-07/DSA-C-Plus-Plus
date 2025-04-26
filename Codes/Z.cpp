// #include <stdio.h>

// float stringToFloat(const char *str) {
//     float result = 0.0, decimalFactor = 1.0;
//     int sign = 1, decimalFlag = 0;

//     // Handle sign
//     if (*str == '-') {
//         sign = -1;
//         str++;
//     } else if (*str == '+') {
//         str++;
//     }

//     // Convert each character
//     while (*str) {
//         if (*str == '.') {
//             if (decimalFlag) break;  // Multiple decimal points (invalid input)
//             decimalFlag = 1;
//             str++;
//             continue;
//         }
        
//         if (*str < '0' || *str > '9') break;  // Invalid character
        
//         if (decimalFlag) {
//             decimalFactor /= 10.0;
//             result += (*str - '0') * decimalFactor;
//         } else {
//             result = result * 10.0 + (*str - '0');
//         }
        
//         str++;
//     }

//     return result * sign;
// }

// int main() {
//     const char *str = "-123.12345";
//     float num = stringToFloat(str);
//     printf("Converted number: %f\n", num);
//     return 0;
// }

// #include <stdio.h>

// #define MY_SIZE(x) ((char*)(&x+1) - (char*)(&x))
// #include <stdio.h>

// #define SIZEOF_VAR(x) ((char *)(&x + 1) - (char *)(&x))
// #define SIZEOF_TYPE(type) ((size_t)(&((type *)0)[1]))

// typedef struct{
//     char a;
//     int b;
//     double c;
// }Sample;

// int main() {
//     Sample *s = 0;
//     s++;
//     printf("%d\n", (int)s);

//     printf("Size of structure (using variable): %lu bytes\n", SIZEOF_VAR(s));
//     printf("Size of structure (using type): %lu bytes\n", SIZEOF_TYPE(Sample));

//     return 0;
// }


// #include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
// 	int n;
// 	cin >> n;
// 	if (n < 26) {
// 		cout << "NO";
// 		return 0;
// 	}

// 	vector<bool>alpha(26, false);
// 	for (auto ch : alpha) {
// 		cout << ch << " ";
// 	}
// 	cout << endl;
// 	char ch;
// 	for (int i = 0; i < n; i++) {
// 		cin >> ch;
// 		if (ch >= 'A' && ch <= 'Z') {
// 			ch = tolower(ch);
// 		}
// 		alpha[ch - 'a'] = true;
// 	}

// 	for (auto ch : alpha) {
// 		cout << ch << " ";
// 	}
// 	cout << endl;

// 	bool isPangram = true;
// 	for (auto ch : alpha) {
// 		if (ch == 0) {
// 			isPangram = false;
// 			break;
// 		}
// 	}

// 	if (isPangram) {
// 		cout << "YES";
// 	}else {
// 		cout << "NO";
// 	}


//     return 0;
// }


#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;

	cin >> n;

	int police = 0, untreat = 0;
	int input;

	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input != -1) {
			police += input;
		}else {
			if (police > 0) {
				police--;
			}else {
				untreat++;
			}
		}
	}

	cout << untreat;
    return 0;
}