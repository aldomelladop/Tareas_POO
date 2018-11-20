//
//  main.cpp
//  Test_6
//
//  Created by Ignacio Quiroga Ascencio on 10/28/18.
//  Copyright © 2018 Ignacio Quiroga Ascencio. All rights reserved.
//

#include <iostream>

using namespace std;

struct slot
{
    int value;
    slot * next;
    slot * previous;
};

class BigInteger
{
    static const int digitsPerSlot = 8;
    static const int valuePerSlot = 100000000;
public:
    BigInteger();
    BigInteger(const BigInteger & that);
    BigInteger(int value);
    BigInteger(const char string[]);
    ~BigInteger();
    
    bool isPositive;
    
    BigInteger & operator=(const BigInteger & that);
    
    BigInteger & operator+=(const BigInteger & that);
    BigInteger operator+(const BigInteger & that) const;
    
    BigInteger & operator-=(const BigInteger & that);
    BigInteger operator-(const BigInteger & that) const;
    
    BigInteger & operator*=(const BigInteger & that);
    BigInteger operator*(const BigInteger & that) const;
    
    bool operator==(const BigInteger & that) const;
    bool operator!=(const BigInteger & that) const;
    
    bool operator<(const BigInteger & that) const;
    bool operator<=(const BigInteger & that) const;
    bool operator>(const BigInteger & that) const;
    bool operator>=(const BigInteger & that) const;
    
    BigInteger & operator++();
    BigInteger operator++(int);
    
    explicit operator bool() const;
    bool operator!() const;
    
    friend ostream & operator<<(ostream & os, const BigInteger & obj);
private:
    void copy(const BigInteger & that);
    void constructPointers();
    
    slot * start;
    slot * end;
    int numberOfSlots;
    
    void clear();
    void put(int value);
    void push(int value);
    
    void add(const BigInteger & that);
    void subtract(const BigInteger & that);
    
    void removeLeadingZeros();
};

BigInteger::BigInteger()
{
    constructPointers();
}

// Shared code among all constructors: make the pointers to the start and end of the list nullpointers and initialise the slotcounter.
void BigInteger::constructPointers()
{
    numberOfSlots = 0;
    start = nullptr;
    end = nullptr;
    isPositive = true;
}

// Copyconstructor
BigInteger::BigInteger(const BigInteger & that)
{
    constructPointers();
    copy(that);
}

// Constructor from int, reads the int into the BigInt.
BigInteger::BigInteger(int value)
{
    constructPointers();
    if (value < 0)
    {
        isPositive = false;
        value *= -1;
    }
    
    if (value >= valuePerSlot)
    {
        put(value / valuePerSlot);
        value %= valuePerSlot;
    }
    put(value);
}

// Constructor from a char array, reads the array into the BigInt. Assumes only digits to be present in the array.
BigInteger::BigInteger(const char string[])
{
    constructPointers();
    
    int lengthOfString = 0;
    while (string[lengthOfString] != '\0')
    {
        lengthOfString++;
    }
    int value = 0;
    int index = 0;
    if (string[0] == '-')
    {
        isPositive = false;
        lengthOfString--;
        index++;
    }
    while (lengthOfString)
    {
        if (!(lengthOfString % digitsPerSlot))
        {
            put(value);
            value = 0;
        }
        value = value * 10 + (string[index] - '0');
        lengthOfString--;
        index++;
    }
    put(value);
}

BigInteger::~BigInteger()
{
    clear();
}

BigInteger & BigInteger::operator=(const BigInteger & that)
{
    if (this != &that)
    {
        copy(that);
    }
    return *this;
}

void BigInteger::copy(const BigInteger & that)
{
    clear();
    isPositive = that.isPositive;
    slot * currentSlot = that.start;
    while (currentSlot != nullptr)
    {
        put(currentSlot->value);
        currentSlot = currentSlot->next;
    }
}

// Depending on the signs of LHS and RHS, either addition or subtraction is required.
BigInteger & BigInteger::operator+=(const BigInteger & that)
{
    if (isPositive && that.isPositive)
    {
        add(that);
    }
    else if (isPositive && !that.isPositive)
    {
        BigInteger placeholder(that);
        placeholder.isPositive = true;
        subtract(placeholder);
    }
    else if (!isPositive && that.isPositive)
    {
        BigInteger placeholder(that);
        placeholder.subtract(*this);
        copy(placeholder);
    }
    else
    {
        add(that);
        isPositive = false;
    }
    
    return *this;
}

