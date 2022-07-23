#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

int str_len = 0;

char XOR(char a, char b) {
    return a == b ? '0' : '1'; }

string tB(char deci) {
    int dec = static_cast<int>(deci);
    string bin;
    while(dec > 0 ){
        char temp = (dec % 2) + '0';
        bin = temp + bin;
        dec = dec/2; }
    while( bin.length() < 8 )
        bin = '0' + bin;
    return bin;
}


string UtB(uint64_t dec) {
    string bin;
    while(dec > 0 ){
        char temp = (dec % 2) + '0';
        bin = temp + bin;
        dec = dec/2; }
    while( bin.length() < 32)
        bin = '0' + bin;
    return bin;
}


char tD(string bin) {
    int deci = 0;
    for( int i = 0; i < bin.length(); i++ ){
        int temp = bin.length() - i - 1;
        if( bin[temp] == '1' )
            deci += pow(2, i); }
    return (char)deci; }

uint64_t toDecimalUint(string bin) {
    uint64_t deci = 0;
    for( int i = 0; i < bin.length(); i++ ){
        int temp = bin.length() - i - 1;
        if( bin[temp] == '1' )
            deci += pow(2, i); }
    return deci;
}

string encrypt( string str ) {
    str_len = str.length();
    string bin;
    for( int i = 0; i < str_len; i++)
        bin += tB(str[i]);
    string L = bin.substr(0, bin.length()/2);
    string R = bin.substr(bin.length()/2);
    for( int i = 0; i < 8; i++ ){
        string nL = R;
        string nR;
        R = UtB((pow(2, 64*(abs(abs(sin(toDecimalUint(R)))*log2(abs(cos(1433893959))+1)))) - 1));
        for( int j = 0; j < L.length(); j++ )
            nR += XOR(R[j], L[j]);
        L = nL;
        R = nR; }
    bin = R + L;
    string dret;
    for( int i = 0; i < bin.length(); i+=8 ){
        string sub = bin.substr(i, 8);
        char ch = tD(sub);
        dret += ch; }
    cout << dret;
    return bin;
}

string decrypt( string bin ){
    string L = bin.substr(0, bin.length()/2);
    string R = bin.substr(bin.length()/2);
    for( int i = 8; i > 0; i-- ){
        string nL = R;
        string nR;
        R = UtB((pow(2, 64*(abs(abs(sin(toDecimalUint(R)))*log2(abs(cos(1433893959))+1)))) - 1));
        for( int j = 0; j < L.length(); j++ ){
            nR += XOR(R[j], L[j]);
        }
        L = nL;
        R = nR;
    }
    bin = R + L;
    string dret;
    for( int i = 0; i < bin.length(); i+=8 ){
        string sub = bin.substr(i, 8);
        char ch = tD(sub);
        dret += ch;
    }
    return dret;
}



int main(){
    string s;
    vector<string> v_s;
    vector<string> v_s_decr;
    constexpr int size = 16;
    cout << "Realialisation Feistel Net on C++ version 1.01" << endl;
    cout<<"<FSNC++> Enter your text to encrypt right here: ";
    getline(cin, s);
    int length = s.length();
    int quotient = length/size;
    if(length % size != 0)
        quotient++;
    for(int i = 0; i < quotient; i++) {
        string new_message = s.substr(0, size);
        v_s.push_back(new_message);
        s.erase(0, size);
    }
    string last_string = v_s.at(v_s.size()-1);
    if (last_string.length() < size)
        last_string.resize(size, '0');
    cout << "<FSNC++> Here is your encrypted message:  ";
    for (const auto& block : v_s){
        auto str = encrypt(block);
        v_s_decr.push_back(str);
    }
    cout << endl;
    cout << "<FSNC++> Now you can see how perfect my program decrypted your message:  ";
    for (const auto& block : v_s_decr)
        cout << decrypt(block);
}
