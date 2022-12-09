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
	char Bank[4];
	long total_saldo;
}Nasabah;
Nasabah user = {.No_Rekening = "221524044",.Nama = "Mahardika",.Pin = "123456",.NoHp = "085864721960",.IdPelanggan = "1122334455",.Bank = "BCA",.total_saldo = 20000000};
Nasabah penerima = {.No_Rekening = "221524057", .Nama = "Reza", .Bank = "BRI", .total_saldo = 500000}; 
//Deklarasi Modul
void MenuBahasa();
void bahasaIndonesia();
void bahasaInggris();
void bacaPin(char inputPin[6]);
int Cek_validitas(int *Valid, char inputPin[6]);
void MenuPenarikanCepat();
int validitasTransaksi(int jumlah);
void MenuJumlahLain();
void bacaJumlahLain(int *nominal);
void PenarikanCepat();
void MenuLainnya();
void MenuTransfer();
void bacaJumlahTrf();
void konfirmasitrf(); 
void MenuKonfirmasi();
int cek_ValiditasNorek(int *Betul);
int cek_ValiditasTransfer(int *Betul);
void MenuPembayaran();
void MenuInformasiSaldo();
void MenuUbahPin();
void MenuMutasi();
void MenuPembayaran();
void MenuTeleponHp();
void MenuListrik();
void MenuPdam();
void MenuTvInternet();
void MenuJumlahNominal();
void MenuInformasiSaldo();
void MenuUbahPin();
void MenuMutasi();

void gotoxy(int x, int y);
void printToxy(int x, int y, char* label);
void header();
void displayMenuBahasa();
void displayMenuPinId();
void displaySalahPin();
void displayAkunTerblokir();
void displayMenuPenarikanCepat();
void displayTransaksiBerhasil();
void displayTransaksiGagal();
void displayTransaksiGagallimit();
void displayMenuJumlahLain();
void displayLoading();
void displayEnd();
void displayMenuLainnya();
void displayMenuTransfer();
void displayProsesTransfer();
void displaytransfergagal();
void displaytransferberhasil();
void displaykonfirmasitrf(int nominal);
void displaygoodtransfer();
void displayMenuPembayaran();
void displayMenuTeleponHp();
void displayJumlahNominal();
void displayMenuListrik();
void displayMenuPdam();
void displayMenuTvInternet();
void displayMenuSaldo();
void displayMenuUbahPin();
void displayMenuMutasi();
//Variabel Global
int i, opsi, nominal, isValid;
int limitTarik=0, limittrf=0;
int admin=3000;
char No_Rek[21];
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
	MenuPenarikanCepat();
}