// Addition. Adds slots together, remembers any carry (either no carry (0) or a carry (1)) and adds those to the next slots.
// Keeps going until all slots of both BigInts and the carry are empty.
void BigInteger::add(const BigInteger & that)
{
    BigInteger placeholder(*this);
    slot * currentSlotThat = that.end;
    slot * currentSlotThis = placeholder.end;
    
    clear();
    bool carry = false;
    while (currentSlotThis != nullptr || currentSlotThat != nullptr || carry)
    {
        int thisValue = 0;
        int thatValue = 0;
        if (currentSlotThis != nullptr)
        {
            thisValue = currentSlotThis->value;
            currentSlotThis = currentSlotThis->previous;
        }
        if (currentSlotThat != nullptr)
        {
            thatValue = currentSlotThat->value;
            currentSlotThat = currentSlotThat->previous;
        }
        int sum = thisValue + thatValue + carry;
        carry = sum >= valuePerSlot;
        push(sum % (valuePerSlot));
    }
}

void BigInteger::subtract(const BigInteger & that)
{
    // Check in advance whether the subtraction will cause the sign of this to flip, by checking if RHS > LHS
    // If that's the case, replace LHS - RHS with (RHS - LHS) * -1
    if (that > *this)
    {
        BigInteger placeholder(that);
        placeholder.subtract(*this);
        copy(placeholder);
        isPositive = false;
    }
    else
    {
        BigInteger placeholder(*this);
        slot * currentSlotThat = that.end;
        slot * currentSlotThis = placeholder.end;
        
        clear();
        
        bool carry = false;
        while (currentSlotThis != nullptr || currentSlotThat != nullptr)
        {
            int thisValue = 0;
            int thatValue = 0;
            if (currentSlotThis != nullptr)
            {
                thisValue = currentSlotThis->value;
                currentSlotThis = currentSlotThis->previous;
            }
            if (currentSlotThat != nullptr)
            {
                thatValue = currentSlotThat->value;
                currentSlotThat = currentSlotThat->previous;
            }
            int diff = thisValue - carry - thatValue;
            if (diff < 0)
            {
                carry = true;
                diff = -1 * diff;
            }
            else
            {
                carry = false;
            }
            push(diff);
        }
        removeLeadingZeros();
    }
}

// Substraction can lead to leading zero valued slots. These need to be removed asap, since this breaks comparison.
void BigInteger::removeLeadingZeros()
{
    slot * currentSlot = start;
    slot * helper;
    
    while (currentSlot->next != nullptr && currentSlot->value == 0)
    {
        helper = currentSlot;
        currentSlot = currentSlot->next;
        delete helper;
    }
    start = currentSlot;
    currentSlot->previous = nullptr;
}


BigInteger BigInteger::operator+(const BigInteger & that) const
{
    return BigInteger(*this) += that;
}

// subtraction operators are defined as LHS - RHS = LHS + (-1 * RHS)
BigInteger & BigInteger::operator-=(const BigInteger & that)
{
    BigInteger placeholder(that);
    placeholder.isPositive = !placeholder.isPositive;
    return *this += placeholder;
}

BigInteger BigInteger::operator-(const BigInteger & that) const
{
    return BigInteger(*this) -= that;
}

// Cross-multiplication of all slots, with adding the sum of the slotcount worth of zero-slots afterwards. Accumulating all the results.
BigInteger & BigInteger::operator*=(const BigInteger & that)
{
    BigInteger placeholder(*this);
    slot * currentSlotThis = placeholder.end;
    
    BigInteger prodPlaceholder;
    
    clear();
    
    int thisSlotCounter = 0;
    while (currentSlotThis != nullptr)
    {
        int thatSlotCounter = 0;
        slot * currentSlotThat = that.end;
        while (currentSlotThat != nullptr)
        {
            prodPlaceholder.clear();
            long long prod = (long long)currentSlotThis->value * (long long)currentSlotThat->value;
            if (prod >= valuePerSlot)
            {
                int overflow = (int)(prod / valuePerSlot);
                prodPlaceholder.put(overflow);
                prod %= valuePerSlot;
            }
            prodPlaceholder.put((int)prod);
            for (int numberOfZeroSlots = 0; numberOfZeroSlots < thisSlotCounter + thatSlotCounter; numberOfZeroSlots++)
            {
                prodPlaceholder.put(0);
            }
            *this += prodPlaceholder;
            thatSlotCounter++;
            currentSlotThat = currentSlotThat->previous;
        }
        thisSlotCounter++;
        currentSlotThis = currentSlotThis->previous;
    }
    isPositive = !(placeholder.isPositive ^ that.isPositive);
    
    return *this;
}

BigInteger BigInteger::operator*(const BigInteger & that) const
{
    return BigInteger(*this) *= that;
}

