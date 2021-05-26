#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ogrenci{
	char ogrenciAd[25];
	char ogrenciSoyad[25];
	int ogrenciNo;
};
struct firma{
	int vergiNo;
	char firmaAd[25];
	char faaliyetAlani[25];
};
struct staj{
	int stajFirmaVergiNo;
};

void ogrenciEkle(struct ogrenci ogrenciBilgisi[],int *i,struct ogrenci *pOgrenci[]){
	
	int k=*i;
	FILE *fp=fopen("Ogrenci.txt","a");
	
	if(fp==NULL){
		printf("Dosya Acilmadi");
}

	fprintf(fp,"Ogrencinin Adi\t\tOgrencinin Soyadi\t\tOgrencinin Numarasi\n");
	fprintf(fp,"---------------------------------------------------------------\n");
	fprintf(fp,"%s\t\t\t%s\t\t\t\t%d\n\n",pOgrenci[k]->ogrenciAd,pOgrenci[k]->ogrenciSoyad,pOgrenci[k]->ogrenciNo);
	
	fclose(fp);
}

void firmaEkle(struct firma firmaBilgisi[],int *f,struct firma *pFirma[]){

	int m=*f;
	
	FILE *fp=fopen("Firma.txt","a");
	
	if(fp==NULL){
		printf("Dosya Acilmadi");
}

	fprintf(fp,"Firmanin Adi\t\tFirmanin faaliyet alani\t\tFirmanin Vergi Numarasý\n");
	fprintf(fp,"---------------------------------------------------------------------------------\n");
	fprintf(fp,"%s\t\t\t%s\t\t\t\t%d\n\n",pFirma[m]->firmaAd,pFirma[m]->faaliyetAlani,pFirma[m]->vergiNo);

	fclose(fp);
}

int main()
{
    int menu_secim;
    int i=0;
    int f=0;
	struct ogrenci ogrenciBilgisi[10];
	struct firma firmaBilgisi[10];
	struct staj stajBilgisi[10];
	
	struct ogrenci *pOgrenci[10];
	struct firma *pFirma[10];
	
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
					printf("\n\t-----------Ogrenci Ekleme-----------\n\n");
					
					printf("Ogrencinin Adini Giriniz: ");
					scanf("%s",&ogrenciBilgisi[i].ogrenciAd);
					printf("Ogrencinin Soydini Giriniz: ");
					scanf("%s",&ogrenciBilgisi[i].ogrenciSoyad);
					printf("Ogrencinin Numarasini Giriniz: ");
					scanf("%d",&ogrenciBilgisi[i].ogrenciNo);
					pOgrenci[i]=&ogrenciBilgisi[i];
					
					ogrenciEkle(ogrenciBilgisi,&i,pOgrenci);
					
					i++;
					
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
                	printf("\n\t-----------Firma Ekleme-----------\n\n");
                	
                	printf("Firmanin ismi: ");
                	scanf("%s",&firmaBilgisi[f].firmaAd);
                	printf("Firmanin faaliyet alani: ");
                	scanf("%s",&firmaBilgisi[f].faaliyetAlani);
                	printf("Firmanin vergi numarasi: ");
                	scanf("%d",&firmaBilgisi[f].vergiNo);
                	
                	pFirma[f]=&firmaBilgisi[f];
                	
                	firmaEkle(firmaBilgisi,&f,pFirma);
                	


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
