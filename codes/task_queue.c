struct task
{
 /* ... */
 struct task *next;
};

struct task *tasks;

void *thread_func(void *info)
{
 struct task *next_task;
 while(tasks)
 {
  next_task = tasks;
  tasks = tasks->next;
  execute(next_task);
  free(next_task);
 }

 return 0;
}
