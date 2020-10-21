#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct biodata {
	char nama[30];
	char alamat[100];
	char lahir[20];
	char email[50];
	char npm[20];
	char jurusan[30];
	char universitas[50];
}mahasiswa;

int i,j,banyak=0;
char lagi;
mahasiswa mhs[50],temp;

int main (){
	int menu;
	printf("SELAMAT DATANG DALAM PROGRAM BIODATA MAHASISWA!!!!!\n\n");
	printf("-----------------------------------------------------------------------------------------------------\n\n");
	printf("1. Input data\n");
	printf("2. Update data\n");
	printf("3. HAPUS DATA\n");
	printf("4. Tampilkan data\n");
	printf("5. Urutkan berdasarkan NPM\n");
	printf("6. EXIT\n");
	printf("\nSilahkan pilih menu yang anda ingin lakukan : ");
	scanf("%d",&menu);
	system("cls");
	printf("SELAMAT DATANG DALAM PROGRAM BIODATA MAHASISWA!!!!!\n\n");
	printf("-----------------------------------------------------------------------------------------------------\n\n");
	switch(menu){
		case 1:
			input();
			break;
		case 2:
			if(banyak>0){
				update();
			}
			else{
				printf("Mohon maaf belum ada data :)\n\n");
				system("pause");
				system("cls");
			}
			break;
		case 3:
			if(banyak>0){
				hapus();
			}
			else{
				printf("Mohon maaf belum ada data :)\n\n");
				system("pause");
				system("cls");
			}
			break;
		case 4:
			if(banyak>0){
				display();
				printf("\n");
				system("pause");
				system("cls");
			}
			else{
				printf("Mohon maaf belum ada data :)\n\n");
				system("pause");
				system("cls");
			}
			break;
			
		case 5:
			if(banyak>0){
				urut();
				printf("\n");
				system("pause");
				system("cls");
			}
			else{
				printf("Mohon maaf belum ada data :)\n\n");
				system("pause");
				system("cls");
			}
			break;
			
		case 6:
			printf("TERIMA KASIH TELAH MENGGUNAKAN PROGRAM INI :)\n\n");
			system("pause");
			return 0;
		default:
			printf("Mohon maaf menu pilihan tersebut tidak ada :(\n\n");
			system("pause");
			system("cls");
	}
	main();
	return 0;
}

int input(){
	printf("Masukkan banyak mahasiswa : ");
	scanf("%d",&banyak);
	fflush(stdin);
	system("cls");
	for(i=0;i<banyak;i++){
		printf("SELAMAT DATANG DALAM PROGRAM BIODATA MAHASISWA!!!!!\n\n");
		printf("-----------------------------------------------------------------------------------------------------\n\n");
		printf("Biodata mahasiswa ke-%d\n\n", i+1);
		printf("Masukkan nama\t\t: ");
		gets(mhs[i].nama);
		printf("Masukkan tanggal lahir\t: ");
		gets(mhs[i].lahir);
		printf("Masukkan alamat\t\t: ");
		gets(mhs[i].alamat);
		printf("Masukkan email\t\t: ");
		gets(mhs[i].email);
		printf("Masukkan NPM\t\t: ");
		gets(mhs[i].npm);
		printf("Masukkan jurusan\t: ");
		gets(mhs[i].jurusan);
		printf("Masukkan universitas\t: ");
		gets(mhs[i].universitas);
		system("cls");
	}
}

int update(){
	display();
	printf("Silahkan pilih biodata ke berapa yang ingin di-update : ");
	scanf("%d",&i);
	system("cls");
	fflush(stdin);
	printf("SELAMAT DATANG DALAM PROGRAM BIODATA MAHASISWA!!!!!\n\n");
	printf("-----------------------------------------------------------------------------------------------------\n\n");
	printf("Biodata mahasiswa ke-%d\n\n", i);
	printf("Masukkan nama\t\t: ");
	gets(mhs[i-1].nama);
	printf("Masukkan tanggal lahir\t: ");
	gets(mhs[i-1].lahir);
	printf("Masukkan alamat\t\t: ");
	gets(mhs[i-1].alamat);
	printf("Masukkan email\t\t: ");
	gets(mhs[i-1].email);
	printf("Masukkan NPM\t\t: ");
	gets(mhs[i-1].npm);
	printf("Masukkan jurusan\t: ");
	gets(mhs[i-1].jurusan);
	printf("Masukkan universitas\t: ");
	gets(mhs[i-1].universitas);
	printf("\n");
	system("pause");
	system("cls");
}

int hapus(){
	display();
	printf("Silahkan pilih biodata ke berapa yang ingin dihapus : ");
	scanf("%d", &i);
	if(i>banyak||i<=0){
		system("cls");
		printf("SELAMAT DATANG DALAM PROGRAM BIODATA MAHASISWA!!!!!\n\n");
		printf("-----------------------------------------------------------------------------------------------------\n\n");
		printf("Mohon maaf tidak ada data tersebut :)\n");
		system("pause");
	}
	else{
		for(i;i<banyak;i++){
			strcpy(mhs[i-1].nama,mhs[i].nama);
			strcpy(mhs[i-1].alamat,mhs[i].alamat);
			strcpy(mhs[i-1].lahir,mhs[i].lahir);
			strcpy(mhs[i-1].email,mhs[i].email);
			strcpy(mhs[i-1].npm,mhs[i].npm);
			strcpy(mhs[i-1].jurusan,mhs[i].jurusan);
			strcpy(mhs[i-1].universitas,mhs[i].universitas);
		}
		banyak=banyak-1;
	}
	system("cls");		
}

