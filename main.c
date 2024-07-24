#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMARAIHTIYACLAR 10
#define MAXISIMUZUNLUK 50

int duzeyler[NUMARAIHTIYACLAR];
char babyName[MAXISIMUZUNLUK];

void printMenu() {
    printf("-- YAPILACAKLAR LISTESI --\n");
    printf("1. Yemek \n");
    printf("2. Uyuma \n");
    printf("3. Sevgi \n");
    printf("4. Sosyallesme \n");
    printf("5. Saglik \n");
    printf("6. Egitim \n");
    printf("7. Hijyen \n");
    printf("8. Tuvalet \n");
    printf("9. Eglence \n");
    printf("10. Susuzluk \n");
    printf("11. Cikis \n");
}

void displayNeedsLevels() {
    printf("Sanal Bebek %s'nin ihtiyac duzeyleri:\n", babyName);
    printf("Yemek: %d\n", duzeyler[0]);
    printf("Uyuma: %d\n", duzeyler[1]);
    printf("Sevgi: %d\n", duzeyler[2]);
    printf("Sosyallesme: %d\n", duzeyler[3]);
    printf("Saglik: %d\n", duzeyler[4]);
    printf("Egitim: %d\n", duzeyler[5]);
    printf("Hijyen: %d\n", duzeyler[6]);
    printf("Tuvalet: %d\n", duzeyler[7]);
    printf("Eglence: %d\n", duzeyler[8]);
    printf("Susuzluk: %d\n", duzeyler[9]);
}

void eat() {
    char yemek[MAXISIMUZUNLUK];
    int miktar;

    printf("Yemek yeme secildi. Kac tane ve ne yemelisiniz? : ");
    printf("\n ornegin: 2 elma, 3 karpuz, 1 pizza, 5 yaprak_sarma \n");
    scanf("%d %s", &miktar, yemek);

    if (strcmp(yemek, "elma") == 0) {
        duzeyler[0] += miktar * 0;
        printf("%d %s yendi. Aclik duzeyi guncellendi.\n", miktar, yemek);
    } else if (strcmp(yemek, "karpuz") == 0) {
        duzeyler[0] += miktar * 1;
        printf("%d %s yendi. Aclik duzeyi guncellendi.\n", miktar, yemek);
    } else if (strcmp(yemek, "pizza") == 0) {
        duzeyler[0] += miktar * 3;
        printf("%d %s yendi. Aclik duzeyi guncellendi.\n", miktar, yemek);
    } else if (strcmp(yemek,"yaprak_sarma")==0){
        duzeyler[0] += miktar * 3;
        printf("%d %s yendi. Aclik duzeyi guncellendi.\n", miktar, yemek);
    } else {
        printf("Gecersiz bir yemek sectiniz.\n");
    }

    // Aþýrý yemek kontrolü
    if (duzeyler[0] > 10) {
        printf("Çok fazla yemek yendigi için sanal bebek patladi! Oyun sona eriyor.\n");
        exit(0);
    }

    if (duzeyler[0] == 0) {
        duzeyler[4]--; // Saðlýk seviyesini azalt
        printf("Aclik seviyesi sifirlandýigi icin saglik seviyesi azaldi.\n");

        // Saðlýk seviyesi 0 ise oyunu sonlandýr
        if (duzeyler[4] <= 0) {
            printf("Saglik seviyesi cok dustu. Oyun sona eriyor.\n");
            exit(0);
        }
    }
    // Hijyen seviyesi 0 ise saðlýk seviyesini azalt
    if (duzeyler[6] == 0) {
        duzeyler[4]--; // Saðlýk seviyesini azalt
        printf("Hijyen seviyesi sifirlandigi icin saglik seviyesi azaldi.\n");

        // Saðlýk seviyesi 0 ise oyunu sonlandýr
        if (duzeyler[4] <= 0) {
            printf("Saglik seviyesi cok dustu. Oyun sona eriyor.\n");
            exit(0);
        }
    }
}



