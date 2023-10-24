#include "tpl_os.h"
#include <stdio.h>

int main(void)
{
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

DeclareAlarm(task_A_timer);

TASK(task_A)
{
  static int task_A_counter = 0;

  printf("Activation task A #%d\r\n", task_A_counter);
  task_A_counter += 500;

  TerminateTask();
}

TASK(task_B)
{
  static int task_B_counter = 1500;

  printf("Activation task B #%d\r\n", task_B_counter);
  task_B_counter += 750;

  TerminateTask();
}

TASK(stop)
{
  CancelAlarm(task_A_timer);
  printf("Shutdown\r\n");
  ShutdownOS(E_OK);
  TerminateTask();
}
