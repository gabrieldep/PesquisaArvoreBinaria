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

void TipoItem::SetDados(std::string valor)
{
	this->dados = valor;
}

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
