//
// Created by Shadman on 12/10/23.
//

#ifndef QUEUETYPE_QUEUETYPE_H
#define QUEUETYPE_QUEUETYPE_H


class FullQueue
{};
class EmptyQueue
{};
template<class ItemType>
class QueType {
public:
    QueType();

    QueType(int max);

    ~QueType();

    void MakeEmpty();

    bool IsEmpty();

    bool IsFull();

    void Enqueue(ItemType);

    void Dequeue(ItemType &);

    void printQueue();

private:
    int front;
    int rear;
    ItemType *items;
    int maxQue;
};
#endif //QUEUETYPE_QUEUETYPE_H