void sleep() {
    int saat;

    printf("Uyuma secildi. Kac saat uyumalisiniz? \n");
    scanf("%d", &saat);
    getchar(); // Enter karakterini temizlemek için
    duzeyler[1] += saat;
    printf("Uyku suresi guncellendi.\n");

    // Diðer ihtiyaçlarý azalt
    if (duzeyler[1] != 0) {
        for (int i = 0; i < NUMARAIHTIYACLAR; i++) {
            if (i != 4) { // 4, saðlýk ihtiyacýnýn indeksi
                duzeyler[i]--;
                if (duzeyler[i] < 0) {
                    duzeyler[i] = 0;
                }
            }
        }
        printf("Uyku seviyesi sifir olmadigi icin diger ihtiyaclar azaldi.\n");
    } else {
        // Uyku seviyesi 0'a düþtü mü kontrol et
        duzeyler[1] = 0; // Uyku seviyesini sýfýrla
        printf("Uyku seviyesi sifirlandi.\n");
    }

    // Açlýk seviyesi 0 ise saðlýk seviyesini azalt
    if (duzeyler[0] == 0) {
        duzeyler[4]--; // Saðlýk seviyesini azalt
        printf("Aclik seviyesi sifirlandigi icin saglik seviyesi azaldi.\n");
        if (duzeyler[4] <= 0) {
            printf("Saglik seviyesi cok dustu. Oyun sona eriyor.\n");
            exit(0);
        }
    }

    // Hijyen seviyesi 0 ise saðlýk seviyesini azalt
    if (duzeyler[6] == 0) {
        duzeyler[4]--; // Saðlýk seviyesini azalt
        printf("Hijyen seviyesi sifirlandigi icin saglik seviyesi azaldi.\n");
        if (duzeyler[4] <= 0) {
            printf("Saglik seviyesi cok dustu. Oyun sona eriyor.\n");
            exit(0);
        }
    }
}

void love() {
    char interaction[MAXISIMUZUNLUK];

    printf("Sevgi secildi. Hangi etkilesimi seciyorsunuz? : ");
    printf("\n ornegin: opme, kucaklama, oynama, dans_etmek \n");
    scanf("%s", interaction);

    if (strcmp(interaction, "opme") == 0) {
        duzeyler[2] += 4;
        printf("%s gerceklestirildi. Sevgi duzeyi guncellendi.\n", interaction);
    } else if (strcmp(interaction, "kucaklama") == 0) {
        duzeyler[2] += 4;
        printf("%s gerceklestirildi. Sevgi duzeyi guncellendi.\n", interaction);
    } else if (strcmp(interaction, "oynama") == 0) {
        duzeyler[2] += 4;
        printf("%s gerceklestirildi. Sevgi duzeyi guncellendi.\n", interaction);
    } else if (strcmp(interaction, "dans_etmek") == 0){
        duzeyler[2] += 4;
        printf("%s gerceklestirildi. Sevgi duzeyi guncellendi.\n", interaction);
    } else {
        printf("Gecersiz bir sevgi etkilesimi sectiniz.\n");
    }

    // Diðer ihtiyaçlarý azalt
    if (duzeyler[2] != 0) {
        for (int i = 0; i < NUMARAIHTIYACLAR; i++) {
            if (i != 4) { // 4, saðlýk ihtiyacýnýn indeksi
                duzeyler[i]--;
                if (duzeyler[i] < 0) {
                    duzeyler[i] = 0;
                }
            }
        }
        printf("Sevgi seviyesi sifir olmadigi icin diger ihtiyaclar azaldi.\n");
    }
    // Açlýk seviyesi 0 ise saðlýk seviyesini azalt
    if (duzeyler[0] == 0) {
        duzeyler[4]--; // Saðlýk seviyesini azalt
        printf("Aclik seviyesi sifirlandigi için saglik seviyesi azaldi.\n");

        // Saðlýk seviyesi 0 ise oyunu sonlandýr
        if (duzeyler[4] <= 0) {
            printf("Saglik seviyesi cok dustu. Oyun sona eriyor.\n");
            exit(0);
        }
    }
    // Hijyen seviyesi 0 ise saðlýk seviyesini azalt
    if (duzeyler[6] == 0) {
        duzeyler[4]--; // Saðlýk seviyesini azalt
        printf("Hijyen seviyesi sifirlandigi icin saglik seviyesi azaldi.\n");

        // Saðlýk seviyesi 0 ise oyunu sonlandýr
        if (duzeyler[4] <= 0) {
            printf("Saglik seviyesi cok dustu. Oyun sona eriyor.\n");
            exit(0);
        }
    }
}

