#ifndef PUBLICCHILD_H
#define PUBLICCHILD_H

#include "parent.h"

class PublicChild : public Parent
{
public:
    PublicChild() {
        m_publicVariable = 3;
        m_protectedVariable = 4;
        //m_privateVariable = 5;
    };
};

#endif // PUBLICCHILD_H
