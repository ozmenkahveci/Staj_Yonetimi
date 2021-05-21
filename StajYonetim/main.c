#include <stdio.h>
#include <stdlib.h>

int main()
{
    int menu_secim;

    printf("\tStaj Yonetim Programina Hos Geldiniz\n\n");
    anamenu:
    printf("\n\t----------------Menu----------------\n\n");
    printf("\t1- Ogrenci Islemleri\n");
    printf("\t2- Firma Islemleri\n");
    printf("\t3- Staj Islemleri\n");
    printf("\n\t\t\t\t Programdan cikis icin 4 tusuna basiniz.\n");
    printf("\nBir islem seciniz: ");
    scanf("%d",&menu_secim);
    switch(menu_secim)
    {
        case 1:
             altbolum1:
             printf("\n\t-----------Ogrenci Menusu-----------\n\n");
            printf("\t1- Ogrenci Ekleme\n");
            printf("\t2- Ogrenci Duzenleme\n");
            printf("\t3- Ogrenci Silme\n");
            printf("\t4- Ogrenci Listele\n");
            printf("\n\t\t\t\t Ana menuye donmek icin 5 tusuna basiniz.\n");
            printf("\nBir islem seciniz: ");
            scanf("%d",&menu_secim);
                switch(menu_secim)
            {
                case 1:


                    goto altbolum1;
                    break;

                case 2:


                    goto altbolum1;
                    break;

                case 3:


                    goto altbolum1;
                    break;

                case 4:


                    goto altbolum1;
                    break;

                case 5:
                    goto anamenu;
                    break;

                default:
                    printf("Lutfen menude bulunan islemlerden birini seciniz!\n");
                    goto altbolum1;

            }
            break;

        case 2:
           altbolum2:
            printf("\n\t------------Firma Menusu-------------\n\n");
            printf("\t1- Firma Ekleme\n");
            printf("\t2- Firma Duzenleme\n");
            printf("\t3- Firma Silme\n");
            printf("\t4- Firma Listele\n");
            printf("\n\t\t\t\t Ana menuye donmek icin 5 tusuna basiniz.\n");
            printf("Bir islem seciniz: ");
            scanf("%d",&menu_secim);
            switch(menu_secim)
            {
                case 1:


                    goto altbolum2;
                    break;

                case 2:


                    goto altbolum2;
                    break;

                case 3:


                    goto altbolum2;
                    break;

                case 4:


                    goto altbolum2;
                    break;

                case 5:
                    goto anamenu;
                    break;

                default:
                    printf("Lutfen menude bulunan islemlerden birini seciniz!\n");
                    goto altbolum2;
            }
            break;
        case 3:
            altbolum3:
            printf("\n\t-------------Staj Menusu-------------\n\n");
            printf("\t1- Staj Ekleme\n");
            printf("\t2- Tamamlanmamis Stajlar\n");
            printf("\t3- Tamamlanmis Stajlar\n");
            printf("\n\t\t\t\t Ana menuye donmek icin 4 tusuna basiniz.\n");
            printf("Bir islem seciniz: ");
            scanf("%d",&menu_secim);
            switch(menu_secim)
            {
                case 1:


                    goto altbolum3;
                    break;

                case 2:


                    goto altbolum3;
                    break;

                case 3:


                    goto altbolum3;
                    break;

                case 4:
                    goto anamenu;
                    break;


                default:
            printf("Lutfen menude bulunan islemlerden birini seciniz!\n");
            goto altbolum3;
            }
            break;


        case 4:
            return 0;
            break;

                default:
                    printf("Lutfen menude bulunan islemlerden birini seciniz!\n");
                    goto anamenu;
    }




    return 0;
}
