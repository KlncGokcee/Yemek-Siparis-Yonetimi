/* ----------------------------------------------------------------------------------- */
/**
 * \file       siparis.c
 *
 * \brief       This file contains the functions of siparis module.
 *
 * \developer  Gokce Kılınc
 *
 * \version
 *              v1.0 Initial Version
 *
 */
/* ----------------------------------------------------------------------------------- */
/* --------------    Include Functions    --------------------------------------------------------------------- */
#include "siparis.h"
/* --------------    Global Variables    --------------------------------------------------------------------- */

/* --------------    Static Variables    --------------------------------------------------------------------- */
static Siparis siparisler[MAX_SIPARIS];
static int siparis_sayisi = 0;

/* --------------    Static Function Prototypes    --------------------------------------------------------------------- */

// Fonksiyon prototipleri


/* --------------    Function Declarations    --------------------------------------------------------------------- */

// Siparişleri dosyadan yükle
void siparisler_yukle() {
    FILE *dosya = fopen("siparisler.txt", "r");
    if (dosya == NULL) {
        printf("siparisler.txt dosyası bulunamadı. Yeni dosya oluşturulacak.\n");
        return;
    }

    siparis_sayisi = 0;
    while (fscanf(dosya, "%d|%[^|]|%[^|]|%d|%f|%[^|]|%ld\n",
                  &siparisler[siparis_sayisi].siparis_id,
                  siparisler[siparis_sayisi].musteri_adi,
                  siparisler[siparis_sayisi].yemek_adi,
                  &siparisler[siparis_sayisi].miktar,
                  &siparisler[siparis_sayisi].toplam_fiyat,
                  siparisler[siparis_sayisi].durum,
                  &siparisler[siparis_sayisi].siparis_zamani) == 7) {
        siparis_sayisi++;
        if (siparis_sayisi >= MAX_SIPARIS) break;
    }
    fclose(dosya);
}

// Siparişleri dosyaya kaydet
void siparisler_kaydet() {
    FILE *dosya = fopen("siparisler.txt", "w");
    if (dosya == NULL) {
        printf("siparisler.txt dosyası oluşturulamadı!\n");
        return;
    }

    for (int i = 0; i < siparis_sayisi; i++) {
        fprintf(dosya, "%d|%s|%s|%d|%.2f|%s|%ld\n",
                siparisler[i].siparis_id,
                siparisler[i].musteri_adi,
                siparisler[i].yemek_adi,
                siparisler[i].miktar,
                siparisler[i].toplam_fiyat,
                siparisler[i].durum,
                siparisler[i].siparis_zamani);
    }
    fclose(dosya);
}

// Yeni sipariş menüsü
void yeni_siparis_menu() {
    int secim;

    do {
        printf("\n=== YENİ SİPARİŞ MENÜSÜ ===\n");
        printf("1. Yemek Listesini Görüntüle\n");
        printf("2. Sipariş Ver\n");
        printf("3. Ana Menüye Dön\n");
        printf("Seçiminizi yapın (1-3): ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                yemek_listesi_goster();
                break;
            case 2:
                siparis_ver();
                break;
            case 3:
                return;
            default:
                printf("Geçersiz seçim! Lütfen 1-3 arasında bir sayı girin.\n");
        }
    } while (secim != 3);
}


