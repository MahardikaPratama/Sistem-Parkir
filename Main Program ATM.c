int main(){
	displayMenuBahasa();
	scanf ("%d", &opsi);
	if (opsi == 4){
		displayMenuPin();
	}
	bacaPin(inputPin);
	Cek_validitas(&benar);
	if (benar == 1){
		displayMenuPenarikanCepat();
	}
	
	
	
	return 0;
}