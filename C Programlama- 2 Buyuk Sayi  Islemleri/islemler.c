#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "islemler.h"




void ekranaYazdir(int readedBytes,int readedBytes3,uint8_t *array,uint8_t *array1,int sayac2){

    int i;
    printf("1. Sayi Ekrana Yazdiriliyor.. : ");
    for (i=0; i<readedBytes; ++i)
    {
        printf("%01x ", *(array+i));
    }
    printf("\n");

    printf("2. Sayi Ekrana Yazdiriliyor.. : ");
    for (i=0; i<readedBytes3; ++i)
    {
        printf("%01x ", *(array1+i));
    }
    printf(" \n");
    printf("Sayilar Ekrana Yazdirildi ! \n");
    printf(" \n");



    char sec;
    printf("[+/-]-> Islem seciniz: ");
    sec=getchar();
    scanf("%c", &sec);
    if (sec == '+')
    {
        printf("\n");
        toplama(readedBytes,readedBytes3,array,array1,sayac2);
    }
    if(sec=='-'){

        printf("\n");
        cikarma(readedBytes,readedBytes3,array,array1,sayac2);
    }
    else 
    {
        printf("Hatali Secim Program Sonlaniyor.");
        exit(0);
    }

}
void toplama(int readedBytes,int readedBytes3,uint8_t *array,uint8_t *array1,int sayac2){

// -----------------------------------TOPLAMA ISLEMI BASLANGICI------------------------------------------------------
    
    int i;

    uint8_t *array2=NULL;
    array2 = malloc(sayac2);

    printf("sorun yok");

    for (i = readedBytes3-1; i>-1; i--)
    {
        *(array2+i) = *(array+i) + *(array1+i);
        //array2[i]=array[i]+array1[i];
        if(*(array2+i)==0xb){
            *(array2+i)=0x1;
            *(array1+(i-1))=*(array1+(i-1))+1;
            //array2[i]=0x1;
            //array1[i-1]=(array1[i-1])+1;
        }
        if(*(array2+i)==0xa){
            *(array2+i)=0x0;
            *(array1+(i-1))=*(array1+(i-1))+1;
            //array2[i]=0x0;
            //array1[i-1]=(array1[i-1])+1;
        }
        if(*(array2+i)==0xc){
            *(array2+i)=0x2;
            *(array1+(i-1))=*(array1+(i-1))+1;   
        }

        if(*(array2+i)==0xd){
            *(array2+i)=0x3;
            *(array1+(i-1))=*(array1+(i-1))+1;   
        }
        if(*(array2+i)==0xe){
            *(array2+i)=0x4;
            *(array1+(i-1))=*(array1+(i-1))+1;   
        }
        if(*(array2+i)==0xf){
            *(array2+i)=0x5;
            *(array1+(i-1))=*(array1+(i-1))+1;   
        }
        if(*(array2+i)==0x10){
            *(array2+i)=0x6;
            *(array1+(i-1))=*(array1+(i-1))+1;   
        }
        if(*(array2+i)==0x11){
            *(array2+i)=0x7;
            *(array1+(i-1))=*(array1+(i-1))+1;   
        }
        if(*(array2+i)==0x12){
            *(array2+i)=0x8;
            *(array1+(i-1))=*(array1+(i-1))+1;   
        }
        if(*(array2+i)==0x13){
            *(array2+i)=0x9;
            *(array1+(i-1))=*(array1+(i-1))+1;   
        }
        
    }
    printf("\n");
    printf("Toplama Islemi Basariyla Tamamlandi !");
    printf("\n");

    int sec;
    int durum = 1;
    while (durum == 1)
    {
        printf(" [1]-> Dosyadan sayilari oku:   [2]-> Okunan sayilari ekrana yaz:  [+/-]-> Islem seciniz:  [4]-> Sonucu ekrana yazdir:  [5]-> Cikis :  \n");
        scanf("%d", &sec);

        if (sec == 4)
        {
            printf("\n");
            printf("Sonuc : ");
            for (i = 0; i < readedBytes3; i++)
            {
                printf("%01x", *(array2 + i));
                //printf("%01x ", array2[i]);
            }

            FILE *yaz = fopen("sonuclar.txt", "w+");
            if (yaz == NULL)
                printf("dosya acilmadi\n");
            else
            {
                for (i = 0; i < readedBytes3; i++)
                {
                    fprintf(yaz, "%01x", *(array2 + i));
                }
            }
            printf("\n");
            printf("sonuclar.txt'ye yazdirma işlemi tamamlandi !\n");
            fclose(yaz);
        }
        if (sec == 5)
        {
            printf("Programdan Cikildi ! \n");
            durum = 0;
            exit(0);
            break;
        }
        if (sec != 4 || sec != 5)
        {
            //printf("Gecerli bir secim yapiniz.. \n ");
        }
    }

    // -----------------------------------TOPLAMA ISLEMI SON-----------------------------------

}


