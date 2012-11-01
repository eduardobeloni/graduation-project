void set_flag(int which, int nv)
{
 pthread_mutex_lock(&guard_flag[which]);
 flag[which] = nv;
 pthread_cond_signal(&flag_cond[which]);
 pthread_mutex_unlock(&guard_flag[which]);
}

int main(int argc, char **argv)
{
 pthread_t runner[MAXTH];
 int i, resume = TRUE;

 sem_init(&done, 0, 0);
 for(i = 0; i < MAXTH; i++)
 {
  init_flag(i);
  pthread_create(&runner[i], 0, &func, (void *)i);
 }

 while(resume)
 {
  resume = some_event_for_thread_resume();
  if(resume) for(i = 0; i < MAXTH; i++) set_flag(i, TRUE);
  else break;

  for(i = 0; i < MAXTH; i++) sem_wait(&done);
  printf("back to main!\n");
 }
	
 for(i = 0; i < MAXTH; i++)
 {
  pthread_cancel(runner[i]);
  pthread_join(runner[i], 0);
  printf("thread %d returned\n", runner[i]);
 }
 return 0;
}
