#include "TipoItemArvore.h"

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

void TipoItemArvore::SetDados(std::string valor)
{
    this->dados = valor;
}

void TipoItemArvore::SetNome(std::string valor)
{
    this->nome = valor;
}

std::string TipoItemArvore::GetDados()
{
    return this->dados;
}

std::string TipoItemArvore::GetNome()
{
    return this->nome;
}

void TipoItemArvore::Imprime()
{
}