void MenuPenarikanCepat(){
	int nominal;
	int opsi;
	char konfirmasi;
	
	KEMBALI:
	system("cls");
	displayMenuPenarikanCepat();
	isValid=0;
	scanf("%d", &opsi);
	switch(opsi){
		case 1: 
			nominal = 250000;
			limitTarik = limitTarik + nominal;
			isValid = validitasTransaksi(nominal);
			if (isValid == 1){
				user.total_saldo = user.total_saldo - nominal;
				system("cls");
				displayLoading();
				sleep(5);
				system("cls");
				displayTransaksiBerhasil();
				gotoxy(49,9);
				printf("SISA SALDO ANDA: %d",user.total_saldo);
				GO:
				gotoxy(88, 24);
				konfirmasi = getch();
				switch(konfirmasi){
					case '5' : 
						goto KEMBALI;
						break;
					case '6' : 
						system("cls");
						displayEnd();
						sleep(5);
						exit(0);
					default:
						goto GO;
					}
				}
			else {
				if(user.total_saldo - nominal < 10000){
					system("cls");
					displayLoading();
					sleep(5);
					system("cls");
					displayTransaksiGagal();
					GO2:
					gotoxy(88, 24);
					konfirmasi = getch();
					switch(konfirmasi){
						case '5' : 
							goto KEMBALI;
							break;
						case '6' : 
							system("cls");
							displayEnd();
							sleep(5);
							exit(0);
						default:
							goto GO2;
					}
				}
				if(limitTarik > 10000000){
					system("cls");
					displayLoading();
					sleep(5);
					system("cls");
					displayTransaksiGagallimit();
					GO3:
					gotoxy(88, 24);
					konfirmasi = getch();
					switch(konfirmasi){
						case '5' : 
							goto KEMBALI;
							break;
						case '6' : 
							system("cls");
							displayEnd();
							sleep(5);
							exit(0);
						default:
							goto GO3;
					}
				}
			}
			break;
		case 2: 
			system("cls");
			nominal = 500000;
			limitTarik = limitTarik + nominal;
			isValid = validitasTransaksi(nominal);
			if (isValid == 1){
				user.total_saldo = user.total_saldo - nominal;
				displayLoading();
				sleep(5);
				system("cls");
				displayTransaksiBerhasil();
				gotoxy(49,9);
				printf("SISA SALDO ANDA: %d",user.total_saldo);
				GO4:
				gotoxy(88, 24);
				konfirmasi = getch();
				switch(konfirmasi){
					case '5' : 
						goto KEMBALI;
						break;
					case '6' : 
						system("cls");
						displayEnd();
						sleep(5);
						exit(0);
					default:
						goto GO4;
				}
			}
			else {
				if(user.total_saldo - nominal < 10000){
					system("cls");
					displayLoading();
					sleep(5);
					system("cls");
					displayTransaksiGagal();
					GO5:
					gotoxy(88, 24);
					konfirmasi = getch();
					switch(konfirmasi){
						case '5' : 
							goto KEMBALI;
							break;
						case '6' : 	
							system("cls");
							displayEnd();
							sleep(5);
							exit(0);
						default:
							goto GO5;
					}
				}
				if(limitTarik > 10000000){
					system("cls");
					displayLoading();
					sleep(5);
					system("cls");
					displayTransaksiGagallimit();
					GO6:
					gotoxy(88, 24);
					konfirmasi = getch();
					switch(konfirmasi){
						case '5' : 
							goto KEMBALI;
							break;
						case '6' : 	
							system("cls");
							displayEnd();
							sleep(5);
							exit(0);
						default:
							goto GO6;
					}
				}
			}
			break;
		case 3:	
			system("cls");
			nominal = 1000000;
			limitTarik = limitTarik + nominal;
			isValid = validitasTransaksi(nominal);
			if (isValid == 1){
				user.total_saldo = user.total_saldo - nominal;
				displayLoading();
				sleep(5);
				system("cls");
				displayTransaksiBerhasil();
				gotoxy(49,9);
				printf("SISA SALDO ANDA: %d",user.total_saldo);
				GO7:
				gotoxy(88, 24);
				konfirmasi = getch();
				switch(konfirmasi){
					case '5' : 
						goto KEMBALI;
						break;
					case '6' : 	
						system("cls");
						displayEnd();
						sleep(5);
						exit(0);
					default:
						goto GO7;
				}
			}
			else {
				if(user.total_saldo - nominal < 10000){
					system("cls");
					displayLoading();
					sleep(5);
					system("cls");
					displayTransaksiGagal();
					GO8:
					gotoxy(88, 24);
					konfirmasi = getch();
					switch(konfirmasi){
						case '5' : 
							goto KEMBALI;
							break;
						case '6' : 	
							system("cls");
							displayEnd();
							sleep(5);
							exit(0);
						default:
							goto GO8;
					}
				}
				if(limitTarik > 10000000){
					system("cls");
					displayLoading();
					sleep(5);
					system("cls");
					displayTransaksiGagallimit();
					GO9:
					gotoxy(88, 24);
					konfirmasi = getch();
					switch(konfirmasi){
						case '5' : 
							goto KEMBALI;
							break;
						case '6' : 	
							system("cls");
							displayEnd();
							sleep(5);
							exit(0);
						default:
							goto GO9;
					}
				}
			}
			break;
		case 4: 
			system("cls");
			nominal = 12500000;
			limitTarik = limitTarik + nominal;
			isValid = validitasTransaksi(nominal);
			if (isValid == 1){
				user.total_saldo = user.total_saldo - nominal;
				displayLoading();
				sleep(5);
				system("cls");
				displayTransaksiBerhasil();
				gotoxy(50,16);
				printf("SISA SALDO ANDA: %d",user.total_saldo);
				GO10:
				gotoxy(88, 24);
				konfirmasi = getch();
				switch(konfirmasi){
					case '5' : 
						goto KEMBALI;
						break;
					case '6' : 	
						system("cls");
						displayEnd();
						sleep(5);
						exit(0);
					default:
						goto GO10;
				}
			}
			else {
				if(user.total_saldo - nominal < 10000){
					system("cls");
					displayLoading();
					sleep(5);
					system("cls");
					displayTransaksiGagal();
					GO11:
					gotoxy(88, 24);
					konfirmasi = getch();
					switch(konfirmasi){
						case '5' : 
							goto KEMBALI;
							break;
						case '6' : 	
							system("cls");
							displayEnd();
							sleep(5);
							exit(0);
						default:
							goto GO11;
					}
				}
				if(limitTarik > 10000000){
					system("cls");
					displayLoading();
					sleep(5);
					system("cls");
					displayTransaksiGagallimit();
					GO12:
					gotoxy(88, 24);
					konfirmasi = getch();
					switch(konfirmasi){
						case '5' : 
							goto KEMBALI;
							break;
						case '6' : 	
							system("cls");
							displayEnd();
							sleep(5);
							exit(0);
						default:
							goto GO12;
					}
				}
			}
			break;
		case 5: 
			system("cls");
			MenuJumlahLain();
			break;
		case 6: 
			MenuLainnya();
			break;
		default:
			goto KEMBALI;
	}
}

