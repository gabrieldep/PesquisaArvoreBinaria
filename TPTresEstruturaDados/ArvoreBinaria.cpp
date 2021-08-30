#include "ArvoreBinaria.h"
#include "TipoItemArvore.h"
#include "StringServices.h"
#include <iostream>

ArvoreBinaria::ArvoreBinaria()
{
	raiz = NULL;
}

ArvoreBinaria::~ArvoreBinaria()
{
	Limpa();
}

/// <summary>
/// Insere um elemento na ArvoreBinaria
/// </summary>
/// <param name="tipoItem">Item a ser adicionado</param>
void ArvoreBinaria::Insere(TipoItemArvore tipoItem)
{
	InsereRecursivo(raiz, tipoItem);
}

/// <summary>
/// Pesquisa na arvore binaria algum elemento que possui a chave igual à chave recebida
/// </summary>
/// <param name="nome">Chave com o nome a ser procurado na arvore binaria</param>
/// <returns></returns>
TipoNo ArvoreBinaria::Pesquisa(std::string nome)
{
	return PesquisaRecursiva(raiz, nome);
}

/// <summary>
/// Remove o elemento com a chave recebida da arvore binaria.
/// </summary>
/// <param name="nome">Chave com o nome do elemento a ser removido da arvore.</param>
void ArvoreBinaria::Remove(std::string nome)
{
	RemoveRecursiva(raiz, nome);
}

/// <summary>
/// Imprime a arvore binaria em uma unica linha em ordem alfabetica.
/// </summary>
void ArvoreBinaria::Imprime()
{
	InOrdem(raiz);
}

/// <summary>
/// Remove todos os elementos da arvore.
/// </summary>
void ArvoreBinaria::Limpa()
{
	ApagaRecursivo(raiz);
	raiz = NULL;
}

/// <summary>
/// Metodo auxiliar para adicionar elemento à arvore de maneira ordenada
/// </summary>
/// <param name="p">Nó atual a ser verificado.</param>
/// <param name="item">Item a ser adicionado.</param>
void ArvoreBinaria::InsereRecursivo(TipoNo*& p, TipoItemArvore item)
{
	if (p == NULL) {
		p = new TipoNo();
		p->SetNome(item.GetNome());

		TipoCelula* celula = new TipoCelula();
		celula->SetDados(item.GetDados());
		
		p->dadosBinarios->Enfileira(*celula);
	}
	else {
		if (item.GetNome() == p->GetNome()) {
			TipoCelula *celula = new TipoCelula();
			celula->SetDados(item.GetDados());
			p->dadosBinarios->Enfileira(*celula);
		}
		else if (StringServices().VemAntes(item.GetNome(), p->GetNome())) {
			InsereRecursivo(p->esq, item);
		}
		else {
			InsereRecursivo(p->dir, item);
		}
	}
}

/// <summary>
/// Metodo auxiliar para pesquisar elemento na arvore.
/// </summary>
/// <param name="p">Nó atual a ser verificado</param>
/// <param name="chave">Chave para encontrar o elemento.</param>
/// <returns>TipoNo correspondente a chave recebida</returns>
TipoNo ArvoreBinaria::PesquisaRecursiva(TipoNo*& p, std::string chave)
{
	TipoNo aux;

	if (p == NULL) {
		aux.SetNome("404");
		return aux;
	}
	if (StringServices().VemAntes(chave, p->GetNome())) {
		return PesquisaRecursiva(p->esq, chave);
	}
	else if (StringServices().VemAntes(p->GetNome(), chave)) {
		return PesquisaRecursiva(p->dir, chave);
	}
	else {
		return *p;
	}
}

/// <summary>
/// Metodo auxiliar para remover elemento na arvore.
/// </summary>
/// <param name="p">Nó atual a ser verificado</param>
/// <param name="chave">Chave para encontrar o elemento a ser removido.</param>
void ArvoreBinaria::RemoveRecursiva(TipoNo*& p, std::string chave)
{
	if (p == NULL) {
		return;
	}
	if (StringServices().VemAntes(chave, p->GetNome())) {
		RemoveRecursiva(p->esq, chave);
	}
	else if (StringServices().VemAntes(p->GetNome(), chave)) {
		RemoveRecursiva(p->dir, chave);
	}
	else {
		if (p->esq == NULL) {
			p = p->dir;
		}
		else if (p->dir == NULL) {
			p = p->esq;
		}
		else {
			Antecessor(p, p->esq);
		}
	}
}

/// <summary>
/// Metodo auxiliar para pesquisar elemento na arvore.
/// </summary>
/// <param name="p">Nó atual a ser deletado</param>
void ArvoreBinaria::ApagaRecursivo(TipoNo* p)
{
	if (p != NULL) {
		ApagaRecursivo(p->esq);
		ApagaRecursivo(p->dir);
		delete p;
	}
}

/// <summary>
/// Metodo que imprime elementos em ordem.
/// </summary>
/// <param name="p">Nó atual para ser impresso e procurar filhos.</param>
void ArvoreBinaria::InOrdem(TipoNo* p)
{
	if (p != NULL) {
		InOrdem(p->esq);
		p->ImprimeNome();
		InOrdem(p->dir);
	}
}

/// <summary>
/// Método que reconstroi a arvore caso algum elemento seja retirado.
/// </summary>
/// <param name="q">Elemento removido</param>
/// <param name="r">Elemento que vai ocupar o lugar.</param>
void ArvoreBinaria::Antecessor(TipoNo* q, TipoNo*& r)
{
	if (r->dir != NULL) {
		Antecessor(q, r->dir);
		return;
	}
	q->nome = r->nome;
	q->dadosBinarios= r->dadosBinarios;
	q = r;
	r = r->esq;
	free(q);
}
