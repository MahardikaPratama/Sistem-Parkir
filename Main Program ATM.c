int main(){
	displayMenuBahasa();
	scanf ("%d", &opsi);
	while (opsi == 4 || opsi == 5){
		switch (opsi){
			case 4 : displayMenuPinId();
				break;
			case 5 : 
			displayMenuPinEng();
		}
		displayMenuBahasa();
		scanf ("%d", &opsi);
	}
	bacaPin(inputPin);
	Cek_validitas(&benar);
	if (benar == 1){
		displayMenuPenarikanCepat();
	}
	
	
	
	return 0;
}
