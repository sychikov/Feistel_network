#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

const int ROUNDS = 8;
const int BLOCK_SIZE = 64;
int str_len = 0;

uint64_t function(uint64_t f)
{
    return (pow(2, 128) - 1) *(abs(abs(cos(f))*pow(5,(-1)*2503480371539364932)));
}

string binary(uint64_t dec)
{
    string bbin;
    while(dec > 0 ){
        char temp = (dec % 2) + '0';
        bbin = temp + bbin;
        dec = dec/2;
    }

    while( bbin.length() < BLOCK_SIZE){
        bbin = '0' + bbin;
    }

    return bbin;
}


uint64_t decimal(string bin)
{
    uint64_t deci = 0;
    for( int i = 0; i < bin.length(); i++ ){
        int temp = bin.length() - i - 1;
        if( bin[temp] == '1' ){
            deci += pow(2, i);
        }
    }
    return deci;

}


string Encryption( string stri )
{

    string L = stri.substr(0, stri.length()/2);
    string R = stri.substr(stri.length()/2);


    for( int i = 0; i < ROUNDS; i++ ){
        string newL = R;
        string newR;

        R = binary(function(decimal(R)));

        for( int j = 0; j < L.length(); j++ ){
            newR += R[j] == L[j] ? '0' : '1';
        }

        L = newL;
        R = newR;
    }

    stri = R + L;

     cout << stri;

    return stri;
}

string Dencryption( string bb ){

    string L = bb.substr(0, bb.length()/2);
    string R = bb.substr(bb.length()/2);



    for( int i = ROUNDS; i > 0; i-- ){
        string newL = R;
        string newR;

        R = binary(function(decimal(R)));

        for( int j = 0; j < L.length(); j++ ){
            newR += R[j] == L[j] ? '0' : '1';
        }
        L = newL;
        R = newR;
    }
    bb = R + L;
    return bb;
}



int main(){

vector<string> vectorrrrr;
vector<string> vectorrr;
constexpr int sss = 16;
string s;
cout<<"Write your binary text to encrypt right here -> ";
cin >> s;
cout << endl;

int length = s.length();
int qui = length/sss;
if(length % sss != 0)
    qui++;

for(int i = 0; i < qui; i++)
{
    string new_message = s.substr(0, sss);
    vectorrrrr.push_back(new_message);
    s.erase(0, sss);
}


string lss = vectorrrrr.at(vectorrrrr.size()-1);
if (lss.length() < sss)
{
    lss.resize(sss, '0');
}

cout << "Encrypted binary text -> ";
for (const auto& block : vectorrrrr)
{
    auto str = Encryption(block);
    vectorrr.push_back(str);
}

cout << endl;
cout << endl;

cout << "Decrypted from early encrypted binary text -> ";
for (const auto& block : vectorrr)
{
    string res = Dencryption(block);
    cout << res;
}
cout << endl;
}
