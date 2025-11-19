#ifndef PARENT_H
#define PARENT_H

class Parent
{
public:
    Parent();
    int summa() { return m_first + m_second; }
    int summa(int a) { return m_first + m_second + a; }

    void setFirst(int buff);
    void setSecond(int buff);

    int getFirst() { return m_first; }
    int getSecond() { return m_second; }

    // Never do that, all variables should exist only as private members
    // This is done only for demo purposes

    int m_publicVariable = 0;
protected:
    int m_protectedVariable = 1;
private:
    int m_first;
    int m_second;
    int m_privateVariable = 2;
};

#endif // PARENT_H
