#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
#include <string>
#include "dado.h"

using namespace std;

class Jogador
{
private:
	string m_nome;
	int m_pontos;
	bool m_ativo;

public:
	Jogador(const string nome);
	~Jogador();
	
	string getNome();
	int getPontos();
	bool isAtivo();
	void desativar();
	void jogar(Dado &d1, Dado &d2);
	
	friend std::ostream& operator<< (std::ostream &o, Jogador  * j);

};

#endif