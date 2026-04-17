/* ----------------------------------------------------------------------------------- */
/**
 * \file        yemek.h
 *
 * \brief       This file contains the interface of yemek module.
 *
 * \developer  Gokce Kılınc
 *
 * \version
 *              v1.0 Initial Version
 *
 */
/* ----------------------------------------------------------------------------------- */
#ifndef _YEMEK_H_
#define _YEMEK_H_
/* --------------    Include Files   --------------------------------------------------------------------- */
#include <stdio.h>

/* --------------    Defines    --------------------------------------------------------------------- */
#define MAX_STRING_OF_FOOD     200
#define MAX_YEMEK               50

//#define FOOD_NOT_FOUND      0
//#define FOOD_FIND           1
/*
enum{
    FOOD_NOT_FOUND = 0,
    FOOD_FIND,
};
*/

typedef enum{
    FOOD_NOT_FOUND = 0,
    FOOD_FIND,
}foodFound;

/* --------------    Types    --------------------------------------------------------------------- */

/*!
 * @def Yemek
 * @brief Structure of Yemek
 * @details This struct includes Id, name, price and category info of Yemek
 */
typedef struct {
    int id;
    char ad[MAX_STRING_OF_FOOD];
    float fiyat;
    char kategori[MAX_STRING_OF_FOOD];
} Yemek;

/* --------------    Global Constants    --------------------------------------------------------------------- */


/* --------------    Global Variables    --------------------------------------------------------------------- */


/* --------------    Public Functions    --------------------------------------------------------------------- */
extern void yemek_listesi_yukle();  //c de sadece extern kullanılır. Diğer fonksiyonlar görmesini isteriz
extern void yemek_listesi_goster();
extern foodFound yemek_bul(int id, Yemek* bulunan_yemek);

#endif //_YEMEK_H_
/*End of yemek.h */
/* ----------------------------------------------------------------------------------- */
