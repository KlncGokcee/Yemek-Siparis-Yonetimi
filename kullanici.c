/* ----------------------------------------------------------------------------------- */
/**
 * \file        kullanici.c
 *
 * \brief       This file contains the main interface of project.
 *
 * \developer  Gokce Kılınc
 *
 * \version
 *              v1.0 Initial Version
 *
 */
/* ----------------------------------------------------------------------------------- */
#include "siparis.h"

// Fonksiyon prototipleri
void ana_menu();

/**
 **  ---------------------------------------------------------------------------
 ** Name : main
 **
 **\brief
 **          This function is main function.\n
 ** Component  :Kullanici \n
 **
 ** \param [in] None
 ** \param [out] None
 **
 ** \returns int
 **
 **  ---------------------------------------------------------------------------
 * */
int main(void) {
    printf("=== ReYeTaP - Restoran Yemek Takip Projesi ===\n");
    printf("Müşteri Uygulaması\n\n");

    // Verileri yükle
    yemek_listesi_yukle();
    siparisler_yukle();

    ana_menu();

    return 0;
}


// Ana menü
void ana_menu() {
    int secim;

    do {
        printf("\n=== ANA MENÜ ===\n");
        printf("1. Yeni Sipariş\n");
        printf("2. Mevcut Sipariş Durumu\n");
        printf("3. Geçmiş Siparişler\n");
        printf("4. Çıkış\n");
        printf("Seçiminizi yapın (1-4): ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                yeni_siparis_menu();
                break;
            case 2:
                mevcut_siparis_durumu();
                break;
            case 3:
                gecmis_siparisler();
                break;
            case 4:
                printf("ReYeTaP uygulamasından çıkılıyor...\n");
                break;
            default:
                printf("Geçersiz seçim! Lütfen 1-4 arasında bir sayı girin.\n");
        }
    } while (secim != 4);
}
