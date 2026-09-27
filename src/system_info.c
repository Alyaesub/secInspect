// function qui appel gethsotname pour recupérer le hostname de la machine
#include <unistd.h>
#include <stdio.h>
#include "system_info.h"

void show_system_info(void)
{
  char hostname[256];

  if (gethostname(hostname, sizeof(hostname)) == -1)
  {
    perror("error gethostname");
    return;
  }
  else
  {
    printf("hostname: %s\n", hostname);
  }
}