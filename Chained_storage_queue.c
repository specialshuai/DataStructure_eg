typedef struct ElemType_node{
	ElemType data;
	struct ElemType_node *next;
}ElemType_Node;
	
typedef struct Chained_storage_queue{
	ElemType_Node *front,*rear;
}Chained_Storage_Queue;

static Chained_Storage_Queue myqueue;

void Queue_init(Chained_Storage_Queue &q)
{
	q.front = q.rear = (ElemType_Node)malloc(sizeof(ElemType_Node));
	q.front->next = NULL;

}
bool isEmpty(Chained_Storage_Queue &q)
{
	if(q.rear == q.front)
		return true;
	return false;
}

bool enqueue(Chained_Storage_Queue &q ,ElemType &x)
{
	ElemType_Node s =((ElemType_Node *)malloc(ElemType_Node));
	s->data = x;
	s->next = NULL;
	
	q.rear->next = s;
	q.rear = s;
}

bool dequeue(Chained_Storage_Queue &q ,ElemType &x)
{
	if(q.rear == q.front)
		return false;
	ElemType_Node *p;
	
	p =q.front->next;
	x =p->data;
	q.front->next= p->next;
	if(q.rear == p)
		q.rear = q.front;
	free(p);

	return true;

}


