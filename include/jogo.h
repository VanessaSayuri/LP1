#ifndef JOGO_H
#define JOGO_H

#include "jogador.h"
#include "dado.h"

#define MAX_JOGADORES 10



class Jogo
{
private:
	Jogador * m_jogadores[MAX_JOGADORES];
	int m_total_jogadores;
	int m_rodada;
	Jogador * m_vencedor;
	Dado * m_dados[2];
	int m_total_ativos;
public:
	Jogo();
	~Jogo();
	int getTotalJogadores();
	Jogador * getVencedor();
	int getRodada();

	static int pontuacaoN;

	void addJogador(Jogador * novo);
	void imprimeVencedor();
	void run();
	bool desativaJogador();
	void defineVencedor();
	void imprimeDadosRodada();

};

#endif