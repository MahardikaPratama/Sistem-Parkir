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
/*Prosedur untuk memilih bahasa antara bahasa Indonesia dan Inggris
	I.S: Bahasa belum dipilih
	F.S: Bahasa sudah dipilih
	*/
void bahasaIndonesia(); 
/* Prosedur tampilan menu dengan menggunakan bahasa Indonesia
	I.S: Tampilan menu belum menggunakan bahasa Indonesia
	F.S: Tampilan menu sudah menggunakan bahasa Indonesia
	*/
void bahasaInggris();
/*Prosedur tampilan menu dengan menggunakan bahasa Inggris
	I.S: Tampilan menu belum menggunakan bahasa Inggris
	F.S: Tampilan menu sudah menggunakan bahasa Inggris
	*/
void bacaPin(char inputPin[6]); 
/*Prosedur untuk membaca input PIN
	I.S: Input PIN belum dibaca
	F.S: Input PIN sudah dibaca
	*/
int Cek_validitas(int *Valid, char inputPin[6]); 
/*Fungsi untuk cek validasi PIN yang diinput apakah benar atau salah
	*/
void MenuPenarikanCepat(); 
/* Prosedur untuk modul fitur Penarikan Cepat
	I.S: Belum menampilkan modul fitur Penarikan Cepat
	F.S: Sudah menampilkan modul fitur Penarikan Cepat
	*/
int validitasTransaksi(int jumlah);
/* Fungsi untuk cek validasi dari jumlah nominal terhadap saldo dan limit penarikan
	*/
void MenuJumlahLain(); 
/* Prosedur untuk modul fitur Jumlah Lain
	I.S: Belum menampilkan modul fitur MenuJumlahLain
	F.S: Sudah menampilkan modul fitur MenuJumlahLain
	*/
void bacaJumlahLain(int *nominal); 
/*Prosedur untuk membaca input jumlah nominal yang akan ditarik
	I.S: Input jumlah nominal belum dibaca
	F.S: Input jumlah nominal sudah dibaca
	*/
void PenarikanCepat(); //
void MenuLainnya(); 
/*Prosedur untuk modul fitur Menu Lainnya
	I.S: Belum menampilkan modul fitur Menu Lainnya
	F.S: Sudah menampilkan modul fitur Menu Lainnya
	*/
void MenuTransfer(); 
/* Prosedur untuk mencakup modul fitur Menu Transfer
	I.S: Belum menampilkan modul fitur Menu Transfer
	F.S: Sudah menampilkan modul fitur Menu Transfer
	*/
void bacaJumlahTrf();
void konfirmasitrf();
/* Prosedur konfirmasi menampilkan data validitas transaksi transfer
	I.S: Belum menampilkan data validitas transaksi transfer
	F.S: Sudah menampilkan data validitas transaksi transfer
	*/
void MenuKonfirmasi(); 
/* Prosedur konfirmasi dari proses transfer 
	I.S: Belum konfirmasi transfer
	F.S: Sudah konfirmasi transfer dengan ke menu selanjutnya
	*/
int cek_ValiditasNorek(int *Betul);
/* Fungsi untuk cek validasi dari No Rekening yang diinput apakah benar atau salah
	*/
int cek_ValiditasTransfer(int *Betul);
/* Fungsi untuk cek validasi dari jumlah nominal yang ingin ditransfer terhadap saldo dan limit transfer
	*/
void MenuPembayaran();
/* Prosedur untuk mencakup modul fitur Menu Pembayaran
	I.S: Belum menampilkan modul fitur Menu Transfer
	F.S: Sudah menampilkan modul fitur Menu Transfer
	*/
void MenuInformasiSaldo();
/* Prosedur untuk mencakup modul dari fitur Menu Informasi Saldo
	I.S: Belum menampilkan modul fitur Menu Informasi Saldo
	F.S: Sudah menampilkan modul fitur Menu Informasi Saldo
	*/
