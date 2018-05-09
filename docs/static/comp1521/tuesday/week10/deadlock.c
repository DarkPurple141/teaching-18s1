
Sem1=1
Sem2=1

Thread1
{
   wait(Sem1)
   wait(Sem2)
   doWork()
   doMoreWork()
   signal(Sem2)
   signal(Sem1)
}


Thread2
{
   wait(Sem1)
   wait(Sem2)
   doWork()
   doMoreWork()
   signal(Sem2)
   signal(Sem1)
}
