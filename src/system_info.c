// function qui appel gethsotname pour recupérer le hostname de la machine
#include <unistd.h>
#include <stdio.h>
#include "system_info.h"
#include <sys/utsname.h>

void show_system_info(void)
{
  char hostname[256] = {0};

  if (gethostname(hostname, sizeof(hostname) - 1) == -1)
  {
    perror("error gethostname");
    return;
  }
  else
  {
    printf("hostname: %s\n", hostname);
  }

  // struct sys_info
  struct utsname sys_info;

  int result = uname(&sys_info);
  if (result == -1)
  {
    perror("error uname");
    return;
  }
  else
  {
    printf("Informations syteme :\n");
    printf(" - name: %s\n", sys_info.sysname);
    printf(" - release: %s\n", sys_info.release);
    printf(" - machine: %s\n", sys_info.machine);
    printf(" - version: %s\n", sys_info.version);
    printf(" - node_name: %s\n", sys_info.nodename);
  }
}