void socialize() {
    char activity[MAXISIMUZUNLUK];

    printf("Sosyallesme secildi. Hangi etkinligi seciyorsunuz? : ");
    printf("\n ornegin: 'oyun_oynama', 'sohbet_etme', 'arkadaslarla_bulusma' \n");
    scanf("%s", activity);

    if (strcmp(activity, "oyun_oynama") == 0) {
        duzeyler[3] += 4;
        printf("%s gerceklestirildi. Sosyallesme duzeyi guncellendi.\n", activity);
    } else if (strcmp(activity, "sohbet_etme") == 0) {
        duzeyler[3] += 4;
        printf("%s gerceklestirildi. Sosyallesme duzeyi guncellendi.\n", activity);
    } else if (strcmp(activity, "arkadaslarla_bulusma") == 0) {
        duzeyler[3] += 4;
        printf("%s gerceklestirildi. Sosyallesme duzeyi guncellendi.\n", activity);
    } else if (strcmp(activity, "konsere_gitmek") == 0){
        duzeyler[3] += 4;
        printf("%s gerceklestirildi. Sosyallesme duzeyi guncellendi.\n", activity);
    } else {
        printf("Gecersiz bir sosyallesme etkinligi sectiniz.\n");
    }

    // Diðer ihtiyaçlarý azalt
    if (duzeyler[3] != 0) {
        for (int i = 0; i < NUMARAIHTIYACLAR; i++) {
            if (i != 4) { // 4, saðlýk ihtiyacýnýn indeksi
                duzeyler[i]--;
                if (duzeyler[i] < 0) {
                    duzeyler[i] = 0;
                }
            }
        }
        printf("Sosyallesme seviyesi sifir olmadigi icin diger ihtiyaclar azaldi.\n");
    }
    // Açlýk seviyesi 0 ise saðlýk seviyesini azalt
    if (duzeyler[0] == 0) {
        duzeyler[4]--; // Saðlýk seviyesini azalt
        printf("Aclik seviyesi sifirlandigi icin saglik seviyesi azaldi.\n");

        // Saðlýk seviyesi 0 ise oyunu sonlandýr
        if (duzeyler[4] <= 0) {
            printf("Saglik seviyesi cok dustu. Oyun sona eriyor.\n");
            exit(0);
        }
    }

    // Hijyen seviyesi 0 ise saðlýk seviyesini azalt
    if (duzeyler[6] == 0) {
        duzeyler[4]--; // Saðlýk seviyesini azalt
        printf("Hijyen seviyesi sifirlandigi icin saglik seviyesi azaldi.\n");

        // Saðlýk seviyesi 0 ise oyunu sonlandýr
        if (duzeyler[4] <= 0) {
            printf("Saglik seviyesi cok dustu. Oyun sona eriyor.\n");
            exit(0);
        }
    }
}

