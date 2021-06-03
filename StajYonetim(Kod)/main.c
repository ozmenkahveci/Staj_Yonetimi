#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	int gun;
	int ay;
	int yil;
}tarih;
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
	tarih stajBaslamaTarihi;
	tarih stajBitirmeTarihi;
	char stajTuru[20];
};


void ogrenciEkle(struct ogrenci ogrenciBilgisi[],int *i,struct ogrenci *pOgrenci[],struct ogrenci ogrenciBilgisiYedek[]){
	
	int k=*i;
	int e=0;
	FILE *fp=fopen("Ogrenci.txt","r");
	while(!feof(fp)){
		fscanf(fp,"%s %s %d",&ogrenciBilgisiYedek[e].ogrenciAd,&ogrenciBilgisiYedek[e].ogrenciSoyad,&ogrenciBilgisiYedek[e].ogrenciNo);	
		if(ogrenciBilgisiYedek[e].ogrenciNo==pOgrenci[k]->ogrenciNo){
			printf("\nAyni Numaraya Sahip Bir Ogrenci Var!!\n");
			return ;
		}
		e++;	
	}
	fclose(fp);
	fp=fopen("Ogrenci.txt","a");
	
	if(fp==NULL){
		printf("Dosya Acilmadi");
		
}
	fprintf(fp,"%s %s %d\n\n",pOgrenci[k]->ogrenciAd,pOgrenci[k]->ogrenciSoyad,pOgrenci[k]->ogrenciNo);
	fclose(fp);
}


void ogrenciDuzenleme(struct ogrenci ogrenciBilgisiYedek[]){
	
	FILE *fp=fopen("Ogrenci.txt","r");
	int i=0,a=0,g=0;
	int ogrenciNumarasi;
	if(fp==NULL){
		printf("Dosya Acilmadi");
}
	printf("Duzenlenecek ogrencinin numarasi: ");
	scanf("%d",&ogrenciNumarasi);
	
	while(!feof(fp)){
		fscanf(fp,"%s %s %d",&ogrenciBilgisiYedek[i].ogrenciAd,&ogrenciBilgisiYedek[i].ogrenciSoyad,&ogrenciBilgisiYedek[i].ogrenciNo);
		if(ogrenciBilgisiYedek[i].ogrenciNo==ogrenciNumarasi){
			printf("Ogrencinin Adini Giriniz: ");
			scanf("%s",&ogrenciBilgisiYedek[i].ogrenciAd);
			printf("Ogrencinin Soydini Giriniz: ");
			scanf("%s",&ogrenciBilgisiYedek[i].ogrenciSoyad);
			printf("Ogrencinin Numarasini Giriniz: ");
			scanf("%d",&ogrenciBilgisiYedek[i].ogrenciNo);	
			g++;
		}
		if(ogrenciBilgisiYedek[i].ogrenciNo==0){
			goto ogrenciDuzenleYazdir;
		}
		i++;	
	}
ogrenciDuzenleYazdir:
	if(g==0){
		printf("\nOgrenci Bulunamadi!\n");
		return;
	}
	fclose(fp);
	fp = fopen("Ogrenci.txt","w");
	for(a=0;a<=(i-1);a++){
	fprintf(fp,"%s %s %d\n\n",ogrenciBilgisiYedek[a].ogrenciAd,ogrenciBilgisiYedek[a].ogrenciSoyad,ogrenciBilgisiYedek[a].ogrenciNo);
}
	fclose(fp);	
}

void ogrenciSilme(struct ogrenci ogrenciBilgisiYedek[]){
	FILE *fp=fopen("Ogrenci.txt","r");
	int i=0,a=0,g=0;
	int ogrenciNumarasi;
	if(fp==NULL){
		printf("Dosya Acilmadi");
}
	printf("Silinecek ogrencinin numarasi: ");
	scanf("%d",&ogrenciNumarasi);
	
	while(!feof(fp)){
		fscanf(fp,"%s %s %d",&ogrenciBilgisiYedek[i].ogrenciAd,&ogrenciBilgisiYedek[i].ogrenciSoyad,&ogrenciBilgisiYedek[i].ogrenciNo);
		
		if(ogrenciBilgisiYedek[i].ogrenciNo==0){
			goto ogrenciSilipYazdir;
		}
		i++;	
	}
ogrenciSilipYazdir:
	
	fclose(fp);

	for(a=0;a<=(i-1);a++){
	if(ogrenciBilgisiYedek[a].ogrenciNo==ogrenciNumarasi){
		a++;
		g++;
}
	if(g==0){
		printf("\nOgrenci Bulunamadi!\n");
		return;
	}
	fp = fopen("Ogrenci.txt","w");
	fprintf(fp,"%s %s %d\n\n",ogrenciBilgisiYedek[a].ogrenciAd,ogrenciBilgisiYedek[a].ogrenciSoyad,ogrenciBilgisiYedek[a].ogrenciNo);
}
	fclose(fp);
}

