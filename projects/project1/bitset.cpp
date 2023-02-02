#include "bitset.hpp"

Bitset::Bitset() {
    // TODO
    // construct a bitset of size 8 initialized to 0

    bitSize = 8;

    // allocate memory for the bitVector

    bitVector = new uint8_t [bitSize];

    for (int i = 0; i < 8; i++)
     {bitVector[i] = 0;}   

}

Bitset::Bitset(intmax_t size) {
    // TODO
    //construct a bitset of size N initialized to 0

    bitSize = size;

    // allocate memory for the bitVector

    bitVector = new uint8_t [bitSize];

    if (bitSize <= 0) { valid = false; }

    for (int i = 0; i < bitSize - 1; i++)
     {bitVector[i] = 0;} 
}

Bitset::Bitset(const std::string & value) 
{
    // TODO

    bitSize = value.length();

    bitVector = new uint8_t [bitSize];
    
    // initialize valid to true

    valid = true;

    for (int i = 0; i < bitSize ; i++)
    {
        if (value.at(i) == '0')
        { bitVector[i] = 0; }
        else if (value.at(i) == '1')
        { bitVector[i] = 1; }
        else
        { valid = false; }
    }


}

std::string Bitset::asString() const
{
    std::string temp = "";
    for (int i = 0 ; i < bitSize ; i++)
    {
        temp.append(std::to_string(bitVector[i]));
    }

    return temp;
}

Bitset::~Bitset() { 
    // TODO 
    delete [] bitVector;
}

// TODO: other methods

intmax_t Bitset::size() const
{
    return bitSize;
}

bool Bitset::good() const
{
    return valid;
}


void Bitset::set(intmax_t index)
{
    if (index < 0 || index >= bitSize)
    { valid = false; } 
    else 
    { bitVector[index] = 1; }
}



void Bitset::reset(intmax_t index)
{
    if (index < 0 || index >= bitSize)
    { valid = false; } 
    else 
    { bitVector[index] = 0; }
}


void Bitset::toggle(intmax_t index)
{
    if (index < 0 || index >= bitSize)
    { valid = false; } 
    else if (bitVector[index] == 0) 
    { bitVector[index] = 1; }
    else 
    { bitVector[index] = 0; }
}


bool Bitset::test(intmax_t index)
{
    if (index < 0 || index >= bitSize)
    { valid = false; return false; } 
    else
    {
        if (bitVector[index] == 1)
        { return true; }
        else
        { return false; }
    }

}