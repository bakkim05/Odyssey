//
// Created by Oska on 4/26/2018.
//

#include "HashFunction.h"
using namespace std;

//std::string primeNumber = "7FFFFFFF";
//
//std::string string_to_hex (const std::string& input)
//{
//    static const char* const lut = "0123456789ABCDEF";
//    size_t len = input.length();
//
//    std::string output;
//    output.reserve(2 * len);
//    for (size_t i = 0; i < len; ++i)
//    {
//        const unsigned char c = input[i];
//        output.push_back(lut[c >> 4]);
//        output.push_back(lut[c & 15]);
//    }
//    std::cout << output << std::endl;
//
//    return output;
//}

long double string_to_binary (const string& input)
{
    //unsigned long double temp;

    for (std::size_t i = 0 ; i < input.size() ; i++)
    {
        long double temp = 0;
        if (i==0)
        {
            int parse = atoi(bitset <8>(input[i]));
            temp = parse;
            cout << "este es: " << temp << endl;

        }else {
            int parse = atoi(bitset <8>(input.c_str()[i]).to_string().c_str());
            temp = concatenate(temp, parse);
        }

        cout << temp << endl;

    }
}

unsigned concatenate(unsigned first, unsigned last)
{
    unsigned power = 10;
    while(last >= power)
        power *= 10;
    //std::cout << first*power + last << std::endl;
    return first * power + last;
}