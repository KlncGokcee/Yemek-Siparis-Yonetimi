/* ----------------------------------------------------------------------------------- */
/**
 * \file        siparis.h
 *
 * \brief       This file contains the interface of siparis module.
 *
 * \developer  Gokce Kılınc
 *
 * \version
 *              v1.0 Initial Version
 *
 */
/* ----------------------------------------------------------------------------------- */
#ifndef _SIPARIS_H_
#define _SIPARIS_H_

/* --------------    Include Files   --------------------------------------------------------------------- */
// #include <stdio.h> , zaten yemek.h içinde include edildiği için yazıldı.Tekrar kullanılmasına gerek yok.
#include <time.h>
#include <string.h>
#include "yemek.h"

/* --------------    Defines    --------------------------------------------------------------------- */
#define MAX_STRING_OF_CUSTOMER  100
#define MAX_STRING_OF_ORDER     200
#define MAX_SIPARIS             100

/*
// Compiler switch
#define PROJECT_VARIANT     1

#if(PROJECT_VARIANT == 1)
    // derlenir
#elif (PROJECT_VARIANT == 2)
    // derlenmez
#else
    //derlenmez
#endif
*/

/* --------------    Types    --------------------------------------------------------------------- */

/*!
 * @def Siparis
 * @brief Structure of Siparis
 * @details This struct includes Id, name of customer, food, price, status and time info of Siparis
 */
typedef struct {
    int siparis_id;
    char musteri_adi[MAX_STRING_OF_ORDER];
    char yemek_adi[MAX_STRING_OF_ORDER];
    int miktar;
    float toplam_fiyat;
    char durum[MAX_STRING_OF_ORDER]; // "Hazırlanıyor", "Hazır", "Teslim Edildi"
    time_t siparis_zamani;
} Siparis;

/* --------------    Global Constants    --------------------------------------------------------------------- */


/* --------------    Global Variables    --------------------------------------------------------------------- */


/* --------------    Public Functions    --------------------------------------------------------------------- */
extern void siparisler_yukle();
extern void siparisler_kaydet();
extern void yeni_siparis_menu();
extern void mevcut_siparis_durumu();
extern void gecmis_siparisler();
extern void siparis_ver();


#endif //_SIPARIS_H_
/*End of siparis.h */
/* ----------------------------------------------------------------------------------- */
