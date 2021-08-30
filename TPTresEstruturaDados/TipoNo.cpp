#include "TipoNo.h"
#include <iostream>

TipoNo::TipoNo()
{
	this->dadosBinarios = new Fila();
	this->nome = "";
}

/// <summary>
/// Define o valor do nome
/// </summary>
/// <param name="nome">Valor a ser atribuido</param>
void TipoNo::SetNome(std::string nome)
{
	this->nome = nome;
}

/// <summary>
/// Retorna o nome
/// </summary>
/// <returns></returns>
std::string TipoNo::GetNome()
{
	return this->nome;
}

/// <summary>
/// Retorna os dados
/// </summary>
/// <returns></returns>
Fila* TipoNo::GetDados()
{
	return dadosBinarios;
}

/// <summary>
/// Imprime o nome na saida padrão
/// </summary>
void TipoNo::ImprimeNome()
{
	std::cout << this->nome << " ";
}

/// <summary>
/// Imprime os dados na saida padrão
/// </summary>
void TipoNo::ImprimeDados()
{
	dadosBinarios->Imprime();
}
