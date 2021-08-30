#include "TipoNo.h"

TipoNo::TipoNo()
{
	this->dadosBinarios = new Fila();
	this->nome = "";
}

void TipoNo::SetNome(std::string nome)
{
	this->nome = nome;
}

std::string TipoNo::GetNome()
{
	return this->nome;
}
