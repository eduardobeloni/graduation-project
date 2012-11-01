int deque_push_bottom(deque *d, pointer new_task)
{
 if(deque_full(d)) return 1;

 if(!d->bot) d->bot = d->capacity - 1;
 else d->bot--;
 d->tasks[d->bot] = new_task;

 return 0;
}

int deque_pop_bottom(deque *d, pointer *dest)
{
 pthread_mutex_lock(&d->guard_pop);

 if(deque_empty(d)) { pthread_mutex_unlock(&d->guard_pop); return 2; }

 *dest = d->tasks[d->bot];
 if(d->bot == d->capacity - 1) d->bot = 0;
 else d->bot++;

 pthread_mutex_unlock(&d->guard_pop);
 return 0;
}
	
int deque_pop_top(deque *d, pointer *dest)
{
 pthread_mutex_lock(&d->guard_pop);

 if(deque_empty(d)) { pthread_mutex_unlock(&d->guard_pop); return 2; }

 if(!d->top) d->top = d->capacity - 1;
 else d->top--;
 *dest = d->tasks[d->top];

 pthread_mutex_unlock(&d->guard_pop);	
 return 0;	
}
