class RecentCounter 
{
    struct QueueElement
    {
        int timeStamp;
        QueueElement* next;
    };

    int queueLength;
    QueueElement* head;
    QueueElement* tail;

    public:
        RecentCounter() 
        {
            queueLength = 0;
            head = nullptr;
            tail = nullptr;
        }

        int ping(int t) 
        {
            QueueElement* newElement = new QueueElement();
            newElement->timeStamp = t;
            if (queueLength == 0)
            {                
                head = newElement;
                tail = head;
                queueLength = 1;
            }
            else
            {
                head->next = newElement;
                head = newElement;
                queueLength++;
                while (tail->timeStamp < t - 3000)
                {
                    QueueElement* oldTail = tail;
                    tail = tail->next;
                    delete oldTail;
                    queueLength--;
                }
            }
            return queueLength;
        }
};