void ogrenciListele(){
	
	FILE *fp=fopen("Ogrenci.txt","r");
	int i=0;
	
	if(fp==NULL){
		printf("Dosya Acilmadi");
}	
	while(!feof(fp)){		
		fputchar(fgetc(fp));	
	}
	fclose(fp);
}

void firmaEkle(struct firma firmaBilgisi[],int *f,struct firma *pFirma[],struct firma firmaBilgisiYedek[]){

	int m=*f;
	int e=0;
	FILE *fp=fopen("Firma.txt","r");
	while(!feof(fp)){
		fscanf(fp,"%s %s %d",&firmaBilgisiYedek[e].firmaAd,&firmaBilgisiYedek[e].faaliyetAlani,&firmaBilgisiYedek[e].vergiNo);	
		if(firmaBilgisiYedek[e].vergiNo==pFirma[m]->vergiNo){
			printf("\nAyni Vergi Numarasina Sahip Bir Firma Var!!\n");
			return ;
		}
		e++;	
	}
	fclose(fp);
	fp=fopen("Firma.txt","a");
	
	if(fp==NULL){
		printf("Dosya Acilmadi");
}

	
	fprintf(fp,"%s %s %d\n\n",pFirma[m]->firmaAd,pFirma[m]->faaliyetAlani,pFirma[m]->vergiNo);

	fclose(fp);
}

void firmaDuzenleme(struct firma firmaBilgisiYedek[]){
	
	FILE *fp=fopen("Firma.txt","r");
	int i=0,a=0,g=0;
	int firmaVergiNo;
	if(fp==NULL){
		printf("Dosya Acilmadi");
}
	printf("Duzenlenecek firmanin vergi numarasi: ");
	scanf("%d",&firmaVergiNo);
	
	while(!feof(fp)){
		firmaBilgisiYedek[i].vergiNo=0;
		fscanf(fp,"%s %s %d",&firmaBilgisiYedek[i].firmaAd,&firmaBilgisiYedek[i].faaliyetAlani,&firmaBilgisiYedek[i].vergiNo);
		if(firmaBilgisiYedek[i].vergiNo==firmaVergiNo){
			printf("Firmanin Adini Giriniz: ");
			scanf("%s",&firmaBilgisiYedek[i].firmaAd);
			printf("Firmanin Faaliyet Alanini Giriniz: ");
			scanf("%s",&firmaBilgisiYedek[i].faaliyetAlani);
			printf("Firmanin Vergi Numarasini Giriniz: ");
			scanf("%d",&firmaBilgisiYedek[i].vergiNo);	
			g++;
		}
		if(firmaBilgisiYedek[i].vergiNo==0){
			goto firmaDuzenleYazdir;
		}
		i++;	
	}
firmaDuzenleYazdir:
	if(g==0){
		printf("\nFirma Bulunamadi!\n");
		return;
	}
	fclose(fp);
	fp = fopen("Firma.txt","w");
	for(a=0;a<=(i-1);a++){
	fprintf(fp,"%s %s %d\n\n",firmaBilgisiYedek[a].firmaAd,firmaBilgisiYedek[a].faaliyetAlani,firmaBilgisiYedek[a].vergiNo);
}
	fclose(fp);	
}