void MenuUbahPin();
/* Prosedur untuk mencakup modul dari fitur Menu Ubah PIN
	I.S: Belum menampilkan modul fitur Menu Ubah PIN
	F.S: Sudah menampilkan modul fitur Menu Ubah PIN
	*/
void UbahPinLama();
/* Prosedur yang mencakup perintah menginput PIN Lama
	I.S: Belum menginput dan cek validitas PIN lama
	F.S: Sudah menginput dan cek validitas PIN lama
	*/
void bacaKonfirmasiPinBaru(char konfirmasiPin[7]);
/* Prosedur untuk menginput konfirmasi PIN Baru
	I.S: Input konfirmasi PIN Baru belum dibaca
	F.S: Input konfirmasi PIN Baru sudah dibaca
	*/
int Cek_validitasPinBaru(int *benar, char inputPinBaru[7], char konfirmasiPin[7]);
/* Fungsi untuk cek validasi PIN Baru yang diinput apakah benar atau salah
	*/
void MasukkanPinBaru();
/* Prosedur untuk mencakup perintah menginput PIN Baru
	I.S: Belum menginput dan cek validitas PIN Baru
	F.S: Sudah menginput dan cek validitas PIN Baru
	*/

void MenuMutasi();


void gotoxy(int x, int y);
/*Prosedur ini berfungsi untuk menentukan kordinat pada tampilan atm 
I.S : koordinat untuk menentukan tampilan display belum tebentuk
F.S : koordinat untuk menentukan tampilan dispaly sudah terbentuk
*/
void printToxy(int x, int y, char* label);
/*prosedur untuk menampilkan suatu inputan sesuai koordinat 
I.S : Inputan belum tercetak
F.S : Inputan sudah tercetak
*/
void header();
/*prosedur untuk mencetak dan menampilkan bagian header pada atm  
I.S : Header ATM belum tercetak
F.S : Header ATM sudah terceta
*/
void displayMenuBahasa();
/*prosedur untuk menampilkan tampilan menu pilih bahasa
I.S : Tampilan menu bahasa belum tercetak
F.S : Tampilan menu bahasa sudah tercetak
*/
void displayMenuPinId();
/*prosedur untuk menampilkan tampilan menu pin
I.S : Tampilan menu PIN belum tercetak
F.S : Tampilan menu PIN sudah tercetak
*/
void displaySalahPin();
/*prosedur untuk menampilkan tampilan jika terdapat kesalahan dalam menginput pin
I.S : Tampilan menu pin jika salah belum terbentuk
F.S : Tampilan menu pin jika salah sudah terbentuk
*/
void displayAkunTerblokir();
/*prosedur untuk menampilkan tampilan jika input kesalahan pin lebih dari tiga kali
I.S : Tampilan jika akun terblokir belum tercetak
F.S : Tampilan jika akun terblokir sudah tercetak
*/
void displayMenuPenarikanCepat();
/*prosedur untuk menampilkan tampilan pada menu penarikan cepat
I.S : Tampilan untuk menu penarikan cepat belum tercetak
F.S : Tampilan untuk menu penarikan cepat sudah tercetak
*/
void displayTransaksiBerhasil();
/*prosedur untuk menampilkan tammpilan jika transaksi berhasil
I.S : Tampilan jika transaksi belum tercetak
F.S : Tampilan jika transaksi berhasil sudah tercetak
*/
void displayTransaksiGagal();
/*prosedur untuk menampilkan tampilan jika transaksi gagal
I.S : Tampilan untuk transaksi gagal belum tercetak
F.S : Tampilan untuk transaksi gagal sudah tercetak
*/
void displayTransaksiGagallimit();
/*prosedur untuk menampilkan tampilan jika transaksi melebihi limit batas perhari
I.S : Tampilan transaksi gagal karena limit belum tercetak
F.S : Tampilan transaksi gagal karena limit sudah tercetak
*/
void displayMenuJumlahLain();
/*prosedur untuk menampilkan tampilan jika user ingin menarik uang dalam jumlah lain 
I.S : Tampilan menu jumlah lain belum tercetak
F.S : Tampilan menu jumlah lain sudah tercetak
*/
void displayLoading();
/*prosedur untuk menampilkan jeda loading pada setiap transaksi
I.S : Tampilan jeda loading pada setiap transaksi belum tercetak
F.S : Tampilan jeda loading pada setiap transaksi sudah tercetak
*/
void displayEnd();
/*prosedur untuk menampilkan tampilan ucapan terima kasih pada setiap akhir transaksi 
I.S : Tampilan dispalyEnd belum tercetak
F.S : Tampilan displayEnd sudah tercetak
*/
void displayMenuLainnya();
/*prosedur untuk meampilkan tampilan jumlah lainnya selain dari menu penarikan cepat
I.S : Tampilan menu lainnya belum tercetak
F.S : Tampilan menu lainnya sudah tercetak
*/
void displayMenuTransfer();
/*prosedur untuk menampilkan tampilan menu transfer
I.S : Tampilan menu transfer belum tercetak
F.S : Tampilan menu transfer sudah tercetak
*/
void displayProsesTransfer();
/*prosedur untuk menampilkan tampilan jika proses transfer berlangsung
I.S : Tampilan proses transfer belum tercetak
F.S : Tampilan proses transfer sudah tercetak
*/
void displaytransfergagal();
/*prosedur untuk menampilkan tampilan jika transfer gagal dilakukan
I.S : Tampilan jika transfer gagal belum tercetak
F.S : Tampilan jika transfer gagal sudah tercetak
*/
void displaytransferberhasil();
/*prosedur untuk menampilkan tampilan jika tranfer berhasil dilakukan
I.S : Tampilan jika transfer berhasil belum tercetak
F.S : Tampilan jika transfer berhasil sudah tercetak
*/
void displaykonfirmasitrf(int nominal);
/*prosedur untuk menampilkan tampilan konfirmasi transfer
I.S : Tampilan untuk konfirmasi transfer belum tercetak
F.S : Tampilan untuk konfifmasi transfer sudah tercetak
*/
void displaygoodtransfer();
/*prosedur untuk menampilkan tampilan jika transaksi selesai dan menanyakan kembali apakah user ingin transfer lagi
I.S : Tampilan transaksi selesai belum tercetak
F.S : Tampilan transaksi selesai sudah tercetak
*/
void displayMenuPembayaran();
void displayMenuTeleponHp();
void displayJumlahNominal();
void displayMenuListrik();
void displayMenuPdam();
void displayMenuTvInternet();
void displayInformasiSaldo();
/*prosedur untuk menampilkan tampilan informasi saldo
I.S : Tampilan informasi saldo belum tercetak
F.S : Tampilan informasi saldo sudah tercetak
*/
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
					system("cls");
             				displaygoodtransfer();
             				gotoxy(50,15);
             				printf("SISA SALDO ANDA : %d", user.total_saldo);
             				MenuKonfirmasi();
             				DO:
					gotoxy(88, 24);
					konfirmasi = getch();
					switch(konfirmasi){
						case '5' : 
							MenuLainnya();
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
							MenuLainnya();
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
							MenuLainnya();
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
             		MenuLainnya();
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
	system("color 1F");
	system("cls");
	displayLoading();
	sleep(5);
	system("cls");
	displayInformasiSaldo();
	scanf("%d", &opsi);
	switch (opsi){
		case 5: MenuLainnya();
			break;
		case 6: system("cls");
			displayEnd();
			sleep(5);
			exit(0);
			break;
	}
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
 
void displayInformasiSaldo(){
	header();
	printToxy(49,4,"SALDO REKENING ANDA");
	printToxy(42,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(52,9,"RP. ");
	printf("%d", user.total_saldo);
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	printToxy(92,13,"IYA");
	printToxy(92,17,"TIDAK");
	printToxy(60,24,"\t Masukan pilihan anda :  ");
}
