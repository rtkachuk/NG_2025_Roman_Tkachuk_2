#include <iostream>

#include "parent.h"
#include "publicchild.h"
#include "privatechild.h"
#include "protectedchild.h"

using namespace std;

void showStatus(char name[50]) {
    cout << "======================" << endl;
    cout << name << ": " << endl;
}

int main()
{
    Parent parentExample;
    parentExample.setFirst(5);
    parentExample.setSecond(10);
    cout << "Parent summ: " << parentExample.summa() << endl;

    PublicChild publicChildExample;
    publicChildExample.setFirst(7);
    publicChildExample.setSecond(8);
    cout << "Public Child summ: " << publicChildExample.summa() << endl;
    cout << "Public Child overloaded summ: " << publicChildExample.summa(5) << endl;

    PrivateChild privateChildExample;
    protectedChild protectedChildExample;


    showStatus("Parent");
    cout << parentExample.m_publicVariable << endl; // Public could be access directly from outside of the class
    //cout << parentExample.m_protectedVariable << endl; // Protected cannot be accessible
    //cout << parentExample.m_privateVariable << endl; // As well as private

    showStatus("PublicChild");
    cout << publicChildExample.m_publicVariable << endl; // Public
    //cout << publicChildExample.m_protectedVariable << endl; // Protected
    //cout << publicChildExample.m_privateVariable << endl; // Private


    // For private inheritance, all members (including public & protected) became private
    showStatus("PrivateChild");
    //cout << privateChildExample.m_publicVariable << endl; // Private
    //cout << privateChildExample.m_protectedVariable << endl; // Private
    //cout << privateChildExample.m_privateVariable << endl; // Private

    showStatus("ProtectedChild");
    //cout << protectedChildExample.m_publicVariable << endl; // Protected
    //cout << protectedChildExample.m_protectedVariable << endl; // Protected
    //cout << protectedChildExample.m_privateVariable << endl; // Private

    return 0;
}
