#include "TipoItemArvore.h"
#include <iostream>

TipoItemArvore::TipoItemArvore()
{
    this->dados = "";
    this->nome = "";
}

TipoItemArvore::TipoItemArvore(std::string dados, std::string nome)
{
    this->dados = dados;
    this->nome = nome;
}

/// <summary>
/// Define o valor dos dados
/// </summary>
/// <param name="valor">Valor a ser atribuido</param>
void TipoItemArvore::SetDados(std::string valor)
{
    this->dados = valor;
}

/// <summary>
/// Define o valor dos dados
/// </summary>
/// <param name="valor">Valor a ser atribuido</param>
void TipoItemArvore::SetDadosInt(int valor)
{
    this->dadosInt = valor;
}

/// <summary>
/// Define o valor do nome
/// </summary>
/// <param name="valor">Valor a ser atribuido</param>
void TipoItemArvore::SetNome(std::string valor)
{
    this->nome = valor;
}

/// <summary>
/// Retorna o valor dos dados
/// </summary>
/// <returns></returns>
std::string TipoItemArvore::GetDados()
{
    return this->dados;
}

/// <summary>
/// Retorna o valor dos dados
/// </summary>
/// <returns></returns>
int TipoItemArvore::GetDadosInt()
{
    return this->dadosInt;
}

/// <summary>
/// Retorna o valor do nome
/// </summary>
/// <returns></returns>
std::string TipoItemArvore::GetNome()
{
    return this->nome;
}

/// <summary>
/// Imprime os dados e o nome
/// </summary>
void TipoItemArvore::Imprime()
{
    std::cout << this->nome << " " << this->dados << std::endl;
}
