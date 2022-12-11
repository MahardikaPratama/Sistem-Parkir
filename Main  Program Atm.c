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
	char Bank[4];
	int total_saldo;
}Nasabah;

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
	
void bacaPin(char inputPin[6]); 
/*Prosedur untuk membaca input PIN
	I.S: Input PIN belum dibaca
	F.S: Input PIN sudah dibaca
	*/
int Cek_validitas(int *Valid, char inputPin[6]); 
/*Fungsi untuk mengembalikan nilai Valid jika pin yang di Input Benar atau Salah
	*/
	
void MenuPenarikanCepat(); 
/* Prosedur untuk modul fitur Penarikan Cepat
	I.S: Belum menampilkan menu fitur Penarikan Cepat
	F.S: Sudah menampilkan menu fitur Penarikan Cepat
	*/
int validitasTransaksi(int jumlah);
/* Fungsi untuk mengembalikan nilai Valid jika jumlah transaksi sesuai dengan aturan yaitu saldo sisa transaksi >= Rp.10000 dan limit penarikan<= Rp.10000000
	*/
void MenuJumlahLain(); 
/* Prosedur untuk menu fitur Jumlah Lain
	I.S: Belum menampilkan menu fitur MenuJumlahLain
	F.S: Sudah menampilkan menu fitur MenuJumlahLain
	*/
void bacaJumlahLain(int *nominal); 
/*Prosedur untuk membaca input jumlah nominal yang akan ditarik
	I.S: Input jumlah nominal belum dibaca
	F.S: Input jumlah nominal sudah dibaca
	*/

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
/* Prosedur untuk membaca jumlah nominal transfer
	I.S: Jumlah nominal transfer belum diketahui
	F.S: Jumlah nominal transfer sudah diketahui
	*/
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

void Menu_setor();
/* Prosedur untuk modul fitur Setor Tunai
	I.S: Belum menampilkan modul fitur Setor Tunai
	F.S: Sudah menampilkan modul fitur Setor Tunai
	*/
	
int cekvalid_setor(int *betul, int nominal);	
/* Fungsi untuk cek validasi dari nominal setor yang diinput apakah benar atau salah
	*/
void bacasetorlagi();
/*prosedur untuk menampilkan pilihan setor lagi atau tidak
I.S : Tampilan untuk pilihan setor lagi atau tidak belum tercetak
F.S : Tampilan untuk pilihan setor lagi atau tidak sudah tercetak
*/

void MenuInformasiSaldo();
/* Prosedur untuk mencakup modul dari fitur Menu Informasi Saldo
	I.S: Belum menampilkan fitur Menu Informasi Saldo
	F.S: Sudah menampilkan fitur Menu Informasi Saldo
	*/
	

void MenuUbahPin();
/* Prosedur untuk mencakup modul dari fitur Menu Ubah PIN
	I.S: Belum menampilkan fitur Menu Ubah PIN
	F.S: Sudah menampilkan fitur Menu Ubah PIN
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
/*Fungsi untuk mengembalikan nilai Valid jika pin yang di Input Benar atau Salah
	*/
	
void MasukkanPinBaru();
/* Prosedur untuk mencakup perintah menginput PIN Baru
	I.S: Belum menginput dan cek validitas PIN Baru
	F.S: Sudah menginput dan cek validitas PIN Baru
	*/

void mutasiRekening();
/* Prosedur untuk menu fitur mutasi rekening
	I.S: Menu fitur mutasi rekening belum ditampilkan
	F.S: Menu fitur mutasi rekening sudah ditampilkan
	*/
	
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

void displayInformasiSaldo();
/*prosedur untuk menampilkan tampilan Informasi Saldo
I.S : Tampilan untuk Informasi Saldo belum tercetak
F.S : Tampilan untuk Informasi Saldo sudah tercetak
*/

void displayUbahPinLama();
/*prosedur untuk menampilkan tampilan meminta input pin lama
I.S : Tampilan untuk tampilan meminta input pin lama belum tercetak
F.S : Tampilan untuk tampilan meminta input pin lama sudah tercetak
*/

void displayMenuSetor();
/*prosedur untuk menampilkan menu setor tunai
I.S : Tampilan untuk menu setor tunai belum tercetak
F.S : Tampilan untuk menu setor tunai sudah tercetak
*/