void firmaSilme(struct firma firmaBilgisiYedek[]){
	FILE *fp=fopen("Firma.txt","r");
	int i=0,a=0,g=0;
	int firmaVergiNo;
	if(fp==NULL){
		printf("Dosya Acilmadi");
}
	printf("Silinecek firmanin vergi numarasi: ");
	scanf("%d",&firmaVergiNo);
	
	while(!feof(fp)){
		firmaBilgisiYedek[i].vergiNo=0;
		fscanf(fp,"%s %s %d",&firmaBilgisiYedek[i].firmaAd,&firmaBilgisiYedek[i].faaliyetAlani,&firmaBilgisiYedek[i].vergiNo);
		if(firmaBilgisiYedek[i].vergiNo==0){
			goto firmaSilipYazdir;
		}
		i++;	
	}
firmaSilipYazdir:
	fclose(fp);
	
	for(a=0;a<=(i-1);a++){
	if(firmaBilgisiYedek[a].vergiNo==firmaVergiNo){
		a++;
		g++;
}
	if(g==0){
		printf("\nFirma Bulunamadi!\n");
		return;
	}
	fp = fopen("Firma.txt","w");
	fprintf(fp,"%s %s %d\n\n",firmaBilgisiYedek[a].firmaAd,firmaBilgisiYedek[a].faaliyetAlani,firmaBilgisiYedek[a].vergiNo);
}
	fclose(fp);
}

void firmaListele(){
	
	FILE *fp=fopen("Firma.txt","r");
	
	if(fp==NULL){
		printf("Dosya Acilmadi");
}
	while(!feof(fp)){		
		fputchar(fgetc(fp));	
	}	
	fclose(fp);
}

void stajEkle(struct staj stajBilgisi[],int *s,struct staj *pStaj[]){
	
	int j=*s;
	
	FILE *fp=fopen("Staj.txt","a");
	
	if(fp==NULL){
		printf("Dosya Acilmadi");
}
	
	fclose(fp);
}

int main()
{
    int menu_secim;
    int i=0;
    int f=0;
    int s=0;
	struct ogrenci ogrenciBilgisi[10];
	struct firma firmaBilgisi[10];
	struct staj stajBilgisi[10];
	
	struct ogrenci ogrenciBilgisiYedek[10];
	struct firma firmaBilgisiYedek[10];
	
	struct ogrenci *pOgrenci[10];
	struct firma *pFirma[10];
	struct staj *pStaj[10];
	
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
					
					ogrenciEkle(ogrenciBilgisi,&i,pOgrenci,ogrenciBilgisiYedek);
					
					i++;
					
                    goto altbolum1;
                    break;

                case 2:
					printf("\n\t-----------Ogrenci Duzenleme-----------\n\n");
					
					ogrenciDuzenleme(ogrenciBilgisiYedek);
					
                    goto altbolum1;
                    break;

                case 3:
                	printf("\n\t-----------Ogrenci Silme-----------\n\n");
                	
                	ogrenciSilme(ogrenciBilgisiYedek);


                    goto altbolum1;
                    break;

                case 4:
                	printf("\n\t-----------Ogrenci Listele-----------\n\n");

					ogrenciListele();
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
                	
                	firmaEkle(firmaBilgisi,&f,pFirma,firmaBilgisiYedek);
                	
                	f++;
                    goto altbolum2;
                    break;

                case 2:
                	printf("\n\t-----------Firma Duzenleme-----------\n\n");
                	
                	firmaDuzenleme(firmaBilgisiYedek);
                	
                    goto altbolum2;
                    break;

                case 3:
                	printf("\n\t-----------Firma Silme-----------\n\n");
                	
                	firmaSilme(firmaBilgisiYedek);
                	
                    goto altbolum2;
                    break;

                case 4:
                	printf("\n\t-----------Firma Listele-----------\n\n");
                	
					firmaListele();

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
					printf("\n\t-----------Staj Ekleme-----------\n\n");
					
					printf("Staj yapilan firmanin vergi numarasi giriniz: ");
					scanf("%d",&stajBilgisi[s].stajFirmaVergiNo);
					printf("Staja baslama tarihini giriniz: ");
					scanf("%d %d %d",&stajBilgisi[s].stajBaslamaTarihi.gun,&stajBilgisi[s].stajBaslamaTarihi.ay,&stajBilgisi[s].stajBaslamaTarihi.yil);
					printf("Staj bitis tarihi giriniz: ");
					scanf("%d %d %d",&stajBilgisi[s].stajBitirmeTarihi.gun,&stajBilgisi[s].stajBitirmeTarihi.ay,&stajBilgisi[s].stajBitirmeTarihi.yil);
					
					pStaj[s]=&stajBilgisi[s];
					
					stajEkle(stajBilgisi,&s,pStaj);
					
					s++;

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
