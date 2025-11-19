#include "parent.h"

Parent::Parent() {}

void Parent::setFirst(int buff)
{
    m_first = buff > 0 ? buff : 0;
}

void Parent::setSecond(int buff)
{
    if (buff > 0)
        m_second = buff;
    else
        m_second = 0;
}
