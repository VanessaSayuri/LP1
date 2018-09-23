#include <iostream>
#include "jogador.h"

Jogador::Jogador(const string nome):m_nome(nome),m_pontos(0), m_ativo(true){}

Jogador::~Jogador(){}

string 
Jogador::getNome(){
	return m_nome;
}

int 
Jogador::getPontos(){
	return m_pontos;
}

bool 
Jogador::isAtivo(){
	return m_ativo;
}

void 
Jogador::desativar(){
	m_ativo = false;
}

void 
Jogador::jogar(Dado &d1, Dado &d2){
	m_pontos = d1.jogar() + d2.jogar();
}

std::ostream& operator<< (std::ostream &o, Jogador  * j){
	if(!j->m_ativo){
		o<<"*";
	}
	o<<j->m_nome<<"("<<j->m_pontos<<") ";

	return o;
}