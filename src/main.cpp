#include <iostream>
#include "jogador.h"
#include "jogo.h"

int Jogo::pontuacaoN=5;

int main(int argc, char const *argv[])
{
	Jogo game;
	//Jogo::pontuacaoN=10;
	game.addJogador(new Jogador("Bolsonaro"));
	game.addJogador(new Jogador("Marina"));
	game.addJogador(new Jogador("Meirelles"));
	game.addJogador(new Jogador("Ciro"));

	game.run();
	return 0;
}