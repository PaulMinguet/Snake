#include "./jeu/serpent.h"
#include "./menu/chargement.h"
#include "./jeu/jeu.h"
#include "./menu/menu.h"

int main(int argc, char const *argv[])
{
	chargement(menu());
	return 0;
}