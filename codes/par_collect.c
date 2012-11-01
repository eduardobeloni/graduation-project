void *claim_task(void *info) {
 pointer task;
 HeapPtr *obj;
 int err = 0, me = (int)info;
 deque *deq = wsd[me];

 while(TRUE)
 {
  while(!resume[me]) pthread_cond_wait(&resume_cond[me], &guard_resume[me]);
  STEAL_SUCCESSFUL:
  while(!err)
  {
   err = deque_pop_bottom(deq, &task);
   if(err) break;
   obj = (HeapPtr *)task;
   *obj = par_evacuate(*obj, deq, me);
  }

  task = steal_some_work(me);
  if(task)
  {
   err = deque_push_bottom(deq, task);
   goto STEAL_SUCCESSFUL;
  }
  err = FALSE;
  sem_post(&done);
 }

 return 0;
}
