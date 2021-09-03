#pragma once
#include "TipoCelula.h"
class Fila
{
private:
	void ImprimeRecursiva(TipoCelula* celula);
	int tamanho;
	TipoCelula* frente;
	TipoCelula* tras;
public:
	Fila();
	~Fila();
	int GetTamanho();
	bool Vazia();
	void Enfileira(TipoCelula tipoCelula);
	void Imprime();
	TipoCelula Desenfilera();
	void Limpa();
};

