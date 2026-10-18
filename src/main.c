// fichier qui appelle les functions
#include <stdio.h>
#include "banner.h"
#include "system_info.h"

int main(void)
{
  // fonction pour la banniere
  show_banner();
  // variable result sert a récupére et stocker les erreurs que show_system_info() reléve
  // et les afficher via le if
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