// stdafx.h: dołącz plik do standardowych systemowych plików dołączanych,
// lub specyficzne dla projektu pliki dołączane, które są często wykorzystywane, ale
// są rzadko zmieniane
//

#pragma once

#include "targetver.h"

//#define WIN32_LEAN_AND_MEAN             // Wyklucz rzadko używane rzeczy z nagłówków systemu Windows
// Pliki nagłówkowe systemu Windows:
#include <windows.h>

// Pliki nagłówkowe środowiska uruchomieniowego C
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: W tym miejscu odwołaj się do dodatkowych nagłówków wymaganych przez program
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <ostream>
#include "date.h"
#include "document.h"
#include "line.h"
#include "upper_window.h"
#include "dialog_box.h"
#include "render_csv.h"
#include "file.h"
#include "preliminary.h"
#include "advance.h"
#include "advance_dialog.h"

#define ID_DODAJ_DOKUMENT 501
#define ID_GENERUJ_RAPORT 502
#define ID_GENERUJ_CSV 503
#define ID_PRELIMINARZ 504
#define ID_ZALICZKI 505
#define BIALY 301