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
		if (StringServices().VemAntes(item.GetNome(), p->GetNome())) {
			InsereRecursivo(p->esq, item);
		}
		else {
			InsereRecursivo(p->dir, item);
		}
	}
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
