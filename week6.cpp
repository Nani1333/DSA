// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

string fun(int sum){
    if (sum == 0) return "0";
    string binary;
    while (sum > 0) {
        binary += (sum % 2) ? '1' : '0';
        sum /= 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

string addbin(string& a,string& b) {
    int c = 0;
    string res;
    int maxi= max(a.size(), b.size());
    string ap = string(maxi - a.size(), '0') + a;
    string bp = string(maxi - b.size(), '0') + b;
    for (int i = maxi - 1; i >= 0; --i) {
        int sum = (ap[i] - '0') + (bp[i] - '0') + c;
        res += (sum % 2) ? '1' : '0';
        c = sum / 2;
    }
    if(c) {
        res += '1';
    }
    reverse(res.begin(), res.end());
    return res;
}

string fun2(string bin){
    while (bin.size() > 4) {
        string overflow = bin.substr(0, bin.size() - 4);
        string remaining = bin.substr(bin.size() - 4);
        bin = addbin(remaining, overflow);
        if(bin.size() > 4){
            bin = bin.substr(bin.size() - 4);
        }
    }
    return bin;
}

string fun3(string wrapSum) {
    string res;
    for (char bit : wrapSum) {
        res += (bit == '0') ? '1' : '0';
    }
    return res;
}

int fun4(string bin) {
    int number = 0;
    int length = bin.size();
   
    for (int i = 0; i < length; ++i) {
        int bit = bin[length - i - 1] - '0';
        if (bit == 1) {
            number += pow(2, i);
        }
    }
    return number;
}

int fun5(string bin){
    for(auto it:bin){
        if(it == '1') return 0;
    }
    return 1;
}

int main() {
    int n,sum=0;
    cout<<"Enter no.of subunits:";
    cin>>n;
    cout<<"Enter subunits:"<<endl;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        sum+=x;
    }
    cout<<"Sender:"<<endl;
    string sumBin = fun(sum);
    cout<<"Sum:"<<sumBin<<endl;
    string wrapSum = fun2(sumBin);
    cout<<"Wrapped sum:"<<wrapSum<<endl;
    string compWrapSum = fun3(wrapSum);
    cout<<"Compliment of wrapped sum:"<<compWrapSum<<endl;
    int newNum = fun4(compWrapSum);
    cout<<"New number:"<<newNum<<endl;
   
    cout<<endl;
    cout<<"Reciever:"<<endl;
    sum+=newNum;
    sumBin = fun(sum);
    cout<<"Sum:"<<sumBin<<endl;
    wrapSum = fun2(sumBin);
    cout<<"Wrapped sum:"<<wrapSum<<endl;
    compWrapSum = fun3(wrapSum);
    cout<<"Compliment of wrapped sum:"<<compWrapSum<<endl;
    int check = fun5(compWrapSum);
    check?cout<<"No error detected"<<endl:cout<<"Error detected";
    return 0;
}
