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

void ArvoreBinaria::Insere(TipoItemArvore tipoItem)
{
	InsereRecursivo(raiz, tipoItem);
}

TipoNo ArvoreBinaria::Pesquisa(std::string nome)
{
	return PesquisaRecursiva(raiz, nome);
}

void ArvoreBinaria::Remove(std::string nome)
{
	RemoveRecursiva(raiz, nome);
}

void ArvoreBinaria::Caminha(int tipo)
{
}

void ArvoreBinaria::Imprime()
{
	InOrdem(raiz);
}

void ArvoreBinaria::Limpa()
{
	ApagaRecursivo(raiz);
	raiz = NULL;
}

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

void ArvoreBinaria::ApagaRecursivo(TipoNo* p)
{
	if (p != NULL) {
		ApagaRecursivo(p->esq);
		ApagaRecursivo(p->dir);
		delete p;
	}
}

void ArvoreBinaria::PorNivel()
{
}

void ArvoreBinaria::PreOrdem(TipoNo* p)
{
	if (p != NULL) {
		p->ImprimeNome();
		PreOrdem(p->esq);
		PreOrdem(p->dir);
	}
}

void ArvoreBinaria::InOrdem(TipoNo* p)
{
	if (p != NULL) {
		InOrdem(p->esq);
		p->ImprimeNome();
		InOrdem(p->dir);
	}
}

void ArvoreBinaria::PosOrdem(TipoNo* p)
{
	if (p != NULL) {
		PosOrdem(p->esq);
		PosOrdem(p->dir);
		p->ImprimeNome();
	}
}

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
