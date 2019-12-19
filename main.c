#include "serpent.h"
#include "chargement.h"
#include "jeu.h"
#include "menu.h"

int main(int argc, char const *argv[])
{
	chargement(menu());
	return 0;
}