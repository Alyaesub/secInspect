// function qui appel gethsotname pour recupérer le hostname de la machine
#include <unistd.h>
#include <stdio.h>
#include "system_info.h"
#include <sys/utsname.h>

// module présentation system
int show_system_info(void)
{

  int status = 0; // status des erreurs total du module, pour les récupéré plus tard dans le main.c

  // donne le hostanme de la machine
  char hostname[256] = {0};

  if (gethostname(hostname, sizeof(hostname) - 1) == -1)
  {
    perror("error gethostname");
    status = 1;
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
    status = 1;
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

  return status;
}
