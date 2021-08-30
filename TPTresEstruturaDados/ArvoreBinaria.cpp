#include "ArvoreBinaria.h"
#include "TipoItemArvore.h"
#include "StringServices.h"

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
}

void ArvoreBinaria::Caminha(int tipo)
{
}

void ArvoreBinaria::Imprime()
{
	PreOrdem(raiz);
}

void ArvoreBinaria::Limpa()
{
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
}

void ArvoreBinaria::ApagaRecursivo(TipoNo* p)
{
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
}

void ArvoreBinaria::PosOrdem(TipoNo* p)
{
}