void health() {
    char action[MAXISIMUZUNLUK];

    printf("Saglik secildi. Hangi saglik kontrolunu yapacaksiniz? : ");
    printf("\n ornegin: 'doktor_muayenesi', 'sebze_yeme', 'ilac_kullanimi', 'spor_yapma' \n");
    scanf("%s", action);

    if (strcmp(action, "doktor_muayenesi") == 0) {
        duzeyler[4] += 3;
        printf("%s gerceklestirildi. Saglik duzeyi guncellendi.\n", action);
    } else if (strcmp(action, "sebze_yeme") == 0) {
        duzeyler[4] += 2;
        printf("%s gerceklestirildi. Saglik duzeyi guncellendi.\n", action);
    } else if (strcmp(action, "ilac_kullanimi") == 0) {
        duzeyler[4] += 3;
        printf("%s gerceklestirildi. Saglik duzeyi guncellendi.\n", action);
    } else if (strcmp(action, "spor_yapma") == 0) {
        duzeyler[4] += 2;
        printf("%s gerçekleþtirildi. Saglik düzeyi guncellendi.\n", action);
    } else {
        printf("Gecersiz bir saglik kontrolu sectiniz.\n");
    }

    if (duzeyler[0] == 0) {
        duzeyler[4]--; // Saðlýk seviyesini azalt
        printf("Aclik seviyesi sifirlandýigi icin saglik seviyesi azaldi.\n");

        // Saðlýk seviyesi 0 ise oyunu sonlandýr
        if (duzeyler[4] <= 0) {
            printf("Saglik seviyesi cok dustu. Oyun sona eriyor.\n");
            exit(0);
        }
    }
    // Hijyen seviyesi 0 ise saðlýk seviyesini azalt
    if (duzeyler[6] == 0) {
        duzeyler[4]--; // Saðlýk seviyesini azalt
        printf("Hijyen seviyesi sifirlandigi icin saglik seviyesi azaldi.\n");

        // Saðlýk seviyesi 0 ise oyunu sonlandýr
        if (duzeyler[4] <= 0) {
            printf("Saglik seviyesi cok dustu. Oyun sona eriyor.\n");
            exit(0);
        }
    }
}

void education() {
    char activity[MAXISIMUZUNLUK];

    printf("Egitim secildi. Hangi egitim etkinligini yapacaksiniz? : ");
    printf("\n ornegin: 'adim_atma', 'konusmak', 'bulmaca_cozme' \n");
    scanf("%s", activity);

    if (strcmp(activity, "adim_atma") == 0) {
        duzeyler[5] += 4;
        printf("%s gerceklestirildi. Egitim duzeyi guncellendi.\n", activity);
    } else if (strcmp(activity, "konusmak") == 0) {
        duzeyler[5] += 4;
        printf("%s gerceklestirildi. Egitim duzeyi guncellendi.\n", activity);
    } else if (strcmp(activity, "bulmaca_cozme") == 0) {
        duzeyler[5] += 4;
        printf("%s gerceklestirildi. Egitim duzeyi guncellendi.\n", activity);
    } else {
        printf("Gecersiz bir egitim etkinligi sectiniz.\n");
    }

    if (duzeyler[5] != 0) {
        for (int i = 0; i < NUMARAIHTIYACLAR; i++) {
            if (i != 4) { // 4, saðlýk ihtiyacýnýn indeksi
                duzeyler[i]--;
                if (duzeyler[i] < 0) {
                    duzeyler[i] = 0;
                }
            }
        }
        printf("Egitim seviyesi sifir olmadigi icin diger ihtiyaclar azaldi.\n");
    }
    // Açlýk seviyesi 0 ise saðlýk seviyesini azalt
    if (duzeyler[0] == 0) {
        duzeyler[4]--; // Saðlýk seviyesini azalt
        printf("Aclik seviyesi sifirlandigi icin saglik seviyesi azaldi.\n");

        // Saðlýk seviyesi 0 ise oyunu sonlandýr
        if (duzeyler[4] <= 0) {
            printf("Saglik seviyesi çok dustu. Oyun sona eriyor.\n");
            exit(0);
        }
    }

    // Hijyen seviyesi 0 ise saðlýk seviyesini azalt
    if (duzeyler[6] == 0) {
        duzeyler[4]--; // Saðlýk seviyesini azalt
        printf("Hijyen seviyesi sifirlandigi icin saglik seviyesi azaldi.\n");

        // Saðlýk seviyesi 0 ise oyunu sonlandýr
        if (duzeyler[4] <= 0) {
            printf("Saglik seviyesi cok dustu. Oyun sona eriyor.\n");
            exit(0);
        }
    }
}