void MenuJumlahLain(){
	int jumlahLain, opsi;
	char konfirmasi;
	
	BACK:
	system("cls");
	displayMenuJumlahLain();
	bacaJumlahLain(&nominal);
	gotoxy(88,24);
	scanf("%d", &opsi);
	if (opsi == 5){
		if(nominal % 50000 == 0 ){
			limitTarik = limitTarik + nominal;
			isValid = validitasTransaksi(nominal);
			if (isValid == 1){
				user.total_saldo = user.total_saldo - nominal;
				system("cls");
				displayLoading();
				sleep(5);
				system("cls");
				displayTransaksiBerhasil();
				gotoxy(49,9);
				printf("SISA SALDO ANDA: %d",user.total_saldo);
				GO13:
				gotoxy(88, 24);
				konfirmasi = getch();
				switch(konfirmasi){
					case '5' : 
						MenuPenarikanCepat();
						break;
					case '6' : 	
						system("cls");
						displayEnd();
						sleep(5);
						exit(0);
					default:
						goto GO13;
				}
			}
			else {
				if(user.total_saldo - nominal < 10000){
					system("cls");
					displayLoading();
					sleep(5);
					system("cls");
					displayTransaksiGagal();
					GO14:
					gotoxy(88, 24);
					konfirmasi = getch();
					switch(konfirmasi){
						case '5' : 
							MenuPenarikanCepat();
							break;
						case '6' : 	
							system("cls");
							displayEnd();
							sleep(5);
							exit(0);
						default:
							goto GO14;
					}
				}
				if(limitTarik > 10000000){
					system("cls");
					displayLoading();
					sleep(5);
					system("cls");
					displayTransaksiGagallimit();
					GO15:
					gotoxy(88, 24);
					konfirmasi = getch();
					switch(konfirmasi){
						case '5' : 
							MenuPenarikanCepat();
							break;
						case '6' : 	
							system("cls");
							displayEnd();
							sleep(5);
							exit(0);
						default:
							goto GO15;
					}
				}
			}
		}
	}
	else if (opsi == 6){
		goto BACK;
	}
	else {
		MenuPenarikanCepat();
	}
}


