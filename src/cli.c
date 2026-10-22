#include <stdio.h>
#include <string.h>
#include "cli.h"
#include "banner.h"
#include "system_info.h"

// function qui gére l'affichage de --help
static void show_help(void)
{
  printf("\033[33mSecInspect — System Security Inspection Tool \033[0m\n");
  printf("\n");
  printf("Usage:\n");
  printf(" SecInspect [options]\n");
  printf("\n");
  printf("Options:\n");
  printf(" --help     Show this help message\n");
  printf(" --version  Show program version\n");
  printf(" --scan     Run system information inspection\n");
  printf("\n");
  printf("Exemples:\n");
  printf(" ./secinspect --help\n");
  printf(" ./secinspect --scan\n");
}

// fonction qui gére l'affichage de --version
static void show_version(void)
{
  printf("\033[33mSecInspect — System Security Inspection Tool \033[0m\n");
  printf("SecInspect v0.1.0\n");
}

// fonction qui gére les appel de commande
int handle_cli(int argc, char *argv[])
{
  if (argc > 2)
  {
    printf("ERROR, too many arguments.\n");
    return 1;
  }
  else
  {
    if (argc > 1)
    {
      if (strcmp(argv[1], "--help") == 0)
      {
        show_help();
        return 0;
      }
      else if (strcmp(argv[1], "--version") == 0)
      {
        show_version();
        return 0;
      }
      else if (strcmp(argv[1], "--scan") == 0)
      {
        show_banner();
        int result = show_system_info();
        if (result == 0)
        {
          printf("[INFO] System inspection completed\n");
        }
        else
        {
          printf("[WARN] System inspection completed with errors\n");
        }
        return result;
      }
      else
      {
        printf("[ERROR] Unknown command option : %s\n", argv[1]);
        printf("Use './secinspect --help' for usage information.\n");
        return 1;
      }
    }

    printf("Usage: ./secinspect --help | --version | --scan\n");
    return 1;
  }
}