void hygiene() {
    char action[MAXISIMUZUNLUK];

    printf("Hijyen secildi. Hangi hijyen aksiyonunu yapacaksiniz? : ");
    printf("\n ornegin: 'dus_alma', 'el_yikama', sac_tarama', 'tirnak_kesme', 'bez_degistirme' \n");
    scanf("%s", action);

    if (strcmp(action, "dus_alma") == 0) {
        duzeyler[6] += 4;
        printf("%s gerceklestirildi. Hijyen duzeyi guncellendi.\n", action);
    } else if (strcmp(action, "el_yikama") == 0) {
        duzeyler[6] += 4;
        printf("%s gerceklestirildi. Hijyen duzeyi guncellendi.\n", action);
    } else if (strcmp(action, "sac_tarama") == 0) {
        duzeyler[6] += 4;
        printf("%s gerceklestirildi. Hijyen duzeyi guncellendi.\n", action);
    } else if (strcmp(action, "tirnak_kesme") == 0) {
        duzeyler[6] += 4;
        printf("%s gerceklestirildi. Hijyen duzeyi guncellendi.\n", action);
    } else if (strcmp(action, "bez_degistirme") == 0) {
        duzeyler[6] += 4;
        printf("%s gerceklestirildi. Hijyen duzeyi guncellendi.\n", action);
    } else {
        printf("Gecersiz bir hijyen aksiyonu sectiniz.\n");
    }

    if (duzeyler[6] != 0) {
        for (int i = 0; i < NUMARAIHTIYACLAR; i++) {
            if (i != 4) { // 4, saðlýk ihtiyacýnýn indeksi
                duzeyler[i]--;
                if (duzeyler[i] < 0) {
                    duzeyler[i] = 0;
                }
            }
        }
        printf("Hijyen seviyesi sifir olmadigi icin diger ihtiyaclar azaldi.\n");
    }
    // Açlýk seviyesi 0 ise saðlýk seviyesini azalt
    if (duzeyler[0] == 0) {
        duzeyler[4]--; // Saðlýk seviyesini azalt
        printf("Aclik seviyesi sifirlandigi icin saglik seviyesi azaldi.\n");

        // Saðlýk seviyesi 0 ise oyunu sonlandýr
        if (duzeyler[4] <= 0) {
            printf("Saglik seviyesi cok dustu. Oyun sona eriyor.\n");
            exit(0);
        }
    }

    // Hijyen seviyesi 0 ise saðlýk seviyesini azalt
    if (duzeyler[6] == 0) {
        duzeyler[4]--; // Saðlýk seviyesini azalt
        printf("Hijyen seviyesi sifirlandigi icin saglik seviyesi azaldi.\n");

        // Saðlýk seviyesi 0 ise oyunu sonlandýr
        if (duzeyler[4] <= 0) {
            printf("Saglik seviyesi cok dustu. Oyun sona eriyor.\n");
            exit(0);
        }
    }
}


