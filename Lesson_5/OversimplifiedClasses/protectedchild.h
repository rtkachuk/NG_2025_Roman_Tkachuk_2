#ifndef PROTECTEDCHILD_H
#define PROTECTEDCHILD_H

#include "parent.h"

class protectedChild : protected Parent
{
public:
    protectedChild() {
        m_publicVariable = 9;
        m_protectedVariable = 10;
        //m_privateVariable = 11;
    };
};

#endif // PROTECTEDCHILD_H
