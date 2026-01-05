#include "manager.h"

Manager::Manager(QObject *parent)
    : QObject{parent}
{}

void Manager::setAmountOfThreads(int amount)
{
    for (Task *task : m_tasks) {
        task->terminate();
        qDebug() << "Waiting for task " << task->getThreadNumber();
        while (task->isFinished() == false) {}
        delete task;
        m_tasks.removeOne(task);
    }

    for (int currentThreadNumber = 0; currentThreadNumber < amount; currentThreadNumber++) {
        Task *task = new Task(currentThreadNumber);
        m_tasks.append(task);
    }
}

void Manager::startJob(int value)                       // 5 threads, 1000
{                                                       // 0 : 0 -> 200; 1 200 -> 400: ... 4: 800 -> 1000
    int threadsAmount = m_tasks.count();
    int baseNumber = value / threadsAmount;
    int counter = 0;

    for (Task *task : m_tasks) {
        task->setRange(baseNumber * counter, baseNumber * (counter+1));
        counter++;
    }

    for (Task *task : m_tasks) {
        qDebug() << "Started task: " << task->getThreadNumber();
        task->start();
    }
}