void displaysetorberhasil();
/*prosedur untuk menampilkan setoran berhasil
I.S : Tampilan untuk setoran berhasil belum tercetak
F.S : Tampilan untuk setoran berhasil sudah tercetak
*/

void displayPinBaru();
/*prosedur untuk menampilkan tampilan meminta input pin baru
I.S : Tampilan untuk tampilan meminta input pin baru belum tercetak
F.S : Tampilan untuk tampilan meminta input pin baru sudah tercetak
*/

void displaySalahMengubahPin();
/*prosedur untuk menampilkan pin yang dimasukkan salah
I.S : Tampilan untuk pin yang dimasukkan salah belum tercetak
F.S : Tampilan untuk pin yang dimasukkan salah sudah tercetak
*/

void displayUbahPinBerhasil();
/*prosedur untuk menampilkan berhasil mengubah pin
I.S : Tampilan untuk berhasil mengubah pin belum tercetak
F.S : Tampilan untuk berhasil mengubah pin sudah tercetak
*/

void displayUbahPinGagal();
/*prosedur untuk menampilkan berhasil mengubah pin
I.S : Tampilan untuk gagal mengubah pin belum tercetak
F.S : Tampilan untuk gagal mengubah pin sudah tercetak
*/

void displaykonfirmasiPin();
/*prosedur untuk menampilkan permintaan konfirmasi pin baru
I.S : Tampilan untuk permintaan konfirmasi pin baru belum tercetak
F.S : Tampilan untuk permintaan konfirmasi pin baru sudah tercetak
*/

void displayMutasi();
/*prosedur untuk menampilkan riwayat mutasi rekening
I.S : Tampilan untuk riwayat mutasi rekening belum tercetak
F.S : Tampilan untuk riwayat mutasi rekeningpermintaan konfirmasi pin baru sudah tercetak
*/

//Deklarasi variabel Global
Nasabah user = {.No_Rekening = "221524044",.Nama = "Mahardika",.Pin = "123456",.Bank = "BCA",.total_saldo = 20000000};
// variable global user dengan tipe data nasabah berjenis record
Nasabah penerima = {.No_Rekening = "221524057", .Nama = "Reza", .Bank = "BRI", .total_saldo = 500000}; 
// variable global penerima dengan tipe data nasabah berjenis record
FILE *mutasi;
// variabel file manipulation untuk mutasi rekening
int i; //variabel counter
int opsi; //variabel untuk memilih input
int benar; //variabel untuk validasi
int nominal; //variabel nominal uang
int limitSetor = 0, limitTarik = 0, limittrf = 0; //variabel menentukan limit transaksi
int admin=3000; // variabel biaya admin
char No_Rek[21]; // variabel input No.Rekening
char inputPin[6]; // variabel input pin
char inputPinBaru[7]; // variabel input pin baru
char konfirmasiPin[7]; // variabel konfirmasi pin
unsigned int sleep (unsigned int seconds); // variabel sleep untuk mengatur waktu loading


/*Algoritma*/

//Main Program
int main(){
	system ("color 1F"); //syntak untuk mengubah warna di cmd
	MenuBahasa(); // Memamnggil modul bahasa
}

//Modul Bahasa
void MenuBahasa(){
	KEMBALI:
	system("cls");
	displayMenuBahasa();	
    scanf("%d",&opsi);
    switch(opsi){
    	case 4: system ("cls");
    			bahasaIndonesia();  //Memanggil modul bahasa indonesia
    			break;
//   	case 5: system ("cls");		
//    			bahasaInggris();	//Tidak keburu
//    			break;
    	default :
        	goto KEMBALI;
    }
}

//Modul Bahasa Indonesia
void bahasaIndonesia(){
	benar = 0;
	i = 1;
	displayMenuPinId(); //Memanggil modul menu pin
	while(benar == 0 && i<=3){
		bacaPin(inputPin); //Memanggil modul baca pin
		Cek_validitas(&benar, inputPin); //Memanggil modul cek validitas pin
	}
	if (benar == 1){
		MenuPenarikanCepat(); //Memanggil modul penarikan cepat
	}
}

