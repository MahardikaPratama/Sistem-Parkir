#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

typedef struct{
	char Nama[25];
	char pin[6];
	int saldo[10];
	char NoRekening [20];
	char NoHp [15];
	char IdPelanggan[15];
}Nasabah;
//Deklarasi Modul
void MenuBahasa();
void displayMenuBahasa();
void bahasaIndonesia();
void bahasaInggris();
void displayMenuPinId();
void bacaPin(char inputPin[6]);
int Cek_validitas(int *Valid);
void PenarikanCepat();
void displayMenuPenarikanCepat();
void MenuPenarikanCepat();
int validitasTransaksi(nominal, &valid);
void MenuJumlahLain();
void MenuLainnya();
void displayBerhasil();
void displayGagal();
void displayJumlahLain();
void displayMenuLainnya();
void MenuTransfer();
void MenuPembayaran();
void MenuInformasiSaldo();
void MenuUbahPin();
void MenuMutasi();
void displayMenuTransfer();
void bacaNoRek(&NoRek);
void cek_ValiditasTransfer();
void displayProsesTransfer();
void displayNoRekTidakAda();
void displayMenuPembayaran();
void MenuPembayaran();
void MenuTeleponHp();
void MenuListrik();
void MenuPdam();
void MenuTvInternet();
void displayMenuTeleponHp();
void displayJumlahNominal();
void MenuJumlahNominal();
void displayMenuListrik();
void displayMenuPdam();
void displayMenuTvInternet();
void MenuInformasiSaldo();
void displayMenuSaldo();
void MenuUbahPin();
void displayMenuUbahPin();
void MenuMutasi();
void displayMenuMutasi();


//Variabel Global
int i, opsi, benar, valid, jumlah;
char inputPin[6];

int main(){
	system ("color 1F");
	MenuBahasa();
}


void MenuBahasa(){
	displayMenuBahasa();
	KEMBALI:
    scanf("%d",&opsi);
    switch(opsi){
    	case 4: bahasaIndonesia();
    			break;
    	case 5: system ("cls");
//    			bahasaInggris();
    			break;
    	default :
        	goto KEMBALI;
    }
}

void bahasaIndonesia(){
	system ("cls");
	displayMenuPinId();
	bacaPin(inputPin);
	Cek_validitas(&benar);
	if (benar == 1){
		PenarikanCepat();
	}
}

void PenarikanCepat(){
	system("cls");
	displayMenuPenarikanCepat();
	MenuPenarikanCepat();
}

void MenuPenarikanCepat(){
	KEMBALI:
    scanf("%d",&opsi);
    switch(opsi){
    	case 1: nominal = 250000;
				validitasTransaksi(nominal, &valid);
    			if (valid == 1){
    				displayBerhasil();
    				break;
				}
				else if(valid == 0){
					displayGagal();
					break;
				}
    	case 2: nominal = 500000;
				validitasTransaksi(nominal, &valid);
    			if (valid == 1){
    				displayBerhasil();
    				break;
				}
				else if(valid == 0){
					displayGagal();
					break;
				}
    	case 3: nominal = 1000000;
				validitasTransaksi(nominal, &valid);
    			if (valid == 1){
    				displayBerhasil();
    				break;
				}
				else if(valid == 0){
					displayGagal();
					break;
				}
    	case 4: nominal = 1250000;
				validitasTransaksi(nominal, &valid);
    			if (valid == 1){
    				displayBerhasil();
    				break;
				}
				else if(valid == 0){
					displayGagal();
					break;
				}
    	case 5: MenuJumlahLain();
				break;
    	case 6: MenuLainnya();
    			break;
    	default :
       		printf("\nMasukkan Tidak Valid !");
        	goto KEMBALI;
    }
}

void MenuJumlahLain(){
	system("cls");
	displayJumlahLain();
	scanf ("%d", &jumlah);
	validitasTransaksi(jumlah, &valid);
    if (valid == 1){
    	displayBerhasil();
	}
	else if(valid == 0){
		displayGagal();
		
	}
}

