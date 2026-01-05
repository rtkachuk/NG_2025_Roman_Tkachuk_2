#include "task.h"

Task::Task(int threadNumber) {
    m_threadNumber = threadNumber;
}

void Task::run()
{
    qDebug() << "[" << QString::number(m_threadNumber) << "]: " << m_start << ":::" << m_stop;
    for (int i=m_start; i<m_stop; i++) {
        qDebug() << "[" << QString::number(m_threadNumber) << "]: " << i;
    }
}
