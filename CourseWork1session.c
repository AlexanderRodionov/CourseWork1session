#include <stdio.h> 

#include <stdlib.h> 

#include <string.h> 

#include <math.h> 

  

int iwc(int* chislo) 

{ 

    char stroka[50]; 

    scanf("%s", &stroka); 

    int len = strlen(stroka); 

    for (int i =0; i<len; i++) 

        if((stroka[i] > '9') || (stroka[i] < '0')) 

            return 0; 

    *chislo = atoi(stroka); 

    return 1; 

} 

  

void zhadnyj(int* cen, int* count, char** metall) 

{ 

    double w[4] = {3.0, 4.0, 1.0, 2.0}; 

    int Q = 0, S = 0, W = 0, WES = 0, kon = 0; 

    int p, k, m; 

    int i = 0, j = 0, r = 0, f = 0, z; 

    for (i=0; i<4 ; i++) Q += count[i]; 

    char *met[Q], *met2[Q]; 

    double otn[Q], I[Q]; 

    int stoim[Q], ves[Q], stoim2[Q], ves2[Q]; 

    double max1 = 999.0, max2 = -1.0; 

  

    printf("Zhadnyj\n"); 

    printf("\nMozno uvezyi vsego KG: "); 

    while (iwc(&p) == 0) 

        printf("Povtorite vvod, vvedeno ne chislo!\n"); 

    printf("Mozno sdelat` zahodov: "); 

    while (iwc(&k) == 0) 

        printf("Povtorite vvod, vvedeno ne chislo!\n"); 

    printf("Mozno unesti za odin zahod KG: "); 

    while (iwc(&m) == 0) 

        printf("Povtorite vvod, vvedeno ne chislo!\n"); 

  

    while (j<4) { 

        while (count[j]>0) { 

            otn[i] = cen[j]/w[j]; 

            stoim[i] = cen[j]; 

            ves[i] = w[j]; 

            met[i] = metall[j]; 

            i++; 

            count[j] = count[j] - 1; 

        } 

        j++; 

    } 

  

    while (kon != 4) { 

        r = 0; 

        for (i=0 ; i<Q ; i++) { 

            if ((otn[i]<max1) && (otn[i]>max2)) max2 = otn[i]; 

        } 

        for (i=0 ; i<Q ; i++) { 

            if (otn[i] == max2) { 

                r++; 

                I[f] = otn[i]; 

                stoim2[f] = stoim[i]; 

                ves2[f] = ves[i]; 

                met2[f] = met[i]; 

                f++; 

            } 

        } 

        max1 = max2; 

        max2 = -1; 

        kon++; 

    } 

  

    i = 0; 

    for (z = 0; z<k ; z++) { 

        printf("\n%d ZAHOD: ", z+1); 

        for (i; ; i++) { 

            if (((W + ves2[i])<=m) && ((WES + ves2[i])<=p) && (i<Q)) { 

                S += stoim2[i]; 

                W += ves2[i]; 

                WES += ves2[i]; 

                printf("%s ", met2[i]); 

            } 

            else break; 

        } 

        W = 0; 

    } 

    printf("\n\nITOGO: %d RUB\n", S); 

} 

  

void perebor(int* cen, int* count, char** met, int* mas) 

