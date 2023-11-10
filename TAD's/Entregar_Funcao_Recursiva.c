/*
Desafio:
Implementar uma fun��o recursiva para lista duplamente encadeadaque fa�a uma das seguintes opera��es:
inser��o na �ltima posi��o, inser��o ordenada ou remo��o
*/

static void inserir_Ultimo_Rec_DE(int key, CellDE *c)
{
    if(c->next == NULL)
    {
        CellDE *nova = criar_celulaDE(key);
        c->next = nova;
        nova->prev = c;
        nova->next = NULL;
    }
    else
        return inserir_Ultimo_Rec_DE(key, c->next);
}

void inserir_Ultimo(int key, ListaDE *l)
{
    if (l == NULL)
        l = criar_ListaDE();

    if (ListaDE_vazia(l))
        inserir_primeiro(key, l);
    else
    {
        return inserir_Ultimo_Rec_DE(key, l->head);
    }
}

static int inserir_Ordenado_Rec_DE(int key, CellDE *c, CellDE *auxP)
{
    if (c == NULL)
        return 0;

    CellDE *nova = criar_celulaDE(key);

    if(key < c->item)
    {
        auxP->next = nova;
        nova->prev = auxP;
        nova->next = c;
        if(c != NULL)
            c->prev = nova;
        return 1;
    }
    else
    {
        return inserir_Ordenado_Rec_DE(key, c->next, c);
    }

}

void inserir_ordenado(int key, ListaDE *l)
{
    CellDE *auxA, *auxP, *nova;

    if (l == NULL)
        l = criar_ListaDE();

    if (ListaDE_vazia(l))
        inserir_primeiro(key, l);
    else
    {
        nova = criar_celulaDE(key);
        if (l->head == NULL)
            l->head = nova;
        else if (key < l->head->item)
        {
            nova->next = l->head;
            l->head->previous = nova;
            l->head = nova;
        }
        else
        {
            auxP=auxA=l->head;
            return inserir_Ordenado_Rec_DE(key, auxA->next, auxP);
        }
    }
}

static int remover_Rec_DE(int key, CellDE *c)
{
    if(c == NULL)
        return 0;

    CellDE *aux;
    if(c->item == key)
    {
        aux = c;
        c = c->next;
        free(aux);
        return 1;
    }
    else
    {
        return remover_Rec_DE(key, c->next);
    }

 }

int remover(int key, ListaDE *l)
{
    CellDE *auxA;

    if (!ListaDE_vazia(l))
    {
        auxA = l->head;

        if(auxA->item == key)
        {
            l->head = l->head->next;
            l->head->prev = NULL;
            free(auxA);
            return 1;
        }
        else
             return remover_Rec_DE(key, auxA->next);
    }

    return 0;
}
