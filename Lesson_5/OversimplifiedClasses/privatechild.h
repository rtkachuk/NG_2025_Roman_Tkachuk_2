#ifndef PRIVATECHILD_H
#define PRIVATECHILD_H

#include "parent.h"

class PrivateChild : private Parent
{
public:
    PrivateChild() {
        m_publicVariable = 6;
        m_protectedVariable = 7;
        //m_privateVariable = 8;
    };
};

#endif // PRIVATECHILD_H