int display(){
	for(i=0;i<banyak;i++){
		printf("Biodata mahasiswa ke-%d\n",i+1);
		printf("Nama\t\t: %s\n", mhs[i].nama);
		printf("Tanggal lahir\t: %s\n", mhs[i].lahir);
		printf("Alamat\t\t: %s\n", mhs[i].alamat);
		printf("E-mail\t\t: %s\n", mhs[i].email);
		printf("NPM\t\t: %s\n", mhs[i].npm);
		printf("Jurusan\t\t: %s\n", mhs[i].jurusan);
		printf("Universitas\t: %s\n\n", mhs[i].universitas);
	}
}

int urut(){
	display();
	int pos;
	double waktu=0.0;
	printf("-----------------------------------------------------------------------------------------------------\n\n");
	printf("1. Bubble Sort\n");
	printf("2. Selection Sort\n");
	printf("Silahkan memilih mengurutkan NPM menggunakan metode apa : ");
	scanf("%d", &i);
	system("cls");
	printf("SELAMAT DATANG DALAM PROGRAM BIODATA MAHASISWA!!!!!\n\n");
	printf("-----------------------------------------------------------------------------------------------------\n\n");
	if(i==1){
		printf("1. Kecil (Ascending)\n");
		printf("2. Besar (Descending)\n");
		printf("Silahkan memilih mengurutkan NPM berdasarkan yang paling ? ");
		scanf("%d", &i);
		if(i==1){
			clock_t start = clock()/CLOCKS_PER_SEC;
			for(j=0;j<banyak-1;j++){
				for(i=0;i<banyak-1;i++){
					if(strcmp(mhs[i].npm,mhs[i+1].npm)>0){
						temp=mhs[i];
						mhs[i]=mhs[i+1];
						mhs[i+1]=temp;
					}
				}
			}
			clock_t end = clock()/CLOCKS_PER_SEC*10;
			waktu = (double)(end-start);
			printf("\nWaktu untuk eksekusi adalah %lf \n\n",waktu);
			printf("Silahkan pencet apapun untuk melanjutkan :)\n");
		}
		else if(i==2){
			clock_t start = clock()/CLOCKS_PER_SEC;
			for(j=0;j<banyak-1;j++){
				for(i=0;i<banyak-1;i++){
					if(strcmp(mhs[i].npm,mhs[i+1].npm)<0){
						temp=mhs[i];
						mhs[i]=mhs[i+1];
						mhs[i+1]=temp;
					}
				}
			}
			clock_t end = clock()/CLOCKS_PER_SEC*10;
			waktu = (double)(end-start);
			printf("\nWaktu untuk eksekusi adalah %lf \n\n",waktu);
			printf("Silahkan pencet apapun untuk melanjutkan :)\n");
		}
		else{
			printf("\nMohon maaf tidak ada pilihan tersebut :)\n\n");
		}
	}
	else if(i==2){
		printf("1. Kecil (Ascending)\n");
		printf("2. Besar (Descending)\n");
		printf("Silahkan memilih mengurutkan NPM berdasarkan yang paling ? ");
		scanf("%d", &i);
		if(i==1){
			clock_t start = clock()/CLOCKS_PER_SEC;
			for(j=0;j<banyak-1;j++){
				pos = j;
				for(i=j+1;i<banyak;i++){
					if(strcmp(mhs[i].npm,mhs[pos].npm)<0){
						pos=i;
					}
				}
				if(pos!=j){
					temp=mhs[j];
					mhs[j]=mhs[pos];
					mhs[pos]=temp;
				}
			}
			clock_t end = clock()/CLOCKS_PER_SEC*10;
			waktu = (double)(end-start);
			printf("\nWaktu untuk eksekusi adalah %lf \n\n",waktu);
			printf("Silahkan pencet apapun untuk melanjutkan :)\n");
		}
		else if(i==2){
			clock_t start = clock()/CLOCKS_PER_SEC;
			long double mulai = (long double)(start);
			for(j=0;j<banyak-1;j++){
				pos = j;
				for(i=j+1;i<banyak;i++){
					if(strcmp(mhs[i].npm,mhs[pos].npm)>0){
						pos=i;
					}
				}
				if(pos!=j){
					temp=mhs[j];
					mhs[j]=mhs[pos];
					mhs[pos]=temp;
				}
			}
			clock_t end = clock()/CLOCKS_PER_SEC*10;
			waktu = (double)(end-start);
			printf("\nWaktu untuk eksekusi adalah %lf \n\n",waktu);
			printf("Silahkan pencet apapun untuk melanjutkan :)\n");
		}
		else{
			printf("\nMohon maaf tidak ada pilihan tersebut :)\n\n");
		}
	}
	else{
		printf("\nMohon maaf tidak ada pilihan tersebut :)\n\n");
	}
}