{ 

    int Q = 0, max_summ = -1, this_ves, SUMM, VES, NO, zah=1, ITOG_VES = 0, ITOG_SUM = 0; 

    int p, k, m; 

    int i, j, t, f; 

    double q = 0; 

    for (i=0; i<4 ; i++) { 

        Q += count[i]; 

        q += count[i]; 

    } 

    int full_mas[Q], full_met[Q], full_cen[Q], dv[Q]; 

    float step = pow(2.0, q) - 1; 

  

    printf("Perebor\n"); 

    printf("\nMozno uvezyi vsego KG: "); 

    while (iwc(&p) == 0) 

        printf("Povtorite vvod, vvedeno ne chislo!\n"); 

    printf("Mozno sdelat` zahodov: "); 

    while (iwc(&k) == 0) 

        printf("Povtorite vvod, vvedeno ne chislo!\n"); 

    printf("Mozno unesti za odin zahod KG: "); 

    while (iwc(&m) == 0) 

        printf("Povtorite vvod, vvedeno ne chislo!\n"); 

  

    int polz[Q]; 

    for (i=0; i<Q; i++) polz[i] = 1; 

  

    i=0; 

    j=0; 

    while (i<4) { 

        while (count[i] > 0) { 

            full_mas[j] = mas[i]; 

            full_cen[j] = cen[i]; 

            full_met[j] = met[i]; 

            count[i] --; 

            j++; 

        } 

        i++; 

    } 

  

    while (zah <= k) { 

        printf("\n%d ZAHOD: ", zah); 

        max_summ = 0; 

        this_ves = 0; 

        NO = 0; 

        for (t=1; t<=step ; t++) { 

            f = t; 

            i = 0; 

            SUMM = 0; 

            VES = 0; 

  

            for(;f>0; f/=2) { 

                dv[i] = f%2; 

                i++; 

            } 

            for(;i<Q; i++) dv[i] = 0; 

  

            for (i=Q-1; i>=0; i--) { 

                SUMM += dv[i]*full_cen[i]; 

                VES += dv[i]*full_mas[i]; 

            } 

  

            if ((SUMM>max_summ)&&(VES<=m)&&(ITOG_VES+VES<=p)){ 

                for (i=0, j=0; i<Q; i++) if (dv[i]>polz[i]) j++; 

                if (j == 0) { 

                    max_summ = SUMM; 

                    this_ves = VES; 

                    NO = t; 

                } 

            } 

        } 

  

        if (ITOG_VES+this_ves<=p){ 

            ITOG_VES += this_ves; 

            ITOG_SUM += max_summ; 

        } 

  

        for(i=0 ;NO>0; NO/=2) { 

            dv[i] = NO%2; 

            i++; 

        } 

        for (;i<Q; i++) dv[i] = 0; 

        for (i = Q-1; i>=0 ; i--) { 

            if (dv[i] != 0){ 

                polz[i]--; 

                printf("%s ", full_met[i]); 

            } 

        } 

    zah ++; 

    } 

    printf("\n\nITOGO: %d RUB\n",ITOG_SUM); 

} 

  

void vetvi(int* cen, int* count, char** met, int* mas) 

{ 

    int Q = 0, i, j, p, k, m, max_summ = -1, this_ves, t, f, SUMM, VES, NO, zah=1, ITOG_VES = 0, ITOG_SUM = 0; 

    double q = 0; 

    for (i=0; i<4 ; i++) { 

        Q += count[i]; 

        q += count[i]; 

    } 

    int full_mas[Q], full_met[Q], full_cen[Q], dv[Q], polz[Q],sovpad[Q]; 

    float step = pow(2.0, q) - 1; 

  

    printf("Vetvi\n"); 

    printf("\nMozno uvezyi vsego KG: "); 

    while (iwc(&p) == 0) 

        printf("Povtorite vvod, vvedeno ne chislo!\n"); 

    printf("Mozno sdelat` zahodov: "); 

    while (iwc(&k) == 0) 

        printf("Povtorite vvod, vvedeno ne chislo!\n"); 

    printf("Mozno unesti za odin zahod KG: "); 

    while (iwc(&m) == 0) 

        printf("Povtorite vvod, vvedeno ne chislo!\n"); 

  

    for (i=0; i<Q; i++) polz[i] = 1; 

    i=0; 

    j=0; 

    while (i<4) { 

        while (count[i] > 0) { 

            full_mas[j] = mas[i]; 

            full_cen[j] = cen[i]; 

            full_met[j] = met[i]; 

            count[i] --; 

            j++; 

        } 

        i++; 

    } 

    for (i=0; i<Q; i++) sovpad[i] = 0; 

  

    while (zah <= k) { 

        printf("\n%d ZAHOD: ", zah); 

        max_summ = 0; 

        this_ves = 0; 

        NO = 0; 

        for (t=1; t<=step ; t++) { 

            f = t; 

            SUMM = 0; 

            VES = 0; 

            for (i=0; f>0; f/=2) { 

                dv[i] = f%2; 

                i++; 

            } 

            for(;i<Q; i++) dv[i] = 0; 

  

            for (i=Q-1; i>=0; i--) { 

                VES += dv[i]*full_mas[i]; 

                SUMM += dv[i]*full_cen[i]; 

                if ((VES>m)||(ITOG_VES>p)) sovpad[i] =1; 

            } 

  

            if ((SUMM>=max_summ)&&(VES<=m)&&(ITOG_VES+VES<=p)){ 

                for (i=0, j=0; i<Q; i++){ 

                    if ((dv[i]>polz[i])&&((dv[i]==1)&&(sovpad[i]==1))) { 

                        j++; 

                    } 

                } 

                if (j == 0) { 

                    max_summ = SUMM; 

                    this_ves = VES; 

                    NO = t; 

                } 

            } 

        } 

  

        if (ITOG_VES+this_ves<=p){ 

            ITOG_VES += this_ves; 

            ITOG_SUM += max_summ; 

        } 

  

        for(i=0 ;NO>0; NO/=2) { 

            dv[i] = NO%2; 

            i++; 

        } 

        for (;i<Q; i++) dv[i] = 0; 

        for (i = Q-1; i>=0 ; i--) { 

            if ((dv[i] == 1)&&(polz[i] == 1)){ 

                printf("%s ",full_met[i]); 

                polz[i] = 0; 

            } 

        } 

    zah ++; 

    } 

    printf("\n\nITOGO: %d RUB\n",ITOG_SUM); 

} 

  

