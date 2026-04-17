/* ----------------------------------------------------------------------------------- */
/**
 * \file        yemek.c
 *
 * \brief       This file contains the functions of yemek module.
 *
 * \developer  Gokce Kılınc
 *
 * \version
 *              v1.0 Initial Version
 *
 */
/* ----------------------------------------------------------------------------------- */
/* --------------    Include Functions    --------------------------------------------------------------------- */
#include "yemek.h"

/* --------------    Global Variables    --------------------------------------------------------------------- */

/* --------------    Static Variables    --------------------------------------------------------------------- */
static Yemek yemekler[MAX_YEMEK];
static int yemek_sayisi = 0;

/* --------------    Static Function Prototypes    --------------------------------------------------------------------- */


/* --------------    Function Declarations    --------------------------------------------------------------------- */

// Yemek listesini dosyadan yükle
void yemek_listesi_yukle() {
    FILE *dosya = fopen("yemeklistesi.txt", "r");
    if (dosya == NULL) {
        printf("yemeklistesi.txt dosyası bulunamadı. Örnek dosya oluşturuluyor...\n");

        // Örnek yemek listesi oluştur
        FILE *yeni_dosya = fopen("yemeklistesi.txt", "w");
        if (yeni_dosya != NULL) {
            fprintf(yeni_dosya, "1|Çorba|15.50|Başlangıç\n");
            fprintf(yeni_dosya, "2|Kebap|45.00|Ana Yemek\n");
            fprintf(yeni_dosya, "3|Pilav|12.00|Yan Ürün\n");
            fprintf(yeni_dosya, "4|Salata|18.00|Salata\n");
            fprintf(yeni_dosya, "5|Baklava|25.00|Tatlı\n");
            fprintf(yeni_dosya, "6|Ayran|8.00|İçecek\n");
            fprintf(yeni_dosya, "7|Künefe|30.00|Tatlı\n");
            fprintf(yeni_dosya, "8|Pide|35.00|Ana Yemek\n");
            fclose(yeni_dosya);
        }

        dosya = fopen("yemeklistesi.txt", "r");
    }

    if (dosya != NULL) {
        yemek_sayisi = 0;
        while (fscanf(dosya, "%d|%[^|]|%f|%[^\n]\n",
                      &yemekler[yemek_sayisi].id,
                      yemekler[yemek_sayisi].ad,
                      &yemekler[yemek_sayisi].fiyat,
                      yemekler[yemek_sayisi].kategori) == 4) {
            yemek_sayisi++;
            if (yemek_sayisi >= MAX_YEMEK) break;
        }
        fclose(dosya);
    }
}


// Yemek listesini göster
void yemek_listesi_goster() {
    printf("\n=== YEMEK LİSTESİ ===\n");
    printf("%-5s %-20s %-10s %-15s\n", "ID", "Yemek Adı", "Fiyat (TL)", "Kategori");
    printf("------------------------------------------------\n");

    for (int i = 0; i < yemek_sayisi; i++) {
        printf("%-5d %-20s %-10.2f %-15s\n",
               yemekler[i].id,
               yemekler[i].ad,
               yemekler[i].fiyat,
               yemekler[i].kategori);
    }
    printf("\n");
}

/**
 **  ---------------------------------------------------------------------------
 ** Name : yemek_bul
 **
 **\brief
 **          This function finds the yemek in yemekler array.\n
 ** Component  :Yemek \n
 **
 ** \param [in] int id - Yemek number
 ** \param [out] Yemek* bulunan_yemek - pointer of finding yemek
 **
 ** \returns foodFound    0 : Not Found
 *                        1 : Food is find
 **
 **  ---------------------------------------------------------------------------
 * */
foodFound yemek_bul(int id, Yemek* bulunan_yemek)
{
    foodFound bulundu = FOOD_NOT_FOUND;
    // Yemeği bul
    for (int i = 0; i < yemek_sayisi; i++) {
        if (yemekler[i].id == id) {
            *bulunan_yemek = yemekler[i];
            bulundu = FOOD_FIND;
            break;
        }
    }
    return bulundu;
}
