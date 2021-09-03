#pragma once
#include "TipoItem.h"
#include <string>
#include "Fila.h"
class TipoNo
{
public:
	TipoNo();
	~TipoNo();
	void SetNome(std::string nome);
	std::string GetNome();
	Fila* GetDados();
	void ImprimeNome();
	void ImprimeDados();
private:
	std::string nome;
	Fila* dadosBinarios;
	TipoNo* esq;
	TipoNo* dir;
	friend class ArvoreBinaria;
};

