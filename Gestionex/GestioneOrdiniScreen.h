#pragma once
#include <imgui.h>
#include <vector>
#include <list>
#include "OrdineEntrata.h"
#include "Magazzino.h"
#include <string>

using namespace std;

void DrawGestioneOrdiniScreen(bool& gestioneOrdini, list<OrdineEntrata>& listOrdini,vector<Magazzino>& listMagazzini);
void DrawAddOrderWindow(bool& showAddOrderWindow, list<OrdineEntrata>& listOrdini);
void DrawModifyOrderWindow(bool& showModifyOrderWindow, list<OrdineEntrata>& listOrdini);
void DrawArticlesWindow(bool& showArticlesWindow, int selectedOrderIndex, list<OrdineEntrata>& listOrdini);
void ShowArticoliDellOrdine(ArticoliDellOrdine& articolo);
void DrawTransferArticlesWindow(bool& showTransferWindow, int selectedOrderIndex, list<OrdineEntrata>& listOrdini,vector<Magazzino>& listMagazzino);
void PopUpTransferInMagazine(vector<Magazzino>& listMagazzino);