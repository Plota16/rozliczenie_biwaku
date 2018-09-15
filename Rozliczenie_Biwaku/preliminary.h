#pragma once
class preliminary
{
public:
	preliminary();
	void set(HWND hDlg);
	double get(int i);
	~preliminary();
	HWND hDlg;
	int state;
	double materialy;
	double transport;
	double wyzywienie;
	double zakup_sprzetu_do_9999;
	double zakup_sprzetu_od_10000;
	double oplaty_komunalne;
	double uslugi_obce;
	double wywoz_odpadow_stalych;
	double woda_i_scieki;
	double wynagrodzenia_z_umowy_zlecenia_netto;
	double skladka_z_tytulu_ubezpieczen_spoleczych;
	double podatek_od_umowy_zlecenia;
	double zuzycie_paliw;
	double podroze_sluzbowe;
	double koszty_zakwaterowania;
	double wydatki_progarmowe;
	double pozostale_koszy;
	double koszty_posrednie;
};

