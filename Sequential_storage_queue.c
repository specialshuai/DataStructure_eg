#define MaxSize 50
typedef struct Sequential_storage_queue{
	ElemType data[MaxSize];
	int front, rear;
}Sequential_Storage_Queue;

static Sequential_Storage_Queue myqueue;

void Queue_init(Sequential_Storage_Queue &q)
{
	q.front = q.rear =0;

}
bool isEmpty(Sequential_Storage_Queue &q)
{
	if(q.rear == q.front)
		return false;
	return true;
}

bool enqueue(Sequential_Storage_Queue &q ,ElemType x)
{
	if((q.rear+1+MaxSize)%MaxSize == q.front)
		return false;
	q.data[q.rear] = x;
	q.rear =(q.rear+1)%MaxSize;
	return true;
}

bool dequeue(Sequential_Storage_Queue &q ,ElemType &x)
{
	if(q.rear == q.front)
		return false;
	x = q.data[q.front];
	q.front = (q.front+1)%MaxSize;
	return true;

}