//Modul baca pin
void bacaPin(char inputPin[6]){
	gotoxy(53, 13);
    for(int i = 0; i < 6; i++){
        inputPin[i] = _getch();
        putchar('*');
        putchar(' ');
    }
}

//Modul cek validitas pin
int Cek_validitas(int *Valid, char inputPin[6]){
	if((strcmp(inputPin, user.Pin)==0)){
		*Valid = 1;
	}
	else if(i<3){
		*Valid = 0;
		i = i + 1;
		system("cls");
		displaySalahPin(); //Memanggil modul displaySalahPin();
	}
	else{
		system("cls");
		displayAkunTerblokir(); //Memanggil modul displayAkunTerblokir();
		sleep(5);
		exit(0);
	}
	return *Valid;
}

//Modul Menu Penarikan Cepat
void MenuPenarikanCepat(){
	char konfirmasi;
	
	KEMBALI:
	system("cls");
	displayMenuPenarikanCepat(); //Memanggil modul displayMenuPenarikanCepat();
	benar=0;
	scanf("%d", &opsi);
	switch(opsi){
		case 1: 
				nominal = 250000;
				limitTarik = limitTarik + nominal;
				benar = validitasTransaksi(nominal); //Memanggil modul validitasTransaksi
				if (benar == 1){
					user.total_saldo = user.total_saldo - nominal;
					system("cls");
					displayLoading(); //Memanggil modul displayLoading();
					sleep(5);
					system("cls");
					displayTransaksiBerhasil(); //Memanggil modul displayTransaksiBerhasil();
					gotoxy(49,9);
					printf("SISA SALDO ANDA: %d",user.total_saldo);
					
					//Membuka file untuk mutasi rekening
					mutasi=fopen("Daftar Mutasi.txt","a");
    				gotoxy(53,16);
					fprintf(mutasi,"\n\nPenarikan\n-Rp. %d", nominal);
    				fclose(mutasi); //Menutup file
    				
					GO:
					gotoxy(88, 24);
					konfirmasi = getch();
					switch(konfirmasi){
						case '5' : goto KEMBALI;
								break;
						case '6' : 	system("cls");
									displayEnd(); //Memanggil modul displayEnd();
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
							case '5' : goto KEMBALI;
									break;
							case '6' : 	system("cls");
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
							case '5' : goto KEMBALI;
									break;
							case '6' : 	system("cls");
										displayEnd();
										sleep(5);
										exit(0);
							default:
								goto GO3;
						}
					}
				}
				break;
		case 2: system("cls");
				nominal = 500000;
				limitTarik = limitTarik + nominal;
				benar = validitasTransaksi(nominal);
				if (benar == 1){
					user.total_saldo = user.total_saldo - nominal;
					displayLoading();
					sleep(5);
					system("cls");
					displayTransaksiBerhasil();
					gotoxy(49,9);
					printf("SISA SALDO ANDA: %d",user.total_saldo);
				
					mutasi=fopen("Daftar Mutasi.txt","a");
    				fprintf(mutasi,"\n\nPenarikan\n-Rp. %d", nominal);
    				fclose(mutasi);
				
					GO4:
					gotoxy(88, 24);
					konfirmasi = getch();
					switch(konfirmasi){
						case '5' : goto KEMBALI;
								break;
						case '6' : 	system("cls");
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
							case '5' : goto KEMBALI;
									break;
							case '6' : 	system("cls");
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
							case '5' : goto KEMBALI;
									break;
							case '6' : 	system("cls");
										displayEnd();
										sleep(5);
										exit(0);
							default:
								goto GO6;
						}
					}
				}
				break;
		case 3:	system("cls");
				nominal = 1000000;
				limitTarik = limitTarik + nominal;
				benar = validitasTransaksi(nominal);
				if (benar == 1){
					user.total_saldo = user.total_saldo - nominal;
					displayLoading();
					sleep(5);
					system("cls");
					displayTransaksiBerhasil();
					gotoxy(49,9);
					printf("SISA SALDO ANDA: %d",user.total_saldo);
					
					mutasi=fopen("Daftar Mutasi.txt","a");
    				fprintf(mutasi,"\n\nPenarikan\n-Rp. %d", nominal);
    				fclose(mutasi);
					
					GO7:
					gotoxy(88, 24);
					konfirmasi = getch();
					switch(konfirmasi){
						case '5' : goto KEMBALI;
								break;
						case '6' : 	system("cls");
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
							case '5' : goto KEMBALI;
									break;
							case '6' : 	system("cls");
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
							case '5' : goto KEMBALI;
									break;
							case '6' : 	system("cls");
										displayEnd();
										sleep(5);
										exit(0);
							default:
								goto GO9;
						}
					}
				}
				break;
		case 4: system("cls");
				nominal = 1250000;
				limitTarik = limitTarik + nominal;
				benar = validitasTransaksi(nominal);
				if (benar == 1){
					user.total_saldo = user.total_saldo - nominal;
					displayLoading();
					sleep(5);
					system("cls");
					displayTransaksiBerhasil();
					gotoxy(50,16);
					printf("SISA SALDO ANDA: %d",user.total_saldo);
					
					mutasi=fopen("Daftar Mutasi.txt","a");
    				fprintf(mutasi,"\n\nPenarikan\n-Rp. %d", nominal);
    				fclose(mutasi);
				
					GO10:
					gotoxy(88, 24);
					konfirmasi = getch();
					switch(konfirmasi){
						case '5' : goto KEMBALI;
								break;
						case '6' : 	system("cls");
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
							case '5' : goto KEMBALI;
									break;
							case '6' : 	system("cls");
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
							case '5' : goto KEMBALI;
									break;
							case '6' : 	system("cls");
										displayEnd();
										sleep(5);
										exit(0);
							default:
								goto GO12;
						}
					}
				}
				break;
		case 5: system("cls");
				MenuJumlahLain(); //Memanggil Modul MenuJumlahLain();
				break;
		case 6: MenuLainnya(); //Memanggil Modul MenuLainnya();
				break;
				
		default:
			goto KEMBALI;
	}
}

