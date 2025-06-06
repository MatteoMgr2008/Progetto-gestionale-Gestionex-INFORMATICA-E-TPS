#pragma once
#include <imgui.h>
#include <vector>
#include "Magazzino.h"
#include <string>

using namespace std;

void DrawGestioneStockScreen(bool& gestioneStock, vector<Magazzino>& listMagazzini);
void DrawPopUpAddStock(bool& popUpAddStock, Magazzino& magazzino, bool& errorPopup);
void DrawInfoStockPopUp(bool& showPopup, Stock& stock, int stockIndex, Magazzino& magazzino);
void DrawModifyStockPopUp(bool& modificaPopup, Stock& stock, Magazzino& magazzino, int stockIndex);