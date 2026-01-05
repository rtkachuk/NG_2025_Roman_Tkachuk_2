#ifndef TASK_H
#define TASK_H

#include <QThread>
#include <QDebug>

class Task : public QThread
{
    Q_OBJECT
public:
    Task(int threadNumber);
    void setRange(int start, int stop) { m_start = start; m_stop = stop; }
    int getThreadNumber() { return m_threadNumber; }
protected:
    virtual void run();
private:
    int m_stop;
    int m_start;
    int m_threadNumber;
};

#endif // TASK_H