void cikarma(int readedBytes,int readedBytes3,uint8_t *array,uint8_t *array1,int sayac2){

    int i;

    //-----------------------------------------------------------

    uint8_t *array2=NULL;
    array2 = malloc(sayac2);


    for (i = readedBytes3-1; i>-1; i--)
    {

        if(*(array+i)<*(array1+i)){
            *(array+i)+=0xA;
            *(array+(i-1))-=0x1;
            *(array2+i)=*(array+i) - *(array1+i);
            //array[i]+=0xA;
            //array[i-1]-=0x1;
            //array2[i]=array[i]-array1[i];
        }
        else{
        *(array2+i)=*(array+i) - *(array1+i);
        //array2[i]=array[i]-array1[i];
        }
    }


//-----------

    int sec;
    int durum = 1;
    while (durum == 1)
    {
        printf(" [1]-> Dosyadan sayilari oku:   [2]-> Okunan sayilari ekrana yaz:  [+/-]-> Islem seciniz:  [4]-> Sonucu ekrana yazdir:  [5]-> Cikis :  \n");
        scanf("%d", &sec);

        if (sec == 4)
        {
            printf("\n");
            printf("Sonuc : ");
            for (i = 0; i < readedBytes3; i++)
            {
                printf("%01x", *(array2 + i));
                //printf("%01x ", array2[i]);
            }

            FILE *yaz = fopen("sonuclar.txt", "w+");
            if (yaz == NULL)
                printf("dosya acilmadi\n");
            else
            {
                for (i = 0; i < readedBytes3; i++)
                {
                    fprintf(yaz, "%01x", *(array2 + i));
                }
            }
            printf("\n");
            printf("sonuclar.txt'ye yazdirma işlemi tamamlandi !\n");
            fclose(yaz);
        }
        if (sec == 5)
        {
            printf("Programdan Cikildi ! \n");
            durum = 0;
            exit(0);
            break;
        }
        if (sec != 4 || sec != 5)
        {
            printf("Gecerli bir secim yapiniz.. \n ");
        }
    }

    //--------

    printf("\n");
    printf("Cikarma Islemi Basariyla Tamamlandi !");
    printf("\n");

    // -----------------------------------CIKARMA ISLEMI SON-----------------------------------

}
void sayilariOku(){

    FILE *fp;
    int number = 0;
    uint8_t *array = NULL;
    int readedBytes = 0;

    int i = 0;

    /// allocate max possible array size = fileSize/2

    //-------basamak sayısı bulma.
    int sayac2 = 0;
    fp = fopen("sayi11.txt", "r");

    /// read data into array
    while (!feof(fp))
    {
        if (fscanf(fp, "%1hhx", &number) == 1)
        {
            sayac2++;
        }
    }
    fclose(fp);
    printf("1. Sayi Basamak Sayisi= %d \n", sayac2);

    //-----------------------------

    fp = fopen("sayi11.txt", "r");

    array = malloc(sayac2);

    /// read data into array
    while (!feof(fp))
    {
        if (fscanf(fp, "%1hhx", &number) == 1)
        {
            *(array+(readedBytes++))=number;
            //array[readedBytes++] = number;
        }
    }
    fclose(fp);

    //-----------

    printf("\n");
    //---------------------------------------------------------------------------

    FILE *fp1;
    int number1 = 0;
    uint8_t *array1 = NULL;
    int readedBytes1 = 0;

    fp1 = fopen("sayi22.txt", "r");

    int sayac = 0;
    /// read data into array
    while (!feof(fp1))
    {
        if (fscanf(fp1, "%1hhx", &number1) == 1)
        {
            sayac++;
        }
    }

    fclose(fp1);
    array1 = malloc(sayac2);
    printf("2. Sayi Basamak Sayisi= %d \n", sayac);
    int kaydirma = readedBytes - sayac;
    readedBytes1 = kaydirma;
    for (i = 0; i < kaydirma; i++)
    {
        //printf("girdi.");
        *(array1+i)=0x0;
        //array1[i] = 0x0;
    }

    //----------------------------------------------------- asil yer.

    FILE *fp3;
    int number3 = 0;
    int readedBytes3 = 0;

    fp3 = fopen("sayi22.txt", "r");

    readedBytes3 = kaydirma;
    /// read data into array
    while (!feof(fp3))
    {
        if (fscanf(fp3, "%1hhx", &number3) == 1)
        {
            *(array1+(readedBytes3++))=number3;
            //array1[readedBytes3++] = number3;
        }
    }

    fclose(fp3);
    printf("Sayilar Okundu ! \n");
    printf("\n");

    int sec;
    int durum=1;
    while(durum ==1){
    printf(" [1]-> Dosyadan sayilari oku:   [2]-> Okunan sayilari ekrana yaz:  [+/-]-> Islem seciniz:  [4]-> Sonucu ekrana yazdir:  [5]-> Cikis :  \n");
    scanf("%d", &sec);

    if (sec == 2)
    {
        printf("\n");
        ekranaYazdir(readedBytes,readedBytes3,array,array1,sayac2);
        durum=0;
        break;
    }
    if(sec== 5) 
    {
        printf("Programdan Cikildi ! \n");
        durum =0;
        exit(0);
        break;
    }
    if (sec !=2 || sec !=5){
        printf("Gecerli bir secim yapiniz.. \n ");
    }
    }
}

void menu(){

    int sec;
    int durum=1;
    while(durum==1){
    printf(" [1]-> Dosyadan sayilari oku:   [2]-> Okunan sayilari ekrana yaz:  [+/-]-> Islem seciniz:  [4]-> Sonucu ekrana yazdir:  [5]-> Cikis : \n ");
    scanf("%d", &sec);
    if (sec == 1)
    {
        printf("\n");
        sayilariOku();
    }
    if(sec==5) 
    {
        printf("Cikis Yapildi.\n");
        exit(0);
        break;
    }
    if(sec!=1 ||sec!=2){
        printf("Hatali Secim !");
    }
    }
}