// Equality check, first check for same amount of slots. If that differs, numbers can't be equal. Second checks for signs, then checks if all slots themselves have equal value.
bool BigInteger::operator==(const BigInteger & that) const
{
    if (this->numberOfSlots != that.numberOfSlots)
    {
        return false;
    }
    if (isPositive != that.isPositive)
    {
        return false;
    }
    slot * currentSlotThis = end;
    slot * currentSlotThat = that.end;
    
    while (currentSlotThis != nullptr)
    {
        if (currentSlotThis->value != currentSlotThat->value)
        {
            return false;
        }
        currentSlotThat = currentSlotThat->previous;
        currentSlotThis = currentSlotThis->previous;
    }
    return true;
}

bool BigInteger::operator!=(const BigInteger & that) const
{
    
    return !(*this == that);
}

// Relational operator. First compares the number of slots, to see if there is already an answer, same for signs. Else it starts at the head of the list to test if the values are equal.
// When they are not equal anymore, they can be compared for a result.
bool BigInteger::operator<(const BigInteger & that) const
{
    if (this->numberOfSlots != that.numberOfSlots || this->isPositive != that.isPositive)
    {
        return this->numberOfSlots * (this->isPositive - 0.5) < that.numberOfSlots * (that.isPositive - 0.5);
    }
    
    slot * currentSlotThis = start;
    slot * currentSlotThat = that.start;
    while (currentSlotThis->next != nullptr && currentSlotThis->value == currentSlotThat->value)
    {
        currentSlotThat = currentSlotThat->next;
        currentSlotThis = currentSlotThis->next;
    }
    return currentSlotThis->value < currentSlotThat->value;
}

bool BigInteger::operator<=(const BigInteger & that) const
{
    return !(that < *this);
}

bool BigInteger::operator>(const BigInteger & that) const
{
    return that < *this;
}

bool BigInteger::operator>=(const BigInteger & that) const
{
    return !(*this < that);
}

BigInteger & BigInteger::operator++()
{
    return *this += BigInteger(1);
}

BigInteger BigInteger::operator++(int)
{
    BigInteger temp(*this);
    operator++();
    return temp;
}

BigInteger::operator bool() const
{
    return *this != 0;
}

bool BigInteger::operator!() const
{
    return !bool(*this);
}

// Remove and delete all slots from an object.
void BigInteger::clear()
{
    slot * currentSlot = start;
    slot * placeholder;
    while (currentSlot != nullptr)
    {
        placeholder = currentSlot;
        currentSlot = placeholder->next;
        delete placeholder;
    }
    start = nullptr;
    end = nullptr;
    numberOfSlots = 0;
}

// Put a slot at the end of the list.
void BigInteger::put(int value)
{
    slot * newslot = new slot;
    newslot->value = value;
    newslot->next = nullptr;
    slot * endOfList = end;
    if (numberOfSlots)
    {
        endOfList->next = newslot;
    }
    else
    {
        start = newslot;
    }
    end = newslot;
    newslot->previous = endOfList;
    numberOfSlots++;
}

// Push a slot to the start of the list.
void BigInteger::push(int value)
{
    slot * newslot = new slot;
    newslot->value = value;
    newslot->next = start;
    slot * startOfList = start;
    if (numberOfSlots)
    {
        startOfList->previous = newslot;
    }
    else
    {
        end = newslot;
    }
    start = newslot;
    newslot->previous = nullptr;
    numberOfSlots++;
}

std::ostream & operator<<(std::ostream & os, const BigInteger & obj)
{
    if (!obj.isPositive)
    {
        os.put('-');
    }
    
    slot * currentSlot = obj.start;
    while (currentSlot != nullptr)
    {
        int value = currentSlot->value;
        int fullValue = value;
        int numberOfPaddingZeros = 1;
        int digit = 10000000;
        if (currentSlot == obj.start && (fullValue == 0))
        {
            os.put('0');
        }
        else
        {
            while (digit)
            {
                // Pad the value in the slot with leading zeros to fill the entire slot, except when it is the first slot.
                if (currentSlot != obj.start || (fullValue >= digit))
                {
                    os.put((value / digit) + '0');
                }
                
                value %= digit;
                digit /= 10;
            }
        }
        currentSlot = currentSlot->next;
    }
    return os;
}

BigInteger fibonacci(int n)
{
    BigInteger a = 0;
    BigInteger b = 1;
    BigInteger placeholder;
    for (int index = 2; index < n; index++)
    {
        placeholder = a;
        a += b;
        b = placeholder;
    }
    return a;
}

int main()
{
    int n;
    BigInteger b;
    for (n=1000; n<1010; n++) {
        
        b = fibonacci(n);
        cout<<"\n";
        cout << b <<endl;
    }
}