//Modul Jumlah Lain
void MenuJumlahLain(){
	char konfirmasi;
	
	BACK:
	system("cls");
	displayMenuJumlahLain(); //Memanggil modul untuk tampilan menu jumlah lain
	bacaJumlahLain(&nominal); //Memanggil modul untuk membaca inputan nominal lain
	gotoxy(88,24);
	scanf("%d", &opsi);
	if (opsi == 5){
		if(nominal % 50000 == 0 ){
			limitTarik = limitTarik + nominal;
			benar = validitasTransaksi(nominal);
			if (benar == 1){
				user.total_saldo = user.total_saldo - nominal;
				system("cls");
				displayLoading();
				sleep(5);
				system("cls");
				displayTransaksiBerhasil();
				gotoxy(49,9);
				printf("SISA SALDO ANDA: %d",user.total_saldo);
					
				mutasi=fopen("Daftar Mutasi.txt","a");
    			fprintf(mutasi,"\n\nPenarikan\n-Rp. %d", nominal);
    			fclose(mutasi);
				
				GO13:
				gotoxy(88, 24);
				konfirmasi = getch();
				switch(konfirmasi){
					case '5' : MenuPenarikanCepat();
								break;
					case '6' : 	system("cls");
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
						case '5' : MenuPenarikanCepat();
								break;
						case '6' : 	system("cls");
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
						case '5' : MenuPenarikanCepat();
								break;
						case '6' : 	system("cls");
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
		MenuPenarikanCepat(); //Memanggil modul menu penarikan cepat
	}
}

//Modul Validitas Transaksi
int validitasTransaksi(int jumlah){
	int isValid;
	
	if (user.total_saldo - jumlah >= 10000 && limitTarik <= 10000000){
		isValid = 1;
	}
	else {
		isValid = 0;
	}
	return isValid;
}

//Modul baca inputan nominal lain
void bacaJumlahLain(int *nominal){	
	gotoxy(52, 10);
	scanf("%d", nominal);
}

//Modul Menu Lainnya
void MenuLainnya(){
	system("cls");
	displayMenuLainnya(); //Memanggil modul display menu lainnya
	KEMBALI:
    scanf("%d",&opsi);
    switch(opsi){
    	case 1: MenuTransfer(); //Memanggil modul menu untuk transfer
    			break;
    	case 2: Menu_setor(); //Memanggil modul menu untuk setor tunai
    			break;
    	case 3: MenuInformasiSaldo(); //Memanggil modul menu untuk melihat informasi saldo
    			break;
    	case 4: MenuUbahPin(); //Memanggil modul menu untuk ubah pin
    			break;
    	case 5: mutasiRekening(); //Memanggil modul menu untuk melihat mutasi rekening
    			break;
    	case 6: MenuPenarikanCepat(); //Memanggil modul menu sebelumnya yaitu penarikan cepat
    			break;
    	default :
    			MenuLainnya(); //Memanggil modulnya sendiri jika default
    }
}

// Modul Menu Transfer
void MenuTransfer(){
 	char konfirmasi;
	benar = 0;
 	int Sama = 0;
    
 	system("cls");
 	displayMenuTransfer(); //Memanggil modul untuk menampilkan display menu transfer
 	gotoxy(55,7);
 	gets (No_Rek);
	cek_ValiditasNorek(&Sama); //Memanggil modul untuk validasi No.Rekening tujuan
	if(Sama==1){
 		gotoxy(90,24);
		scanf("%d",&opsi);
		switch(opsi){
			case 4 : 
		    	    system("cls");
		        	displayProsesTransfer(); //Memanggil modul untuk menampilkan display proses transfer
		    		gotoxy(56,8);
             		scanf("%d", &nominal);
             		limittrf = limittrf + nominal; //Assignment untuk batas limit transfer
					cek_ValiditasTransfer( &benar); //Memanggil modul untuk validasi Nominal Transfer
		        	if (benar==1){
             			if (nominal>=50000){
             				user.total_saldo=user.total_saldo-nominal-admin;
             				system("cls");
             				displaykonfirmasitrf(nominal); //Memanggil modul untuk menampilkan display konfirmasi transfer
             				konfirmasitrf(); //Memanggil modul untuk konfirmasi Transfer
             				
							//Membuka file untuk mutasi transfer 
							mutasi=fopen("Daftar Mutasi.txt","a");
    						fprintf(mutasi,"\n\nTransfer\n%s\n%s\n-Rp. %d\n", user.Bank, user.No_Rekening, nominal);
    						fclose(mutasi);
    						//Tutup File
             				system("cls");
             				displaygoodtransfer(); //Memanggil modul untuk menampilkan transfer berhasil
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

//Modul cek validitas no.rekening
int cek_ValiditasNorek(int *Betul){
	if((strcmp(No_Rek, penerima.No_Rekening)==0)&&user.total_saldo-nominal>=10000&&limittrf <=10000000){
     	*Betul=1;
 	}
    else {
		*Betul=0;
	}
	return *Betul;
 }
//Modul cek validitas nominal transfer
int cek_ValiditasTransfer(int *Betul){
    if(user.total_saldo-nominal>=10000&&limittrf <=10000000){
     	*Betul=1;
    }
   	else {
		*Betul=0;
	}
	return *Betul;	
 }

//Modul Konfirmasi Transfer
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
 
 //Modul transaksi lainnya
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

//Modul Setor Tunai
void Menu_setor(){
	benar = 0;
	
	system("cls");
	displayMenuSetor();
	gotoxy(54,13);
	scanf("%d", &nominal);
	cekvalid_setor(&benar, nominal);
	if(benar==1){
		user.total_saldo = user.total_saldo + nominal;
		system("cls");
		displayLoading();
		sleep(5);
		system("cls");
		displaysetorberhasil();
		
		//Membuka file untuk mutasi setor
		mutasi=fopen("Daftar Mutasi.txt","a");
    	fprintf(mutasi,"\n\nSetor Tunai \n+Rp. %d", nominal);
    	fclose(mutasi);
		//Tutuf file
		
		gotoxy(60,13);
		printf("%d", user.total_saldo);
		bacasetorlagi();	
	}
	else {
		if (nominal%50000!=0){
		 	Menu_setor();
		}
		if (limitSetor>5000000){
			system("cls");
			displayLoading();
			sleep(5);
			system("cls");
			displayTransaksiGagallimit();
			bacasetorlagi();
		}
		 
	}
}

//Modul cek validitas nominal setor
int cekvalid_setor(int *betul, int nominal){
	limitSetor = limitSetor + nominal;
	if(nominal % 50000 == 0 && limitSetor <= 5000000){
		*betul=1;
 	   	}
 	   else {
		*betul=0;
		}
	return *betul;
}

//Modul setor lagi
void bacasetorlagi(){
	gotoxy(92,24);
	scanf("%d", &opsi);
	switch (opsi){
		case 5 : 
		       MenuLainnya();
		       break;
		case 6 : 
				system("cls");
				displayEnd();
				sleep(5);
				exit(0);
	    		break;
	    default: bacasetorlagi();
	}
}

//Modul Informasi Saldo
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
		default : MenuInformasiSaldo();
	}
}

//Modul Ubah Pin
void MenuUbahPin(){
	UbahPinLama(); //Memanggil modul UbahPinLama();
}

void UbahPinLama(){
	benar = 0;
	system("cls");
	displayUbahPinLama();
	while(benar == 0 && i<=3){
		bacaPin(inputPin);
		Cek_validitas(&benar, inputPin);
	}
	if (benar == 1){
		MasukkanPinBaru();
	}
}

void MasukkanPinBaru(){

	benar = 0;
	system("cls");
	displayPinBaru();
	gotoxy(53, 11);
    for(int i = 0; i < 6; i++){
        inputPinBaru[i] = _getch();
        putchar('*');
        putchar(' ');
    }
    	i = 1;
    system("cls");
	displaykonfirmasiPin();
	while(benar == 0 && i<=3){
		bacaKonfirmasiPinBaru(konfirmasiPin); //Modul untuk baca konfirmasi pin baru
		Cek_validitasPinBaru(&benar, inputPinBaru, konfirmasiPin); //Modul untuk mengonfirmasi pin baru
	}
	if (benar == 1){
		PINBERHASIL:
		system("cls");
		displayLoading();
		sleep(5);
		system("cls");
		displayUbahPinBerhasil();
		scanf("%d", &opsi);
		switch (opsi){
			case 5: system("cls");
					MenuLainnya();	
					break;
			case 6: system("cls");
					displayEnd();
					sleep(5);
					exit(0);
			default:
				goto PINBERHASIL;
		}
	}
}

//Modul Baca konfirmasi pin baru
void bacaKonfirmasiPinBaru(char konfirmasiPin[7]){
	system("cls");
	displaykonfirmasiPin();
	gotoxy(53, 11);
    for(int i = 0; i < 6; i++){
        konfirmasiPin[i] = _getch();
        putchar('*');
        putchar(' ');
    }
}
//Modul validasi pin baru
int Cek_validitasPinBaru(int *benar, char inputPinBaru[7], char konfirmasiPin[7]){
	if(strcmp(inputPinBaru,konfirmasiPin)==0){
		strcpy(user.Pin, inputPinBaru);
		strcpy(inputPin, inputPinBaru);
    	*benar=1;
	}
	else if(i<3){
		*benar = 0;
		i = i + 1;
		system("cls");
		displaySalahMengubahPin();
	}
	else{
		PINGAGALBARU:
		system("cls");
		displayUbahPinGagal();
		scanf("%d", &opsi);
		switch (opsi){
			case 5: MenuLainnya();
					break;
			case 6: system("cls");
					displayEnd();
					sleep(5);
					exit(0);
			default:
				goto PINGAGALBARU;
		}
	}
	return *benar;
}

//Modul Mutasi Rekening
void mutasiRekening(){
	i = 4;
	system("cls");
    FILE *mutasi=fopen("Daftar Mutasi.txt","r");
    char Buffer[255];
    system("cls");
    displayMutasi();
	while(fgets(Buffer, 255, mutasi )){
    	gotoxy(20,i);
    	printf("\t\t%s\n", Buffer);
    	i = i+1;
	}
    fclose(mutasi);
    gotoxy(88,24);
	scanf("%d", &opsi);
	switch (opsi){
		case 5: MenuLainnya();
				break;
		case 6: system("cls");
				displayEnd();
				sleep(5);
				exit(0);
		default:
				mutasiRekening();
	}
}


//Prosedur Display

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
	printToxy(18,13,"SETOR TUNAI");
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
 
 void displaysetorberhasil(){
    header();
	printToxy(53,3,"PENYETORAN BERHASIL ");
	printToxy(45,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(34,13,"SALDO ANDA SAAT INI : ");
	printToxy(7,17,"[3] =>");
	printToxy(53,17,"SETOR LAGI ?");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(94,13,"YA");
	printToxy(105,17,"<= [6]");
	printToxy(94,17,"TIDAK");
	printToxy(60,24,"\t Masukan pilihan anda :  ");
	
}

 void displayLoading(){
	header();
	printToxy(52,3,"HARAP TUNGGU PROSES ");
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

void displayUbahPinLama(){
	header();
	printToxy(52,3,"PERUBAHAN PIN");
	printToxy(43,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	printToxy(53,14,"_ _ _ _ _ _");
	printToxy(51,8,"MASUKKAN 6 DIGIT");
	printToxy(52,9,"PIN LAMA ANDA");
	printToxy(60,24,"\t Masukan pilihan anda :  ");
}

void displayPinBaru(){
	header();
	printToxy(52,3,"PERUBAHAN PIN");
	printToxy(43,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	printToxy(53,12,"_ _ _ _ _ _");
	printToxy(51,8,"MASUKKAN 6 DIGIT");
	printToxy(52,9,"PIN BARU ANDA");
}

void displayUbahPinBerhasil(){
	header();
	printToxy(52,3,"PERUBAHAN PIN");
	printToxy(43,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	printToxy(52,12,"TRANSAKSI LAGI ?");
	printToxy(51,8,"UBAH PIN BERHASIL");
	printToxy(90,13,"YA");
	printToxy(90,17,"TIDAK");
	printToxy(60,24,"\t Masukan pilihan anda :  ");
}

void displayUbahPinGagal(){
	header();
	printToxy(52,3,"PERUBAHAN PIN");
	printToxy(43,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	printToxy(48,8,"ANDA TELAH 3(KALI) SALAH");
	printToxy(52,9,"MEMASUKKAN PIN");
	printToxy(51,6,"GAGAL MENGUBAH PIN");
	printToxy(50,11,"LANJUTKAN TRANSAKSI ?");
	printToxy(90,13,"YA");
	printToxy(90,17,"TIDAK");
	printToxy(60,24,"\t Masukan pilihan anda :  ");
}

void displaySalahMengubahPin(){
	header();
	printToxy(52,3,"PIN ANDA SALAH ");
	printToxy(47,4,"SILAKAN MASUKKAN KEMBALI ");
	printToxy(49,5,"NOMOR PIN YANG BENAR ");
	printToxy(43,6,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(53,12,"_ _ _ _ _ _");
	printToxy(47,16,"ANDA AKAN DIKELUARKAN");
	printToxy(43,17,"BILA ANDA SALAH PIN 3(TIGA) KALI");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
}

void displaykonfirmasiPin(){
	header();
	printToxy(47,3,"KONFIRMASI PERUBAHAN PIN");
	printToxy(43,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	printToxy(53,12,"_ _ _ _ _ _");
	printToxy(51,8,"MASUKKAN KEMBALI");
	printToxy(52,9,"PIN BARU ANDA");
}

void displayMenuSetor(){
  header();
	printToxy(50,3,"SILAKAN MASUKAN JUMLAH ");
	printToxy(49,4,"NOMINAL YANG AKAN DISETOR");
	printToxy(45,5,"=================================");
	printToxy(37,7,"HARAP MASUKKAN NOMINAL DENGAN KELIPATAN Rp. 50000");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(34,13,"NOMINAL SETOR : Rp. ");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
}

void displayMutasi(){
	header();
	printToxy(55,3,"Daftar Mutasi");
	printToxy(45,5,"=================================");
	printToxy(2,9,"[1] =>");
	printToxy(2,13,"[2] =>");
	printToxy(2,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	printToxy(57,12,"INGIN TRANSAKSI LAGI ?");
	printToxy(90,13,"YA");
	printToxy(90,17,"TIDAK");
	printToxy(60,24,"\t Masukan pilihan anda :  ");
}
