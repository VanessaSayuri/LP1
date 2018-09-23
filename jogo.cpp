#include <iostream>
#include "jogo.h"
#include "dado.h"

using namespace std;

Jogo::Jogo():
	m_total_jogadores(0),m_rodada(0),
	m_vencedor(nullptr),m_total_ativos(0){
	m_dados[0] = new Dado(6);
	m_dados[1] = new Dado(6);
}

Jogo::~Jogo(){}

int 
Jogo::getTotalJogadores(){
	return m_total_jogadores;
}

Jogador * 
Jogo::getVencedor(){
	return m_vencedor;
}

int 
Jogo::getRodada(){
	return m_rodada;
}

void 
Jogo::addJogador(Jogador * novo){
	if (m_total_jogadores<MAX_JOGADORES) {
		m_jogadores[m_total_jogadores++] = novo;
		m_total_ativos++;
	} else {
		cerr << "Jogo lotado." << endl;
	}
}
	
void 
Jogo::imprimeVencedor(){
	cout << "O vencedor foi: " << m_vencedor->getNome()
		<< " com o total de pontos: " << m_vencedor->getPontos()
		<< "." << endl;
}

void 
Jogo::run(){
	while (m_total_ativos>1){
		/* Simula a roda */
		//cout << "Rodada " << ++m_rodada << endl;
		++m_rodada;
		for (int i = 0; i < m_total_jogadores; ++i)
		{
			if (m_jogadores[i]->isAtivo()){
				m_jogadores[i]->jogar(*m_dados[0],*m_dados[1]);
			}
		}
		if (!desativaJogador()){
			cerr << "Nao removi ninguem!" << endl;
		}
		imprimeDadosRodada();
	}
	defineVencedor();
	/* Imprimir dados do vencedor */
	imprimeVencedor();
}

void 
Jogo::defineVencedor(){
	for (int i = 0; i < m_total_jogadores; ++i)
	{
		if (m_jogadores[i]->isAtivo()){
			if(m_jogadores[i]->getPontos() == pontuacaoN)
			m_vencedor = m_jogadores[i];
			break;

		}
		/*else if (m_jogadores[i]->isAtivo() == 1){
			m_vencedor = m_jogadores[i];
			break;
		}*/
	}
}

bool 
Jogo::desativaJogador(){
	//bool iguais = false;
	
	/*int j=0;
	while(!m_jogadores[j]->isAtivo()) j++;
	//Jogador * pontuacaoN = m_jogadores[j];

	for (int i = j+1; i < m_total_jogadores; ++i)
	{
		if (m_jogadores[i]->isAtivo()){
			if (m_jogadores[i]->getPontos() > pontuacaoN){
				m_jogadores[i]->desativar();
			}
		}
	}
	return false;*/
	//bool iguais = false;
	/*int j=0;
	while(!m_jogadores[j]->isAtivo()) j++;
	Jogador * maior = m_jogadores[j];*/

	for (int i = 0; i < m_total_jogadores; ++i)
	{
		if (m_jogadores[i]->isAtivo()){
			/*if(m_jogadores[i]->getPontos() == maior->getPontos()){
				iguais = false;
			}*/
			//if (m_jogadores[i]->getPontos() > maior->getPontos()){
			//	maior = m_jogadores[i];
			//	iguais = true;

				if(m_jogadores[i]->getPontos() > pontuacaoN){
					m_jogadores[i]->desativar();
					//maior = m_jogadores[i];
					//iguais = false;
					m_total_ativos--;
				}
				else if(m_jogadores[i]->getPontos() == pontuacaoN){
					//m_jogadores->desativar();
					//maior = m_jogadores[i];
					//iguais = false;
					m_jogadores[i]->isAtivo();;

				}
				/*else{
					iguais = true;
				}*/
			//}
		}
	}
	/*if(!iguais){
		maior->desativar();
		m_total_ativos--;
		return true;
	}*/
	
	return true;
}

void Jogo::imprimeDadosRodada(){
	cout<<"Rodada "<< m_rodada << ": ";
	for (int i = 0; i < m_total_jogadores; ++i)
	{
		// if(!m_jogadores[i]->isAtivo()){
		// 	cout << "*";
		// }
		// cout<<m_jogadores[i]->getNome()<<"("<<m_jogadores[i]->getPontos()<<") ";
		cout<<m_jogadores[i];
	}
	cout<<endl;
}