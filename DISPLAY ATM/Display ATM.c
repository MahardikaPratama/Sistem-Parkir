#include<stdio.h>
#include<windows.h>

//Type Data Bentukan
typedef struct{
	char No_Rekening[10];
   	char Nama[30];
    char Pin[7];
	char Bank[4];
	int total_saldo;
}Nasabah;

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
F.S : Header ATM sudah tercetak
*/

void displayLoginAtm();
/* prosedur untuk menampilkan tampilan Login ATM
I.S : Tampilan Login ATM belum tercetak
F.S : Tampilan Login ATM sudah tercetak
	*/
void displayBacaKartu();
/* prosedur untuk menampilkan tampilan 
	*/

void displayTidakTerdaftar();

void displayMenuBahasa();
/*prosedur untuk menampilkan tampilan menu pilih bahasa
I.S : Tampilan menu bahasa belum tercetak
F.S : Tampilan menu bahasa sudah tercetak
*/
void displayMenuPinId(int bhs);
/*prosedur untuk menampilkan tampilan menu pin
I.S : Tampilan menu PIN belum tercetak
F.S : Tampilan menu PIN sudah tercetak
*/
void displaySalahPin(int bhs);
/*prosedur untuk menampilkan tampilan jika terdapat kesalahan dalam menginput pin
I.S : Tampilan menu pin jika salah belum terbentuk
F.S : Tampilan menu pin jika salah sudah terbentuk
*/
void displayAkunTerblokir(int bhs);
/*prosedur untuk menampilkan tampilan jika input kesalahan pin lebih dari tiga kali
I.S : Tampilan jika akun terblokir belum tercetak
F.S : Tampilan jika akun terblokir sudah tercetak
*/
void displayMenuPenarikanCepat(int bhs);
/*prosedur untuk menampilkan tampilan pada menu penarikan cepat
I.S : Tampilan untuk menu penarikan cepat belum tercetak
F.S : Tampilan untuk menu penarikan cepat sudah tercetak
*/
void displayTransaksiBerhasil(int bhs);
/*prosedur untuk menampilkan tammpilan jika transaksi berhasil
I.S : Tampilan jika transaksi belum tercetak
F.S : Tampilan jika transaksi berhasil sudah tercetak
*/
void displayTransaksiGagal(int bhs);
/*prosedur untuk menampilkan tampilan jika transaksi gagal
I.S : Tampilan untuk transaksi gagal belum tercetak
F.S : Tampilan untuk transaksi gagal sudah tercetak
*/
void displayTransaksiGagallimit(int bhs);
/*prosedur untuk menampilkan tampilan jika transaksi melebihi limit batas perhari
I.S : Tampilan transaksi gagal karena limit belum tercetak
F.S : Tampilan transaksi gagal karena limit sudah tercetak
*/
void displayMenuJumlahLain(int bhs);
/*prosedur untuk menampilkan tampilan jika user ingin menarik uang dalam jumlah lain 
I.S : Tampilan menu jumlah lain belum tercetak
F.S : Tampilan menu jumlah lain sudah tercetak
*/
void displayLoading(int bhs);
/*prosedur untuk menampilkan jeda loading pada setiap transaksi
I.S : Tampilan jeda loading pada setiap transaksi belum tercetak
F.S : Tampilan jeda loading pada setiap transaksi sudah tercetak
*/
void displayEnd(int bhs);
/*prosedur untuk menampilkan tampilan ucapan terima kasih pada setiap akhir transaksi 
I.S : Tampilan dispalyEnd belum tercetak
F.S : Tampilan displayEnd sudah tercetak
*/
void displayMenuLainnya(int bhs);
/*prosedur untuk meampilkan tampilan jumlah lainnya selain dari menu penarikan cepat
I.S : Tampilan menu lainnya belum tercetak
F.S : Tampilan menu lainnya sudah tercetak
*/
void displayMenuTransfer(int bhs);
/*prosedur untuk menampilkan tampilan menu transfer
I.S : Tampilan menu transfer belum tercetak
F.S : Tampilan menu transfer sudah tercetak
*/

void displayNo_RekNull(int bhs);

void displayProsesTransfer(int bhs);
/*prosedur untuk menampilkan tampilan jika proses transfer berlangsung
I.S : Tampilan proses transfer belum tercetak
F.S : Tampilan proses transfer sudah tercetak
*/
void displaytransfergagal(int bhs);
/*prosedur untuk menampilkan tampilan jika transfer gagal dilakukan
I.S : Tampilan jika transfer gagal belum tercetak
F.S : Tampilan jika transfer gagal sudah tercetak
*/
void displaytransferberhasil(int bhs);
/*prosedur untuk menampilkan tampilan jika tranfer berhasil dilakukan
I.S : Tampilan jika transfer berhasil belum tercetak
F.S : Tampilan jika transfer berhasil sudah tercetak
*/
void displaykonfirmasitrf(int bhs,int nilai[], int admin);
/*prosedur untuk menampilkan tampilan konfirmasi transfer
I.S : Tampilan untuk konfirmasi transfer belum tercetak
F.S : Tampilan untuk konfifmasi transfer sudah tercetak
*/
void displaygoodtransfer(int bhs);
/*prosedur untuk menampilkan tampilan jika transaksi selesai dan menanyakan kembali apakah user ingin transfer lagi
I.S : Tampilan transaksi selesai belum tercetak
F.S : Tampilan transaksi selesai sudah tercetak
*/