void toilet() {
    printf("Tuvalet secildi.\n");
    duzeyler[7] += 4;
    printf("Tuvalet ihtiyaci giderildi. Tuvalet duzeyi sifirlandi.\n");

    if (duzeyler[5] != 0) {
        for (int i = 0; i < NUMARAIHTIYACLAR; i++) {
            if (i != 4) { // 4, saðlýk ihtiyacýnýn indeksi
                duzeyler[i]--;
                if (duzeyler[i] < 0) {
                    duzeyler[i] = 0;
                }
            }
        }
        printf("Tuvalet seviyesi sifir olmadigi icin diger ihtiyaclar azaldi.\n");
    }
    // Açlýk seviyesi 0 ise saðlýk seviyesini azalt
    if (duzeyler[0] == 0) {
        duzeyler[4]--; // Saðlýk seviyesini azalt
        printf("Aclik seviyesi sifirlandigi icin saglik seviyesi azaldi.\n");

        // Saðlýk seviyesi 0 ise oyunu sonlandýr
        if (duzeyler[4] <= 0) {
            printf("Saglik seviyesi cok dustu. Oyun sona eriyor.\n");
            exit(0);
        }
    }

    // Hijyen seviyesi 0 ise saðlýk seviyesini azalt
    if (duzeyler[6] == 0) {
        duzeyler[4]--; // Saðlýk seviyesini azalt
        printf("Hijyen seviyesi sifirlandigi icin saglik seviyesi azaldi.\n");

        // Saðlýk seviyesi 0 ise oyunu sonlandýr
        if (duzeyler[4] <= 0) {
            printf("Saglik seviyesi cok dustu. Oyun sona eriyor.\n");
            exit(0);
        }
    }
}

void entertain() {
    char activity[MAXISIMUZUNLUK];

    printf("Eglence secildi. Hangi eglence etkinligini yapacaksiniz? : ");
    printf("\n ornegin:'oyun_oynama', 'disarida_gezme', 'muzik_dinleme' \n");
    scanf("%s", activity);

    if (strcmp(activity, "oyun_oynama") == 0) {
        duzeyler[8] += 4;
        printf("%s gerceklestirildi. Eglence duzeyi guncellendi.\n", activity);
    } else if (strcmp(activity, "disarida_gezme") == 0) {
        duzeyler[8] += 4;
        printf("%s gerceklestirildi. Eglence duzeyi guncellendi.\n", activity);
    } else if (strcmp(activity, "muzik_dinleme") == 0) {
        duzeyler[8] += 4;
        printf("%s gerceklestirildi. Eglence duzeyi guncellendi.\n", activity);
    } else {
        printf("Gecersiz bir eglence etkinligi sectiniz.\n");
    }

    if (duzeyler[5] != 0) {
        for (int i = 0; i < NUMARAIHTIYACLAR; i++) {
            if (i != 4) { // 4, saðlýk ihtiyacýnýn indeksi
                duzeyler[i]--;
                if (duzeyler[i] < 0) {
                    duzeyler[i] = 0;
                }
            }
        }
        printf("Eglence seviyesi sifir olmadigi icin diger ihtiyaclar azaldi.\n");
    }
    // Açlýk seviyesi 0 ise saðlýk seviyesini azalt
    if (duzeyler[0] == 0) {
        duzeyler[4]--; // Saðlýk seviyesini azalt
        printf("Aclik seviyesi sifirlandigi icin saglik seviyesi azaldi.\n");

        // Saðlýk seviyesi 0 ise oyunu sonlandýr
        if (duzeyler[4] <= 0) {
            printf("Saglik seviyesi çok dustu. Oyun sona eriyor.\n");
            exit(0);
        }
    }

    // Hijyen seviyesi 0 ise saðlýk seviyesini azalt
    if (duzeyler[6] == 0) {
        duzeyler[4]--; // Saðlýk seviyesini azalt
        printf("Hijyen seviyesi sifirlandigi icin saglik seviyesi azaldi.\n");

        // Saðlýk seviyesi 0 ise oyunu sonlandýr
        if (duzeyler[4] <= 0) {
            printf("Saglik seviyesi cok dustu. Oyun sona eriyor.\n");
            exit(0);
        }
    }
}

