#include "bitset.hpp"

Bitset::Bitset() {
    // TODO
    // construct a bitset of size 8 initialized to 0

    for (int i = 0; i < 8; i++)
     {*(bitVector + i) = 0;}   

}

Bitset::Bitset(intmax_t size) {
    // TODO
    //construct a bitset of size N initialized to 0

    if (size < 0) { valid = false; }

    for (int i = 0; i < size; i++)
     {bitVector[i] = 0;} 
}

Bitset::Bitset(const std::string & value) {
    // TODO
    // for (int i = 0; i < size(); i++)
    //{ *(bitVector + i) = dynamic_cast< Bitset * >(value); }

    int strSize = value.length();

    for (int i = 0; i < strSize; i++)
    {
        uint8_t temp;
        temp = static_cast<uint8_t>(value[i]);
        bitVector[i] = temp;
    }

    //how do you convert from string to bit vector?
}

std::string Bitset::asString() const
{
    return "";
}

Bitset::~Bitset() { 
    // TODO 
    delete [] bitVector;
}

// TODO: other methods

intmax_t Bitset::size() const
{
    intmax_t vectorSize = sizeof(bitVector)/sizeof(bitVector[0]);
    return vectorSize;
}

bool Bitset::good() 
{
    for (int i = 0; i < size(); i++)
    {
        
        if (bitVector[i] == 0 || bitVector[i] == 1)
            { valid = true; }
        else
            { valid = false;
            break;}
    }
    return valid;
}


void Bitset::set(intmax_t index)
{
    if (index < 0 || index > size() - 1)
    { valid = false; } 
    else 
    { bitVector[index] = 1; }
}



void Bitset::reset(intmax_t index)
{
    if (index < 0 || index > size() - 1)
    { valid = false; } 
    else 
    { bitVector[index] = 0; }
}


void Bitset::toggle(intmax_t index)
{
    if (index < 0 || index > size() - 1)
    { valid = false; } 
    else if (bitVector[index] == 0) 
    { bitVector[index] = 1; }
    else 
    { bitVector[index] = 0; }
}


bool Bitset::test(intmax_t index)
{
    if (index < 0 || index > size() - 1)
    { valid = false; return false;} 
    else
    {
        if (bitVector[index] == 1)
        { return true; }
        else
        { return false; }
    }

}