#include "TipoNo.h"
#include <iostream>

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

void TipoNo::ImprimeNome()
{
	std::cout << this->nome << std::endl;
}

void TipoNo::ImprimeDados()
{
	dadosBinarios->Imprime();
}
