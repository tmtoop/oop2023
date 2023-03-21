#include "Shoes.h"

std::string Shoes::getType() const
{
    return m_Type;
}

size_t Shoes::getCount() const
{
    return m_Count;
}

void Shoes::decreaseCount()
{
    if (m_Count > 0)
    {
        --m_Count;
        return;
    }
    else
    {
        throw std::runtime_error("No shoes left");
    }
}


void Shoes::changeCount(size_t amount)
{
    m_Count += amount;
}

void Shoes::setRating(float rating)
{
    m_Rating = rating;
}