void MenuLainnya(){
	system("cls");
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
 	char konfirmasi;
	int Benar=0;
 	int Sama;
    
 	system("cls");
 	displayMenuTransfer();
 	gotoxy(55,7);
 	gets (No_Rek);
	cek_ValiditasNorek(&Sama);
	if(Sama==1){
 	gotoxy(90,24);
	scanf("%d",&opsi);
	switch(opsi){
		case 4 : 
		        system("cls");
		        displayProsesTransfer();
		    	gotoxy(56,8);
             		scanf("%d", &nominal);
             		limittrf=limittrf+nominal;
			cek_ValiditasTransfer( &Benar);
		        if (Benar==1){
             			if (nominal>=50000){
             				user.total_saldo=user.total_saldo-nominal-admin;
             				system("cls");
             				displaykonfirmasitrf(nominal);
             				konfirmasitrf();
             				displaygoodtransfer();
             				gotoxy(50,15);
             				printf("SISA SALDO ANDA : %d", user.total_saldo);
             				MenuKonfirmasi();
             				DO:
					gotoxy(88, 24);
					konfirmasi = getch();
					switch(konfirmasi){
						case '5' : 
							MenuTransfer();
							break;
						case '6' : 	
							system("cls");
							displayEnd();
							sleep(5);
							exit(0);
						default:
							goto DO;
             				}
				}	 
		    	}
			else {
				if(user.total_saldo-nominal<10000){
			    		system("cls");
			    		displayLoading();
			    		sleep(5);
			    		system("cls");
			    		displaytransfergagal();
			    		DO2:
					gotoxy(88, 24);
					konfirmasi = getch();
					switch(konfirmasi){
						case '5' : 
							MenuTransfer();
							break;
						case '6' : 	
							system("cls");
							displayEnd();
							sleep(5);
							exit(0);
						default:
							goto DO2;
					}
				}	
				if(limittrf>1000000){
					system("cls");
					displayLoading();
					sleep(5);
					system("cls");
					displayTransaksiGagallimit();
					DO3:
					gotoxy(88, 24);
					konfirmasi = getch();
					switch(konfirmasi){
						case '5' : 
							MenuTransfer();
							break;
						case '6' : 	
							system("cls");
							displayEnd();
							sleep(5);
							exit(0);
						default:
							goto DO3;
					}
				}
			}
	        	break;
		case 5 :  
		 	MenuTransfer();
			break;
		default : 	        
  			MenuTransfer();
  			break;
	}
  	}
 	else {
 	MenuTransfer();
 	}
}

int cek_ValiditasNorek(int *Betul){
	if((strcmp(No_Rek, penerima.No_Rekening)==0)&&user.total_saldo-nominal>=10000&&limittrf <=10000000){
     		*Betul=1;
 	}
    	else {
		*Betul=0;
	}
	return *Betul;
 }
 
int cek_ValiditasTransfer(int *Betul){
      	if(user.total_saldo-nominal>=10000&&limittrf <=1000000){
 	    	*Betul=1;
    	}
   	else {
		*Betul=0;
	}
	return *Betul;	
 }

void MenuKonfirmasi(){
 	gotoxy(90,24);
 	scanf("%d", &opsi);
 	switch (opsi){
 		case 5 : 
			system("cls");
             		MenuTransfer();
             		break;
  	      	case 6:  
			system("cls");
			displayEnd();
			sleep(5);
			exit(0);
        		break;
		default : 
			MenuKonfirmasi();		
 	}
}

