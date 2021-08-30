#include "TipoItem.h"
#include <iostream>
#include <string>

/// <summary>
/// Construtor sem valor inicial.
/// </summary>
TipoItem::TipoItem()
{
	this->dados = "";
}

/// <summary>
/// Construtor com valor inicial.
/// </summary>
/// <param name="caractere"></param>
TipoItem::TipoItem(std::string dados)
{
	this->dados = dados;
}

/// <summary>
/// Define o valor do atributo dados
/// </summary>
/// <param name="valor">Valor a ser atribuido</param>
void TipoItem::SetDados(std::string valor)
{
	this->dados = valor;
}

/// <summary>
/// Pega o valor dos dados
/// </summary>
/// <returns>Valor do atributo dados.</returns>
std::string TipoItem::GetDados()
{
	return this->dados;
}

/// <summary>
/// Imprime no terminal o valor da chave.
/// </summary>
void TipoItem::Imprime()
{
	std::string b = GetDados();
	std::cout << b << "\n";
}
