#include <bits/stdc++.h> 
using namespace std; 

string xor1(string a, string b) { 
	string result = ""; 
	int n = b.length(); 
	for (int i = 1; i < n; i++) { 
		result += (a[i] != b[i] ? "1" : "0"); 
	} 
	return result; 
} 

string mod2div(string dividend, string divisor) { 
	int pick = divisor.length(); 
	string tmp = dividend.substr(0, pick); 
	int n = dividend.length(); 
	while (pick < n) { 
		if (tmp[0] == '1') 
			tmp = xor1(divisor, tmp) + dividend[pick]; 
		else
			tmp = xor1(string(pick, '0'), tmp) + dividend[pick]; 
		pick += 1; 
	} 
	if (tmp[0] == '1') 
		tmp = xor1(divisor, tmp); 
	else
		tmp = xor1(string(pick, '0'), tmp); 
	return tmp; 
} 

void encodeData(string data, string key) { 
	int l_key = key.length(); 
	string appended_data = data + string(l_key - 1, '0'); 
	string remainder = mod2div(appended_data, key); 
	string codeword = data + remainder; 
	cout << "Remainder:" << remainder << "\n"; 
	cout << "Code word:" << codeword << "\n"; 
} 

void receiver(string data, string key) { 
	string currxor = mod2div(data.substr(0, key.size()), key); 
	int curr = key.size(); 
	while (curr != data.size()) { 
		if (currxor.size() != key.size()) { 
			currxor.push_back(data[curr++]); 
		} else { 
			currxor = mod2div(currxor, key); 
		} 
	} 
	if (currxor == string(key.length(), '0') ) { 
		cout << "No error\n"; 
	} else { 
		cout << "Error\n"; 
	} 
} 

int main() { 
	string data, key; 
	cout << "Enter data: "; 
	cin >> data; 
	cout << "Enter key: "; 
	cin >> key; 
	cout << "Encoding...\n"; 
	encodeData(data, key); 
	cout << "\nReceiver's side:\nDecoding...\n"; 
	string codeword = data + mod2div(data + string(key.size() - 1, '0'), key); 
	cout << "Code word:" << codeword << "\n"; 
	receiver(codeword, key); 
	return 0; 
} 