void konfirmasitrf(){
 	gotoxy(90,24);
 	scanf("%d", &opsi);
 	switch (opsi){
 		case 5 : 
			system("cls");
             		displayLoading();
             		sleep(5);
             		system("cls");
             		displayTransaksiBerhasil();
             		break;
        	case 6 :    
			MenuTransfer();
		default :
			konfirmasitrf();	
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

int validitasTransaksi(int jumlah){
	int isValid;
	
	limitTarik = limitTarik + jumlah;
	if (user.total_saldo - jumlah >= 10000 && limitTarik <= 10000000){
		isValid = 1;
	}
	else {
		isValid = 0;
	}
	return isValid;
}

void bacaJumlahLain(int *nominal){	
	gotoxy(52, 10);
	scanf("%d", nominal);
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
	printToxy(50,3,"MENU PENARIKAN CEPAT");
	printToxy(44,4,"SILAHKAN PILIH JUMLAH PENARIKAN");
	printToxy(43,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(18,9,"Rp. 250.000,00");
	printToxy(7,13,"[2] =>");
	printToxy(18,13,"Rp. 500.000,00");
	printToxy(7,17,"[3] =>");
	printToxy(18,17,"Rp. 1.000.000,00");
	printToxy(105,9,"<= [4]");
	printToxy(83,9,"Rp. 1.250.000,00");
	printToxy(105,13,"<= [5]");
	printToxy(83,13,"Jumlah Lain");
	printToxy(105,17,"<= [6]");
	printToxy(83,17,"Menu Lainnya");
	printToxy(60,24,"\t Masukan pilihan anda :  ");
}

void displayTransaksiBerhasil(){
	header();
	printToxy(52,3,"DETAIL TRANSAKSI");
	printToxy(43,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	printToxy(95,13,"YA");
	printToxy(92,17,"TIDAK");
	printToxy(51,7,"TRANSAKSI BERHASIL");
	printToxy(40,11,"APAKAH ANDA INGIN MELANJUTKAN TRANSAKSI ?");
	printToxy(60,24,"\t Masukan pilihan anda :  ");
}

void displayTransaksiGagal(){
	header();
	printToxy(52,3,"DETAIL TRANSAKSI");
	printToxy(43,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	printToxy(95,13,"YA");
	printToxy(92,17,"TIDAK");
	printToxy(52,8,"TRANSAKSI GAGAL");
	printToxy(48,9,"PASTIKAN SALDO ANDA CUKUP");
	printToxy(40,11,"APAKAH ANDA INGIN MELANJUTKAN TRANSAKSI ?");
	printToxy(60,24,"\t Masukan pilihan anda :  ");
}

void displayTransaksiGagallimit(){
	header();
	printToxy(52,3,"DETAIL TRANSAKSI");
	printToxy(43,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	printToxy(95,13,"YA");
	printToxy(92,17,"TIDAK");
	printToxy(53,8,"TRANSAKSI GAGAL");
	printToxy(42,9,"ANDA TELAH MELEWATI LIMIT BATAS PENARIKAN");
	printToxy(42,11,"APAKAH ANDA INGIN MELANJUTKAN TRANSAKSI ?");
	printToxy(60,24,"\t Masukan pilihan anda :  ");
}

void displayMenuJumlahLain(){
	header();
	printToxy(51,3,"SILAHKAN MASUKKAN");
	printToxy(47,4,"JUMLAH YANG INGIN DI TARIK ");
	printToxy(43,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(19, 17,"CANCEL");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	printToxy(92,17,"SALAH");
	printToxy(48,10,"Rp.");
	printToxy(92,13,"BENAR");
	printToxy(60,24,"\t Masukan pilihan anda :  ");
}

void displayLoading(){
	header();
	printToxy(51,3,"HARAP TUNGGU PROSES ");
	printToxy(48,4,"TRANSAKSI SEDANG BERLANGSUNG  ");
	printToxy(45,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(40,13,"TERIMA KASIH TELAH BERTRANSAKSI DENGAN KAMI");
	printToxy(105,17,"<= [6]");
}

void displayEnd(){
  	header();
	printToxy(55,3,"BANK RAKYAT");
	printToxy(45,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(44,10,"TERIMA KASIH TELAH MEMERCAYAI KAMI");
	printToxy(43,11,"SEBAGAI PARTNER ANDA DALAM PERBANKAN ");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
}

void displayMenuLainnya(){
	header();
	printToxy(52,3,"PILIH TRANSAKSI");
	printToxy(51,4,"YANG ANDA INGINKAN");
	printToxy(43,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(18,9,"TRANSFER");
	printToxy(7,13,"[2] =>");
	printToxy(18,13,"PEMBAYARAN/PEMBELIAN");
	printToxy(7,17,"[3] =>");
	printToxy(18,17,"INFORMASI SALDO");
	printToxy(105,9,"<= [4]");
	printToxy(84,9,"UBAH PIN");
	printToxy(105,13,"<= [5]");
	printToxy(84,13,"MUTASI REKENING");
	printToxy(105,17,"<= [6]");
	printToxy(84,17,"MENU SEBELUMNYA");
	printToxy(60,24,"\t Masukan pilihan anda :  ");
}

void displayMenuTransfer(){
	header();
	printToxy(44,3,"MASUKKAN NOMOR REKENING TUJUAN");
	printToxy(43,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(49,8,"_ _ _ _ _ _ _ _ _ _ _");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(90,9,"BENAR");
	printToxy(105,13,"<= [5]");
	printToxy(90,13,"SALAH");
	printToxy(105,17,"<= [6]");
	printToxy(60,24,"\t Masukan pilihan anda :  ");
	
 	
}

 void displayProsesTransfer(){
	header();
	printToxy(48,3,"MASUKKAN JUMLAH NOMINAL");
	printToxy(49,4,"YANG AKAN DITRANSFER ");
	printToxy(43,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(52,8,"RP. ");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(90,9,"BENAR");
	printToxy(105,13,"<= [5]");
	printToxy(90,13,"SALAH");
	printToxy(105,17,"<= [6]");
	printToxy(60,24,"\t Masukan pilihan anda :  ");

}

void displaytransfergagal(){
	header();
	printToxy(53,3,"MAAF TRANSFER GAGAL");
	printToxy(40,4,"NO REKENING/SALDO ANDA SALAH/TIDAK MENCUKUPI ");
	printToxy(45,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(50,13,"PASTIKAN SALDO ANDA CUKUP ");
	printToxy(42,14,"DAN NO REKENING YANG ANDA MASUKKAN BENAR ");
	printToxy(105,17,"<= [6]");
	printToxy(90,17,"EXIT");
	printToxy(60,24,"\t Masukan pilihan anda :  ");
	
}

void displaygoodtransfer(){
   header();
	printToxy(50,3,"TRANSAKSI TELAH SELESAI");
	printToxy(49,4,"PERLU TRANSAKSI YANG LAIN ?");
	printToxy(45,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(90,13,"YA");
	printToxy(105,17,"<= [6]");
	printToxy(90,17,"TIDAK");
	printToxy(60,24,"\t Masukan pilihan anda :  ");
 
 }

void displaykonfirmasitrf(int nominal){
 	header();
 	printToxy(52,3,"KONFIRMASI TRANSFER");
	printToxy(43,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	printToxy(95,13,"YA");
	printToxy(92,17,"TIDAK");
	printToxy(50,9,"BANK       :");
 	printf ("%s", penerima.Bank);
	printToxy(50,10,"TUJUAN     :");
	printf ("%s", penerima.No_Rekening);
	printToxy(50,11,"NAMA       :");
	printf ("%s", penerima.Nama);
	printToxy(50,12,"JUMLAH     :");
	printf ("%d", nominal);
	printToxy(50,13,"ADMIN BANK :");
	printf ("%d", admin);
	printToxy(50,14,"TOTAL      :");
	printf ("%d", nominal+admin);
	printToxy(60,24,"\t Masukan pilihan anda :  ");

 }
 
