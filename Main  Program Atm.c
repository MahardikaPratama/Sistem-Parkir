#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<unistd.h>

typedef struct{
	char No_Rekening[10];
    	char Nama[30];
    	char Pin[7];
	char NoHp [13];
	char IdPelanggan[15];
	long total_saldo;
}Nasabah;
Nasabah user = {.No_Rekening = "221524044",.Nama = "Mahardika",.Pin = "123456",.NoHp = "085864721960",.IdPelanggan = "1122334455",.total_saldo = 1000000};
Nasabah penerima = {.No_Rekening = "221524043", .Nama = "Reza", .total_saldo = 500000};
//Deklarasi Modul
void MenuBahasa();
void displayMenuBahasa();
void bahasaIndonesia();
void bahasaInggris();
void displayMenuPinId();
void displaySalahPin();
void displayAkunTerblokir();
void bacaPin(char inputPin[6]);
int Cek_validitas(int *Valid, char inputPin[6]);
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

void gotoxy(int x, int y);
void printToxy(int x, int y, char* label);
void header();

//Variabel Global
int i, jumlah, opsi;
unsigned int sleep (unsigned int seconds);

int main(){
	system ("color 1F");
	MenuBahasa();
}


void MenuBahasa(){
	KEMBALI:
	system("cls");
	displayMenuBahasa();	
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
	int benar = 0;
	char inputPin[6];
	i = 1;
	displayMenuPinId();
	while(benar == 0 && i<=3){
		bacaPin(inputPin);
		Cek_validitas(&benar, inputPin);
	}
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


void bacaPin(char inputPin[6]){
	gotoxy(53, 13);
        for(int i = 0; i < 6; i++){
            inputPin[i] = _getch();
            putchar('*');
            putchar(' ');
        }
}

int Cek_validitas(int *Valid, char inputPin[6]){
	if((strcmp(inputPin, user.Pin)==0)&&i<=1){
		*Valid = 1;
	}
	else if(i<3){
		*Valid = 0;
		i = i + 1;
		system("cls");
		displaySalahPin();
	}
	else{
		system("cls");
		displayAkunTerblokir();
		sleep(5);
		exit(0);
	}
	return *Valid;
}

void gotoxy(int x, int y){
    COORD coord;
	coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void printToxy(int x, int y, char* label){
    gotoxy(x,y);
    printf("%s",label);
}

void header(){
	for (int i = 1; i<25; i++){
    	printToxy(15,1+i,"||");
	}
	for (int i =0; i<=119; i++){
    	printToxy(0+i,1,"=");
	}
	for (int i = 1; i<25; i++){
    	printToxy(100,1+i,"||");
	}
	for (int i =0; i<=119; i++){
    	printToxy(0+i,25,"=");
	}
}

void displayMenuBahasa(){
	header();
	printToxy(50,3,"PEMILIHAN BAHASA");
	printToxy(48,4,"LANGUAGE REFFFERENCE");
	printToxy(42,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(82,9,"BAHASA INDONESIA");
	printToxy(105,13,"<= [5]");
	printToxy(82,13,"ENGLISH LANGUAGE");
	printToxy(105,17,"<= [6]");
	printToxy(60,24,"\t Masukan pilihan anda :  ");
}

void displayMenuPinId(){
	header();
	printToxy(53,3,"MASUKKAN PIN");
	printToxy(54,4,"ATM ANDA !");
	printToxy(42,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(53,14,"_ _ _ _ _ _");
	printToxy(105,17,"<= [6]");
}

void displaySalahPin(){
	header();
	printToxy(52,3,"PIN ANDA SALAH ");
	printToxy(47,4,"SILAKAN MASUKKAN KEMBALI ");
	printToxy(49,5,"NOMOR PIN YANG BENAR ");
	printToxy(43,6,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(53,14,"_ _ _ _ _ _");
	printToxy(47,16,"KARTU ANDA AKAN DIBLOKIR");
	printToxy(43,17,"BILA ANDA SALAH PIN 3(TIGA) KALI");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
}

void displayAkunTerblokir(){
	header();
	printToxy(48,3,"ANDA TELAH 3 KALI SALAH");
	printToxy(52,4,"MEMASUKKAN PIN");
	printToxy(43,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	printToxy(47,17,"SILAHKAN AMBIL KARTU ANDA");
	printToxy(46,18,"DAN HUBUNGI CALL CENTER KAMI");
	printToxy(46,13,". . . . . . . . . . . . . . ");
	printToxy(50,11,"KARTU ANDA SEMENTARA");
	printToxy(48,12,"TIDAK DAPAT DIPERGUNAKAN");
}

void displayMenuPenarikanCepat(){
	header();
	printToxy(51,3,"MENU PENARIKAN CEPAT");
	printToxy(45,4,"SILAKAN PILIH JUMLAH PENARIKAN");
	printToxy(43,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(18,9,"Rp. 250.000,00");
	printToxy(7,13,"[2] =>");
	printToxy(18,13,"Rp. 500.000,00");
	printToxy(7,17,"[3] =>");
	printToxy(18,17,"Rp. 1.000.000,00");
	printToxy(105,9,"<= [4]");
	printToxy(75,9,"Rp. 1.250.000,00");
	printToxy(105,13,"<= [5]");
	printToxy(75,13,"JUMLAH LAIN");
	printToxy(105,17,"<= [6]");
	printToxy(75,17,"MENU SEBELUMNYA");
	printToxy(60,24,"\t Masukan pilihan anda :  ");
}
