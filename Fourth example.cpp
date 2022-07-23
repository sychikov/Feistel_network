#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

int str_len = 0;
char myownxor(char c1, char c2){
    return c1 == c2 ? '0' : '1';
}


string toBinary(char deci)
{
    int dec = static_cast<int>(deci);
    string bin;
    while(dec > 0 ){
        char temp = (dec % 2) + '0';
        bin = temp + bin;
        dec = dec/2;
    }

    while( bin.length() < 8 ){
        bin = '0' + bin;
    }
    return bin;
}


string UintToBinary(uint64_t dec)
{
    string bin;
    while(dec > 0 ){
        char temp = (dec % 2) + '0';
        bin = temp + bin;
        dec = dec/2;
    }

    while( bin.length() < 64){
        bin = '0' + bin;
    }

    return bin;
}


char toDecimal(string bin)
{
    int deci = 0;
    for( int i = 0; i < bin.length(); i++ ){
        int temp = bin.length() - i - 1;
        if( bin[temp] == '1' ){
            deci += pow(2, i);
        }
    }
    return (char)deci;
}

uint64_t toDecimalUint(string bin)
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



string encrypt( string str )
{

    str_len = str.length();
    string bin;

    for( int i = 0; i < str_len; i++ ){
        bin += toBinary(str[i]);
    }
    string L = bin.substr(0, bin.length()/2);
    string R = bin.substr(bin.length()/2);
    for( int i = 0; i < 8; i++ ){
        string brandnewl = R;
        string brandnewr;
        R = UintToBinary((pow(2, 64*(abs(abs(sin(toDecimalUint(R)))+log2(cos(2495599072149523524)+1)))) - 1));

        for( int j = 0; j < L.length(); j++ ){
            brandnewr += myownxor(R[j], L[j]);
        }

        L = brandnewl;
        R = brandnewr;
    }

    bin = R + L;

    string ret;

    for( int i = 0; i < bin.length(); i+=8 ){
        string sub = bin.substr(i, 8);
        char ch = toDecimal(sub);
        ret += ch;
    }

    cout << ret;

    return bin;
}

string decrypt( string bin ){

    string L = bin.substr(0, bin.length()/2);
    string R = bin.substr(bin.length()/2);



    for( int i = 8; i > 0; i-- ){
        string brandnewl = R;
        string brandnewr;

        R = UintToBinary((pow(2, 64*(abs(abs(sin(toDecimalUint(R)))+log2(cos(2495599072149523524)+1)))) - 1));

        for( int j = 0; j < L.length(); j++ ){
            brandnewr += myownxor(R[j], L[j]);
        }

        L = brandnewl;
        R = brandnewr;
    }

    bin = R + L;

    string ret;

    for( int i = 0; i < bin.length(); i+=8 ){
        string sub = bin.substr(i, 8);
        char ch = toDecimal(sub);
        ret += ch;

    }
    return ret;
}



int main(){



    string s;


    vector<string> v_s;
    vector<string> v_s_decr;
    constexpr int size = 16;



    cout<<"Текст для шифрования: ";
    getline(cin, s);


    int length = s.length();
    int quotient = length/size;
    if(length % size != 0)
        quotient++;

    for(int i = 0; i < quotient; i++)
    {
        string new_message = s.substr(0, size);
        v_s.push_back(new_message);
        s.erase(0, size);
    }


    string last_string = v_s.at(v_s.size()-1);
    if (last_string.length() < size)
    {
        last_string.resize(size, '0');
    }




    cout << "Готовый шифр: ";
    for (const auto& block : v_s)
    {
        auto str = encrypt(block);
        v_s_decr.push_back(str);
    }

    cout << "\n";



    cout << "Вновь расшифрованный текст: ";
    for (const auto& block : v_s_decr)
    {
        string res = decrypt(block);
        cout << res;
    }
    return 0;
}
