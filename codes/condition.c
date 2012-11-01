int flag[MAXTH];
pthread_mutex_t guard_flag[MAXTH];
pthread_cond_t flag_cond[MAXTH];
sem_t done;

void init_flag(int which)
{
 pthread_mutex_init(&guard_flag[which], 0);
 pthread_cond_init(&flag_cond[which], 0);
 flag[which] = FALSE;
}

void *func(void *info)
{
 int which = (int)info;
 while(TRUE)
 {
  pthread_mutex_lock(&guard_flag[which]);
  while(!flag[which]) pthread_cond_wait(&flag_cond[which], &guard_flag[which]);
  pthread_mutex_unlock(&guard_flag[which]);

  perform_task();
  printf("thread %d: work done\n", pthread_self());
		
  flag[which] = FALSE;
  sem_post(&done);
 }
 return 0;
}