void DP(int* cen, int* count, char** met, int* mas) 

{ 

    int i, j=0; 

    int Q=0; 

    int p, k, m; 

    for (i=0; i<4 ; i++) Q += count[i]; 

    int full_mas[Q], full_met[Q], full_cen[Q]; 

    i = 0; 

    full_cen[0] = 0; 

    full_mas[0] = 0; 

    printf("DP\n"); 

    printf("\nMozno uvezyi vsego KG: "); 

    while (iwc(&p) == 0) 

        printf("Povtorite vvod, vvedeno ne chislo!\n"); 

    /* printf("Mozno sdelat` zahodov: "); 

    while (iwc(&k) == 0) 

        printf("Povtorite vvod, vvedeno ne chislo!\n"); 

    printf("Mozno unesti za odin zahod KG: "); 

    while (iwc(&m) == 0) 

        printf("Povtorite vvod, vvedeno ne chislo!\n"); */ 

  

    while (i<4) { 

        while (count[i] > 0) { 

            full_mas[j+1] = mas[i]; 

            full_cen[j+1] = cen[i]; 

            full_met[j+1] = met[i]; 

            count[i] --; 

            j++; 

        } 

        i++; 

    } 

  

    int** ALG; 

    ALG = (int**)malloc(Q * sizeof(int*)); 

    for (i=0; i<=Q; ++i) 

        ALG[i] = (int*)malloc(p * sizeof(int)); 

  

    for (i=0, j = 0; i<=Q; i++) ALG[i][j] = 0; 

    for (i=0, j = 0; j<=p; j++) ALG[i][j] = 0; 

  

    for (i=1; i<=Q; ++i) { 

        for (j=1; j<=p; ++j) { 

            if ((j-full_mas[i])<0) ALG[i][j] = ALG[i-1][j]; 

            else { 

                if (ALG[i-1][j]<(ALG[i-1][j-full_mas[i]]+full_cen[i])) 

                    ALG[i][j] = ALG[i-1][j-full_mas[i]]+full_cen[i]; 

                else 

                    ALG[i][j] = ALG[i-1][j]; 

            } 

            printf("%d\t", ALG[i][j]); 

        } 

        printf("\n"); 

    } 

    printf("ITOGO: %d RUB\n", ALG[Q][p]); 

} 

  

int main() 

{ 

    int cena_slitka[4] = {4, 1, 2, 3}; 

    int kolichestvo[4] = {1, 4, 3, 6}; 

    int massa_slitka[4] = {3,4,1,2}; 

    char *nazvanie[4] = {"PALLADIY", "SEREBRO", "ZOLOTO", "PLATINA"}; 

    printf("-----------------V HRANILISHE:-----------------\n"); 

    for (int i=0; i<4; i++) printf("%s : \t %d RUB \t %d KG \t %d Q\n", nazvanie[i], cena_slitka[i], massa_slitka[i], kolichestvo[i]); 

    int select; 

    printf("-----------------------------------------------\nCommand:\n0 - exit\n1 - zhadnyj\n2 - perebor\n3 - vetvi\n4 - DP\n\nInput: "); 

    scanf("%d",&select); 

    if ((select == 0) || (select == 1) || (select == 2) || (select == 3) || (select == 4)) { 

        switch(select) { 

            case 0: 

                printf("Exit program\n"); 

                system("pause"); 

                return 0; 

                break; 

  

            case 1: 

                printf("-----------------------------------------------\n"); 

                zhadnyj(cena_slitka, kolichestvo, nazvanie); 

                system("pause"); 

                break; 

  

            case 2: 

                printf("-----------------------------------------------\n"); 

                perebor(cena_slitka, kolichestvo, nazvanie, massa_slitka); 

                system("pause"); 

                break; 

  

            case 3: 

                printf("-----------------------------------------------\n"); 

                vetvi(cena_slitka, kolichestvo, nazvanie, massa_slitka); 

                system("pause"); 

                break; 

  

            case 4: 

                printf("-----------------------------------------------\n"); 

                DP(cena_slitka, kolichestvo, nazvanie, massa_slitka); 

                system("pause"); 

                break; 

        } 

    } 

    else { 

        printf("No  command\n"); 

        system("pause"); 

        return 0; 

    } 

    printf("-----------------------------------------------\n"); 

    return 0; 

} 