void displayInformasiSaldo(int bhs);
/*prosedur untuk menampilkan tampilan Informasi Saldo
I.S : Tampilan untuk Informasi Saldo belum tercetak
F.S : Tampilan untuk Informasi Saldo sudah tercetak
*/

void displayUbahPinLama(int bhs);
/*prosedur untuk menampilkan tampilan meminta input pin lama
I.S : Tampilan untuk tampilan meminta input pin lama belum tercetak
F.S : Tampilan untuk tampilan meminta input pin lama sudah tercetak
*/

void displayMenuSetor(int bhs);
/*prosedur untuk menampilkan menu setor tunai
I.S : Tampilan untuk menu setor tunai belum tercetak
F.S : Tampilan untuk menu setor tunai sudah tercetak
*/


void displaysetorberhasil(int bhs);
/*prosedur untuk menampilkan setoran berhasil
I.S : Tampilan untuk setoran berhasil belum tercetak
F.S : Tampilan untuk setoran berhasil sudah tercetak
*/

void displayPinBaru(int bhs);
/*prosedur untuk menampilkan tampilan meminta input pin baru
I.S : Tampilan untuk tampilan meminta input pin baru belum tercetak
F.S : Tampilan untuk tampilan meminta input pin baru sudah tercetak
*/

void displaySalahMengubahPin(int bhs);
/*prosedur untuk menampilkan pin yang dimasukkan salah
I.S : Tampilan untuk pin yang dimasukkan salah belum tercetak
F.S : Tampilan untuk pin yang dimasukkan salah sudah tercetak
*/

void displayUbahPinBerhasil(int bhs);
/*prosedur untuk menampilkan berhasil mengubah pin
I.S : Tampilan untuk berhasil mengubah pin belum tercetak
F.S : Tampilan untuk berhasil mengubah pin sudah tercetak
*/

void displayUbahPinGagal(int bhs);
/*prosedur untuk menampilkan berhasil mengubah pin
I.S : Tampilan untuk gagal mengubah pin belum tercetak
F.S : Tampilan untuk gagal mengubah pin sudah tercetak
*/
void displaySaldoAtmHabis(int Bhs);
//

void displaykonfirmasiPin(int bhs);
/*prosedur untuk menampilkan permintaan konfirmasi pin baru
I.S : Tampilan untuk permintaan konfirmasi pin baru belum tercetak
F.S : Tampilan untuk permintaan konfirmasi pin baru sudah tercetak
*/

void cetakMutasi(int bhs, int nilai[], int transaksi[], int *i);
/*prosedur untuk menampilkan riwayat mutasi rekening
I.S : Tampilan untuk riwayat mutasi rekening belum tercetak
F.S : Tampilan untuk riwayat mutasi rekeningpermintaan konfirmasi pin baru sudah tercetak
*/

 void displaybuatakun();
 
 void displayAkunBerhasil();

//Deklarasi variabel Global
Nasabah user[100] = {
				{.No_Rekening="221524044",.Nama="Mahardika",.Pin="123456",.Bank = "BRI", .total_saldo=1000000},
				{.No_Rekening="221524043",.Nama="Keanu",.Pin="111111",.Bank = "BCA", .total_saldo=20000},
				{.No_Rekening="221524057",.Nama="Reza",.Pin="123123",.Bank = "BNI", .total_saldo=50000},
			};	
//variabel untuk index nominal
int k;
//variabel untuk index user
int j;
//variabel untuk index penerima
int r;
//variabel global untuk data uang atm
int saldo_ATM = 5000000;

