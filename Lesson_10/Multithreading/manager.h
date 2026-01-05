#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include "task.h"

class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(QObject *parent = nullptr);
    void setAmountOfThreads(int amount);
    void startJob(int value);

signals:
private:
    QVector<Task*> m_tasks;
};

#endif // MANAGER_H
