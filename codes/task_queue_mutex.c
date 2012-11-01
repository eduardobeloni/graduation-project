struct task
{
 /* ... */
 struct task *next;
};

struct task *tasks;
pthread_mutex_t guard_task = PTHREAD_MUTEX_INITIALIZER;

void *thread_func(void *info)
{
 struct task *next_task;
 while(TRUE)
 {
  pthread_mutex_lock(&guard_task);
  if(!tasks) next_task = 0;
  else
  {
   next_task = tasks;
   tasks = tasks->next;
  }
  pthread_mutex_unlock(&guard_task);
 
  if(!tasks) break;

  execute(next_task);
  free(next_task);
 }

 return 0;
}
