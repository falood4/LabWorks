#include <stdio.h>


struct poly
{
        int coeff;
        int exp;
} term[100];


int pree = 0; 


void newterm(int a, int b); 
int compare(int exp1, int exp2); 


int main()
{
        int af, al, bf, bl;
        
        printf("Enter the highest exponent of polynomial A: ");
        scanf("%d", &al);
        printf("Enter the highest exponent of polynomial B: ");
        scanf("%d", &bl);


        
        printf("Enter the coefficients and exponents of polynomial A:\n");
        for (int i = 0; i <= al; i++)
        {
            printf("Coefficient for x^%d: ", i);
            scanf("%d", &term[i].coeff);
            term[i].exp = i;
            pree++;
        }


        
        printf("Enter the coefficients and exponents of polynomial B:\n");
        for (int i = 0; i <= bl; i++)
        {
            printf("Coefficient for x^%d: ", i);
            scanf("%d", &term[pree].coeff);
            term[pree].exp = i;
            pree++;
        }


        int p, q, c;
        p = 0;
        q = al + 1; 


        while (p <= al && q <= (al + bl + 1))
        {
            switch (compare(term[p].exp, term[q].exp))
            {
            case '=':
                c = term[p].coeff + term[q].coeff;
                if (c != 0)
                    newterm(c, term[p].exp);
                p++;
                q++;
                break;
            case '<':
                newterm(term[q].coeff, term[q].exp);
                q++;
                break;
            case '>':
                newterm(term[p].coeff, term[p].exp);
                p++;
                break;
            }
        }


        
        while (p <= al)
        {
            newterm(term[p].coeff, term[p].exp);
            p++;
        }


        
        while (q <= (al + bl + 1))
        {
            newterm(term[q].coeff, term[q].exp);
            q++;
        }


        printf("First polynomial:\n");
	for (int i = 0; i <= al; i++)
        {
            printf("%dx^%d: ", term[i].coeff,term[i].exp);
        }

	printf("\nSecond polynomial:\n");
	for (int i = al+1; i <= al+bl+1; i++)
        {
            printf("%dx^%d: ", term[i].coeff,term[i].exp);
        }

        printf("\nResultant Polynomial:\n");
        for (int i = al+bl+2; i < pree; i++)
        {
            printf("%dx^%d", term[i].coeff, term[i].exp);
            if (i < pree - 1)
                printf(" + ");
        }
        printf("\n");


        return 0;
}


int compare(int exp1, int exp2)
{
        if (exp1 == exp2)
            return '=';
        else if (exp1 < exp2)
            return '<';
        else
            return '>';
}


void newterm(int a, int b)
{
        if (pree >= 100)
            printf("Not enough space\n");
        else
        {
            term[pree].coeff = a;
            term[pree].exp = b;
            pree++;
        }
}