int main(){
	system ("color 1F"); //syntak untuk mengubah warna di cmd
	system("cls");
	displayLoginAtm();
	return 0;
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

void displayLoginAtm(){
	int i;
	header();
	printToxy(50,3,"SILAKAN MASUKKAN");
	printToxy(51,4,"KARTU ATM ANDA");
	printToxy(42,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	for(i=1; i<35;i++){
		printToxy(20+i,9,"_");
	}
	for(i=1; i<10;i++){
		printToxy(20,9+i,"|");
	}
	for(i=1; i<35;i++){
		printToxy(20+i,18,"_");
	}
	for(i=1; i<16;i++){
		printToxy(55,6+i,"|");
	}
	for(i=1; i<3;i++){
		printToxy(55+i,6,"_");
	}
	for(i=1; i<16;i++){
		printToxy(58,6+i,"|");
	}
	for(i=1; i<3;i++){
		printToxy(55+i,21,"_");
	}
	
	printToxy(24,10,"_______");
	printToxy(24,12,"_______");
	printToxy(23,11,"|");
	printToxy(23,12,"|");
	printToxy(31,12,"|");
	printToxy(31,11,"|");
	printToxy(90,9,"LOG IN");
	printToxy(90,13,"BUAT AKUN");
	printToxy(60,24,"\t Masukan pilihan anda : ");
}

void displayBacaKartu(){
	int i;
	header();
	printToxy(50,3,"SILAKAN MASUKKAN");
	printToxy(51,4,"KARTU ATM ANDA");
	printToxy(42,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	for(i=1; i<35;i++){
		printToxy(20+i,9,"_");
	}
	for(i=1; i<10;i++){
		printToxy(20,9+i,"|");
	}
	for(i=1; i<35;i++){
		printToxy(20+i,18,"_");
	}
	for(i=1; i<16;i++){
		printToxy(55,6+i,"|");
	}
	for(i=1; i<3;i++){
		printToxy(55+i,6,"_");
	}
	for(i=1; i<16;i++){
		printToxy(58,6+i,"|");
	}
	for(i=1; i<3;i++){
		printToxy(55+i,21,"_");
	}
	
		printToxy(24,10,"_______");
		printToxy(24,12,"_______");
		printToxy(23,11,"|");
		printToxy(23,12,"|");
		printToxy(31,12,"|");
		printToxy(31,11,"|");
		printToxy(60,9,"MASUKKAN NO REKENING ANDA UNTUK");	
		printToxy(60,10,"VALIDASI KARTU : ");		
}

void displayTidakTerdaftar(){
	int i;
	header();
	printToxy(43,3,"REKENING YANG ANDA MASUKKAN TIDAK TERDAFTAR");
	printToxy(37,4,"SILAKAN MEMASUKKAN KEMBALI NOMOR REKENING");
	printToxy(42,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	for(i=1; i<35;i++){
		printToxy(20+i,9,"_");
	}
	for(i=1; i<10;i++){
		printToxy(20,9+i,"|");
	}
	for(i=1; i<35;i++){
		printToxy(20+i,18,"_");
	}
	for(i=1; i<16;i++){
		printToxy(55,6+i,"|");
	}
	for(i=1; i<3;i++){
		printToxy(55+i,6,"_");
	}
	for(i=1; i<16;i++){
		printToxy(58,6+i,"|");
	}
	for(i=1; i<3;i++){
		printToxy(55+i,21,"_");
	}
	
		printToxy(24,10,"_______");
		printToxy(24,12,"_______");
		printToxy(23,11,"|");
		printToxy(23,12,"|");
		printToxy(31,12,"|");
		printToxy(31,11,"|");
		
		printToxy(60,9,"MASUKKAN NO REKENING ANDA : ");
		
}

void displaybuatakun(){
	int i;
	header();
	printToxy(50,3,"SILAKAN MASUKKAN");
	printToxy(51,4,"KARTU ATM ANDA");
	printToxy(42,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	for(i=1; i<35;i++){
		printToxy(20+i,9,"_");
	}
	for(i=1; i<10;i++){
		printToxy(20,9+i,"|");
	}
	for(i=1; i<35;i++){
		printToxy(20+i,18,"_");
	}
	for(i=1; i<16;i++){
		printToxy(55,6+i,"|");
	}
	for(i=1; i<3;i++){
		printToxy(55+i,6,"_");
	}
	for(i=1; i<16;i++){
		printToxy(58,6+i,"|");
	}
	for(i=1; i<3;i++){
		printToxy(55+i,21,"_");
	}
	
	printToxy(24,10,"_______");
	printToxy(24,12,"_______");
	printToxy(23,11,"|");
	printToxy(23,12,"|");
	printToxy(31,12,"|");
	printToxy(31,11,"|");	
}

void displayAkunBerhasil(){
	int i;
	header();
	printToxy(50,3,"KARTU ATM TELAH");
	printToxy(48,4,"BERHASIL DIDAFTARKAN");
	printToxy(42,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	for(i=1; i<35;i++){
		printToxy(20+i,9,"_");
	}
	for(i=1; i<10;i++){
		printToxy(20,9+i,"|");
	}
	for(i=1; i<35;i++){
		printToxy(20+i,18,"_");
	}
	for(i=1; i<16;i++){
		printToxy(55,6+i,"|");
	}
	for(i=1; i<3;i++){
		printToxy(55+i,6,"_");
	}
	for(i=1; i<16;i++){
		printToxy(58,6+i,"|");
	}
	for(i=1; i<3;i++){
		printToxy(55+i,21,"_");
	}
	
		printToxy(24,10,"_______");
		printToxy(24,12,"_______");
		printToxy(23,11,"|");
		printToxy(23,12,"|");
		printToxy(31,12,"|");
		printToxy(31,11,"|");
			
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
	printToxy(60,24,"\t Masukan pilihan anda : ");
}

void displayMenuPinId(int bhs){
	header();
	if (bhs == 1){
	printToxy(53,3,"MASUKKAN PIN");
	printToxy(54,4,"ATM ANDA !");
	}
	else if(bhs == 2){
	printToxy(53,3,"ENTER YOUR");
	printToxy(54,4,"ATM PIN !");
	}
	printToxy(42,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(53,14,"_ _ _ _ _ _");
	printToxy(105,17,"<= [6]");
	
}

void displaySalahPin(int bhs){
	header();
	printToxy(43,6,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(53,14,"_ _ _ _ _ _");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	printToxy(105,21,"<=[99]");
	if(bhs == 1){
		printToxy(52,3,"PIN ANDA SALAH ");
		printToxy(47,4,"SILAKAN MASUKKAN KEMBALI ");
		printToxy(49,5,"NOMOR PIN YANG BENAR ");
		printToxy(47,16,"KARTU ANDA AKAN DIBLOKIR");
		printToxy(43,17,"BILA ANDA SALAH PIN 3(TIGA) KALI");
		printToxy(90,21,"KELUAR");
		
		
	}
	else if(bhs == 2){
		printToxy(52,3,"YOUR PIN IS WRONG ");
		printToxy(53,4,"PLEASE RE-ENTER ");
		printToxy(49,5,"THE CORRECT PIN NUMBER ");
		printToxy(47,16,"YOU CARD WILL BE BLOCKED");
		printToxy(43,17,"IF YOU WRONG PIN 3(THREE) TIMES");
	}
}

void displayAkunTerblokir(int bhs){
	header();
	printToxy(43,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	printToxy(46,13,". . . . . . . . . . . . . . ");
	if (bhs == 1){
		printToxy(48,3,"ANDA TELAH 3 KALI SALAH");
		printToxy(52,4,"MEMASUKKAN PIN");
		printToxy(47,17,"SILAHKAN AMBIL KARTU ANDA");
		printToxy(46,18,"DAN HUBUNGI CALL CENTER KAMI");
		printToxy(50,11,"KARTU ANDA SEMENTARA");
		printToxy(48,12,"TIDAK DAPAT DIPERGUNAKAN");
	}
	else if(bhs == 2){
		printToxy(48,3,"YOU HAVE ENTERED THE WRONG");
		printToxy(55,4,"PIN 3 TIMES");
		printToxy(50,17,"PLEASE TAKE YOUR CARD");
		printToxy(46,18,"AND CONTACT OUR CALL CENTER");
		printToxy(55,11,"YOU CARD IS");
		printToxy(50,12,"TEMPORARILY UNUSABLE");
	}
}

void displayMenuPenarikanCepat(int bhs){
	header();
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
	printToxy(105,17,"<= [6]");
	printToxy(105,21,"<=[99]");
	if (bhs == 1){
		printToxy(50,3,"MENU PENARIKAN CEPAT");
		printToxy(44,4,"SILAHKAN PILIH JUMLAH PENARIKAN");
		printToxy(83,13,"Jumlah Lain");
		printToxy(83,17,"Menu Lainnya");
		printToxy(90,21,"KELUAR");
		printToxy(60,24,"\t Masukan pilihan anda : ");
		
	}
	if (bhs == 2){
		printToxy(50,3,"QUICK WITHDRAWAL MENU");
		printToxy(42,4,"PLEASE SELECT THE WITHDRAWAL AMOUNT");
		printToxy(83,13,"Another Amount");
		printToxy(83,17,"Other Menus");
		printToxy(60,24,"\t Enter Your Choice : ");
		printToxy(90,21,"EXIT");
	}
}

void displayTransaksiBerhasil(int bhs){
	header();
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	if(bhs == 1){
		printToxy(52,3,"DETAIL TRANSAKSI");
		printToxy(95,13,"YA");
		printToxy(92,17,"TIDAK");
		printToxy(51,7,"TRANSAKSI BERHASIL");
		gotoxy(49,9);
		printf("SISA SALDO ANDA: %d", user[j].total_saldo);
		printToxy(40,11,"APAKAH ANDA INGIN MELANJUTKAN TRANSAKSI ?");
		printToxy(60,24,"\t Masukan pilihan anda : ");
	}
	else if(bhs ==2){
		printToxy(52,3,"TRANSACTION DETAILS");
		printToxy(95,13,"YES");
		printToxy(95,17,"NO");
		printToxy(51,7,"SUCCESSFUL TRANSACTION");
			gotoxy(49,9);
		printf("YOUR CURRENT BALANCE: %d", user[j].total_saldo);
		printToxy(40,11,"DO YOU WANT TO CONTINUE THE TRANSACTION ?");
		printToxy(60,24,"\t Enter Your Choice : ");
	}
}

void displayTransaksiGagal(int bhs){
	header();
	printToxy(43,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	if(bhs == 1){
		printToxy(52,3,"DETAIL TRANSAKSI");
		printToxy(95,13,"YA");
		printToxy(92,17,"TIDAK");
		printToxy(52,8,"TRANSAKSI GAGAL");
		printToxy(48,9,"PASTIKAN SALDO ANDA CUKUP");
		printToxy(40,11,"APAKAH ANDA INGIN MELANJUTKAN TRANSAKSI ?");
		printToxy(60,24,"\t Masukan pilihan anda : ");
	}
	else if(bhs == 2){
		printToxy(52,3,"TRANSACTION DETAILS");
		printToxy(95,13,"YES");
		printToxy(95,17,"NO");
		printToxy(52,8,"TRANSACTION FAILED");
		printToxy(45,9,"MAKE SURE YOUR BALANCE IS ENOUGH");
		printToxy(40,11,"DO YOU WANT TO CONTINUE THE TRANSACTION ?");
		printToxy(60,24,"\t Enter Your Choice : ");
	}
}

void displayTransaksiGagallimit(int bhs){
	header();
	printToxy(43,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	if (bhs == 1){
		printToxy(52,3,"DETAIL TRANSAKSI");
		printToxy(95,13,"YA");
		printToxy(92,17,"TIDAK");
		printToxy(53,8,"TRANSAKSI GAGAL");
		printToxy(42,9,"ANDA TELAH MELEWATI LIMIT BATAS PENARIKAN");
		printToxy(42,11,"APAKAH ANDA INGIN MELANJUTKAN TRANSAKSI ?");
		printToxy(60,24,"\t Masukan pilihan anda : ");
	}
	else if(bhs == 2){
		printToxy(50,3,"TRANSACTION DETAILS");
		printToxy(95,13,"YES");
		printToxy(95,17,"NO");
		printToxy(52,8,"TRANSACTION FAILED");
		printToxy(42,9,"YOU HAVE EXCEEDED THE WITHDRAWAL LIMIT");
		printToxy(40,11,"DO YOU WANT TO CONTINUE THE TRANSACTION ?");
		printToxy(60,24,"\t Enter Your Choice : ");
	}
}

void displayMenuJumlahLain(int bhs){
	header();
	printToxy(43,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	printToxy(48,10,"Rp.");
	if (bhs == 1){
		printToxy(51,3,"SILAHKAN MASUKKAN");
		printToxy(47,4,"JUMLAH YANG INGIN DI TARIK ");
		printToxy(19, 17,"BATAL");
		printToxy(92,17,"SALAH");
		printToxy(92,13,"BENAR");
		printToxy(60,24,"\t Masukan pilihan anda : ");
	}
	else if(bhs == 2){
		printToxy(54,3,"PLEASE ENTER");
		printToxy(44,4,"THE AMOUNT YOU WISH TO WITHDRAWL ");
		printToxy(19, 17,"CANCEL");
		printToxy(92,17,"FALSE");
		printToxy(92,13,"TRUE");
		printToxy(60,24,"\t Enter Your Choice : ");
	}
}

void displayEnd(int bhs){
  	header();
  	printToxy(45,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
  	if (bhs == 1){
		printToxy(55,3,"BANK RAKYAT");
		printToxy(44,10,"TERIMA KASIH TELAH MEMERCAYAI KAMI");
		printToxy(43,11,"SEBAGAI PARTNER ANDA DALAM PERBANKAN ");
	}
	else if (bhs == 2){
		printToxy(55,3,"BANK RAKYAT");
		printToxy(47,10,"THANK YOU FOR TRUSTING US AS ");
		printToxy(49,11,"YOUR PARTNER IN BANKING ");
	}
}

void displayMenuLainnya(int bhs){
	header();
	printToxy(43,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	printToxy(105,21,"<=[99]");
		
	if (bhs == 1){
		printToxy(48,3,"SILAKAN PILIH TRANSAKSI");
		printToxy(51,4,"YANG ANDA INGINKAN");
		printToxy(18,9,"TRANSFER");
		printToxy(18,13,"SETOR TUNAI");
		printToxy(18,17,"INFORMASI SALDO");
		printToxy(84,9,"UBAH PIN");
		printToxy(84,13,"MUTASI REKENING");
		printToxy(84,17,"MENU SEBELUMNYA");
		printToxy(90,21,"KELUAR");
		printToxy(60,24,"\t Masukan pilihan anda : ");
	
	}
	else if (bhs == 2){
		printToxy(49,3,"SELECT THE TRANSACTION");
		printToxy(56,4,"YOU WANT");
		printToxy(18,9,"TRANSFER");
		printToxy(18,13,"CASH DEPOSIT");
		printToxy(18,17,"BALANCE INFORMATION");
		printToxy(84,9,"CHANGE PIN");
		printToxy(84,13,"ACCOUNT MUTATION");
		printToxy(84,17,"PREVIOUS MENUS");
		printToxy(90,21,"KELUAR");
		printToxy(60,24,"\t Enter Your Choice : ");
	}
}

void displayMenuTransfer(int bhs){
	header();
	printToxy(43,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(49,8,"_ _ _ _ _ _ _ _ _ _ _");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	if (bhs == 1){
		printToxy(90,9,"BENAR");
		printToxy(44,3,"MASUKKAN NOMOR REKENING TUJUAN");
		printToxy(90,13,"SALAH");
		printToxy(60,24,"\t Masukan pilihan anda : ");
	}
	else if(bhs == 2){
		printToxy(42,3,"ENTER THE DESTINATION ACCOUNT NUMBER");
		printToxy(90,9,"TRUE");
		printToxy(90,13,"FALSE");
		printToxy(60,24,"\t Enter Your Choice : ");
	}
}

 void displayNo_RekNull(int bhs){
	header();
	printToxy(43,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(49,8,"_ _ _ _ _ _ _ _ _ _ _");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	if (bhs == 1){
		printToxy(90,9,"BENAR");
		printToxy(48,3,"NOMOR REKENING TIDAK ADA");
		printToxy(44,4,"MASUKKAN NO REKENING YANG BENAR");
		printToxy(90,13,"SALAH");
		printToxy(60,24,"\t Masukan pilihan anda : ");
	}
	else if(bhs == 2){
		printToxy(47,3,"NUMBER ACCOUNT DOESN'T EXIST");
		printToxy(42,4,"ENTER THE DESTINATION ACCOUNT NUMBER");
		printToxy(90,9,"TRUE");
		printToxy(90,13,"FALSE");
		printToxy(60,24,"\t Enter Your Choice : ");
	}
}

 void displayProsesTransfer(int bhs){
	header();
	printToxy(43,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(52,8,"RP. ");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	if (bhs == 1){
		printToxy(48,3,"MASUKKAN JUMLAH NOMINAL");
		printToxy(49,4,"YANG AKAN DITRANSFER ");
		printToxy(60,24,"\t Masukan pilihan anda : ");
	}
	else if (bhs == 2){
		printToxy(48,3,"ENTER THE NOMINAL AMOUNT");
		printToxy(51,4,"TO BE TRANSFERED ");
		printToxy(60,24,"\t Enter Your Choice : ");
	}
}

void displaytransfergagal(int bhs){
	header();
	printToxy(45,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	if (bhs == 1){
		printToxy(51,3,"MAAF TRANSFER GAGAL");
		printToxy(48,4,"SALDO ANDA TIDAK MENCUKUPI ");
		printToxy(50,13,"PASTIKAN SALDO ANDA CUKUP ");
		printToxy(90,13,"LANJUTKAN");
		printToxy(90,17,"EXIT");
		printToxy(60,24,"\t Masukan pilihan anda : ");
	}
	else if (bhs == 2){
		printToxy(51,3,"SORRY TRANSFER FAILED");
		printToxy(37,4,"YOUR ACCOUNT NUMBER/BALANCE IS WRONG/INNADEQUATE ");
		printToxy(45,13,"MAKE SURE YOUR BALANCE IS ENOUGH ");
		printToxy(90,13,"CONTINUE");
		printToxy(90,17,"EXIT");                                               
		printToxy(60,24,"\t Enter Your Choice : ");  
	}
}

void displaygoodtransfer(int bhs){
   	header();
	printToxy(45,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	if (bhs == 1){
		printToxy(50,3,"TRANSAKSI TELAH SELESAI");
		printToxy(49,4,"PERLU TRANSAKSI YANG LAIN ?");
		printToxy(90,13,"YA");
		printToxy(90,17,"TIDAK");
		printToxy(60,24,"\t Masukan pilihan anda : ");
	}
	else if(bhs == 2){
		printToxy(47,3,"TRANSACTION HAS BEEN COMPLETED");
		printToxy(49,4,"NEED ANOTHER TRANSACTION ?");
		printToxy(90,13,"YES");
		printToxy(90,17,"NO");
		printToxy(60,24,"\t Enter Your Choice : ");
	}
 }

void displaykonfirmasitrf(int bhs,int nilai[], int admin){
 	header();
	printToxy(43,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	if (bhs == 1){
		printToxy(52,3,"KONFIRMASI TRANSFER");
		printToxy(95,13,"YA");
		printToxy(92,17,"TIDAK");
		printToxy(50,9,"BANK       :");
	 	printf ("%s", user[r].Bank);
		printToxy(50,10,"TUJUAN     :");
		printf ("%s", user[r].No_Rekening);
		printToxy(50,11,"NAMA       :");
		printf ("%s", user[r].Nama);
		printToxy(50,12,"JUMLAH     :");
		printf ("%d", nilai[k]);
		printToxy(50,13,"ADMIN BANK :");
		printf ("%d", admin);
		printToxy(50,14,"TOTAL      :");
		printf ("%d", nilai[k]+admin);
		printToxy(60,24,"\t Masukan pilihan anda :  ");
	}
	else if (bhs == 2){
		printToxy(52,3,"TRANSFER CONFIRMATION");
		printToxy(95,13,"YES");
		printToxy(95,17,"NO");
		printToxy(50,9,"BANK       :");
	 	printf ("%s", user[r].Bank);
		printToxy(50,10,"DESTINATION:");
		printf ("%s", user[r].No_Rekening);
		printToxy(50,11,"NAME       :");
		printf ("%s", user[r].Nama);
		printToxy(50,12,"AMOUNT     :");
		printf ("%d", nilai[k]);
		printToxy(50,13,"ADMIN FEE  :");
		printf ("%d", admin);
		printToxy(50,14,"TOTAL      :");
		printf ("%d", nilai[k]+admin);
		printToxy(60,24,"\t Enter Your Choice :  ");
	}
 }
 
 void displaysetorberhasil(int bhs){
    header();
	printToxy(45,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	if (bhs == 1){
		printToxy(53,3,"PENYETORAN BERHASIL ");
		printToxy(34,13,"SALDO ANDA SAAT INI : ");
		printToxy(53,17,"SETOR LAGI ?");
		printToxy(94,13,"YA");
		printToxy(94,17,"TIDAK");
		printToxy(60,24,"\t Masukan pilihan anda :  ");
	}
	else if (bhs == 2){
		printToxy(53,3,"SUCCESSFUL DEPOSIT ");
		printToxy(34,13,"YOUR CURRENT BALANCE : ");
		printToxy(53,17,"DEPOSIT AGAIN ?");
		printToxy(94,13,"YES");
		printToxy(94,17,"NO");
		printToxy(60,24,"\t Enter Your Choice :  ");
	}
	
}

 void displayLoading(int bhs){
	header();
	printToxy(45,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	if (bhs == 1){
		printToxy(52,3,"HARAP TUNGGU PROSES ");
		printToxy(48,4,"TRANSAKSI SEDANG BERLANGSUNG  ");
		printToxy(40,13,"TERIMA KASIH TELAH BERTRANSAKSI DENGAN KAMI");
	}
	else if (bhs ==2){
		printToxy(52,3,"PLEASE WAIT FOR THE ");
		printToxy(45,4,"TRANSACTION PROCESS TO TAKE PLACE  ");
		printToxy(45,13,"THANK YOU FOR TRANSACTING WITH US");
	}
}

void displayInformasiSaldo(int bhs){
	header();
	printToxy(42,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(52,9,"RP. ");
	printf("%d", user[j].total_saldo);
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	if (bhs == 1){
		printToxy(49,4,"SALDO REKENING ANDA");
		printToxy(92,13,"IYA");
		printToxy(92,17,"TIDAK");
		printToxy(60,24,"\t Masukan pilihan anda :  ");
	}
	else if (bhs == 2){
		printToxy(49,4,"YOUR ACCOUNT BALANCE");
		printToxy(92,13,"YES");
		printToxy(92,17,"NO");
		printToxy(60,24,"\t Enter Your Choice :  ");
	}
}

void displayUbahPinLama(int bhs){
	header();
	printToxy(43,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	printToxy(53,14,"_ _ _ _ _ _");
	if (bhs == 1){
		printToxy(52,3,"PERUBAHAN PIN");
		printToxy(51,8,"MASUKKAN 6 DIGIT");
		printToxy(52,9,"PIN LAMA ANDA");
		printToxy(60,24,"\t Masukan pilihan anda :  ");
	}
	else if(bhs == 2){
		printToxy(54,3,"PIN CHANGE");
		printToxy(52,8,"ENTER YOUR OLD");
		printToxy(53,9,"6 DIGIT PIN");
		printToxy(60,24,"\t Enter Your Choice :  ");
	}
}

void displayPinBaru(int bhs){
	header();
	printToxy(43,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	printToxy(53,12,"_ _ _ _ _ _");
	if (bhs == 1){
		printToxy(52,3,"PERUBAHAN PIN");
		printToxy(51,8,"MASUKKAN 6 DIGIT");
		printToxy(52,9,"PIN BARU ANDA");
	}
	else if (bhs == 2){
		printToxy(54,3,"PIN CHANGE");
		printToxy(52,8,"ENTER YOUR NEW");
		printToxy(53,9,"6 DIGIT PIN");
	}
}

void displayUbahPinBerhasil(int bhs){
	header();
	printToxy(43,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	if (bhs == 1){
		printToxy(52,3,"PERUBAHAN PIN");
		printToxy(52,12,"TRANSAKSI LAGI ?");
		printToxy(51,8,"UBAH PIN BERHASIL");
		printToxy(90,13,"YA");
		printToxy(90,17,"TIDAK");
		printToxy(60,24,"\t Masukan pilihan anda :  ");
	}
	else if (bhs == 2){
		printToxy(54,3,"PIN CHANGE");
		printToxy(50,12,"ANOTHER TRANSACTION ?");
		printToxy(48,8,"CHANGE PIN WAS SUCCESSFUL");
		printToxy(88,13,"YES");
		printToxy(88,17,"NO");
		printToxy(60,24,"\t Enter Your Choice :  ");
	}
}

void displayUbahPinGagal(int bhs){
	header();
	printToxy(43,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	if (bhs == 1){
		printToxy(52,3,"PERUBAHAN PIN");
		printToxy(48,8,"ANDA TELAH 3(KALI) SALAH");
		printToxy(52,9,"MEMASUKKAN PIN");
		printToxy(51,6,"GAGAL MENGUBAH PIN");
		printToxy(50,11,"LANJUTKAN TRANSAKSI ?");
		printToxy(90,13,"YA");
		printToxy(90,17,"TIDAK");
		printToxy(60,24,"\t Masukan pilihan anda :  ");
	}
	else if(bhs == 2){
		printToxy(54,3,"PIN CHANGE");
		printToxy(46,8,"YOU HAVE CHANGED THE WRONG");
		printToxy(50,9,"PIN 3(THREE) TIMES");
		printToxy(49,6,"FAILED TO CHANGE PIN");
		printToxy(48,11,"CONTINUE TRANSACTION ?");
		printToxy(90,13,"YES");
		printToxy(90,17,"NO");
		printToxy(60,24,"\t Enter Your Choice :  ");
	}
}

void displaySalahMengubahPin(int bhs){
	header();
	printToxy(43,6,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(53,12,"_ _ _ _ _ _");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	if (bhs == 1){
		printToxy(52,3,"PIN ANDA SALAH ");
		printToxy(47,4,"SILAKAN MASUKKAN KEMBALI ");
		printToxy(49,5,"NOMOR PIN YANG BENAR ");
		printToxy(47,16,"ANDA AKAN DIKELUARKAN");
		printToxy(43,17,"BILA ANDA SALAH PIN 3(TIGA) KALI");
	}
	else if (bhs == 2){
		printToxy(52,3,"YOUR PIN IS WRONG ");
		printToxy(47,4,"PLEASE RE-ENTER THE ");
		printToxy(49,5,"CORRECT PIN NUMBER ");
		printToxy(47,16,"YOU WILL BE KICKED OUT");
		printToxy(43,17,"IF YOU WRONG PIN 3 TIMES");
	}
}

void displaykonfirmasiPin(int bhs){
	header();
	printToxy(43,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	printToxy(53,12,"_ _ _ _ _ _");
	if (bhs == 1){
		printToxy(47,3,"KONFIRMASI PERUBAHAN PIN");
		printToxy(51,8,"MASUKKAN KEMBALI");
		printToxy(52,9,"PIN BARU ANDA");
	}
	else if (bhs == 2){
		printToxy(52,3,"CONFIRM PIN CHANGE");
		printToxy(55,8,"RE-ENTER");
		printToxy(53,9,"YOUR NEW PIN");
	}
}

void displayMenuSetor(int bhs){
  	header();
	printToxy(45,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	if (bhs == 1){
		printToxy(50,3,"SILAKAN MASUKAN JUMLAH ");
		printToxy(49,4,"NOMINAL YANG AKAN DISETOR");
		printToxy(37,7,"HARAP MASUKKAN NOMINAL DENGAN KELIPATAN Rp. 50000");
		printToxy(34,13,"NOMINAL SETOR : Rp. ");
	}
	else if (bhs == 2){
		printToxy(50,3,"PLEASE ENTER THE NOMINAL ");
		printToxy(51,4,"AMOUNT TO BE DEPOSITED");
		printToxy(42,7,"PLEASE ENTER IN MULTIPLIES Rp. 50000");
		printToxy(34,13,"DEPOSIT AMOUNT : Rp. ");
	}
}

void displayGagalMin(int bhs){
  	header();
	printToxy(45,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");
	if (bhs == 1){
		printToxy(47,7,"MOHON MAAF TRANSAKSI GAGAL ");
		printToxy(38,8,"HARAP MASUKKAN JUMLAH NOMINAL MINIMUM Rp. 50000");
		printToxy(53,4,"DETAIL TRANSAKSI ");
		printToxy(44,12,"APAKAH ANDA INGIN TRANSAKSI LAGI?");
		printToxy(90,13,"YA");
		printToxy(87,17,"TIDAK");
		printToxy(60,24,"\t Masukan pilihan anda :  ");
	}
	else if (bhs == 2){
		printToxy(48,7,"SORRY TRANSACTION FAILED ");
		printToxy(36,8,"PLEASE ENTER THE MINIMUM NOMINAL AMOUNT OF Rp. 50000");
		printToxy(53,4,"TRANSACTION DETAIL ");
		printToxy(45,12,"DO YOU WANT ANOTHER TRANSACTION?");
		printToxy(92,13,"YES");
		printToxy(92,17,"NO");
		printToxy(60,24,"\t Enter Your Choice :  ");
	}
}

void cetakMutasi(int bhs, int nilai[], int transaksi[], int *i){
	if (bhs == 1){
		if (transaksi[*i] == 1){
			printf("\n|			   |");
			printf("\n|	Penarikan	   |");
			printf("\n|	-Rp. %d	   |", nilai[*i]);
		}
		else if (transaksi[*i] == 2){
			printf("\n|			   |");
			printf("\n|	Transfer	   |");
			printf("\n|	%s		   |", user[r].Bank);
			printf("\n|	%s	   |", user[r].No_Rekening);
			printf("\n|	-Rp. %d	   |", nilai[*i] );
		}
		else if (transaksi[*i] == 3){
			printf("\n|			   |");
			printf("\n|	Setor Tunai	   |");
			printf("\n|	+Rp. %d	   |", nilai[*i]);
		}	
	}
	else if(bhs == 2){
		if (transaksi[*i] == 1){
			printf("\n|			   |");
			printf("\n|	Withdrawal	   |");
			printf("\n|	-Rp. %d	   |", nilai[*i]);
		}
		else if (transaksi[*i] == 2){
			printf("\n|			   |");
			printf("\n|	Transfer	   |");
			printf("\n|	%s		   |", user[r].Bank);
			printf("\n|	%s	   |", user[r].No_Rekening);
			printf("\n|	-Rp. %d	   |", nilai[*i] );
		}
		else if (transaksi[*i] == 3){
			printf("\n|			   |");
			printf("\n|	Cash Deposit	   |");
			printf("\n|	+Rp. %d	   |", nilai[*i]);
		}	
	}
}

void displaySaldoAtmHabis(int bhs){
	header();
 	if (bhs == 1){
    printToxy(46,3,"UNTUK SEMENTARA TRANSAKSI");
	printToxy(48,4,"TIDAK DAPAT DIPROSES");
	printToxy(45,9,"PERLU TRANSAKSI YANG LAIN");
	printToxy(90,13,"YA");
	printToxy(90,17,"TIDAK");
	}
 	else if(bhs == 2){
	printToxy(46,3,"FOR THE TIME THE TRANSACTION ");
	printToxy(48,4,"CANNOT BE PROCESSED");
	printToxy(45,9,"NEED ANOTHER TRANSACTION");
	printToxy(90,9,"YES");
	printToxy(90,17,"NO");
	}
	
	printToxy(42,5,"=================================");
	printToxy(7,9,"[1] =>");
	printToxy(7,13,"[2] =>");
	printToxy(7,17,"[3] =>");
	printToxy(105,9,"<= [4]");
	printToxy(105,13,"<= [5]");
	printToxy(105,17,"<= [6]");			
}

