#include <iostream>
#include <cstdlib>
#include <conio.h> 
using namespace std;

class sllc
{
public:

  int urut;
  sllc *next; 
}; 
  sllc *depan_ptr = NULL;
  sllc *posisi;         
  int option = 0; 

// Tambah Data Depan
void tambah_data_depan_list()
{
  sllc *baru;
  baru = new sllc;
  cout << "Masukkan Data     : ";
  cin >> baru->urut;
  baru->next = NULL;
  if(depan_ptr == NULL)
  {
    depan_ptr=baru;
    depan_ptr->next = NULL;
  }
  else
  {
    baru->next = depan_ptr;
    depan_ptr = baru;
  }
} 

// Tambah data belakang
void tambah_data_sllc_di_belakang()
  {
  sllc *temp, *temp2;   
  temp = new sllc; 
  cout << "Masukkan Data     : ";
  cin >>   temp->urut;
  temp->next = NULL; 


  if (depan_ptr == NULL)
  {
    depan_ptr = temp;
    posisi = depan_ptr;
  }
  else
  {
    temp2 = depan_ptr;

    while (temp2->next != NULL)
    {
      temp2 = temp2->next; 
      
    }
  temp2->next = temp;
  }
} 
// Menampilkan list
void display_list()
{
  sllc *temp;
  temp = depan_ptr;
  cout << endl;
  cout << "DATA [";  
  if (temp == NULL)
    cout << "Data kosong!]" << endl;
  else
  {
    while (temp != NULL)
    {  
     
     cout << "" << temp->urut << ",";
     
     if (temp == posisi)
        cout << "";

     temp = temp->next; 
    }
    cout << "] ";  
    cout << "" << endl;
  }
  
} 
//Hapus data depan
void hapus_depan_sllc()
{
  sllc *temp;
  temp = depan_ptr;
  depan_ptr = depan_ptr->next;
  delete temp;
} 
//Hapus data belakang
void hapus_belakang_sllc()
{
  sllc *temp1, *temp2;
  if (depan_ptr == NULL)
    cout << "Data kosong!" << endl;
  else
  {
    temp1 = depan_ptr;
    if (temp1->next == NULL)
    {
      delete temp1;
      depan_ptr = NULL;
    }
    else 
    {
      while (temp1->next != NULL)
      {
        temp2 = temp1;
        temp1 = temp1->next;
      }
      delete temp1;
      temp2->next = NULL;
    }

   }
} 
//Tambah data sisip
void tambah_data_yang_akan_disisipkan_list()
{
  sllc *baru, *bantu;
  int posisi_sisip;
  if(depan_ptr != NULL)
  {
  
   
    cout<<"Akan disisip setelah Data Ke ? : ";
    cin>>posisi_sisip;
    baru =new sllc;
   bantu=depan_ptr;
     
    for(int i=1;i<posisi_sisip-1;i++) {
      if(bantu->next != NULL)
        bantu=bantu->next;
      else
        break; 
    }
  cout << "Masukkan Data     : ";
  cin >> baru->urut;
  baru->next=bantu->next;
  bantu->next=baru;
  }
  else
  {
    cout<<"Maaf data anda belum ada ! silahkan isi data terlebih dulu....";
    getch();
  } 
}
//Hapus data sisip
void Hapus_data_yang_telah_disisipkan_list()
{
  int banyakdata,posisi_hapus,poshapus;
  sllc *hapus, *bantu;
  if(depan_ptr != NULL)
  {
    cout<<"Data yang akan dihapus  : ";
    cin>>posisi_hapus;
    banyakdata=1;
    bantu=depan_ptr;
    while(bantu->next != NULL)
    {
      bantu=bantu->next;
      banyakdata++;
    }
    if((posisi_hapus<1)||(posisi_hapus>banyakdata))
    {
      cout<<"Belum ada data !! masukkan Data dula aja...\n";
    }
    else
    {
      bantu=depan_ptr;
      poshapus=1;
      while(poshapus<(posisi_hapus-1))
      {
        bantu=bantu->next;
        poshapus++;
      }
      hapus=bantu->next;
      bantu->next=hapus->next;
      delete hapus;
    }
 }
 else 
    cout<<"Maaf data anda belum ada !! silahkan isi data terlebih dulu... ";
 getch();
}
 

int init(int nilai){
 sllc *baru;
  baru = new sllc;
  baru->urut=nilai;
  baru->next = NULL;
  if(depan_ptr == NULL)
  {
    depan_ptr=baru;
    depan_ptr->next = NULL;
  }
  else
  {
    baru->next = depan_ptr;
    depan_ptr = baru;
  }
}
int main()
{
  cout <<"Nama :\tJeremmy Hesa		1817051035"<<endl;
  cout <<"\tM. Umaruddin Syam	1857051006"<<endl;
  cout <<"\tVindo RizkiYanto	1817051059"<<endl;
  cout <<"\tZia Danisvara Pakpahan	1817051067"<<endl;
  cout <<endl<< "\t\tLINKED LIST" << endl;
  depan_ptr = NULL;
  
  do
  {
    display_list();
    cout << endl;
    cout << "MENU PILIHAN : " << endl;
    cout << "0. Keluar program." << endl;
    cout << "1. Tambah data depan list." << endl;
    cout << "2. Tambah data belakang list." << endl;
    cout << "3. Hapus data depan list." << endl;
    cout << "4. Hapus data belakang list." << endl;
    cout << "5. Tambah data yang akan disisipkan list."<< endl;
    cout << "6. Hapus data yang telah disisipkan  list." << endl;
    cout << endl << "Pilihan : ";
    cin >> option; 

switch (option)
  {
  case 1 : tambah_data_depan_list(); 
  system("CLS");
    break;
  case 2 : tambah_data_sllc_di_belakang();
  system("CLS");
    break;
  case 3 : hapus_depan_sllc();
  system("CLS");
    break;
  case 4 : hapus_belakang_sllc();
  system("CLS");
    break;
  case 5 : tambah_data_yang_akan_disisipkan_list();
  system("CLS");
    break;
  case 6 : Hapus_data_yang_telah_disisipkan_list();
  system("CLS");
   
  }
 }  
while (option != 0); 
}
