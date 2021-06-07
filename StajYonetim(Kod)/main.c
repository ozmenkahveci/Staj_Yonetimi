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
	int stajOgrenciNo;
	int stajFirmaVergiNo;
	tarih stajBaslamaTarihi;
	tarih stajBitirmeTarihi;
	char stajTuru[20];
	int hafta;
};


void ogrenciEkle(struct ogrenci ogrenciBilgisi[],int *i,struct ogrenci *pOgrenci[],struct ogrenci ogrenciBilgisiYedek[]){
	
	int k=*i;
	int e=0;
	FILE *fp=fopen("Ogrenci.txt","a+");
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
	int i=0,a=0,g=0,q=0;
	int ogrenciNumarasi;
	if(fp==NULL){
		printf("Dosya Acilmadi");
}
	printf("Silinecek ogrencinin numarasi: ");
	scanf("%d",&ogrenciNumarasi);
	
	while(!feof(fp)){	
		fscanf(fp,"%s %s %d",&ogrenciBilgisiYedek[i].ogrenciAd,&ogrenciBilgisiYedek[i].ogrenciSoyad,&ogrenciBilgisiYedek[i].ogrenciNo);
		if(ogrenciBilgisiYedek[i].ogrenciNo==ogrenciNumarasi){	
			q=i;
			g++;
		}
			i++;
	}
ogrenciSilipYazdir:
	fclose(fp);
fp = fopen("Ogrenci.txt","w");
	for(a=0;a<(i-1);a++){
	if(ogrenciBilgisiYedek[a].ogrenciNo==ogrenciBilgisiYedek[q].ogrenciNo){	
		strcpy(ogrenciBilgisiYedek[a].ogrenciAd,ogrenciBilgisiYedek[a+1].ogrenciAd);
		strcpy(ogrenciBilgisiYedek[a].ogrenciSoyad,ogrenciBilgisiYedek[a+1].ogrenciSoyad);
		ogrenciBilgisiYedek[a].ogrenciNo = ogrenciBilgisiYedek[a+1].ogrenciNo;	
}
	}
	if(g==0){
		printf("\nOgrenci Bulunamadi!\n");
		return;
	}
	for(a=0;a<(i-2);a++){
		if(ogrenciBilgisiYedek[a].ogrenciNo==ogrenciNumarasi){
		a++;
}
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
	FILE *fp=fopen("Firma.txt","a+");
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
	
	FILE *fp=fopen("Firma.txt","a+");
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
	int i=0,a=0,g=0,q=0;
	int firmaVergiNo;
	if(fp==NULL){
		printf("Dosya Acilmadi");
}
	printf("Silinecek firmanin vergi numarasi: ");
	scanf("%d",&firmaVergiNo);
	
	while(!feof(fp)){
		firmaBilgisiYedek[i].vergiNo=0;
		fscanf(fp,"%s %s %d",&firmaBilgisiYedek[i].firmaAd,&firmaBilgisiYedek[i].faaliyetAlani,&firmaBilgisiYedek[i].vergiNo);
		if(firmaBilgisiYedek[i].vergiNo==firmaVergiNo){
			q=i;
			g++;
		}
		i++;	
	}

	fclose(fp);
	fp = fopen("Firma.txt","w");
	for(a=0;a<(i-1);a++){
	if(firmaBilgisiYedek[a].vergiNo==firmaBilgisiYedek[q].vergiNo){
		strcpy(firmaBilgisiYedek[a].firmaAd,firmaBilgisiYedek[a+1].firmaAd);
		strcpy(firmaBilgisiYedek[a].faaliyetAlani,firmaBilgisiYedek[a+1].faaliyetAlani);
		firmaBilgisiYedek[a].vergiNo = firmaBilgisiYedek[a+1].vergiNo;
		
}}
	if(g==0){
		printf("\nFirma Bulunamadi!\n");
		return;
	}
	for(a=0;a<(i-2);a++){
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

void ogrenciKontrol(struct ogrenci ogrenciBilgisiYedek[],struct staj *pStaj[],int *s){
	FILE *fp = fopen("Ogrenci.txt","r");
	int i;
	int j=*s;
	while(!feof(fp)){
		fscanf(fp,"%s %s %d",&ogrenciBilgisiYedek[i].ogrenciAd,&ogrenciBilgisiYedek[i].ogrenciSoyad,&ogrenciBilgisiYedek[i].ogrenciNo);
		
		if(ogrenciBilgisiYedek[i].ogrenciNo==pStaj[j]->stajOgrenciNo){
			
			fclose(fp);
			return;
		}
		i++;	
	}
	pStaj[j]->stajOgrenciNo=0;
	printf("\nKayitli ogrenci bulunamadi!\n");
	
	fclose(fp);
}

void firmaKontrol(struct firma firmaBilgisiYedek[],struct staj *pStaj[],int *s){
	FILE *fp = fopen("Firma.txt","a+");
	int i;
	int j=*s;
	while(!feof(fp)){
		fscanf(fp,"%s %s %d",&firmaBilgisiYedek[i].firmaAd,&firmaBilgisiYedek[i].faaliyetAlani,&firmaBilgisiYedek[i].vergiNo);
		
		if(firmaBilgisiYedek[i].vergiNo==pStaj[j]->stajFirmaVergiNo){
			
			fclose(fp);
			return;
		}
		i++;	
	}
	pStaj[j]->stajFirmaVergiNo=0;
	printf("\nKayitli firma bulunamadi!\n");
	
	fclose(fp);
	
}

int haftaHesapla(struct staj *pStaj[],int *s){
	
	int j=*s;
	int hafta;
	
	if(pStaj[j]->stajBitirmeTarihi.gun < pStaj[j]->stajBaslamaTarihi.gun){
		if(pStaj[j]->stajBitirmeTarihi.ay == 4 || pStaj[j]->stajBitirmeTarihi.ay == 6 || pStaj[j]->stajBitirmeTarihi.ay == 9 || pStaj[j]->stajBitirmeTarihi.ay == 11){
		pStaj[j]->stajBitirmeTarihi.gun = pStaj[j]->stajBitirmeTarihi.gun+30;
		pStaj[j]->stajBitirmeTarihi.ay = pStaj[j]->stajBitirmeTarihi.ay-1;
	}
		else if(pStaj[j]->stajBitirmeTarihi.ay == 2 && pStaj[j]->stajBitirmeTarihi.yil%4==0){
		pStaj[j]->stajBitirmeTarihi.gun = pStaj[j]->stajBitirmeTarihi.gun+29;
		pStaj[j]->stajBitirmeTarihi.ay = pStaj[j]->stajBitirmeTarihi.ay-1;
		}
		else if(pStaj[j]->stajBitirmeTarihi.ay == 2){
		pStaj[j]->stajBitirmeTarihi.gun = pStaj[j]->stajBitirmeTarihi.gun+28;
		pStaj[j]->stajBitirmeTarihi.ay = pStaj[j]->stajBitirmeTarihi.ay-1;
		}
		else{
		pStaj[j]->stajBitirmeTarihi.gun = pStaj[j]->stajBitirmeTarihi.gun+31;
		pStaj[j]->stajBitirmeTarihi.ay = pStaj[j]->stajBitirmeTarihi.ay-1;
		}
	}
	
	pStaj[j]->stajBitirmeTarihi.gun = pStaj[j]->stajBitirmeTarihi.gun - pStaj[j]->stajBaslamaTarihi.gun;
	
	if(pStaj[j]->stajBitirmeTarihi.ay < pStaj[j]->stajBaslamaTarihi.ay){
		pStaj[j]->stajBitirmeTarihi.ay = pStaj[j]->stajBitirmeTarihi.ay+12;
		pStaj[j]->stajBitirmeTarihi.yil = pStaj[j]->stajBitirmeTarihi.yil-1;
	}
	
	pStaj[j]->stajBitirmeTarihi.ay = pStaj[j]->stajBitirmeTarihi.ay - pStaj[j]->stajBaslamaTarihi.ay;
	
	pStaj[j]->stajBitirmeTarihi.yil = pStaj[j]->stajBitirmeTarihi.yil - pStaj[j]->stajBaslamaTarihi.yil;
	
	if(pStaj[j]->stajBitirmeTarihi.yil > 0){
		pStaj[j]->stajBitirmeTarihi.yil = pStaj[j]->stajBitirmeTarihi.yil*12;
		pStaj[j]->stajBitirmeTarihi.ay = pStaj[j]->stajBitirmeTarihi.ay + pStaj[j]->stajBitirmeTarihi.yil;
	}
	if(pStaj[j]->stajBitirmeTarihi.ay > 0){
		pStaj[j]->stajBitirmeTarihi.ay = pStaj[j]->stajBitirmeTarihi.ay*30;
		pStaj[j]->stajBitirmeTarihi.gun = pStaj[j]->stajBitirmeTarihi.gun + pStaj[j]->stajBitirmeTarihi.ay;
	}
	while(pStaj[j]->stajBitirmeTarihi.gun >= 7){
		pStaj[j]->stajBitirmeTarihi.gun = pStaj[j]->stajBitirmeTarihi.gun - 7;
		hafta++;
	}
	printf("Tamamlanan Staj Haftasi: %d",hafta);
	
	return hafta;
}

void stajEkle(struct staj stajBilgisi[],int *s,struct staj *pStaj[],int hafta){
	
	int j=*s;
	FILE *fp=fopen("Staj.txt","a");
	if(fp==NULL){
		printf("Dosya Acilmadi");
}
	fprintf(fp,"%d %d %s %d\n\n",pStaj[j]->stajOgrenciNo,pStaj[j]->stajFirmaVergiNo,pStaj[j]->stajTuru,pStaj[j]->hafta);
	fclose(fp);
}

void stajKontrol(struct staj stajBilgisiYedek[],struct staj stajBilgisiYedek2[],struct staj *pTamamlanmayanStaj[],int *t){
	
	FILE *fp = fopen("Staj.txt","r");
	int i=0,e=0,a=0;
	int pt=0;
	int hafta=0;
	while(!feof(fp)){
		fscanf(fp,"%d %d %s %d",&stajBilgisiYedek[i].stajOgrenciNo,&stajBilgisiYedek[i].stajFirmaVergiNo,&stajBilgisiYedek[i].stajTuru,&stajBilgisiYedek[i].hafta);	
		if(strcmp(stajBilgisiYedek[i].stajTuru,"Donanim") == 0 && stajBilgisiYedek[i].hafta>= 2){	
			stajBilgisiYedek2[e].stajOgrenciNo = stajBilgisiYedek[i].stajOgrenciNo;
			stajBilgisiYedek2[e].hafta = stajBilgisiYedek[i].hafta;
			strcpy(stajBilgisiYedek2[e].stajTuru,stajBilgisiYedek[i].stajTuru);
			e++;	
		}
		else if(strcmp(stajBilgisiYedek[i].stajTuru,"Donanim") == 0){
			pTamamlanmayanStaj[pt] = &stajBilgisiYedek[i];
			pt++;
		}
		i++;	
	}
	fclose(fp);
	e=0;
	for(a=0;a<(i-1);a++){
		if(stajBilgisiYedek[a].stajOgrenciNo==stajBilgisiYedek2[e].stajOgrenciNo && strcmp(stajBilgisiYedek[a].stajTuru,"Yazilim") == 0 && stajBilgisiYedek[a].hafta >= 4){
			hafta = stajBilgisiYedek[a].hafta + stajBilgisiYedek2[e].hafta;
					if(hafta >= 12){
						printf("%d %d %s-%d %s-%d %d\n",stajBilgisiYedek[a].stajOgrenciNo,stajBilgisiYedek[a].stajFirmaVergiNo,stajBilgisiYedek[a].stajTuru,stajBilgisiYedek[a].hafta,stajBilgisiYedek2[e].stajTuru,stajBilgisiYedek2[e].hafta,hafta);
						
					}
					else{
						pTamamlanmayanStaj[pt] = &stajBilgisiYedek[a];
						pt++;
					}
					e++;
		}
		else if(strcmp(stajBilgisiYedek[a].stajTuru,"Yazilim") == 0){
			pTamamlanmayanStaj[pt] = &stajBilgisiYedek[a];
			pt++;
		}
	}
	*t=pt;
}

void tamamlanmayanStaj(struct staj *pTamamlanmayanStaj[],int *t){
	int pt=*t;
	int i=0;
	for(i=0; i<pt; i++){
		printf("%d %d %s %d",pTamamlanmayanStaj[i]->stajOgrenciNo,pTamamlanmayanStaj[i]->stajFirmaVergiNo,pTamamlanmayanStaj[i]->stajTuru,pTamamlanmayanStaj[i]->hafta);
	}
}


int main()
{
    int menu_secim;
    int i=0;
    int f=0;
    int s=0;
    int t=0;
    int hafta;
	struct ogrenci ogrenciBilgisi[10];
	struct firma firmaBilgisi[10];
	struct staj stajBilgisi[10];
	
	struct ogrenci ogrenciBilgisiYedek[10];
	struct firma firmaBilgisiYedek[10];
	struct staj stajBilgisiYedek[10];
	struct staj stajBilgisiYedek2[10];
	
	struct ogrenci *pOgrenci[10];
	struct firma *pFirma[10];
	struct staj *pStaj[10];
	struct staj *pTamamlanmayanStaj[10];
	
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
					
					printf("Staj yapan ogrencinin numarasi: ");
					scanf("%d",&stajBilgisi[s].stajOgrenciNo);
					pStaj[s]=&stajBilgisi[s];
					ogrenciKontrol(ogrenciBilgisiYedek,pStaj,&s);
					if(pStaj[s]->stajOgrenciNo==0){
						goto cikis;
					}
					printf("Staj yapilan firmanin vergi numarasi giriniz: ");
					scanf("%d",&stajBilgisi[s].stajFirmaVergiNo);
					pStaj[s]=&stajBilgisi[s];
					firmaKontrol(firmaBilgisiYedek,pStaj,&s);
					if(pStaj[s]->stajFirmaVergiNo==0){
						goto cikis;
					}
					printf("Staj turunu giriniz(Donanim/Yazilim): ");
					scanf("%s",stajBilgisi[s].stajTuru);
					printf("Staja baslama tarihini giriniz(gun ay yil þeklinde): ");
					scanf("%d %d %d",&stajBilgisi[s].stajBaslamaTarihi.gun,&stajBilgisi[s].stajBaslamaTarihi.ay,&stajBilgisi[s].stajBaslamaTarihi.yil);
					printf("Staj bitis tarihi giriniz(gun ay yil þeklinde): ");
					scanf("%d %d %d",&stajBilgisi[s].stajBitirmeTarihi.gun,&stajBilgisi[s].stajBitirmeTarihi.ay,&stajBilgisi[s].stajBitirmeTarihi.yil);
					
					pStaj[s]=&stajBilgisi[s];
					
					stajBilgisi[s].hafta = haftaHesapla(pStaj,&s);
					
					
					
					stajEkle(stajBilgisi,&s,pStaj,hafta);
					
					s++;
				cikis:
                    goto altbolum3;
                    break;

                case 2:
                	printf("\n\t-----------Tamamlanmayan Stajlar-----------\n\n");

					tamamlanmayanStaj(pTamamlanmayanStaj,&t);
                    goto altbolum3;
                    break;

                case 3:
                	printf("\n\t-----------Tamamlanan Stajlar-----------\n\n");
                	
                	
                	stajKontrol(stajBilgisiYedek,stajBilgisiYedek2,pTamamlanmayanStaj,&t);
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