void MenuLainnya(){
	system ("cls");
	displayMenuLainnya();
	KEMBALI:
    scanf("%d",&opsi);
    switch(opsi){
    	case 1: MenuTransfer();
    			break;
    	case 2: MenuPembayaran();
    			break;
    	case 3: MenuInformasiSaldo();
    			break;
    	case 4: MenuUbahPin();
    			break;
    	case 5: MenuMutasi();
    			break;
    	case 6: MenuPenarikanCepat();
    			break;
    	default :
       		printf("\nMasukkan Tidak Valid !");
        	goto KEMBALI;
    }
}
void MenuTransfer(){
	system("cls");
	displayMenuTransfer();
	KEMBALI:
	bacaNoRek(&NoRek);
	if (No_Rekening != NULL){
		system("cls");
		displayMasukkanNominal();
		bacaNominal();
		cek_ValiditasTransfer();
		system("cls");
		displayProsesTransfer();
		system("cls");
		displayBerhasil();
	}
	else{
		system("cls");
		displayNoRekTidakAda();
		goto KEMBALI;
	}
}

void MenuPembayaran(){
	system("cls");
	displayMenuPembayaran();
	MenuPembayaran();
}

void MenuPembayaran(){
	KEMBALI:
    scanf("%d",&opsi);
    switch(opsi){
    	case 1: MenuTeleponHp();
    			break;
    	case 2: MenuListrik();
    			break;
    	case 3: MenuPdam();
    			break;
    	case 4: MenuTvInternet();
    			break;
    	case 5: MenuTransfer();
    			break;
    	default :
       		printf("\nMasukkan Tidak Valid !");
        	goto KEMBALI;
    }
}

void MenuTeleponHp(){
	system("cls");
	displayMenuTeleponHp();
	gets(noHp);
	system("cls");
	displayJumlahNominal();
	MenuJumlahNominal();
}

void MenuJumlahNominal(){
	KEMBALI:
    scanf("%d",&opsi);
    switch(opsi){
    	case 1: nominal = 25000;
				validitasTransaksi(nominal, &valid);
    			if (valid == 1){
    				displayBerhasil();
    				break;
				}
				else if(valid == 0){
					displayGagal();
					break;
				}
    	case 2: nominal = 50000;
				validitasTransaksi(nominal, &valid);
    			if (valid == 1){
    				displayBerhasil();
    				break;
				}
				else if(valid == 0){
					displayGagal();
					break;
				}
    	case 3: nominal = 100000;
				validitasTransaksi(nominal, &valid);
    			if (valid == 1){
    				displayBerhasil();
    				break;
				}
				else if(valid == 0){
					displayGagal();
					break;
				}
    	case 4: nominal = 150000;
				validitasTransaksi(nominal, &valid);
    			if (valid == 1){
    				displayBerhasil();
    				break;
				}
				else if(valid == 0){
					displayGagal();
					break;
				}
    	default :
       		printf("\nMasukkan Tidak Valid !");
        	goto KEMBALI;
    }
}

void MenuListrik(){
	system("cls");
	displayMenuListrik();
	gets(idPelanggan);
	system("cls");
	displayJumlahNominal();
	MenuJumlahNominal();
}

void MenuPdam(){
	system("cls");
	displayMenuPdam();
	gets(idPelanggan);
	system("cls");
	displayJumlahNominal();
	MenuJumlahNominal();
}

void MenuTvInternet(){
	system("cls");
	displayMenuTvInternet();
	gets(idPelanggan);
	system("cls");
	displayJumlahNominal();
	MenuJumlahNominal();
}

void MenuInformasiSaldo(){
	system("cls");
	displayMenuSaldo();
}

void MenuUbahPin(){
	system("cls");
	displayMenuUbahPin();
}

void MenuMutasi(){
	system("cls");
	displayMenuMutasi();
}