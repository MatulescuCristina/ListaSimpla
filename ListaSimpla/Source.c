#include<stdio.h>
#include<malloc.h>

// structura Oras
struct Oras
{
	char* denumire;
	int nrLocuitori;
	float suprafata;
};

// structura Nod
struct Nod
{
	struct Oras info;
	struct Nod* next;
};

// inserare nod la inceput
struct Nod* inserareInceput(struct Nod* cap, struct Oras o)
{
	struct Nod* nou = (struct Nod*)malloc(sizeof(struct Nod));

	nou->info.denumire = (char*)malloc((strlen(o.denumire) + 1) * sizeof(char));
	strcpy(nou->info.denumire, o.denumire);

	nou->info.nrLocuitori = o.nrLocuitori;
	nou->info.suprafata = o.suprafata;

	nou->next = NULL;

	if (cap == NULL)
	{
		cap = nou;
		return cap;
	}
	else
	{
		nou->next = cap;
		cap = nou;
		return cap;
	}
}

// inserare nod la final
struct Nod* inserareFinal(struct Nod* cap, struct Oras o)
{
	struct Nod* nou = (struct Nod*)malloc(sizeof(struct Nod));

	nou->info.denumire = (char*)malloc((strlen(o.denumire) + 1) * sizeof(char));
	strcpy(nou->info.denumire, o.denumire);

	nou->info.nrLocuitori = o.nrLocuitori;
	nou->info.suprafata = o.suprafata;

	nou->next = NULL;

	if (cap == NULL)
	{
		cap = nou;
	}
	else
	{
		struct Nod* aux = cap;
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = nou;
	}
	return cap;
}

// inserare nod in interior (dupa nr loc)
struct Nod* inserareInterior(struct Nod* cap, struct Nod* p, struct Oras o)
{
	struct Nod* nou = (struct Nod*)malloc(sizeof(struct Nod));

	nou->info.denumire = (char*)malloc((strlen(o.denumire) + 1) * sizeof(char));
	strcpy(nou->info.denumire, o.denumire);

	nou->info.nrLocuitori = o.nrLocuitori;
	nou->info.suprafata = o.suprafata;

	if (cap != NULL)
	{
		cap = nou;
		return cap;
	}
	if (cap == p)
	{
		nou->next = cap;
		cap = nou;
		return nou;
	}
	nou->next = p->next;
	p->next = nou;
}

// afisare lista simpla
void afisare(struct Nod* cap)
{
	if (cap)
	{
		struct Nod* aux = cap;
		while (aux != NULL)
		{
			printf("Denumire oras: %s, nr locuitori: %d, suprafata: %5.2f\n",
				aux->info.denumire, aux->info.nrLocuitori, aux->info.suprafata);
			aux = aux->next;
		}
	}
}

// stergere lista simpla
void stergere(struct Nod* cap)
{
	while (cap)
	{
		free(cap->info.denumire);

		struct Nod* aux = cap;
		cap = cap->next;
		free(aux);
	}
}
void main()
{
	int nr;
	struct Nod* cap = NULL;
	struct Oras o;
	char buffer[20];

	FILE* f = fopen("oras.txt", "r");
	fscanf(f, "%d", &nr);

	for (int i = 0; i < nr; i++)
	{
		fscanf(f, "%s", buffer);
		o.denumire = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
		strcpy(o.denumire, buffer);

		fscanf(f, "%d", &o.nrLocuitori);

		fscanf(f, "%f", &o.suprafata);

		cap = inserareFinal(cap, o);
		free(o.denumire);
	}
	fclose(f);

	printf("\n	Lista simpla\n");
	afisare(cap);

}