// Sipariş ver
void siparis_ver() {
    char musteri_adi[MAX_STRING_OF_CUSTOMER];
    int yemek_id, miktar;
    foodFound isFoodFind = FOOD_NOT_FOUND;
    Yemek secilen_yemek;

    printf("\n=== YENİ SİPARİŞ ===\n");

    // Müşteri adını al
    printf("Adınızı girin: ");
    scanf(" %[^\n]", musteri_adi);

    // Yemek listesini göster
    yemek_listesi_goster();

    // Yemek seçimi
    printf("Sipariş vermek istediğiniz yemeğin ID'sini girin: ");
    scanf("%d", &yemek_id);

    isFoodFind = yemek_bul(yemek_id, &secilen_yemek);

    if (isFoodFind == FOOD_NOT_FOUND) {
        printf("Geçersiz yemek ID'si!\n");
        return;
    }

    // Miktar al
    printf("Miktar girin: ");
    scanf("%d", &miktar);

    if (miktar <= 0) {
        printf("Geçersiz miktar!\n");
        return;
    }

    // Sipariş oluştur
    Siparis yeni_siparis;
    yeni_siparis.siparis_id = siparis_sayisi + 1;
    strcpy(yeni_siparis.musteri_adi, musteri_adi);
    strcpy(yeni_siparis.yemek_adi, secilen_yemek.ad);
    yeni_siparis.miktar = miktar;
    yeni_siparis.toplam_fiyat = secilen_yemek.fiyat * miktar;
    strcpy(yeni_siparis.durum, "Hazırlanıyor");
    yeni_siparis.siparis_zamani = time(NULL);

    // Siparişi listeye ekle
    siparisler[siparis_sayisi] = yeni_siparis;
    siparis_sayisi++;

    // Dosyaya kaydet
    siparisler_kaydet();

    printf("\n=== SİPARİŞ BAŞARILI ===\n");
    printf("Sipariş ID: %d\n", yeni_siparis.siparis_id);
    printf("Yemek: %s\n", yeni_siparis.yemek_adi);
    printf("Miktar: %d\n", yeni_siparis.miktar);
    printf("Toplam Fiyat: %.2f TL\n", yeni_siparis.toplam_fiyat);
    printf("Durum: %s\n", yeni_siparis.durum);
    printf("Sipariş zamanı: %s", ctime(&yeni_siparis.siparis_zamani));
}

// Mevcut sipariş durumu
void mevcut_siparis_durumu() {
    char musteri_adi[MAX_STRING_OF_CUSTOMER];
    int siparis_bulundu = 0;

    printf("\n=== MEVCUT SİPARİŞ DURUMU ===\n");
    printf("Adınızı girin: ");
    scanf(" %[^\n]", musteri_adi);

    printf("\n%-10s %-20s %-8s %-12s %-15s %-20s\n",
           "Sipariş ID", "Yemek", "Miktar", "Toplam Fiyat", "Durum", "Sipariş Zamanı");
    printf("--------------------------------------------------------------------------------\n");

    for (int i = 0; i < siparis_sayisi; i++) {
        if (strcmp(siparisler[i].musteri_adi, musteri_adi) == 0) {
            printf("%-10d %-20s %-8d %-12.2f %-15s %-20s",
                   siparisler[i].siparis_id,
                   siparisler[i].yemek_adi,
                   siparisler[i].miktar,
                   siparisler[i].toplam_fiyat,
                   siparisler[i].durum,
                   ctime(&siparisler[i].siparis_zamani));
            siparis_bulundu = 1;
        }
    }

    if (!siparis_bulundu) {
        printf("Bu isimle kayıtlı sipariş bulunamadı.\n");
    }
    printf("\n");
}

// Geçmiş siparişler
void gecmis_siparisler() {
    char musteri_adi[MAX_STRING_OF_CUSTOMER];
    int siparis_bulundu = 0;

    printf("\n=== GEÇMİŞ SİPARİŞLER ===\n");
    printf("Adınızı girin: ");
    scanf(" %[^\n]", musteri_adi);

    printf("\n%-10s %-20s %-8s %-12s %-15s %-20s\n",
           "Sipariş ID", "Yemek", "Miktar", "Toplam Fiyat", "Durum", "Sipariş Zamanı");
    printf("--------------------------------------------------------------------------------\n");

    for (int i = 0; i < siparis_sayisi; i++) {
        if (strcmp(siparisler[i].musteri_adi, musteri_adi) == 0) {
            printf("%-10d %-20s %-8d %-12.2f %-15s %-20s",
                   siparisler[i].siparis_id,
                   siparisler[i].yemek_adi,
                   siparisler[i].miktar,
                   siparisler[i].toplam_fiyat,
                   siparisler[i].durum,
                   ctime(&siparisler[i].siparis_zamani));
            siparis_bulundu = 1;
        }
    }

    if (!siparis_bulundu) {
        printf("Bu isimle kayıtlı sipariş bulunamadı.\n");
    }
    printf("\n");
}