void thirsty() {
    char activity[MAXISIMUZUNLUK];

    printf("Susuzluk secildi. Hangi susuzluk etkinligini yapacaksiniz? : ");
    printf("\n ornegin:'karpuz', 'cilek', 'soda' \n");
    scanf("%s", activity);

    if (strcmp(activity, "karpuz") == 0) {
        duzeyler[9] += 4;
        printf("%s gerceklestirildi. Susuzluk duzeyi guncellendi.\n", activity);
    } else if (strcmp(activity, "cilek") == 0) {
        duzeyler[9] += 4;
        printf("%s gerceklestirildi. Susuzluk duzeyi guncellendi.\n", activity);
    } else if (strcmp(activity, "soda") == 0) {
        duzeyler[9] += 4;
        printf("%s gerceklestirildi. Susuzluk duzeyi guncellendi.\n", activity);
    } else {
        printf("Gecersiz bir susuzluk etkinligi sectiniz.\n");
    }

    if (duzeyler[5] != 0) {
        for (int i = 0; i < NUMARAIHTIYACLAR; i++) {
            if (i != 4) { // 4, saðlýk ihtiyacýnýn indeksi
                duzeyler[i]--;
                if (duzeyler[i] < 0) {
                    duzeyler[i] = 0;
                }
            }
        }
        printf("Susuzluk seviyesi sifir olmadigi icin diger ihtiyaclar azaldi.\n");
    }
    // Açlýk seviyesi 0 ise saðlýk seviyesini azalt
    if (duzeyler[0] == 0) {
        duzeyler[4]--; // Saðlýk seviyesini azalt
        printf("Aclik seviyesi sifirlandigi icin saglik seviyesi azaldi.\n");

        // Saðlýk seviyesi 0 ise oyunu sonlandýr
        if (duzeyler[4] <= 0) {
            printf("Saglik seviyesi çok dustu. Oyun sona eriyor.\n");
            exit(0);
        }
    }

    // Hijyen seviyesi 0 ise saðlýk seviyesini azalt
    if (duzeyler[6] == 0) {
        duzeyler[4]--; // Saðlýk seviyesini azalt
        printf("Hijyen seviyesi sifirlandigi icin saglik seviyesi azaldi.\n");

        // Saðlýk seviyesi 0 ise oyunu sonlandýr
        if (duzeyler[4] <= 0) {
            printf("Saglik seviyesi cok dustu. Oyun sona eriyor.\n");
            exit(0);
        }
    }
}



int main() {
    int secim;

    printf("Sanal bebegin ismini girin: ");
    scanf("%s", babyName);

    // Ýhtiyaç düzeylerini baþlat
     for (int i = 0; i < NUMARAIHTIYACLAR; i++) {
        duzeyler[i] = 5;// ilk enerji düzeyleri
    }


    while(1) {
        displayNeedsLevels();
        printMenu();
        printf("Yapmak istediginiz islemi secin (1-11): ");
        if (scanf("%d", &secim) != 1) {
            printf("Gecersiz girdi. Lutfen bir sayi giriniz.\n");
            while (getchar() != '\n'); // Buffer temizleme
            continue;
        }
            switch (secim) {
                case 1:
                    eat();
                    break;
                case 2:
                    sleep();
                    break;
                case 3:
                    love();
                    break;
                case 4:
                    socialize();
                    break;
                case 5:
                    health();
                    break;
                case 6:
                    education();
                    break;
                case 7:
                    hygiene();
                    break;
                case 8:
                    toilet();
                    break;
                case 9:
                    entertain();
                    break;
                case 10:
                    thirsty();
                    break;
                case 11:
                printf("Oyun sona erdi. Sanal bebeðinizle vakit geçirdiðiniz için teþekkürler!\n");
                exit(0);
                default:
                    printf("Gecersiz secim yaptiniz. Lutfen tekrar deneyin.\n");

            }

    }
    return 0;
}
